/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>
#include <cmath>

#include "EsperimentoPrisma.h"

using namespace std;

EsperimentoPrisma::EsperimentoPrisma(unsigned int seed, double l1, double l2, double alpha, double sigmath, double A, double B)
	: m_rand(seed),
	  m_lambda1(l1),
	  m_lambda2(l2),
	  m_alpha(alpha * M_PI / 180.), //to rad
	  m_sigmath(sigmath),
	  m_A_input(A),
	  m_B_input(B)

{
	m_n1_input = sqrt(m_A_input + (m_B_input / (m_lambda1 * m_lambda1)));
	m_n2_input = sqrt(m_A_input + (m_B_input / (m_lambda2 * m_lambda2)));

	m_th0_input = M_PI / 2.;

	double dm1 = 2. * asin(m_n1_input * sin(0.5 * m_alpha)) - m_alpha;
	m_th1_input = m_th0_input + dm1;

	double dm2 = 2. * asin(m_n2_input * sin(0.5 * m_alpha)) - m_alpha;
	m_th2_input = m_th0_input + dm2;
}

void EsperimentoPrisma::Esegui()
{
	m_th0_misura = m_rand.GaussBoxMuller(m_th0_input, m_sigmath);
	m_th1_misura = m_rand.GaussBoxMuller(m_th1_input, m_sigmath);
	m_th2_misura = m_rand.GaussBoxMuller(m_th2_input, m_sigmath);
}

void EsperimentoPrisma::Analizza()
{
	double dth1 = m_th1_misura - m_th0_misura;
	double dth2 = m_th2_misura - m_th0_misura;

	m_n1_misura = sin(0.5 * (dth1 + m_alpha)) / sin(0.5 * m_alpha);
	m_n2_misura = sin(0.5 * (dth2 + m_alpha)) / sin(0.5 * m_alpha);

	m_A_misura = (pow(m_lambda2, 2) * pow(m_n2_misura, 2) - pow(m_lambda1, 2) * pow(m_n1_misura, 2)) / (pow(m_lambda2, 2) - pow(m_lambda1, 2));
	m_B_misura = (pow(m_n2_misura, 2) - pow(m_n1_misura, 2)) / (pow(1 / m_lambda2, 2) - pow(1 / m_lambda1, 2));
}
/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include "RandomGen.h"

class EsperimentoPrisma
{
private:
	RandomGen m_rand;

	double m_lambda1, m_lambda2, m_alpha, m_sigmath;

	double m_A_input, m_A_misura;
	double m_B_input, m_B_misura;
	double m_n1_input, m_n1_misura;
	double m_n2_input, m_n2_misura;
	double m_th0_input, m_th0_misura;
	double m_th1_input, m_th1_misura;
	double m_th2_input, m_th2_misura;

public:
	EsperimentoPrisma(unsigned int seed, double l1, double l2, double alpha, double sigmath, double A, double B);

	double AInput() { return m_A_input; };
	double BInput() { return m_B_input; };
	double n1Input() { return m_n1_input; };
	double n2Input() { return m_n2_input; };
	double th0Input() { return m_th0_input; };
	double th1Input() { return m_th1_input; };
	double th2Input() { return m_th2_input; };
	double AMisura() { return m_A_misura; };
	double BMisura() { return m_B_misura; };
	double n1Misura() { return m_n1_misura; };
	double n2Misura() { return m_n2_misura; };
	double th0Misura() { return m_th0_misura; };
	double th1Misura() { return m_th1_misura; };
	double th2Misura() { return m_th2_misura; };

	void Esegui();
	void Analizza();

	void Run()
	{
		Esegui();
		Analizza();
	};
};
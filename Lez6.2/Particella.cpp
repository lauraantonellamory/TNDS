/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <cstdlib>
#include <iostream>

#include "Particella.h"

using namespace std;

Particella::Particella()
{
	m_massa = 0.;
	m_carica = 0.;
}

Particella::Particella(double massa, double carica)
{
	m_massa = massa;
	m_carica = carica;
}

void Particella::Print() const
{
	cout << "Particella: m= " << m_massa
		 << ", q= " << m_carica << endl;
}

Elettrone::Elettrone()
	: Particella(9.1093826E-31, -1.60217653E-19){};

void Elettrone::Print() const
{
	cout << "Elettrone: m= " << m_massa
		 << ", q= " << m_carica << endl;
}

CorpoCeleste::CorpoCeleste()
{
	m_nome = "test";
	m_raggio = 0.;
};

CorpoCeleste::CorpoCeleste(string nome, double massa, double raggio) : Particella(massa, 0)
{
	m_nome = nome;
	m_raggio = raggio;
}

void CorpoCeleste::Print() const
{
	cout << m_nome << ": m= " << m_massa
		 << ", R=" << m_raggio
		 << endl;
}
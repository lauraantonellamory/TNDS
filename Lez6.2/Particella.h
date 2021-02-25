/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <iostream>

#include "Posizione.h"

using namespace std;

class Particella
{
protected:
	double m_massa;
	double m_carica;

public:
	Particella();
	Particella(double massa, double carica);

	double GetMassa() const { return m_massa; }
	double GetCarica() const { return m_carica; }
	void Print() const;
};

class Elettrone : public Particella
{
public:
	Elettrone();

	void Print() const;
};

class CorpoCeleste : public Particella
{
protected:
	std::string m_nome;
	double m_raggio;

public:
	CorpoCeleste();
	CorpoCeleste(std::string nome, double massa, double raggio);

	void SetNome(std::string nome) { m_nome = nome; }
	void SetMassa(double massa) { m_massa = massa; }
	void SetRaggio(double raggio) { m_raggio = raggio; }
	std::string GetNome() const { return m_nome; }
	double GetRaggio() const { return m_raggio; }

	void Print() const;
};
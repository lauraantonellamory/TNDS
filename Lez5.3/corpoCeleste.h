/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <iostream>
#include <string>

#include "particella.h"
#include "posizione.h"

class corpoCeleste : public particella
{
protected:
	std::string n;
	double R;
	posizione p;

public:
	const double G = 6.67E-11;

public:
	corpoCeleste(std::string nome, double massa, double raggio, posizione pos) : particella(massa, 0)
	{
		n = nome;
		R = raggio;
		p = pos;
	}

	// non ho allocato nulla, non ho nulla da distruggere
	// il compilatore ne creerà uno vuoto lui
	//~corpoCeleste() {}

	std::string getNome() const
	{
		return n;
	}
	double getRaggio() const
	{
		return R;
	}
	posizione getPosizione() const
	{
		return p;
	}
	double getPotenzialeG(posizione pos) const
	{
		double r = p.distanzaDalPunto(pos);

		return -(G * m) / r;
	}
	void setNome(std::string nome)
	{
		n = nome;
	}
	void setMassa(double massa)
	{
		m = massa;
	}
	void setRaggio(double raggio)
	{
		R = raggio;
	}
	void setPosizione(posizione pos)
	{
		p = pos;
	}
	void stampa() const
	{
		std::cout
			<< "Il corpo celeste " << n
			<< " ha massa m: " << m << " kg "
			<< " e raggio R: " << R << " m "
			<< std::endl;
	}
};
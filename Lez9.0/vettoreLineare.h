/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <iostream>
#include <cstddef>

#include "vettore.h"

using namespace std;

class vettoreLineare : public vettore
{
private:
	bool controlla_stesse_dimensioni(const vettoreLineare &b) const
	{
		auto ok = (b.size() == size());

		if (!ok)
		{
			cout
				<< "Impossibile eseguire operazioni tra vettori di dimensionalità differenti"
				<< endl;

			exit(-2);
		}

		return ok;
	}

public:
	//vettoreLineare();

	//vettore(const size_t dimensione)
	vettoreLineare(const size_t dimensione) : vettore(dimensione) {}

	//~vettoreLineare();

	// addizione vettoriale
	vettoreLineare operator+(const vettoreLineare &b) const
	{
		vettoreLineare m(size());

		if (controlla_stesse_dimensioni(b))
			for (size_t i = 0; i < size(); i++)
				m[i] = get(i) + b.get(i);

		return m;
	}

	// prodotto vettoriale
	vettoreLineare operator*(const double s) const
	{
		vettoreLineare m(size());

		for (size_t i = 0; i < size(); i++)
			m[i] = s * get(i);

		return m;
	}

	// prodotto scalare
	double operator*(const vettoreLineare &b) const
	{
		double s = 0;

		if (controlla_stesse_dimensioni(b))
			for (size_t i = 0; i < size(); i++)
				s += get(i) * b.get(i);

		return s;
	}
};
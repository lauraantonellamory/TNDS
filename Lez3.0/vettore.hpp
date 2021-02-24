/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <cstddef>

using namespace std;

template <class T>
class vettore
{
private:
	const size_t dimensione;
	T *elementi = nullptr;

public:
	// costruttore con dimensione
	vettore(const size_t dimensione) : dimensione(dimensione)
	{
		elementi = new T[dimensione];
	}

	// distruttore
	~vettore()
	{
		delete[] elementi;
	}

	size_t size() const
	{
		return dimensione;
	}

	// https://en.cppreference.com/w/cpp/language/operators
	// Array subscript operator
	// modifica la componente i-esima
	T &operator[](const size_t indice)
	{
		return elementi[indice];
	}

public:
	void scambia(const size_t indice_A, const size_t indice_B)
	{
		auto tmp = elementi[indice_A];

		elementi[indice_A] = elementi[indice_B];
		elementi[indice_B] = tmp;
	}
};
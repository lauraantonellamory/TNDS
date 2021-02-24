/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>
#include <cmath>

#include "funzioni.hpp"

using namespace std;

double funzioni::mediana(vettore &vettore, const size_t dimensione)
{
	ordina(vettore, dimensione);

	return vettore[dimensione / 2];
}

double funzioni::varianza(vettore &vettore, const size_t dimensione, double media_)
{
	double sommatoria = 0;

	for (size_t i = 0; i < dimensione; i++)
		sommatoria += pow(vettore[i] - media_, 2);

	return sommatoria / double(dimensione - 1);
}

double funzioni::media(vettore &vettore, const size_t dimensione)
{
	double sommatoria = 0;

	for (size_t i = 0; i < dimensione; i++)
		sommatoria += vettore[i];

	return sommatoria / double(dimensione);
}

// https://en.wikipedia.org/wiki/Insertion_sort
void funzioni::ordina(vettore &vettore, const size_t dimensione)
{
	double x;
	size_t i, j;

	i = 1;

	while (i < dimensione)
	{
		x = vettore[i];
		j = i - 1;

		while (j >= 0 && vettore[j] > x)
		{
			vettore[j + 1] = vettore[j];
			j--;
		}

		vettore[j + 1] = x;
		i++;
	}
}

void funzioni::print(vettore &vettore, const size_t dimensione)
{
	for (size_t i = 0; i < dimensione; i++)
		cout << i << "#: " << vettore[i] << endl;
}
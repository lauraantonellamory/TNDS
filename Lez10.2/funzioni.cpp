/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>
#include <cstdlib>
#include <fstream>

#include "funzioni.h"

using namespace std;

double media(unsigned int ndata, double *data)
{

	double media = 0;
	for (int k = 0; k < ndata; k++)
	{
		media += data[k];
	}
	media = media / double(ndata);

	return media;
}

double varianza(unsigned int ndata, double *data, double fmedia)
{

	double varianza = 0;
	double quad = 0;

	for (int i = 0; i < ndata; i++)
	{
		quad += (data[i] * data[i]);
	}
	double mediaquad = (quad / ndata);
	varianza = mediaquad - ((fmedia) * (fmedia));

	return varianza;
}

double CalcolaMediana(char *filename, double *vect, unsigned int size)
{

	double *vcopy = new double[size];

	for (int i = 0; i < size; i++)
	{
		vcopy[i] = vect[i];
	}

	selection_sort(vcopy, size);

	double fmediana = 0;

	if (size % 2 == 0)
	{
		fmediana = ((vcopy[size / 2 + 1] + vcopy[size / 2]) / 2.);
	}
	else
	{
		fmediana = vcopy[size / 2];
	}

	Print(filename, vcopy, size);

	delete[] vcopy;
	return fmediana;
}

double selection_sort(double *vect, unsigned int size)
{

	for (unsigned int j = 0; j < size - 1; j++)
	{

		int imin = j;
		double min = vect[imin];

		for (unsigned int i = j + 1; i < size; i++)
		{
			if (vect[i] < min)
			{
				min = vect[i];
				imin = i;
			}
		}
		ScambiaByRef(vect[j], vect[imin]);
	}
}

double *ReadDataFromFile(char *filename, unsigned int size)
{

	double *data = new double[size];

	ifstream fin;
	fin.open(filename);

	if (fin.eof())
	{
		cout << "Errore nel caricamento dati!" << endl;
		return NULL;
	}

	for (unsigned int i = 0; i < size; i++)
	{
		fin >> data[i];
		cout << data[i] << endl;
	}

	fin.close();

	return data;
}

void Print(char *filename, double *data, unsigned int size)
{

	ofstream fout(filename);

	for (int i = 0; i < size; i++)
	{
		fout << data[i] << endl;
	}

	fout.close();
}

void Print(double *data, int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << data[i] << endl;
	}
}

void ScambiaByRef(double &a, double &b)
{
	double c = a;
	a = b;
	b = c;
}
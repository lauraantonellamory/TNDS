/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <iostream>

#include "funzioneBase.h"
#include "randomGen.h"

using namespace std;

class IntegralMC
{
private:
	RandomGen *m_myrand;

public:
	IntegralMC(unsigned int seed)
	{
		m_myrand = new RandomGen(seed);
	};

	//metodo per hitormiss
	double IntegraleHoM(double xmin, double xmax, double fmax, funzioneBase *f, int punti)
	{
		double x, y;
		double step = 0;
		double a = min(xmin, xmax);
		double b = max(xmin, xmax);
		double sign = (a > b ? -1 : 1);

		for (size_t i = 0; i < punti; i++)
		{
			x = m_myrand->Unif(a, b);
			y = m_myrand->Unif(0, fmax);

			if (f->Eval(x) > y)
				step++;
		}

		return sign * (b - a) * fmax * step / punti;
	}

	//calcolo dell'integrale con il metodo della media
	double IntegraleAVE(double xmin, double xmax, FunzioneBase *f, int punti)
	{
		double a = min(xmin, xmax);
		double b = max(xmin, xmax);
		double sign = (a > b ? -1 : 1);
		double sum = 0.;

		for (size_t i = 0; i < punti; i++)
			sum += f->Eval(m_myrand->Unif(a, b));

		return sign * (b - a) * (sum / punti);
	}
};
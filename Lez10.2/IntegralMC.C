/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>
#include <algorithm>
#include <cfloat>

#include "IntegralMC.h"
#include "FunzioneBase.h"
#include "RandomGen.h"

double IntegralMC::IntegraleHoM(double xmin, double xmax, double fmax, FunzioneBase *f, int punti)
{
	double a = min(xmin, xmax);
	double b = max(xmin, xmax);
	double sign;

	if (a > b)
		sign = -1;
	else
		sign = 1;

	double Ni = 0;

	for (int i = 0; i < punti; i++)
	{
		double x = m_myrand->Unif(a, b);
		double y = m_myrand->Unif(0, fmax);
		if (f->Eval(x) > y)
			Ni++;
	}

	double integral = (b - a) * fmax * (Ni / punti);

	return sign * integral;
}

double IntegralMC::IntegraleAVE(double xmin, double xmax, FunzioneBase *f, int punti)
{
	double a = min(xmin, xmax);
	double b = max(xmin, xmax);
	double sign;
	if (a > b)
		sign = -1;
	else
		sign = 1;

	double sum = 0.;

	for (int i = 0; i < punti; i++)
	{
		sum += f->Eval(m_myrand->Unif(a, b));
	}

	double integral = (b - a) * (sum / punti);

	return sign * integral;
}
/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include "funzioneBase.h"

class integrale
{
protected:
	double a;
	double b;
	double h;
	double S;
	double I;
	int sign;
	const funzioneBase *f;

public:
	integrale(double a_, double b_, const funzioneBase *f_)
	{
		a = std::min(a_, b_);
		b = std::max(a_, b_);
		f = f_;

		if (a > b)
			sign = -1;
		else
			sign = 1;
	}

	double simpson(unsigned int steps)
	{
		S = 0.;
		h = (b - a) / steps;

		double x;

		for (unsigned int k = 0; k < steps; k++)
		{
			x = a + h * k;
			S += (f->eval(x) + 4. * f->eval(x + h / 2.) + f->eval(x + h)) / 6.;
		}

		I = sign * S * h;

		return I;
	}
};
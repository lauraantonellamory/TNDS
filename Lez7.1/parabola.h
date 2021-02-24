/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <cmath>

#include "funzioneBase.h"

class parabola : public funzioneBase
{
protected:
	double a;
	double b;
	double c;

public:
	parabola(double a, double b, double c)
		: a(a), b(b), c(c) {}

	//~parabola();

	double getA() const
	{
		return a;
	}
	void setA(double value_a)
	{
		a = value_a;
	}
	double getB() const
	{
		return b;
	}
	void setB(double value_b)
	{
		b = value_b;
	}
	double getC() const
	{
		return c;
	}
	void setC(double value_c)
	{
		c = value_c;
	}
	double eval(double x) const override
	{
		double y = a * pow(x, 2) + b * x + c;

		return y;
	}
};
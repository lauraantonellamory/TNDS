/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include "solutore.h"

class bisezione : public solutore
{
private:
	int sign(double x) const
	{
		return (x < 0 ? -1 : 1);
	}

public:
	double cercaZeri(double a, double b, const funzioneBase *f) const override
	{
		double c = 0;

		while (abs(b - a) > epsilon)
		{
			c = a + 0.5 * (b - a);

			if (f->eval(c) == 0)
				return c;

			if (sign(f->eval(a)) * sign(f->eval(c)) < 0)
			{
				//a = a; non ha senso
				b = c;
			}
			else if (sign(f->eval(c)) * sign(f->eval(b)) < 0)
			{
				a = c;
				//b = b; non ha senso
			}
		}

		return c;
	}
};
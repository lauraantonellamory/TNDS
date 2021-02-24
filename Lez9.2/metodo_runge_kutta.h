/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <cmath>

#include "vettoreLineare.h"
#include "equazioneDifferenzialeBase.h"

class metodo_runge_kutta : public equazioneDifferenzialeBase
{
public:
	virtual void passo(double t, vettoreLineare &b, double h, funzioneVettorialeBase *f) const override
	{
		//f->eval() : (0, 1)
		//f->eval() : (x, v)

		auto k1 = f->eval(t, b);

		auto k2 = f->eval(t + h * 0.5, b + k1 * h * 0.5);

		auto k3 = f->eval(t + h * 0.5, b + k2 * h * 0.5);

		auto k4 = f->eval(t + h, b + k3 * h);

		b[0] += (k1[0] + 2. * k2[0] + 2. * k3[0] + k4[0]) * h / 6.;
		b[1] += (k1[1] + 2. * k2[1] + 2. * k3[1] + k4[1]) * h / 6.;
	}
};
/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <cmath>
#include <iomanip>

#include "funzioneVettorialeBase.h"

class pendolo : public funzioneVettorialeBase
{
private:
	double l, A;

public:
	const double g = 9.8;

public:
	pendolo(double l, double A)
		: l(l), A(A) {}

	//virtual vettoreLineare eval(double x, const vettoreLineare &v) const = 0;
	vettoreLineare eval(double t, const vettoreLineare &b) const override
	{
		vettoreLineare o(2);

		auto theta = b.get(0);
		auto vel = b.get(1);

		auto acc = -g / l * sin(theta);

		o[0] = vel; // theta
		o[1] = acc; // velocità

		return o;
	}
};
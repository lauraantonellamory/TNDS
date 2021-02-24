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

class oscillatoreArmonicoSmorzato : public funzioneVettorialeBase
{
private:
	double _omega0, _omega, _alpha;

public:
	oscillatoreArmonicoSmorzato(double omega0, double omega, double alpha)
		: _omega0(omega0), _omega(omega), _alpha(alpha) {}

	double alpha() const { return _alpha; };
	double omega() const { return _omega; };
	double omega0() const { return _omega0; };

	//virtual vettoreLineare eval(double x, const vettoreLineare &v) const = 0;
	vettoreLineare eval(double t, const vettoreLineare &b) const override
	{
		auto theta = b.get(0);
		auto vel = b.get(1);

		vettoreLineare o(2);
		o[0] = vel;
		o[1] = -pow(_omega0, 2) * theta - _alpha * (vel + sin(_omega * t));

		return o;
	}
};
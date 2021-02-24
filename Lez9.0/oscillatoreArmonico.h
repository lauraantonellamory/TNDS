/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <cmath>

#include "funzioneVettorialeBase.h"

class oscillatoreArmonico : public funzioneVettorialeBase
{
private:
	double omega0;

public:
	oscillatoreArmonico(double omega0_)
		: omega0(omega0_) {}

	//virtual vettoreLineare eval(double x, const vettoreLineare &v) const = 0;
	vettoreLineare eval(double t, const vettoreLineare &b) const override
	{
		vettoreLineare o(2);

		// posizione nuova = velocità precedente
		o[0] = b.get(1);

		// velocità nuova = -omega^2 * posizione precedente
		o[1] = -pow(omega0, 2) * b.get(0);

		return o;
	}
};
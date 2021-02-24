/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include "posizione.h"

#include <cmath>

class campoVettoriale : public posizione
{
protected:
	double v_x;
	double v_y;
	double v_z;

public:
	campoVettoriale(const posizione &pos, double v_x, double v_y, double v_z)
		: posizione(pos),
		  v_x(v_x), v_y(v_y), v_z(v_z) {}

	campoVettoriale(const posizione &pos)
		: campoVettoriale(pos, 0, 0, 0) {}

	campoVettoriale(double x, double y, double z, double v_x, double v_y, double v_z)
		: campoVettoriale(posizione(x, y, z), v_x, v_y, v_z) {}

	campoVettoriale operator+(const campoVettoriale &b) const
	{
		return campoVettoriale(
			m_x, m_y, m_z,
			v_x + b.getVx(),
			v_y + b.getVy(),
			v_z + b.getVz());
	}

	campoVettoriale &operator+=(const campoVettoriale &b)
	{
		*this = *this + b;

		return *this;
	}

	//~campoVettoriale();

	double getVx() const
	{
		return v_x;
	}
	double getVy() const
	{
		return v_y;
	}
	double getVz() const
	{
		return v_z;
	}
	double modulo() const
	{
		return sqrt(pow(v_x, 2) + pow(v_y, 2) + pow(v_z, 2));
	}

	static campoVettoriale daDuePunti(
		double a_x, double a_y, double a_z,
		double b_x, double b_y, double b_z)
	{
		return campoVettoriale(
			a_x, a_y, a_z, // origine
			a_x - b_x,	   //v_x
			a_y - b_y,	   //v_y
			a_z - b_z);	   //v_z
	}
};
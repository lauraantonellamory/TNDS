/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <cmath>

class posizione
{
private:
	double m_x;
	double m_y;
	double m_z;

public:
	posizione()
	{
		m_x = 0;
		m_y = 0;
		m_z = 0;
	}

	posizione(double x, double y, double z)
	{
		m_x = x;
		m_y = y;
		m_z = z;
	}

	// non ho allocato nulla, non ho nulla da distruggere
	// il compilatore ne creerà uno vuoto lui
	//~posizione();

	double getX() const
	{
		return m_x;
	}
	double getY() const
	{
		return m_y;
	}
	double getZ() const
	{
		return m_z;
	}
	double getR() const
	{
		return sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
	}

	double getPhi() const
	{
		return atan2(m_y, m_x);
	}
	double getTheta() const
	{
		return acos(m_z / getR());
	}
	double getRho() const
	{
		return sqrt(pow(m_x, 2) + pow(m_y, 2));
	}

	double distanzaDalPunto(const posizione &b) const
	{
		return sqrt(
			pow(m_x - b.m_x, 2) + //misuro la distanza dal punto che ho nella classe posizione (m_x, m_y, m_z) e il nuovo punto b (b.m_x, b.m_y, b.m_z) che ho inserito in distanzaDalPunto
			pow(m_y - b.m_y, 2) +
			pow(m_z - b.m_z, 2));
	}
};
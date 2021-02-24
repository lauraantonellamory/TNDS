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
	double m_R;
	double m_Phi;
	double m_Theta;

public:
	posizione()
	{
		m_R = 0;
		m_Phi = 0;
		m_Theta = 0;
	}

	posizione(double m_x, double m_y, double m_z)
	{
		m_R = sqrt(pow(m_x, 2) + pow(m_y, 2) + pow(m_z, 2));
		m_Phi = atan2(m_y, m_x);
		m_Theta = acos(m_z / getR());
	}

	// non ho allocato nulla, non ho nulla da distruggere
	// il compilatore ne creerà uno vuoto lui
	//~posizione() {}

	double getX() const
	{
		return m_R * cos(m_Phi) * sin(m_Theta);
	}
	double getY() const
	{
		return m_R * sin(m_Phi) * sin(m_Theta);
	}
	double getZ() const
	{
		return m_R * cos(m_Theta);
	}
	double getR() const
	{
		return m_R;
	}
	double getPhi() const
	{
		return m_Phi;
	}
	double getTheta() const
	{
		return m_Theta;
	}
	double getRho() const
	{
		return sqrt(pow(getX(), 2) + pow(getY(), 2));
	}
	double distanzaDalPunto(const posizione &b) const
	{
		return sqrt(
			pow(getX() - b.getX(), 2) + //misuro la distanza dal punto che ho nella classe posizione (m_x, m_y, m_z) e il nuovo punto b (b.m_x, b.m_y, b.m_z) che ho inserito in distanzaDalPunto
			pow(getY() - b.getY(), 2) +
			pow(getZ() - b.getZ(), 2));
	}
};
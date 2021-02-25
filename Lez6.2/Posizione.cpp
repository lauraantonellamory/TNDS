/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <cmath>
#include <cstdlib>
#include <iostream>

#include "Posizione.h"

using namespace std;

Posizione::Posizione()
{
	m_x = 0.;
	m_y = 0.;
	m_z = 0.;
}

Posizione::Posizione(double x, double y, double z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

double Posizione::getX() const
{
	return m_x;
}
double Posizione::getY() const
{
	return m_y;
}
double Posizione::getZ() const
{
	return m_z;
}

double Posizione::getR() const
{
	return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

double Posizione::getPhi() const
{
	return atan2(m_y, m_x);
}
double Posizione::getTheta() const
{
	return acos(m_z / getR());
}

double Posizione::getRho() const
{
	return sqrt(m_x * m_x + m_y * m_y);
}

double Posizione::Distanza(const Posizione &b) const
{
	return sqrt(pow(getX() - b.getX(), 2) + pow(getY() - b.getY(), 2) + pow(getZ() - b.getZ(), 2));
}
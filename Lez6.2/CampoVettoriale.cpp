/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <cmath>
#include <iostream>
#include <cstdlib>

#include "Posizione.h"
#include "CampoVettoriale.h"

CampoVettoriale::CampoVettoriale() : Posizione()
{
	m_Fx = 0.;
	m_Fy = 0.;
	m_Fz = 0.;
}

CampoVettoriale::CampoVettoriale(const Posizione &pos, double Fx, double Fy, double Fz) : Posizione(pos)
{
	m_Fx = Fx;
	m_Fy = Fy;
	m_Fz = Fz;
}

CampoVettoriale::CampoVettoriale(double x, double y, double z, double Fx, double Fy, double Fz) : Posizione(x, y, z)
{
	m_Fx = Fx;
	m_Fy = Fy;
	m_Fz = Fz;
}

CampoVettoriale CampoVettoriale::operator+(const CampoVettoriale &v) const
{
	CampoVettoriale sum(v);

	sum.m_Fx += getFx();
	sum.m_Fy += getFy();
	sum.m_Fz += getFz();

	return sum;
}

CampoVettoriale &CampoVettoriale::operator+=(const CampoVettoriale &v)
{
	return (*this) = (*this) + v;
}

double CampoVettoriale::Modulo()
{
	return sqrt(getFx() * getFx() + getFy() * getFy() + getFz() * getFz());
}
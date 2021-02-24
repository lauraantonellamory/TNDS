/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include "posizione.h"
#include "particella.h"
#include "campoVettoriale.h"

class puntoMateriale : public posizione, public particella
{
public:
	const double G = 6.67E-11;
	const double epsilon_0 = 8.85E-12;
	const double pigreco = 3.14;

public:
	puntoMateriale(const posizione &pos, double massa, double carica)
		: posizione(pos),
		  particella(massa, carica) {}

	puntoMateriale(double x, double y, double z, double massa, double carica)
		: posizione(x, y, z),
		  particella(massa, carica) {}

	//~puntoMateriale();

	campoVettoriale campoElettrico(const posizione &pos) const
	{
		auto r = campoVettoriale::daDuePunti(
			getX(), getY(), getZ(),
			pos.getX(), pos.getY(), pos.getZ());

		auto a = q / (4 * pigreco * epsilon_0) * (pow(r.modulo(), 3));

		campoVettoriale e(
			getX(), getY(), getZ(), //pos
			a * r.getVx(),			//v_x
			a * r.getVy(),			//v_y
			a * r.getVz());			//v_z

		return e;
	}
	campoVettoriale campoGravitazionale(const posizione &pos) const
	{
		auto r = campoVettoriale::daDuePunti(
			getX(), getY(), getZ(),
			pos.getX(), pos.getY(), pos.getZ());

		auto a = -(G * m / pow(r.modulo(), 3));

		campoVettoriale g(
			getX(), getY(), getZ(), //pos
			a * r.getVx(),			//v_x
			a * r.getVy(),			//v_y
			a * r.getVz());			//v_z

		return g;
	}
};
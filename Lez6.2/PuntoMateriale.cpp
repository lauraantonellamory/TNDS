/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <cmath>
#include <cstdlib>
#include <iostream>

#include "PuntoMateriale.h"
#include "Particella.h"
#include "Posizione.h"
#include "CampoVettoriale.h"

using namespace std;

PuntoMateriale::PuntoMateriale(double massa, double raggio, double carica, const Posizione &pos)
	: Particella(massa, carica), Posizione(pos)
{
	m_raggio = raggio;
};

PuntoMateriale::PuntoMateriale(double massa, double raggio, double carica, double x, double y, double z)
	: Particella(massa, carica), Posizione(x, y, z)
{
	m_raggio = raggio;
};

CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione &pos) const
{
	double Ex, Ey, Ez;

	Ex = (GetCarica() * (pos.getX() - getX())) / ((4 * M_PI * 8.85E-12) * (pow(Distanza(pos), 3)));
	Ey = (GetCarica() * (pos.getY() - getY())) / ((4 * M_PI * 8.85E-12) * (pow(Distanza(pos), 3)));
	Ez = (GetCarica() * (pos.getZ() - getZ())) / ((4 * M_PI * 8.85E-12) * (pow(Distanza(pos), 3)));

	CampoVettoriale Elettro(pos, Ex, Ey, Ez);

	return Elettro;
}

CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione &pos) const
{
	double Gx, Gy, Gz;

	double G = 6.67E-11;

	Gx = (-G * GetMassa() * (pos.getX() - getX())) / (pow(Distanza(pos), 3)); //dividi per r^2, devi calcolarti la distanza del punto dalla carica
	Gy = (-G * GetMassa() * (pos.getY() - getY())) / (pow(Distanza(pos), 3)); //dividi per r^2, devi calcolarti la distanza del punto dalla carica
	Gz = (-G * GetMassa() * (pos.getZ() - getZ())) / (pow(Distanza(pos), 3)); //dividi per r^2, devi calcolarti la distanza del punto dalla carica

	CampoVettoriale Gravitaz(pos, Gx, Gy, Gz);

	return Gravitaz;
}
/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <cmath>
#include <iostream>
#include <iomanip>

#include "root/TApplication.h"
#include "root/TCanvas.h"
#include "root/TGraph.h"

#include "bisezione.h"
#include "funzioneBase.h"
#include "funzioniEs.h"
#include "funzioni.hpp"
#include "integrale.h"
#include "IntegralMC.h"

using namespace std;

void punto1(double &x_min, double &x_max, double precisione)
{
	auto f = new funzioniEs();
	auto bis = new bisezione();
	bis->setPrecisione(precisione);

	x_min = bis->cercaZeri(0, 1, f);
	x_max = bis->cercaZeri(5, 6, f);

	cout
		<< "Punto 1):" << endl
		<< "x min in [0, 1]: " << x_min << endl
		<< "x max in [5, 6]: " << x_max << endl;

	delete bis;
	delete f;
}

void punto2_3(double &x_min, double &x_max, double precisione)
{
	auto f = new funzioniEs();
	auto integrali = new integrale(x_min, x_max, precisione, f);

	auto i = integrali->trapezi(10);

	cout
		<< "Punto 2):" << endl
		<< "integrale tra [" << x_min << ", " << x_max << "]: "
		<< i << endl;

	cout
		<< "Punto 3):" << endl
		<< "Errore commesso con il metodo dei trapezoidi: "
		<< integrali->getErrore() << endl;

	delete integrali;
	delete f;
}

void punto4(double &x_min, double &x_max)
{
	cout
		<< "Punto 4):" << endl
		<< "Passi richiesti per avere errore di 0.002: "
		<< (x_max - x_min) / 10. << endl;
}

void punto5(double &x_min, double &x_max)
{
	const size_t MAX = 10000;
	const int nstp = 1000;

	auto f = new funzioniEs();
	auto util = new funzioni();
	auto mc = new IntegralMC(1998);
	auto AVE = new double[MAX];

	for (size_t i = 0; i < MAX; i++)
		AVE[i] = mc->IntegraleAVE(x_min, x_max, f, nstp);

	double AVEmedia = util->media(AVE, MAX);
	double varianzaAVE = util->varianza(AVE, MAX, AVEmedia);
	double stdAVE = pow(varianzaAVE, 0.5);

	cout
		<< "Punto 5):" << endl
		<< "L'integrale tramite AVERAGE: "
		<< AVEmedia
		<< " con un errore di: "
		<< stdAVE
		<< endl;

	double AVEk = sqrt(nstp) * stdAVE;

	double prec = 0.002;

	double NnecessariAVE = ((AVEk * AVEk) / (prec * prec)) + 1;

	cout
		<< "Metodo della Media necessari "
		<< NnecessariAVE
		<< " punti per avere la precisione di " << prec
		<< " sul risultato dell'integrale."
		<< endl;

	delete util;
	delete mc;
	delete f;
	delete[] AVE;
}

void punto7()
{
	const int steps = 1000;

	auto util = new funzioni();
	auto f = new funzioniEs();
	auto rg = new RandomGen(1998);

	double precisioni[5] = {0.1, 0.07, 0.05, 0.03, 0.01};

	cout
		<< "Punto 6):" << endl;

	TApplication app("Punto 6", 0, 0);
	auto graphPos = new TGraph();
	graphPos->SetTitle("Punto 6;precisione;std");

	for (size_t i = 0; i < 5; i++)
	{
		auto prec = precisioni[i];
		auto bis = new bisezione();
		bis->setPrecisione(prec);

		auto x_min = bis->cercaZeri(0, 1, f);
		auto x_max = bis->cercaZeri(5, 6, f);

		auto valori = new double[steps];

		for (size_t n = 0; n < steps; n++)
		{
			auto x_min_unif = rg->Unif(x_min - prec / 2., x_min + prec / 2.);
			auto x_max_unif = rg->Unif(x_max - prec / 2., x_max + prec / 2.);

			auto integrali = new integrale(x_min_unif, x_max_unif, prec, f);
			auto integ = integrali->trapezi(10);
			valori[n] = integ;

			delete integrali;
		}

		double VALmedia = util->media(valori, steps);
		double varianzaVAL = util->varianza(valori, steps, VALmedia);
		double stdVAL = pow(varianzaVAL, 0.5);

		cout
			<< " Prec: " << prec << endl
			<< " Std: " << stdVAL << endl;

		graphPos->SetPoint(i, prec, stdVAL);

		delete[] valori;
		delete bis;
	}

	delete util;
	delete rg;
	delete f;

	TCanvas canvas;
	graphPos->Draw();
	app.Run();
}

int main(int argc, char **argv)
{
	double x_min, x_max;

	punto1(x_min, x_max, 0.1);
	punto2_3(x_min, x_max, 0.1);
	punto4(x_min, x_max);
	//punto5(x_min, x_max);
	punto7();
	//punto7(x_min, x_max);

	return 0;
}
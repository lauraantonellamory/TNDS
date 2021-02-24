/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <cmath>

#include "root/TApplication.h"
#include "root/TCanvas.h"
#include "root/TH1F.h"
#include "root/TAxis.h"
#include "root/TGraph.h"

#include "randomGen.h"
#include "seno.h"
#include "funzioni.hpp"
#include "IntegralMC.h"

using namespace std;

const int MAX = 10000;

int main()
{
	TApplication app("app", 0, 0);

	double a = 0;
	double b = M_PI;

	int nstp = 100;

	TH1F h1("Media", "Media", 100, 0, 4);
	TH1F h2("HoM", "HoM", 100, 0, 4);

	auto seno = new seno();
	auto integrale = new IntegralMC(1);

	auto AVE = new double[MAX];
	auto HoM = new double[MAX];

	for (int i = 0; i < MAX; i++)
	{
		AVE[i] = integrale->IntegraleAVE(a, b, seno, nstp);
		HoM[i] = integrale->IntegraleHoM(a, b, 1., seno, nstp);

		h1.Fill(AVE[i]);
		h2.Fill(HoM[i]);
	}

	double AVEmedia = media(MAX, AVE);
	double HoMmedia = media(MAX, HoM);

	double varianzaAVE = varianza(MAX, AVE, AVEmedia);
	double varianzaHoM = varianza(MAX, HoM, HoMmedia);

	double stdAVE = pow(varianzaAVE, 0.5);
	double stdHoM = pow(varianzaHoM, 0.5);

	cout << "L'integrale calcolato col metodo AVERAGE è: " << AVEmedia << "con un errore di: " << stdAVE << endl;

	cout << "L'integrale calcolato col metodo HitOrMiss è: " << HoMmedia << "con un errore di: " << stdHoM << endl;

	cout << "Per avere una precisione prestabilita di 0.001 bisogna considerare che l'errore ha andamento di k/radq(n) dove n è il numero di punti. Per una precisione fissata basta che io trovi k per un qualunque n e inverta poi la funzione per isolare il 'n' che voglio." << endl;

	double AVEk = sqrt(nstp) * stdAVE;
	double HoMk = sqrt(nstp) * stdHoM;

	double prec = 0.001;

	double NnecessariAVE = ((AVEk * AVEk) / (prec * prec)) + 1;
	double NnecessariHoM = ((HoMk * HoMk) / (prec * prec)) + 1;

	cout << "Per il metodo della Media sono necessari " << NnecessariAVE << " punti per avere la precisione di 0.001 sul risultato dell'integrale." << endl;

	cout << "Per il metodo HitOrMiss sono necessari " << NnecessariHoM << " punti per avere la precisione di 0.001 sul risultato dell'integrale." << endl;

	auto canvas = new TCanvas();

	canvas->Divide(2, 1);
	canvas->cd(1);
	h1.SetTitle("Media");
	h1.SetMarkerStyle(7);
	h1.SetMarkerColor(30);
	h1.Draw();

	canvas->cd(2);
	h2.SetTitle("Hit or Miss");
	h2.SetMarkerStyle(7);
	h2.SetMarkerColor(9);
	h2.Draw();

	app.Run();

	delete integrale;
	delete seno;
	delete[] AVE;
	delete[] HoM;
}
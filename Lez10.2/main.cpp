/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <cmath>

#include "TApplication.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TAxis.h"
#include "TGraph.h"

#include "funzioni.h"
#include "float.h"
#include "RandomGen.h"
#include "Seno.h"
#include "FunzioneBase.h"
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

	FunzioneBase *seno = new Seno();

	IntegralMC *integrale = new IntegralMC(1);

	double *AVE = new double[MAX];
	double *HoM = new double[MAX];

	for (int i = 0; i < MAX; i++)
	{
		AVE[i] = integrale->IntegraleAVE(a, b, seno, nstp);

		h1.Fill(AVE[i]);

		HoM[i] = integrale->IntegraleHoM(a, b, 1., seno, nstp);

		h2.Fill(HoM[i]);
	}

	double AVEmedia = media(MAX, AVE);
	double HoMmedia = media(MAX, HoM);

	double varianzaAVE = varianza(MAX, AVE, AVEmedia);
	double varianzaHoM = varianza(MAX, HoM, HoMmedia);

	double stdAVE = pow(varianzaAVE, 0.5);
	double stdHoM = pow(varianzaHoM, 0.5);

	cout
		<< "L'integrale tramite AVERAGE: "
		<< AVEmedia
		<< "con un errore di: "
		<< stdAVE
		<< endl;

	cout
		<< "L'integrale tramite HitOrMiss: "
		<< HoMmedia
		<< "con un errore di: "
		<< stdHoM
		<< endl;

	double AVEk = sqrt(nstp) * stdAVE;
	double HoMk = sqrt(nstp) * stdHoM;

	double prec = 0.001;

	double NnecessariAVE = ((AVEk * AVEk) / (prec * prec)) + 1;
	double NnecessariHoM = ((HoMk * HoMk) / (prec * prec)) + 1;

	cout
		<< "Metodo della Media necessari "
		<< NnecessariAVE
		<< " punti per avere la precisione di 0.001 sul risultato dell'integrale."
		<< endl;

	cout
		<< "HitOrMiss necessari "
		<< NnecessariHoM
		<< " punti per avere la precisione di 0.001 sul risultato dell'integrale."
		<< endl;

	TCanvas *c = new TCanvas("c", "c");

	c->Divide(2, 1);
	c->cd(1);
	h1.SetTitle("Media");
	h1.SetMarkerStyle(7);
	h1.SetMarkerColor(30);
	h1.Draw();

	c->cd(2);
	h2.SetTitle("Hit or Miss");
	h2.SetMarkerStyle(7);
	h2.SetMarkerColor(9);
	h2.Draw();

	app.Run();

	return 0;
}
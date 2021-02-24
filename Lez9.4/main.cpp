/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>

#include "root/TApplication.h"
#include "root/TCanvas.h"
#include "root/TGraph.h"

#include "vettoreLineare.h"
#include "oscillatoreArmonicoSmorzato.h"
#include "metodo_runge_kutta.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		double A;
		double v;
		double h = atof(argv[1]);
		double omega = atof(argv[2]);
		double omega0 = 10;
		double alpha = 1. / 30.;
		double t = 0;
		double tmax = 30;
		size_t steps = tmax / h + 0.5;

		metodo_runge_kutta runge_kutta;
		auto oscillatore_armonico_smorzato = new oscillatoreArmonicoSmorzato(omega0, omega, alpha);

		TApplication app("Metodo di Runge-Kutta", 0, 0);

		auto graphLor = new TGraph();
		//t;x;y
		graphLor->SetTitle("Metodo di Runge-Kutta;pulsazione [rad/s];ampiezza [u.a.]");

		auto graphPos = new TGraph();
		graphPos->SetTitle("Metodo di Runge-Kutta;tempo t[s];posizione x[u.a.]");

		vettoreLineare o(2);
		o[0] = 0; // theta
		o[1] = 0; // velocità

		for (size_t step = 0; step < steps; step++)
		{
			graphPos->SetPoint(step, t, o[0]);

			runge_kutta.passo(t, o, h, oscillatore_armonico_smorzato);
			t += h;
		}

		tmax = 10. / oscillatore_armonico_smorzato->alpha();
		steps = tmax / h + 0.5;

		delete oscillatore_armonico_smorzato;

		for (size_t i = 0; i < 40; i++)
		{
			A = 0;
			v = 0;

			o[0] = 0;
			o[1] = 0;

			t = 0;
			oscillatore_armonico_smorzato = new oscillatoreArmonicoSmorzato(omega0, 9. + i / 20., alpha);

			for (size_t step = 0; step < steps; step++)
			{
				runge_kutta.passo(t, o, h, oscillatore_armonico_smorzato);
				t += h;
			}

			do
			{
				v = o[1];
				runge_kutta.passo(t, o, h, oscillatore_armonico_smorzato);
				A = o[0];

				t += h;
			} while (v * o[1] > 0);

			graphLor->SetPoint(i, oscillatore_armonico_smorzato->omega(), abs(A));

			delete oscillatore_armonico_smorzato;
		}

		auto canvas = new TCanvas();
		canvas->Divide(2, 1); // 2 col 1 riga

		canvas->cd(1);
		graphPos->Draw("APC");

		canvas->cd(2);
		graphLor->Draw("A*CP");

		app.Run();
		canvas->Close();
	}
	else
	{
		cout << " Uso: " << argv[0] << " <h> <omega>" << endl;
	}

	return 0;
}
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
#include "pendolo.h"
#include "metodo_runge_kutta.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		double v_attuale = 0;
		double v_precedente = 0;

		double h = atof(argv[1]);
		double l = atof(argv[2]);
		double A = 3.14;
		double t = 0;

		metodo_runge_kutta runge_kutta;
		auto pendolo_ = new pendolo(l, A);

		TApplication app("Metodo di Runge-Kutta", 0, 0);

		auto graphAP = new TGraph();
		graphAP->SetTitle("Metodo di Runge-Kutta;ampiezza A[m];periodo t[s]");

		auto graphPos = new TGraph();
		graphPos->SetTitle("Metodo di Runge-Kutta;posizione x[m];periodo t[s]");

		vettoreLineare o(2);
		o[0] = -A; // theta
		o[1] = 0;  // velocità

		while (o[1] >= 0)
		{
			v_precedente = o[1];

			// o passato per riferimento in memoria
			runge_kutta.passo(t, o, h, pendolo_);

			t += h;
		}

		t -= h;
		v_attuale = o[1];

		auto T = 2. * (t - v_precedente * h / (v_attuale - v_precedente));
		size_t steps = ((5 * T) / h) + 0.5;

		cout << "# T: " << T << endl;
		cout << "# step: " << steps << endl;

		o[0] = -A; // theta
		o[1] = 0;  // velocità
		t = 0;

		for (size_t step = 0; step < steps; step++)
		{
			graphPos->SetPoint(step, t, o[0]);

			// o passato per riferimento in memoria
			runge_kutta.passo(t, o, h, pendolo_);
			t += h;
		}

		cout << "Calcolo ampiezze..." << endl;
		for (size_t i = 0; i < 30; i++)
		{
			A = 0.1 * (i + 1);
			t = 0;

			o[0] = -A; // theta
			o[1] = 0;  // velocità

			while (o[1] >= 0)
			{
				v_precedente = o[1];

				// o passato per riferimento in memoria
				runge_kutta.passo(t, o, h, pendolo_);

				t += h;
			}

			t -= h;
			v_attuale = o[1];
			T = 2. * (t - v_precedente * h / (v_attuale - v_precedente));

			graphAP->SetPoint(i, A, T);
		}

		auto canvas1 = new TCanvas();
		graphAP->Draw("ALP");

		auto canvas2 = new TCanvas();
		graphPos->Draw("ALP");

		app.Run();

		canvas1->Close();
		canvas2->Close();
	}
	else
	{
		cout << " Uso: " << argv[0] << " <h> <l>" << endl;
	}

	return 0;
}
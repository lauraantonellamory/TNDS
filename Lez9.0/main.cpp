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
#include "oscillatoreArmonico.h"
#include "metodo_eulero.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		double t = 0;
		double tmax = 70;
		double h = atof(argv[1]);
		size_t steps = tmax / h + 0.5;

		metodo_eulero eulero;
		auto oscillatore_armonico = new oscillatoreArmonico(1);

		vettoreLineare x(2);
		x[0] = 0;
		x[1] = 1;

		TApplication app("Metodo di Eulero", 0, 0);
		auto graph = new TGraph();

		for (size_t step = 0; step < steps; step++)
		{
			graph->SetPoint(step, t, x[0]);

			cout
				<< t << " "
				<< x[0] << ", " << x[1]
				<< endl;

			//eulero funziona per riferimento di x, x viene aggiornata ad ogni chiamata di passo direttamente in memoria
			eulero.passo(t, x, h, oscillatore_armonico);
			t += h;
		}

		auto canvas = new TCanvas();
		graph->Draw("AL");
		app.Run();
	}
	else
	{
		cout << " Uso: " << argv[0] << " <steps>" << endl;
	}

	return 0;
}
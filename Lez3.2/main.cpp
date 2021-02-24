/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"

using namespace std;

void plotting(vector<double> &datiOscilloscopioInMemoriaRam)
{
	TApplication app("app", 0, 0);
	TH1F histo("histo", "histo", 100, -10, 100);
	histo.StatOverflows(kTRUE);

	for (int i = 0; i < datiOscilloscopioInMemoriaRam.size(); i++)
		histo.Fill(datiOscilloscopioInMemoriaRam[i]);

	cout << "Media dei valori caricati: " << histo.GetMean() << endl;

	TCanvas mycanvas("Histo", "Histo");
	histo.Draw();
	histo.GetXaxis()->SetTitle("measurement");

	app.Run();
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "uso: " << argv[0] << " <percorso del file>" << endl;
		return -1;
	}

	auto percorsoDelFileDaLeggere = argv[1];
	ifstream datiOscilloscopioSulDisco(percorsoDelFileDaLeggere);

	double rigo;
	vector<double> datiOscilloscopioInMemoriaRam;

	while (datiOscilloscopioSulDisco.eof() == false)
	{
		datiOscilloscopioSulDisco >> rigo;

		datiOscilloscopioInMemoriaRam.push_back(rigo);
	}

	plotting(datiOscilloscopioInMemoriaRam);

	return 0;
}
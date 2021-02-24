/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <cmath>
#include <iostream>
#include <functional>

#include "root/TH1F.h"
#include "root/TApplication.h"
#include "root/TCanvas.h"
#include "root/TAxis.h"

#include "randomGen.h"

using namespace std;

const size_t nmax = 10000;
size_t currCanvas = 0;

TCanvas *canvas;

//https://stackoverflow.com/questions/6339970/c-using-function-as-parameter
void fai(TH1F *grafico, function<double()> f)
{
	currCanvas++;

	for (size_t k = 0; k < nmax; k++)
		grafico->Fill(f());

	canvas->cd(currCanvas);
	grafico->GetXaxis()->SetTitle("x [AU]");
	grafico->GetYaxis()->SetTitle("N");
	grafico->Draw();
}

TH1F *newTH1F(const char *titolo)
{
	return new TH1F(titolo, titolo, 100, 4, 11);
}

int main()
{
	TApplication app("Numeri casuali", 0, 0);

	canvas = new TCanvas();
	canvas->Divide(4, 1);

	auto gU = newTH1F("Uniforme");
	auto gE = newTH1F("Esponenziale");
	auto gBM = newTH1F("Gaussiana Box-Muller");
	auto gAR = newTH1F("Gaussiana Accept-Reject");

	randomGen random_gen(1998);

	fai(gU, [&]() {
		return random_gen.unif(5, 10);
	});

	fai(gE, [&]() {
		return random_gen.exp(0);
	});

	fai(gBM, [&]() {
		return random_gen.gaussBM(1, 1);
	});

	fai(gAR, [&]() {
		return random_gen.gaussAR(1, 1);
	});

	app.Run();
	canvas->Close();
}
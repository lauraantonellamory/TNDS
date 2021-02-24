/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include "TH1F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TAxis.h"

#include <iostream>

#include "randomGen.h"

using namespace std;

int main () {

TApplication app("app", 0, 0);

randomGen myGen(1);

int nmax = 10000;

TH1F unif("Uniforme", "Uniforme", 100, 4, 11);

for (int k = 0; k < nmax; k++)
unif.Fill(myGen.unif(5, 10));

TCanvas can2("Uniforme", "Uniforme");
can2.cd;
unif.GetXaxis()->SetTitle("x [AU]");
unif.GetYaxis()->SetTitle("N");
unif.Draw();

app.Run();

}
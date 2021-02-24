/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <cmath>
#include <iostream>

#include "bisezione.h"
#include "funzioneBase.h"

using namespace std;

class funzione_es71 : public funzioneBase
{
public:
	double eval(double x) const
	{
		return 3. * pow(x, 2) + 5. * x - 2.;
	}
};

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		double a = atof(argv[1]);
		double b = atof(argv[2]);
		double epsilon = atof(argv[3]);

		auto f = new funzione_es71();
		auto bis = new bisezione();
		bis->setPrecisione(epsilon);

		auto soluzione = bis->cercaZeri(a, b, f);

		cout
			<< "Soluzione di 3x² + 5x - 2: "
			<< soluzione
			<< endl;

		delete bis;
		delete f;
	}
	else
	{
		cout << " Uso: " << argv[0] << " <a> <b> <epsilon> " << endl;
	}

	return 0;
}
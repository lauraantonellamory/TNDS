/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <cmath>
#include <iostream>
#include <iomanip>

#include "bisezione.h"
#include "funzioneBase.h"

using namespace std;

class funzione_es73 : public funzioneBase
{
public:
	double eval(double x) const
	{
		return x * cos(x) - sin(x);
	}
};

int main(int argc, char **argv)
{
	const double epsilon = 10E-6;

	auto f = new funzione_es73();
	auto bis = new bisezione();
	bis->setPrecisione(epsilon);

	for (size_t n = 1; n < 21; n++)
	{
		auto a = n * M_PI;
		auto b = n * M_PI + M_PI / 2;

		auto soluzione = bis->cercaZeri(a, b, f);

		cout
			<< "Soluzione di x = tan(x) in ("
			<< n << "pi, " << n << "pi + pi/2): "
			<< soluzione
			<< endl;
	}

	delete bis;
	delete f;

	return 0;
}
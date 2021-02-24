/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>
#include <cstdlib>

#include "campoVettoriale.h"
#include "puntoMateriale.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		double x = atof(argv[1]);
		double y = atof(argv[2]);
		double z = atof(argv[3]);
		posizione r(x, y, z);

		const double delta = 10E-10;
		puntoMateriale elettrone(0, 0, -delta / 2, 9.11E-31, -1.60E-19);
		puntoMateriale protone(0, 0, delta / 2, 1.67E-27, 1.60E-19);

		campoVettoriale E = elettrone.campoElettrico(r) + protone.campoElettrico(r);

		cout
			<< "E = " << E.getVx()
			<< " , " << E.getVy()
			<< " , " << E.getVz()
			<< " è il campo elettrico del dipolo elettrone-protone "
			<< endl;
	}
	else
	{
		cout << " Uso: " << argv[0] << " <x> <y> <z> " << endl;
	}

	return 0;
}
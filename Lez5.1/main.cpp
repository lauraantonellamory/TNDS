/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>
#include <cstdlib>

#include "posizione.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		double x = atof(argv[1]);
		double y = atof(argv[2]);
		double z = atof(argv[3]);

		posizione p1(x, y, z);

		cout << "Le coordinate cartesiane di p1 sono:" << p1.getX() << "," << p1.getY() << "," << p1.getZ() << ";" << endl;
		cout << "Le coordinate sferiche di p1 sono:" << p1.getR() << "," << p1.getPhi() << "," << p1.getTheta() << ";" << endl;
		cout << "Le coordinate cilindriche di p1 sono:" << p1.getRho() << "," << p1.getPhi() << "," << p1.getZ() << ";" << endl;
	}
	else
	{
		cout << "Uso: " << argv[0] << " <x> <y> <z>" << endl;
	}
	
	return 0;
}
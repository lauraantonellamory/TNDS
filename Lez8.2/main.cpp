/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>
#include <cmath>
#include <iomanip>

#include "funzioneBase.h"
#include "integrale.h"
#include "seno.h"

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		unsigned int steps = atoi(argv[1]);
		double epsilon = atoi(argv[2]);

		double a = 0;
		double b = M_PI;

		auto mysin = new seno();
		auto integrator = new integrale(a, b, epsilon, mysin);

		cout
			<< "Integrazione tramite formula dei trapezi tra 0 e pi di sen(x): "
			<< integrator->trapezi(steps)
			<< endl
			<< " errore accumulato: "
			<< integrator->getErrore()
			<< endl;

		delete integrator;
		delete mysin;
	}
	else
	{
		cout << " Uso: " << argv[0] << " <steps> <e>" << endl;
	}

	return 0;
}
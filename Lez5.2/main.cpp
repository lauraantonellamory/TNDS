/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>
#include <cstdlib>
#include <memory>

#include "particella.h"
#include "elettrone.h"
#include "corpoCeleste.h"

using namespace std;

int main()
{
	/*
	smart pointers C++14
	Gli smart pointers sono oggetti del linguaggio C++ che facilitano l'utilizzo dei puntatori.
	Lo scopo principale di uno smart pointer è quello di provvedere una cancellazione automatica della memoria.
	tratto da: https://en.wikipedia.org/wiki/Smart_pointer
	*/

	{
		auto p = make_unique<particella>(1, 1.6E-19);
		auto e = make_unique<elettrone>();
		auto c = make_shared<corpoCeleste>("Terra", 5.9742E24, 6.372797E6);
		// c è shared perché c2 è un shared smart pointers, che punta a c (tramite assegnazione "operator="")
		// p, e sono unique perché non vengono assegnati ad altre variabili

		p->stampa();
		e->stampa();
		c->stampa();

		auto p2 = make_unique<particella>(*p);
		p2->stampa();

		auto e2 = make_unique<elettrone>(*e);
		e2->stampa();

		auto p3 = make_unique<particella>(*e);
		p3->stampa();

		auto c2 = c;
		c2->stampa();

	} // p, p2, p3, e, e2, c, c2 si autodistruggono qui

	return 0;
}
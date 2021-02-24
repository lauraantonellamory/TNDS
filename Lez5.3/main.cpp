/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>

#include "corpoCeleste.h"
#include "posizione.h"

using namespace std;

int main()
{
	corpoCeleste sole("Sole", 1.9891E+30, 6.963E+8, posizione(1.478E+11, 0, 0));
	corpoCeleste terra("Terra", 5.9726E+24, 6.371E+6, posizione(0, 0, 0));
	corpoCeleste luna("Luna", 7.3420E+22, 1.7374E+6, posizione(3.993E+8, 0, 0));

	// La formula del potenziale è corretta perché utilizziamo la luna come particella di massa unitaria
	auto potenzialeSoleLuna = luna.getPotenzialeG(sole.getPosizione());
	auto potenzialeTerraLuna = luna.getPotenzialeG(terra.getPosizione());

	if (potenzialeSoleLuna > potenzialeTerraLuna)
	{
		cout
			<< "Il potenziale gravitazionale che esercita il Sole sulla Luna di "
			<< potenzialeSoleLuna << " J/Kg "
			<< " è più grande di quello che esercita la Terra sulla Luna di "
			<< potenzialeTerraLuna << " J/Kg "
			<< endl;
	}
	else
	{
		cout
			<< "Il potenziale gravitazionale che esercita la Terra sulla Luna di "
			<< potenzialeTerraLuna << " J/Kg "
			<< " è più grande di quello che esercita il Sole sulla Luna di "
			<< potenzialeSoleLuna << " J/Kg "
			<< endl;
	}

	return 0;
}
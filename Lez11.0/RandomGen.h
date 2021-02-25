/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

class RandomGen
{
public:
	RandomGen(unsigned int); //costruttore

	void setA(unsigned int a_) { a = a_; }

	void setC(unsigned int c_) { c = c_; }

	void setM(unsigned int m_) { m = m_; }

	double Rand();
	double Unif(double xmin, double xmax);			  //distribuzione uniforme
	double Exp(double mean);						  //distribuzione esponenziale
	double GaussBoxMuller(double mean, double sigma); //gauss con BOXMULLER
	double GaussAR(double mean, double sigma);		  //gauss ACCEPTREJECT

private:
	unsigned int a;
	unsigned int c;
	unsigned int m;
	unsigned int seed;
};
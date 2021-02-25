/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <cmath>
#include <iostream>
#include <float.h>

#include "RandomGen.h"

using namespace std;

RandomGen::RandomGen(unsigned int seed_)
{
	// tratto da: Numerical Recipes
	a = 1664525;
	c = 1013904223;
	m = pow(2, 31);
	seed = seed_;
}

double RandomGen::Rand()
{
	double m_ = m;

	seed = (a * seed + c) % m;

	return seed / m_;
}

double RandomGen::Unif(double xmin, double xmax)
{
	double x = rand();

	return (xmin + (xmax - xmin) * x);
}

double RandomGen::Exp(double mean)
{
	double y = rand();
	double x = -(1 / mean) * log(1 - y);

	return x;
}

double RandomGen::GaussBoxMuller(double mean, double sigma)
{
	double s = rand();
	double t = rand();
	double x = mean + sigma * sqrt(-2 * log(s)) * cos(2 * M_PI * t);

	return x;
}

double RandomGen::GaussAR(double mean, double sigma)
{
	auto ok = false;
	double x, y, yMax, fx;

	yMax = 1. / sqrt(2. * M_PI * sigma * sigma);

	while (!ok)
	{
		x = Unif(mean - 5. * sigma, mean + 5. * sigma);
		y = rand() * yMax;

		fx = GaussBoxMuller(mean, sigma);

		if (fx >= y)
			ok = true;
	}

	return x;
}

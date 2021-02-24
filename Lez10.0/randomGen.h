/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#pragma once

#include <cmath>
#include <cstddef>
#include <iomanip>

class randomGen
{
private:
  unsigned int a;
  unsigned int c;
  unsigned int m;  
  unsigned int seed;  
  double *X; // array

public:
  /* 
    tratto da https://it.wikipedia.org/wiki/Generatore_lineare_congruenziale
    Il generatore lineare congruenziale è un algoritmo per la generazione di numeri pseudo-casuali.
    Il generatore è definito ricorsivamente: X[i + 1] = (a * X[i] + c) % m
    
    X: la successione
    m: modulo; m > 0
    a: moltiplicatore; 0 < a < m
    c: incremento; 0 ≤ c < m
    X[0] = seed: seme; 0 ≤ X[0] < m
  */
  randomGen(unsigned int seed)
  {
    // tratto da: Numerical Recipes
    a = 1664525;
    c = 1013904223;
    m = pow(2, 31);
    seed = seed_;
    
    auto size = 10000;

    X = new double[size];
    X[0] = seed;    
    
    for (size_t i = 1; i < size; i++)
      X[i] = fmod(a * X[i - 1] + c, m);
  }

  ~randomGen()
	{
		delete[] X;
	}

  void setA(unsigned int a_) { a = a_; }

  void setC(unsigned int c_) {c = c_; }

  void setM(unsigned int m_) { m = m_; }  

  double rand()
  {
    X[0]
  }

  // distribuzione uniforme
  double unif(double xmin, double xmax)
  {    
    return 1 / (xmax - xmin);
  }
 
  // distribuzione esponenziale
  double exp(double mean)
  {
    double y = unif(0, 1);
    double x = - mean * log(1 - y);
    return x;
  }

  // distribuzione di Gauss Box-Muller
  double gaussBM(double mean, double sigma)
  {
    double s = rand(unif(0,1));
    double t = rand(unif(0,1));
    double x = mean + sigma * sqrt(-2 * log(s)) * cos(2 * M_PI * t);
    return x; 
  }

  // distribuzione di Gauss Accept-reject
  double gaussAR(double mean, double sigma)
  {
    double s = rand(unif(0,1));
    double t = rand(unif(0,1));
    double x = a
  }
};
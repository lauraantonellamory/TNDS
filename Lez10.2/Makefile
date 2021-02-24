# MIT License
#
# Copyright (c) 2019 Laura Antonella Mory
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
INCS = $(shell root-config --cflags)
LIBS = $(shell root-config --libs)

main.x: main.o IntegralMC.o funzioni.o funzioni.hpp
	g++  main.o funzioni.o IntegralMC.o -o main.x ${INCS} ${LIBS}
main.o: main.cpp IntegralMC.h funzioni.hpp
	g++ -c main.cpp -o main.o ${INCS}
IntegralMC.o: IntegralMC.C IntegralMC.h
	g++ -c IntegralMC.C
funzioni.o:funzioni.cpp funzioni.hpp
	g++ -c funzioni.cpp
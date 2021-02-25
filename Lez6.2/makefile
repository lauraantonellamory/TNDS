# MIT License
#
# Copyright (c) 2019 Laura Antonella Mory
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
LIBS = `root-config --libs`
INCS = `root-config --cflags`

p62.exe: main.o Particella.o Posizione.o PuntoMateriale.o CampoVettoriale.o
	g++ main.o Particella.o Posizione.o PuntoMateriale.o CampoVettoriale.o -o p62.exe ${INCS} ${LIBS}

main.o: main.cpp PuntoMateriale.h Particella.h Posizione.h CampoVettoriale.h
	g++ -c main.cpp ${INCS}

PuntoMateriale.o:PuntoMateriale.cpp PuntoMateriale.h Particella.h Posizione.h CampoVettoriale.h
	g++ -c PuntoMateriale.cpp

CampoVettoriale.o: CampoVettoriale.cpp CampoVettoriale.h Posizione.h
	g++ -c CampoVettoriale.cpp

Particella.o: Particella.cpp Particella.h Posizione.h
	g++ -c Particella.cpp

Posizione.o: Posizione.cpp Posizione.h
	g++ -c Posizione.cpp
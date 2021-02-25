# MIT License
#
# Copyright (c) 2019 Laura Antonella Mory
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

LIBS = `root-config --libs`
INCS = `root-config --cflags`

p102.exe: main.o RandomGen.o IntegralMC.o funzioni.o RandomGen.h FunzioneBase.h Seno.h funzioni.h 
	g++  main.o RandomGen.o funzioni.o IntegralMC.o -o p102.exe ${INCS} ${LIBS}
main.o: main.cpp IntegralMC.h RandomGen.h FunzioneBase.h  Seno.h funzioni.h
	g++ -c main.cpp -o main.o  ${INCS}
IntegralMC.o: IntegralMC.C IntegralMC.h FunzioneBase.h RandomGen.h
	g++ -c IntegralMC.C
RandomGen.o: RandomGen.cpp RandomGen.h
	g++ -c RandomGen.cpp
funzioni.o:funzioni.cpp funzioni.h
	g++ -c funzioni.cpp

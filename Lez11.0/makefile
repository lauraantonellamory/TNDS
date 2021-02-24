LIBS = `root-config --libs`
INCS = `root-config --cflags`


esercizio11.0.x: esercizio11.0.o RandomGen.o RandomGen.h EsperimentoPrisma.o EsperimentoPrisma.h 
	g++  esercizio11.0.o RandomGen.o EsperimentoPrisma.o -o esercizio11.0.x ${INCS} ${LIBS}
esercizio11.0.o: esercizio11.0.cpp EsperimentoPrisma.h RandomGen.h
	g++ -c esercizio11.0.cpp -o esercizio11.0.o  ${INCS}
EsperimentoPrisma.o: EsperimentoPrisma.cpp EsperimentoPrisma.h
	g++ -c EsperimentoPrisma.cpp
RandomGen.o: RandomGen.cpp RandomGen.h
	g++ -c RandomGen.cpp

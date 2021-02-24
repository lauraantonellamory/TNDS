LIBS = `root-config --libs`
INCS = `root-config --cflags`




esercizio6.2.x: esercizio6.2.o Particella.o Posizione.o PuntoMateriale.o CampoVettoriale.o
	g++ esercizio6.2.o Particella.o Posizione.o PuntoMateriale.o CampoVettoriale.o -o esercizio6.2.x ${INCS} ${LIBS}

esercizio6.2.o: esercizio6.2.cpp PuntoMateriale.h Particella.h Posizione.h CampoVettoriale.h
	g++ -c esercizio6.2.cpp ${INCS}

PuntoMateriale.o:PuntoMateriale.cpp PuntoMateriale.h Particella.h Posizione.h CampoVettoriale.h
	g++ -c PuntoMateriale.cpp

CampoVettoriale.o: CampoVettoriale.cpp CampoVettoriale.h Posizione.h
	g++ -c CampoVettoriale.cpp

Particella.o: Particella.cpp Particella.h Posizione.h
	g++ -c Particella.cpp

Posizione.o: Posizione.cpp Posizione.h
	g++ -c Posizione.cpp

# -c compila e non linka, -o linka i file oggetto

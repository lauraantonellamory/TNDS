#ifndef __Particella_h__
#define __Particella_h__

#include "Posizione.h"
#include <iostream>
using namespace std;

class Particella{

public:

//costruttori
Particella();
Particella(double massa, double carica);
//distruttore
~Particella();

//metodi
double GetMassa() const {return m_massa;}
double GetCarica() const{return m_carica;}
void Print() const;

protected:

double m_massa;
double m_carica;

};


class Elettrone : public Particella {//eredita con il massimo livello di visibilità ciò che c'è in particella. Se fosse stato protected, anche il public di particella sarebbe diventato protected

public:
//costruttore
Elettrone();
//distruttore
~Elettrone();
//
void Print() const;
};

class CorpoCeleste : public Particella {

public:

	//costruttori
	CorpoCeleste();
	CorpoCeleste(std::string nome, double massa, double raggio);

	//distruttore
	~CorpoCeleste();

	//nuovi metodi
	void SetNome(std::string nome) {m_nome=nome;}
	void SetMassa(double massa) {m_massa=massa;}
	void SetRaggio(double raggio) {m_raggio=raggio;}
	std::string GetNome() const {return m_nome;}//tutto quello che viene elaborato dalla funzione non deve poter modificare le cose esterne alla funzione che vengono utilizzate (giusto?)
	double GetRaggio() const {return m_raggio;}

	void Print() const;

protected:

	//nuovi data membri
	std::string m_nome;
	double m_raggio;

};


#endif

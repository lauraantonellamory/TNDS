#include "Particella.h"

#include <cstdlib>
#include <iostream>
using namespace std;


Particella::Particella(){
	m_massa=0.;
	m_carica=0.;
}

Particella::Particella(double massa, double carica){
	m_massa=massa;
	m_carica=carica;
}

Particella::~Particella() {  }

void Particella::Print() const{
	cout << "Particella: m= " << m_massa
	<<", q= " << m_carica << endl;

}


Elettrone::Elettrone() : Particella (9.1093826E-31, -1.60217653E-19){
//voglio che l'elettrone abbia esattamente i suoi dati prestabiliti
};


Elettrone::~Elettrone() {}

void Elettrone::Print() const{
	cout << "Elettrone: m= " << m_massa
	<< ", q= " << m_carica << endl   ;}


CorpoCeleste::CorpoCeleste(){ //se tu non specifichi che richiami il costruttore di Particella, lui si va a prendere il costruttore di default di Particella
m_nome="test";
m_raggio=0.;
};

CorpoCeleste::CorpoCeleste(string nome, double massa, double raggio): Particella(massa,0){//specializza il costruttore di Particella a inserire anche i nuovi datamembri

	m_nome=nome;
	m_raggio=raggio;
}

CorpoCeleste::~CorpoCeleste(){ }

void CorpoCeleste::Print() const{
	cout << m_nome << ": m= " << m_massa
	<< ", R=" << m_raggio
	<< endl;
}





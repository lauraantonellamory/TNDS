#include "Posizione.h"
#include "CampoVettoriale.h"
#include <cmath>
#include <iostream>
#include <cstdlib>

CampoVettoriale:: CampoVettoriale(): Posizione(){
	
	m_Fx=0.;
	m_Fy=0.;
	m_Fz=0.;

	}

CampoVettoriale:: CampoVettoriale(const Posizione& pos, double Fx, double Fy, double Fz): Posizione(pos) {//operazione di assegnazione che chiama il costruttore di posizione a partire da una posizione già costruita, credo sia assegnazione di default che lega i due link

	m_Fx=Fx;
	m_Fy=Fy;
	m_Fz=Fz;

}


CampoVettoriale:: CampoVettoriale(double x,double y, double z, double Fx,double Fy,double Fz): Posizione(x,y,z){
 //Può essere utile staccare le tre coordinate se ci si vuole spostare lungo una sola delle coordinate
	m_Fx=Fx;
	m_Fy=Fy;
	m_Fz=Fz;

}


CampoVettoriale CampoVettoriale::operator+(const CampoVettoriale & v) const{
//operator è applicato a un oggetto chiamante implicito e prende in ingresso un oggetto chiamato v. Entrambi gli oggetti sono protetti perché vogliamo che nel main non vengano modificati. 

//essendo v un oggetto che non contiene puntatori, la costruzione di default di sum(v) è fatta con un copyconstructor by value che non ripunta allo stesso oggetto di partenza, sum sarà un nuovo oggetto che è copia del vecchio oggetto ma su cui potremo lavorare perché il const di v non lo riguarda più

	CampoVettoriale sum(v);
	sum.m_Fx += getFx();
	sum.m_Fy += getFy();
	sum.m_Fz += getFz();

	return sum;//sum è restituito by value
}

CampoVettoriale & CampoVettoriale::operator+=(const CampoVettoriale & v){//non metto const perché non voglio proteggere il chiamante

	return (*this)=(*this)+v;//faccio puntare this alla casella in cui viene copiato sum by value, 
//in questo caso la modifica viene fatta sull'oggetto chiamante
//il metodo restituisce un puntatore all'oggetto chiamante a cui assegno 
}

double CampoVettoriale::Modulo(){

	double c;
	c=sqrt(getFx()*getFx()+getFy()*getFy()+getFz()*getFz());
	return c;

}












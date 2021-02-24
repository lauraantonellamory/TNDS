#include "Posizione.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


//costruttore di default

Posizione::Posizione(){
	m_x=0.;
	m_y=0.;
	m_z=0.;
}

//costruttore a partire da una terna cartesiana

Posizione::Posizione(double x,double y,double z){
	m_x=x;
	m_y=y;
	m_z=z;
}

//distruttore(può essere vuoto)
Posizione::~Posizione(){
}

//Metodi
//Coordinate cartesiane

double Posizione::getX() const{
	return m_x;
}
double Posizione::getY() const{
	return m_y;
}
double Posizione::getZ() const{
	return m_z;
}

//Coordinate sferiche

double Posizione::getR() const{
	return sqrt(m_x*m_x+m_y*m_y+m_z*m_z); //norma euclidea
}

double Posizione::getPhi() const{
	return atan2(m_y,m_x);//prende in ingresso i valori tra cui fare il rapporto da solo, atan e basta prende in ingresso il rapporto già fatto
}
double Posizione::getTheta()const{
	return acos(m_z/getR());
}
//raggio delle coordinate cilindriche
double Posizione::getRho() const{
	return sqrt(m_x*m_x+m_y*m_y);
}

//distanza da un altro punto
double Posizione::Distanza(const Posizione& b) const{
	return sqrt(pow(getX()-b.getX(),2)+pow(getY()-b.getY(),2)+pow(getZ()-b.getZ(),2));

}





















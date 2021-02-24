#include "PuntoMateriale.h"
#include "Particella.h"
#include "Posizione.h"
#include "CampoVettoriale.h"

#include <cmath>//usiamo M_PI per il campo elettrico
#include <cstdlib>
#include <iostream>
using namespace std;

	PuntoMateriale::PuntoMateriale(double massa, double raggio, double carica, const Posizione& pos): Particella(massa, carica), Posizione(pos){
//non aggiungo nient'altro
m_raggio=raggio;
};


	PuntoMateriale::PuntoMateriale(double massa, double raggio, double carica, double x, double y, double z): Particella(massa, carica), Posizione(x,y,z){
//non aggiungo nient'altro
m_raggio=raggio;
};

//Metto PuntoMateriale:: perché abbiamo dichiarato tale metodo nel PuntoMateriale.h
//CampoElettrico è un metodo della classe punto materiale che restituisce un CampoVettoriale e così facendo lo costruisce
	CampoVettoriale PuntoMateriale::CampoElettrico(const Posizione& pos) const{
	 
	//è un costruttore di un oggetto di tipo campovettoriale definito all'interno di punto materiale perché utilizza getcarica che è intrinseco nell'oggetto di tipo puntomateriale


	double Ex,Ey,Ez;


	Ex=(GetCarica()*(pos.getX()-getX()))/((4*M_PI*8.85E-12)*(pow (Distanza(pos),3)));//dividi per r^2, devi calcolarti la distanza del punto dalla carica 

	Ey=(GetCarica()*(pos.getY()-getY()))/((4*M_PI*8.85E-12)*(pow(Distanza(pos),3)));//dividi per r^2, devi calcolarti la distanza del punto dalla carica 

	Ez=(GetCarica()*(pos.getZ()-getZ()))/((4*M_PI*8.85E-12)*(pow(Distanza(pos),3)));//dividi per r^2, devi calcolarti la distanza del punto dalla carica 


	CampoVettoriale Elettro(pos,Ex,Ey,Ez);

	return Elettro;

}

	CampoVettoriale PuntoMateriale::CampoGravitazionale(const Posizione& pos) const{

	double Gx,Gy,Gz;

	double G= 6.67E-11;

	Gx=(-G*GetMassa()*(pos.getX()-getX()))/(pow(Distanza(pos),3));//dividi per r^2, devi calcolarti la distanza del punto dalla carica 

	Gy=(-G*GetMassa()*(pos.getY()-getY()))/(pow(Distanza(pos),3));//dividi per r^2, devi calcolarti la distanza del punto dalla carica 

	Gz=(-G*GetMassa()*(pos.getZ()-getZ()))/(pow(Distanza(pos),3));//dividi per r^2, devi calcolarti la distanza del punto dalla carica 


	CampoVettoriale Gravitaz(pos,Gx,Gy,Gz);

	return Gravitaz;

}










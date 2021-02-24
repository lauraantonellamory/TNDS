#ifndef __PuntoMateriale_h__
#define __PuntoMateriale_h__


#include "Particella.h"
#include "Posizione.h"

#include "CampoVettoriale.h"

class PuntoMateriale : public Particella, Posizione {//campo vettoriale è figlia della classe posizione quindi se 

	public:
	
	PuntoMateriale(double massa, double raggio, double carica, const Posizione&);
	PuntoMateriale(double massa, double raggio, double carica, double x, double y, double z);
	~PuntoMateriale() { };

	
	CampoVettoriale CampoElettrico(const Posizione&) const;
	CampoVettoriale CampoGravitazionale(const Posizione&) const;

	//potevo scriverle in Posizione?? Dato un punto materiale con una determinata posizione si può a livello logico astrarre il concetto di sorgente del campo in un'unica classe "Punto Materiale". No, sono dei metodi di puntomateriale che restituiscono un oggetto di tipo CampoVettoriale (costruendoli).

	protected:

	double m_raggio;

};

#endif // __PuntoMateriale_h__

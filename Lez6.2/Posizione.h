#ifndef __Posizione_h__
#define __Posizione_h__

class Posizione{

public:

//costruttori

	Posizione();
	Posizione(double x, double y, double z);

//distruttore

	~Posizione();

//metodi

	double getX() const;    //Coordinate cartesiane
	double getY() const;
	double getZ() const;

	double getR() const;    //Coordinate sferiche
	double getPhi() const;
	double getTheta() const;
	double getRho() const;    //raggio delle coordinate cilindriche
	double Distanza(const Posizione&) const; //distanza da un altro punto.

protected: 

	double m_x,m_y,m_z;

};

#endif //Posizione.h

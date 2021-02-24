#ifndef __RANDOMGEN_H__
#define __RANDOMGEN_H__

class RandomGen {

public:

	RandomGen(unsigned int);//costruttore
	
	void SetA(unsigned int a){m_a=a;}
	void SetC(unsigned int c){m_c=c;}
	void SetM(unsigned int m){m_m=m;}

	double Rand();
	double Unif(double xmin, double xmax);//distribuzione uniforme
	double Exp(double mean);//distribuzione esponenziale
	double GaussBoxMuller(double mean, double sigma);//gauss con BOXMULLER
	double GaussAR(double mean, double sigma);//gauss ACCEPTREJECT

private:

	unsigned int m_a, m_c, m_m;
	unsigned int m_seed;

};

#endif


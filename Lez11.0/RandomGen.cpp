#include "RandomGen.h"
#include <cmath>
#include <iostream>
#include <float.h>

using namespace std;

RandomGen::RandomGen(unsigned int seed){
	m_seed = seed;
	m_a = 1664525;
	m_c = 1013904223;
	m_m = pow(2,31);//massimo numero di resti possibili, massima periodicità nella sequenza
}

double RandomGen::Rand() {
	double n = 1.*((m_a*(m_seed)+m_c)%(m_m));//hai un numero di bit maggiori per tenere dentro il valore di n che vien fuori
	m_seed = (unsigned int) n;//riassocia seed quindi la prossima volta che richiamo rand lui avrà un nuovo m_seed
	return (n / (m_m-1));//raggiungi gli estremi dell'intervallo
//mm non sarà mai raggiunto dalla operazione di modulo perché se ho resto mm in realtà posso ancora dividere e dunque ho resto 0. Il massimo resto possibile è mm-1.
//ti serve un n che sia double perché così nella divisione applica l'aritmetica double
}

double RandomGen::Unif(double xmin, double xmax){

	double r=xmin+(xmax-xmin)*Rand();
	return r;//valori equiprobabili
}


double RandomGen::Exp(double lambda){
	double y = Rand();//this è una casella che contiene un indirizzo di memoria, cioè quello dell'oggetto stesso su cui applico Exp. Avrei potuto chiamare this->Rand() per dire: io this punto al metodo rand() che è indicato dal mio indirizzo.
	
	//NOTA BENE//if(y==0){y+=FLT_MIN;}//per evitare il caso ----> log(0)//NO?

	return -(1/lambda)*log(1-y);
}

double RandomGen::GaussBoxMuller(double media, double sigma){
	double s = this->Rand();
	double t = this->Rand();//essendo m_seed un datamembro private esterno alla funione Rand(), lo modifico all'esterno della funzione chiamando Rand e quindi la seconda volta che lo chiamo partirò da un nuovo seed
	double g = sqrt(-2.*log(s))*cos(2*M_PI*t);//prende solo 
	return media + sigma*g;
}


double RandomGen::GaussAR(double mean, double sigma){
	double x= -5*sigma + (10*sigma)* Rand();
	double max = (1./sqrt(2*M_PI));
	double y= max*Rand();
	double z;
	double s= (1/(sigma*sqrt(2*M_PI)))* pow(2.718281828, -(x-mean)*(x-mean)/(2*sigma*sigma));
	if (y< s) z =x;
	else z=-999;
	return z;
}


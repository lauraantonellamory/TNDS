#include "EsperimentoPrisma.h"

#include <iostream>

#include <cmath>

using namespace std;

EsperimentoPrisma::EsperimentoPrisma(unsigned int seed, double l1, double l2, double alpha, double sigmath, double A, double B):
  //uso una lista di inizializzazione per poter invocare il costruttore opportuno di m_rand prima ancora che venga costruito vuoto dall'esperimento prisma per poi riempirlo nonsisacome, visto che il costruttore vuoto non esiste
	m_rand(seed),
	m_lambda1(l1),
	m_lambda2(l2),
	m_alpha(alpha*M_PI/180.),//trasformazione di alpha in radianti per uso successivo nel seno
	m_sigmath(sigmath),
	m_A_input(A),
	m_B_input(B)

{
	m_n1_input=sqrt(m_A_input + (m_B_input / (m_lambda1*m_lambda1))); 
	m_n2_input=sqrt(m_A_input + (m_B_input / (m_lambda2*m_lambda2))); 

	m_th0_input=M_PI/2.;//viene dato come elemento prefissato nella fase di costruzione dell'apparato virtuale.

	double dm1=2.*asin(m_n1_input * sin(0.5*m_alpha))-m_alpha;
	m_th1_input=m_th0_input + dm1;

	double dm2=2.*asin(m_n2_input * sin(0.5*m_alpha))-m_alpha;
	m_th2_input=m_th0_input + dm2;

}

void EsperimentoPrisma::Esegui(){//esegue le misurazioni pratiche che verrebbero eseguite in laboratorio

	m_th0_misura=m_rand.GaussBoxMuller(m_th0_input, m_sigmath);
	m_th1_misura=m_rand.GaussBoxMuller(m_th1_input, m_sigmath);
	m_th2_misura=m_rand.GaussBoxMuller(m_th2_input, m_sigmath);

}

void EsperimentoPrisma::Analizza(){
	//il metodo che fa i calcoli dalle misure virtuali di esegui

  double dth1=m_th1_misura-m_th0_misura;//dm1 misurato
  double dth2=m_th2_misura-m_th0_misura;//dm2 misurato

  m_n1_misura=sin(0.5*(dth1+m_alpha))/sin(0.5*m_alpha);
  m_n2_misura=sin(0.5*(dth2+m_alpha))/sin(0.5*m_alpha);

  m_A_misura=(pow(m_lambda2,2)*pow(m_n2_misura,2)-pow(m_lambda1,2)*pow(m_n1_misura,2))/(pow(m_lambda2,2)-pow(m_lambda1,2));
  m_B_misura=(pow(m_n2_misura,2)-pow(m_n1_misura,2))/(pow(1/m_lambda2,2)-pow(1/m_lambda1,2));

}

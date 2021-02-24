#ifndef __ESPERIMENTO_PRISMA_H__
#define __ESPERIMENTO_PRISMA_H__

#include "RandomGen.h"

class EsperimentoPrisma{

  public:

	EsperimentoPrisma(unsigned int seed, double l1, double l2, double alpha, double sigmath, double A, double B);
	~EsperimentoPrisma(){};

	double GetAInput(){return m_A_input;};
	double GetBInput(){return m_B_input;};
	double Getn1Input(){return m_n1_input;};
	double Getn2Input(){return m_n2_input;};
	double Getth0Input(){return m_th0_input;};//i metodi sono in maiuscolo
	double Getth1Input(){return m_th1_input;};
	double Getth2Input(){return m_th2_input;};
	double GetAMisura(){return m_A_misura;};
	double GetBMisura(){return m_B_misura;};
	double Getn1Misura(){return m_n1_misura;};
	double Getn2Misura(){return m_n2_misura;};
	double Getth0Misura(){return m_th0_misura;};
	double Getth1Misura(){return m_th1_misura;};
	double Getth2Misura(){return m_th2_misura;};

	void Esegui();
	void Analizza();

	void Run(){Esegui(); Analizza();};


  private:

	//generatore di numeri casuali che verrà utilizzato per fare le misure virtuali
	RandomGen m_rand;

	//parametri dell'apparato sperimentale
	double m_lambda1, m_lambda2, m_alpha, m_sigmath;

	//valori delle quantità misurabili - "vere" e "misurate"
	double m_A_input, m_A_misura;//internamente sono in minuscolo
	double m_B_input, m_B_misura;
	double m_n1_input, m_n1_misura;
	double m_n2_input, m_n2_misura;
	double m_th0_input, m_th0_misura;
	double m_th1_input, m_th1_misura;
	double m_th2_input, m_th2_misura;

};

#endif

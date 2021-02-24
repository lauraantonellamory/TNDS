#include "PuntoMateriale.h"
#include "CampoVettoriale.h"
#include "Posizione.h"
#include "Particella.h"


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"


using namespace std;

int main(){
	

	TApplication myapp("app",0,0);

	const double mTerra=5.9726E24;
	const double mSatellite=0.;
	const double diametro=12745594.;
	const double raggioTerra= diametro/2.;
	cout << raggioTerra << endl;
	double x=0.;
	double y=raggioTerra+2.5E5;
	double z=0.;
	Posizione r(x,y,z);

	PuntoMateriale Satellite(mSatellite,0., 0., x, y, z);
	PuntoMateriale Terra(mTerra, raggioTerra, 0.,0.,0.,0.);

	CampoVettoriale g(Terra.CampoGravitazionale(r));

	cout << "g=("<< g.getFx() << "," << g.getFy() << "," << g.getFz() << ")" << endl;
	cout << "Il modulo del vettore campo gravitazionale è: " << g.Modulo() << endl;

	double raggioMassetta=1E3;
	double densitaMassetta=3E3;//kg/m^3
	double volumeMassetta=(4./3.)*M_PI*pow(raggioMassetta,3);//volume della sfera
	double massaMassetta=volumeMassetta*densitaMassetta;


	PuntoMateriale** montagna= new PuntoMateriale*[100];//(variabile puntatore a puntatori)montagna punta a un vettore di cento puntatori, ognuno puntante a un oggetto di classe puntomateriale
//mi serve perché poi dovrò creare tramite ognuno di questi 100 puntatore una montagna in una posizione diversa
	for(int i=0; i<100; i++) {
		double phi=i*(2.*raggioMassetta)/raggioTerra;
		cout << endl <<"L'angolo phi è: " << phi << endl;//controllo che posizioni correttamente le montagne sulla terra
		montagna[i]=new PuntoMateriale(massaMassetta,raggioMassetta,0.,raggioTerra*sin(phi), raggioTerra*cos(phi),0.);
cout << "Il seno dell'angolo, cioè x è= " << sin(phi) << endl;
		cout << "la montagna è posizionata nelle coordinate: "<< raggioTerra*sin(phi) << " " << raggioTerra*cos(phi) << endl;
	}//C'è un errore nel posizionamento delle montagne ovvero nell'utilizzo di sin(phi)

	const double passo=1E4;//metri, arco di circonferenza sull'orbita
	
	//divido il passo per z, cos da ottenere il passo in angolo
	const double theta=passo/y;

	//il numero di passi angolari per ricoprire l'orbita 2*M_PI
	const long int npassi=int(2*M_PI/theta)+1;

	//Posizione rS(); NON LO CREO ALL'ESTERNO, LO CREO NEL FOR E SI AUTODISTRUGGE AD OGNI CICLO
	//double vettore[100]; lettura standard: cosa creo a destra, cosa contiene a sinistra
	//CampoVettoriale* CampoTotaletot[npassi+1];//così questo è un array grande npassi+1 che contiene puntatori a CampoVettoriale

	double dg[npassi];//un vettore in cui registro le diff di gravità in modo da graficarle
	CampoVettoriale CampoTotaletot[npassi];//ho bisogno di un vettore che registri le n rilevazioni
	
	for(int i=0; i<npassi;i++){
//stai usando sempre lo stesso oggetto rS, dunque ci sovrascrivi
	Posizione rS(y*sin(i*theta),y*cos(i*theta),0.);//costruttore senza nome perché associa a un oggetto Posizione già esistente, ho costruito tutto nel piano x y


cout << "La posizione x del satellite è: " << rS.getX() << "La posizione y del satellite è: " << rS.getY() << "La posizione z del satellite è: " << rS.getZ() << endl; 


	CampoVettoriale CampoTotale;
	
	CampoTotale=Terra.CampoGravitazionale(rS);//campogravitazionale prende in ingresso una posizione. C'è da prendere rS perché così le componenti vengono di volta in volta a cambiare, anche se il campo somma vettoriale poi resta uguale, di base deve costruire su un campo nel punto rS

		for (int k=0;k<100;k++){
		//cout << "Il satellite è nella posizione: " << rS.getX() << " " << rS.getY() << " " << rS.getZ() << endl;//NON VIENE STAMPATO
		CampoTotale+=montagna[k]->CampoGravitazionale(rS);
		}
	//(*CampoTotaletot[i])=CampoTotale;//al contenuto dell'oggetto puntato dalla casella iesima 

	CampoTotaletot[i]=CampoTotale;
	
	
	//non va chiamato il distruttore perché appena esce dal for l'oggetto CampoTotale si distrugge automaticamente

	}

	//SEMBRA CHE GLI STIA GIRANDO INTORNO SUL PIANO X-Z dalla componente di z del campo gravitazionale

	TGraph *diffdigravita=new TGraph();
	int contatore=0;
	for(int i=0; i<npassi;i++){
	cout << "g=("<< CampoTotaletot[i].getFx() << "," << CampoTotaletot[i].getFy() << "," << CampoTotaletot[i].getFz() << ")" << " ";
	double sum=(pow(CampoTotaletot[i].getFx(),2)+pow(CampoTotaletot[i].getFy(),2)+pow(CampoTotaletot[i].getFz(),2));
	cout << "gtot= " << pow(sum,1./2)<< endl;
	dg[i]=CampoTotaletot[i].Modulo()-g.Modulo();//osservazione: il modulo di g senza montagne è identico ovunque, posso usare g
	diffdigravita->SetPoint(contatore, i, dg[i]);//uso i come x e dg[i] come y. La x sarà l'arco di circonferenza percorso.
	contatore++;
	}

	diffdigravita->GetXaxis()->SetTitle("Arco di circonferenza [m*(10^4)]");
	diffdigravita->GetYaxis()->SetTitle("Differenza di gravità [m/(s^2)]");

	TCanvas *DG=new TCanvas();
	DG->cd();

	diffdigravita->Draw("AL");

	
	myapp.Run();	

	return 0;
}

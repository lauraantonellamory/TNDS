#include <iostream>
#include <climits>
#include <ctime>

#include "TH1F.h"
#include "TH2F.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TAxis.h"

#include "EsperimentoPrisma.h"
#include "RandomGen.h"

using namespace std;

int main(){

  TApplication app("app",0,0);

  int A;
  srand((unsigned)time(NULL));
  A=rand()%INT_MAX;

  EsperimentoPrisma esp(A, 579.1e-9, 404.7e-9, 60., 0.3e-3, 2.7, 60000e-18);//60.000*(10^-9)^2

  double th1th2=0, n1n2=0, AB=0;//le uso per il calcolo degli indici di correlazione
  
  //Definizione istogrammi
  TH1F hth0("theta0", "theta0", 100, (M_PI/2.)-5*0.3e-3, (M_PI/2.)+5*0.3e-3 );//definisco l'istogramma da (pi/2)-5sigma a (pi/2)+5 sigma, questo ospiterà i possibili theta0
  TH1F hth1("theta1", "theta1", 100, esp.Getth1Input()-5*0.3e-3, esp.Getth1Input()+5*0.3e-3 );//uguale, ma per theta1 che viene da Get cioè dall'oggetto già costruito
  TH1F hth2("theta2", "theta2", 100, esp.Getth2Input()-5*0.3e-3, esp.Getth2Input()+5*0.3e-3 );
//definiti da -5sigma a +5sigma

//differenza rispetto ai valori veri di th1 e th2
  TH1F hddth1("d theta1", "d theta1", 100, -2.*0.3e-3, 2.*0.3e-3);
  TH1F hddth2("d theta2", "d theta2", 100, -2.*0.3e-3, 2.*0.3e-3);
  TH2F hcorr_dth("correlazione dth", "correlazione th1 th2", 100,-0.002 ,0.002 , 100,-0.002 , 0.002);//indica come sono correlate le dm(th1 e th2 sono dm1 e dm2), prende nbin x, xmin, xmax, nbin y, ymin, ymax

//differenze tra "n misurati" ed "n veri"
  TH1F hdn1("dn1", "dn1", 100, -1e-3, 1e-3);
  TH1F hdn2("dn2", "dn2", 100, -1e-3, 1e-3);
  TH2F hcorr_dn("correlazione n", "correlazione", 100, -0.001, 0.001, 100, -0.001, 0.001);//indica come sono correlate le n1-n2 misurate, entrambi dipendono a monte dallo stesso th0

//differenza tra valori misurati di AB e quelli veri di AB
  TH1F hdA("d A", "d A", 100, -0.005, 0.005);
  TH1F hdB("d B", "d B", 100, -0.8e-15, 0.8e-15);
  TH2F hcorr_AB("correlazione AB", "correlazione AB", 100, -0.005, 0.005, 100, -0.8e-15, 0.8e-15);//come sono correlate le A e le B misurate, dipendono da th0

//userò le statistiche di root ma voglio che mi includa i valori che sono nelle code e dunque vengono esclusi dalla rappresentazione
  hth0.StatOverflows(kTRUE);
  hth1.StatOverflows(kTRUE);
  hth2.StatOverflows(kTRUE);
  hddth1.StatOverflows(kTRUE);
  hddth2.StatOverflows(kTRUE);
  hcorr_dth.StatOverflows(kTRUE);
  hdn1.StatOverflows(kTRUE);
  hdn2.StatOverflows(kTRUE);
  hcorr_dn.StatOverflows(kTRUE);
  hdA.StatOverflows(kTRUE);
  hdB.StatOverflows(kTRUE);
  hcorr_AB.StatOverflows(kTRUE);


  //simulazioni
  for(int i=0;i<10000;i++){
    esp.Run();//fatto e analizzato l'esperimento, vanno riempiti i grafici

    hth0.Fill(esp.Getth0Misura());
    hth1.Fill(esp.Getth1Misura());
    hth2.Fill(esp.Getth2Misura());


    hddth1.Fill((esp.Getth1Input()-esp.Getth0Input())-(esp.Getth1Misura()-esp.Getth0Misura()));//dm1 vero-dm1 misurato

    hddth2.Fill((esp.Getth2Input()-esp.Getth0Input())-(esp.Getth2Misura()-esp.Getth0Misura()));//dm2 vero-dm2 misurato

    hcorr_dth.Fill((esp.Getth1Input()-esp.Getth0Input())-(esp.Getth1Misura()-esp.Getth0Misura()),(esp.Getth2Input()-esp.Getth0Input())-(esp.Getth2Misura()-esp.Getth0Misura()));//dm1vero-dm1mis,dm2vero-dm2mis

//indice di correlazione tra th1 e th2
//rho=(<xy>-<x><y>)/Sx*Sy
//(dm1vero-dm1mis)*(dm2vero-dm2mis)
//ddm1=dm1vero-dm1mis
    th1th2+=((esp.Getth1Input()-esp.Getth0Input())-(esp.Getth1Misura()-esp.Getth0Misura()))/*ddm1*/*((esp.Getth2Input()-esp.Getth0Input())-(esp.Getth2Misura()-esp.Getth0Misura()))/*ddm2*/;

    
    hdn1.Fill(esp.Getn1Misura()-esp.Getn1Input());//diff tra n1vero ed n1 mis
    hdn2.Fill(esp.Getn2Misura()-esp.Getn2Input());
    hcorr_dn.Fill(esp.Getn1Misura()-esp.Getn1Input(), esp.Getn2Misura()-esp.Getn2Input());
    n1n2+=(esp.Getn1Misura()-esp.Getn1Input())*(esp.Getn2Misura()-esp.Getn2Input());


    hdA.Fill(esp.GetAMisura()-esp.GetAInput());
    hdB.Fill(esp.GetBMisura()-esp.GetBInput());
    hcorr_AB.Fill(esp.GetAMisura()-esp.GetAInput(),esp.GetBMisura()-esp.GetBInput());
    AB+=(esp.GetAMisura()-esp.GetAInput())*(esp.GetBMisura()-esp.GetBInput());

  }

// fare th1th2/=10000; è come fare th1th2= th1th2/10000;
  th1th2/=10000;
  n1n2/=10000;
  AB/=10000;
//si usano per i rho di correlazione
  
//cout<<"\t" stampa in cout uno spazio di tabulazione,\n stampa su una nuova linea
//hth0.GetRMS() estrae dall'istrogramma la ROOTMEANSQUARE, cioè la deviazione standard, la sua def su root.cern.ch è return GetStdDev;
  cout<<"\t Media \t DevStd \n";
  cout<<"\t"<<hth0.GetMean()<<"\t"<<hth0.GetRMS()<<"\t Theta 0 \n";
  cout<<"\t"<<hth1.GetMean()<<"\t"<<hth1.GetRMS()<<"\t Theta 1 \n";
  cout<<"\t"<<hth2.GetMean()<<"\t"<<hth2.GetRMS()<<"\t Theta 2 \n";

  cout<<"\n\n\t Corr \n";
  cout<<"\t"<<(th1th2-(hddth1.GetMean()*hddth2.GetMean()))/(hddth1.GetRMS()*hddth2.GetRMS())<<"\t Theta1 theta2 \n";
  cout<<"\t"<<(n1n2-(hdn1.GetMean()*hdn2.GetMean()))/(hdn1.GetRMS()*hdn2.GetRMS())<<"\t n1 n2 \n";
  cout<<"\t"<<(AB-(hdA.GetMean()*hdB.GetMean()))/(hdA.GetRMS()*hdB.GetRMS())<<"\t A B \n";

  //Disegno istogrammi
  TCanvas cmisure("dati misurati", "dati misurati");
  TCanvas cdtheta("angoli", "angoli");
  TCanvas cn("indici di rifrazione", "indici di rifrazione");
  TCanvas cAB("coeff. di cauchy", "coeff. di cauchy");

  cmisure.Divide(3,1);
  cdtheta.Divide(3,1);
  cn.Divide(3,1);
  cAB.Divide(3,1);

  cmisure.cd(1);//qui stampo le misure estratte attorno al valore vero tramite la gaussianaboxmuller
  hth0.GetXaxis()->SetTitle("[rad]");
  hth0.GetYaxis()->SetTitle("N");
  hth0.Draw();
  cmisure.cd(2);
  hth1.GetXaxis()->SetTitle("[rad]");
  hth1.GetYaxis()->SetTitle("N");
  hth1.Draw();
  cmisure.cd(3);
  hth2.GetXaxis()->SetTitle("[rad]");
  hth2.GetYaxis()->SetTitle("N");
  hth2.Draw();

  cdtheta.cd(1);//qui stampo le diff tra th1 vero e th1 mis
  hddth1.GetXaxis()->SetTitle("[rad]");
  hddth1.GetYaxis()->SetTitle("N");
  hddth1.Draw();
  cdtheta.cd(2);//tra th2 vero e th2 mis
  hddth2.GetXaxis()->SetTitle("[rad]");
  hddth2.GetYaxis()->SetTitle("N");
  hddth2.Draw();
  cdtheta.cd(3);//qui la correlazione tra le due differenze
  hcorr_dth.GetXaxis()->SetTitle("[rad]");
  hcorr_dth.GetYaxis()->SetTitle("[rad]");
  hcorr_dth.Draw("SURF3");//aggiunge una linea di contorno

  cn.cd(1);
  hdn1.GetXaxis()->SetTitle("indice rifrazione");
  hdn1.GetYaxis()->SetTitle("N");
  hdn1.Draw();
  cn.cd(2);
  hdn2.GetXaxis()->SetTitle("indice rifrazione");
  hdn2.GetYaxis()->SetTitle("N");
  hdn2.Draw();
  cn.cd(3);
  hcorr_dn.GetXaxis()->SetTitle("indice rifrazione");
  hcorr_dn.GetYaxis()->SetTitle("indice rifrazione");
  hcorr_dn.Draw("SURF3");

  cAB.cd(1);
  hdA.GetXaxis()->SetTitle("A");
  hdA.GetYaxis()->SetTitle("N");
  hdA.Draw();
  cAB.cd(2);
  hdB.GetXaxis()->SetTitle("B");
  hdB.GetYaxis()->SetTitle("N");
  hdB.Draw();
  cAB.cd(3);
  hcorr_AB.GetXaxis()->SetTitle("A");
  hcorr_AB.GetYaxis()->SetTitle("B");
  hcorr_AB.Draw("SURF3");
  

  app.Run();

  return 0;
}

/*
MIT License

Copyright (c) 2019 Laura Antonella Mory

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions: The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"

#include "PuntoMateriale.h"
#include "CampoVettoriale.h"
#include "Posizione.h"
#include "Particella.h"

using namespace std;

int main()
{
	TApplication myapp("app", 0, 0);

	const double mTerra = 5.9726E24;
	const double mSatellite = 0.;
	const double diametro = 12745594.;
	const double raggioTerra = diametro / 2.;
	cout << raggioTerra << endl;

	double x = 0.;
	double y = raggioTerra + 2.5E5;
	double z = 0.;
	Posizione r(x, y, z);

	PuntoMateriale Satellite(mSatellite, 0., 0., x, y, z);
	PuntoMateriale Terra(mTerra, raggioTerra, 0., 0., 0., 0.);

	CampoVettoriale g(Terra.CampoGravitazionale(r));

	cout << "g=(" << g.getFx() << "," << g.getFy() << "," << g.getFz() << ")" << endl;
	cout << "Il modulo del vettore campo gravitazionale è: " << g.Modulo() << endl;

	double raggioMassetta = 1E3;
	double densitaMassetta = 3E3;									   //kg/m^3
	double volumeMassetta = (4. / 3.) * M_PI * pow(raggioMassetta, 3); //volume della sfera
	double massaMassetta = volumeMassetta * densitaMassetta;

	PuntoMateriale **montagna = new PuntoMateriale *[100];

	for (int i = 0; i < 100; i++)
	{
		double phi = i * (2. * raggioMassetta) / raggioTerra;

		cout << endl
			 << "L'angolo phi è: " << phi << endl;

		montagna[i] = new PuntoMateriale(massaMassetta, raggioMassetta, 0., raggioTerra * sin(phi), raggioTerra * cos(phi), 0.);

		cout << "Il seno dell'angolo, cioè x è= " << sin(phi) << endl;
		cout << "la montagna è posizionata nelle coordinate: " << raggioTerra * sin(phi) << " " << raggioTerra * cos(phi) << endl;
	}

	const double passo = 1E4; //metri, arco di circonferenza sull'orbita

	//divido il passo per z, cos da ottenere il passo in angolo
	const double theta = passo / y;

	//il numero di passi angolari per ricoprire l'orbita 2*M_PI
	const long int npassi = int(2 * M_PI / theta) + 1;

	double dg[npassi];						//un vettore in cui registro le diff di gravità in modo da graficarle
	CampoVettoriale CampoTotaletot[npassi]; //ho bisogno di un vettore che registri le n rilevazioni

	for (int i = 0; i < npassi; i++)
	{
		Posizione rS(y * sin(i * theta), y * cos(i * theta), 0.);

		cout << "La posizione x del satellite è: " << rS.getX() << "La posizione y del satellite è: " << rS.getY() << "La posizione z del satellite è: " << rS.getZ() << endl;

		CampoVettoriale CampoTotale;

		CampoTotale = Terra.CampoGravitazionale(rS);

		for (int k = 0; k < 100; k++)
		{
			CampoTotale += montagna[k]->CampoGravitazionale(rS);
		}

		CampoTotaletot[i] = CampoTotale;
	}

	TGraph *diffdigravita = new TGraph();
	int contatore = 0;
	for (int i = 0; i < npassi; i++)
	{
		cout << "g=(" << CampoTotaletot[i].getFx() << "," << CampoTotaletot[i].getFy() << "," << CampoTotaletot[i].getFz() << ")"
			 << " ";

		double sum = (pow(CampoTotaletot[i].getFx(), 2) + pow(CampoTotaletot[i].getFy(), 2) + pow(CampoTotaletot[i].getFz(), 2));

		cout << "gtot= " << pow(sum, 1. / 2) << endl;

		dg[i] = CampoTotaletot[i].Modulo() - g.Modulo(); //osservazione: il modulo di g senza montagne è identico ovunque, posso usare g
		diffdigravita->SetPoint(contatore, i, dg[i]);	 //uso i come x e dg[i] come y. La x sarà l'arco di circonferenza percorso.

		contatore++;
	}

	diffdigravita->GetXaxis()->SetTitle("Arco di circonferenza [m*(10^4)]");
	diffdigravita->GetYaxis()->SetTitle("Differenza di gravità [m/(s^2)]");

	TCanvas *DG = new TCanvas();
	DG->cd();

	diffdigravita->Draw("AL");

	myapp.Run();

	return 0;
}
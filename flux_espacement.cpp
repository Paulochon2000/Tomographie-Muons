#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>

#include "Muon.h"

using namespace std;

int main(){
	
	// Nous prenons les caracteristiques du systeme. Les notations sont definies dans le document donne.txt .
	ifstream donne("donne.txt");
	
	int N, P;
	double demi_l, demi_L;	
	donne>>P>>N>>demi_l>>demi_L;
	
	// chargeons les particules arrivant au premier plan.
	ifstream particules("plan_1.txt");
	double x, y, phi, theta;
	Muon muon;
	
	//prenons differents intervalles entre les plans.
	double espace1 =0;
	double espace2 =0.01;
	double espace3 = 0.04;
	double espace4 = 0.07;
	double espace5 =0.1;
	double espace6 = 0.13;
	double espace7 = 0.16;
	double espace8 = 0.19;
	double espace9 = 0.21;
	double espace10 = 0.24;
	double espace11 = 0.27;
	double espace12 = 0.3;
	
	int N_plan = N-1;// le nombre de plan a traverser.
	
	// les compteurs pour chaque espacement.
	double n1=0;
	double n2=0;
	double n3=0;
	double n4=0;
	double n5=0;
	double n6=0;
	double n7=0;
	double n8=0;
	double n9=0;
	double n10=0;
	double n11=0;
	double n12=0;
	
	
	
	
	//ce fichier prendra les espacements avec le nombre de particule final.
	ofstream flux_doc("donne_flux.txt");
	flux_doc<<"#espace  "<<"  #Comptage"<<endl;	
	while (!particules.eof())
	{
		particules>>x>>y>>phi>>theta;
		
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace1);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n1++;
		}
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace2);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n2++;
		}
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace3);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n3++;
		}
		
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace4);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n4++;
		}
		
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace5);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n5++;
		}
		
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace6);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n6++;
		}
		
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace7);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n7++;
		}
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace8);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n8++;
		}
		
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace9);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n9++;
		}
		
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace10);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n10++;
		}
		
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace11);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n11++;
		}
		
		
		muon.init(x, y, phi, theta);
		muon.entre_plan((N_plan)*espace12);
		// Verifions que le muon passe bien par le plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
		{
			n2++;
		}
	
	}
	flux_doc<<espace1<<"       "<<n1<<endl;
	flux_doc<<espace2<<"       "<<n2<<endl;
	flux_doc<<espace3<<"       "<<n3<<endl;
	flux_doc<<espace4<<"       "<<n4<<endl;
	flux_doc<<espace5<<"       "<<n5<<endl;
	flux_doc<<espace6<<"       "<<n6<<endl;
	flux_doc<<espace7<<"       "<<n7<<endl;
	flux_doc<<espace8<<"       "<<n8<<endl;
	flux_doc<<espace9<<"       "<<n9<<endl;
	flux_doc<<espace10<<"       "<<n10<<endl;
	flux_doc<<espace11<<"       "<<n11<<endl;
	flux_doc<<espace12<<"       "<<n12<<endl;
		
	
}

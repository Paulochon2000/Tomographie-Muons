#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>


#include "Muon.h"

using namespace std;

int main(){
	
	// Nous prenons les caracteristiques du systeme. Les notations sont definies dans le document donne.txt .
	ifstream donne("donne.txt");
	int N, P;
	double d_plan,demi_l, demi_L,intervalle;	
	donne>>P>>N>>demi_l>>demi_L>>d_plan>>intervalle;
	
	// chargeons les particules arrivant au plan.
	ifstream particules("plan_1.txt");
	double x, y, phi, theta;
	Muon muon;
	
	
	// ces fichiers serviront a recuperer les coordonnees des particules arrivant au dernier plan.
	ofstream x_doc("x.txt");
	ofstream y_doc("y.txt");
	ofstream angles_doc("angles_simule.txt");
	
	
	
	int N_2=0;//nombres de particule final.
	
	
	
	
	int N_plan = N-1;// le nombre de plan a traverser.
	
	
	while (!particules.eof())
	{
		
		particules>>x>>y>>phi>>theta;
		muon.init(x, y, phi, theta);
		
			
		
		muon.entre_plan((N_plan)*intervalle);
		
		// Verifions que le muon passe bien par le dernier plan.
		if ( abs(muon.Getx())< demi_l && abs(muon.Gety())<demi_L)
			{
			N_2++;
			muon.entre_plan(-(N_plan)*intervalle); //retourne au premier plan.
			x_doc<<muon.Getx()<<"  ";
			y_doc<<muon.Gety()<<"  ";
			
			// recuperons les coordonnees pour chaque plan.
			for (int i=1; i<N;i++){
			muon.entre_plan(intervalle);
			x_doc<<muon.Getx()<<"  ";
			y_doc<<muon.Gety()<<"  ";
			
			
			
			
			}
			x_doc<<" "<<endl;
			y_doc<<" "<<endl;
			angles_doc<<muon.Getphi()<<"  "<<muon.Gettheta()<<endl;
			
			
		}
	}
	
	
	
	cout<<"Le nombre particules arrivant au plan est de  "<<N_2<<" ce qui equivaut a une fraction de "<<double(N_2)/double(P)<<" des muons generees."<<endl;
	
}
	
	

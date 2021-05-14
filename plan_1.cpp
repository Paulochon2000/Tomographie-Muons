#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>

#include "Muon.h"

using namespace std;



// fonction reduisant le nombres de particules passant par l'objet.
double reduc_flux(double d, double D, double I_0){
	double I;
	I = I_0*exp(-d/D);
	return int(I);
	}






int main(){
	
	
	// Nous prenons les caracteristiques du systeme. Les notations sont definies dans le document donne.txt .
	ifstream donne("donne.txt");
	int P,N;
	double demi_l,demi_L,d_plan;
	donne>>P>>N>>demi_l>>demi_L>>d_plan;
	
	
	
	//Chargeons l'ensemble des particules passant par l'objet.
	ifstream muon_in("muons_in.txt");
	
	
	//Chargeons les muons ne passant pas par l'objet.
	ifstream muon_out("muons_out.txt");
	
	// recuperons la repartition des particules selon l'objet.
	ifstream nombres("nombres.txt");
	double nb_in,nb_out;
	nombres>>nb_in>>nb_out;
	
	//Ce fichier sert a stocker les muons qui arrivent au premier plan.
	ofstream premier_plan("plan_1.txt"); 
	
	//Chargeons les donnees sur l'objet.
	ifstream objet("objet.txt");
	double l_obj,L_obj,e_obj;
	objet>>l_obj>>L_obj>>e_obj;
	
	
	
	//Calculons la reduction du flux.
	double reduc_flux(double, double,double);
	nb_in = reduc_flux(e_obj, 4., nb_in);
	
	
	
	
	double x,y,phi,theta;
	Muon muon;
	
	int N_1 = 0; //nombre de particules final.
	
	for (int i=0; i<nb_in;i++)
	{
		muon_in>>x>>y>>phi>>theta;
		muon.init(x,y,phi,theta);
		muon.avant_plan(d_plan);//deplace de l'objet au premier plan.
		N_1++;
		premier_plan<<muon.Getx()<<"  "<<muon.Gety()<<"   "<<muon.Getphi()<<"  "<<muon.Gettheta()<<endl;
		
	}
	for(int j=0; j<nb_out;j++)
	{
		muon_out>>x>>y>>phi>>theta;
		muon.init(x,y,phi,theta);
		muon.avant_plan(d_plan);//deplace de l'objet au premier plan.
		N_1++;
		premier_plan<<muon.Getx()<<"  "<<muon.Gety()<<"   "<<muon.Getphi()<<"  "<<muon.Gettheta()<<endl;
		
	}
	
	
	cout<<"Le nombre particules arrivant au premier plan est de  "<<N_1<<" ce qui equivaut a une fraction de "<<double(N_1)/double(P)<<" des muons generees."<<endl;

}	
	
	
	
	

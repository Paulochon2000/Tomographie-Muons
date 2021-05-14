#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>

#include "Muon.h"


using namespace std;

int main(){
	
	// Nous prenons les caracteristiques du systeme. Les notations sont definies dans le document donne.txt .
	ifstream donne("donne.txt");
	
	int P,N;
	double demi_l,demi_L,d_plan;
	
	donne>>P>>N>>demi_l>>demi_L>>d_plan;
	
	
	
	//Creons l'objet. Ici, l'objet n'utilise pas la largeur et la longeur definies.On etudie la difference entre la detection sans et avec objet en priorite.
	ifstream carac_obj("objet.txt");
	double l_obj, L_obj, e_obj;
	carac_obj>>l_obj>>L_obj>>e_obj;
	
	
	
	
	//Ces fichiers vont recuperer les particules qui passent dans l'objet et celles qui ne passent pas.
	ofstream muons_in("muons_in.txt");
	ofstream muons_out("muons_out.txt");
	ofstream nombres("nombres.txt");
	
	
	//Chargons l'ensemble des particules generees.
	ifstream particules("particules.txt");
	
	double x,y,phi,theta;
	Muon muon;
	
	int nb_out = 0; //nombres de particules passant par l'objet.
	int nb_in = 0; //nombres de particules ne passant  pas par l'objet.
	
	for (int i=0; i<P; i++)
	{
		particules>>x>>y>>phi>>theta;
		muon.init(x, y, phi, theta);
		muon.avant_plan(-d_plan); // va du premier plan jusqu'a l'objet.
		
		// Regardons si le muon passe par l'objet.
		if ( muon.Getx()<0)
		{
			nb_in++;
			muons_in<<muon.Getx()<<"  "<<muon.Gety()<<"   "<<muon.Getphi()<<"  "<<muon.Gettheta()<<endl;
			
		}
		else 
		{
			nb_out++;
			muons_out<<muon.Getx()<<"  "<<muon.Gety()<<"   "<<muon.Getphi()<<"  "<<muon.Gettheta()<<endl;
		}
	}
	nombres<<nb_in<<"  "<<nb_out<<endl;
	
	cout<<"Il y a "<<nb_in<<" muons passant par l'objet et "<<nb_out<<" l'evitant"<<endl;
	
}

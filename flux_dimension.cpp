#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <math.h>
#include <fstream>

#include "Muon.h"


using namespace std;

//equation reduisant le nombre de particules passant par l'objet.
double equation_flux(double theta){
	double I = 0.8* pow(cos(theta),1.85);   /* exprime en cm-2.s-1 */
	return I;
}
	
	
double uniforme(double v_min, double v_max){
	double interval = v_max-v_min;
	double valeur = rand()*1./RAND_MAX*interval;
	valeur += v_min;
	return valeur;
} 
	
	
int main(){
	double equation_flux(double);
	double uniforme(double,double);
	
	//chargeons les donnees sur le systeme. Variables expliquees dans le document donne.txt.
	int P,N;  
	ifstream donne("donne.txt");
	double d_plan,demi_l, demi_L,intervalle;	
	donne>>P>>N>>demi_l>>demi_L>>d_plan>>intervalle;
	
	
	//prenons plusieurs dimensions pour le detecteur. L'effet sur la variation de la longueur sera le meme pour la variation de la largeur.
	double demi_l_1 = 0.5;
	double demi_l_2 = 0.8;
	double demi_l_3 = 1.1;
	double demi_l_4 = 1.4;
	double demi_l_5 = 1.7;
	double demi_l_6 = 2;
	double demi_l_7 = 2.3;
	double demi_l_8 = 2.6;
	
	demi_L = 0.5;
 		
	double x_1,x_2,x_3,x_4,x_5,x_6,x_7,x_8;
	
	// initialisation des diffrents compteurs de particules.
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int n6 = 0;
	int n7 = 0;
	int n8 = 0;
	
	// fichier qui recolte les donnes.
	ofstream flux_doc("flux_dim.txt");
	
	
	// generation aleatoire des particules, en suivant la methode des rejets, sur le premier plan.
	double y, phi, theta;
	double pi = 4.*atan(1);
	double I;
	double I_0 = 0.8; 
	srand(time(NULL));
	Muon muon; // on utilise la structure muon qui se fera initialiser apres la generation de ses parametres.
	
	int N_plan = N-1;// le nombre de plan a traverser.
	
	//generons P muons avec des coordonnees differentes selon la largeur.
	for (int i=0; i<P; i++)
	{
		x_1 = uniforme(0,2*demi_l_1)-demi_l_1;
		x_2 = uniforme(0,2*demi_l_2)-demi_l_2;
		x_3 = uniforme(0,2*demi_l_3)-demi_l_3;
		x_4 = uniforme(0,2*demi_l_4)-demi_l_4;
		x_5 = uniforme(0,2*demi_l_5)-demi_l_5;
		x_6 = uniforme(0,2*demi_l_6)-demi_l_6;
		x_7 = uniforme(0,2*demi_l_7)-demi_l_7;
		x_8 = uniforme(0,2*demi_l_8)-demi_l_8;
		y = uniforme(0,2*demi_L)-demi_L;
		phi = uniforme(0,2*pi);
		theta = uniforme(0,pi/2.);
		I = uniforme(0, 2*I_0) - I_0;
		while (I<equation_flux(theta))
		{
			theta = uniforme(0,pi/2.);
			I = uniforme(0, 2*I_0) - I_0;
		}
		
		
		// a ce moment nous avons un muon avec ses parametres geometriques. 
		
		muon.init(x_1, y, phi, theta);
		
		// Verifions que le muon passe bien par le dernier plan.
		muon.entre_plan((N_plan)*intervalle);
		if ( abs(muon.Getx())< demi_l_1 && abs(muon.Gety())<demi_L)
			{
			n1++;
			}
		
		muon.init(x_2, y, phi, theta);
		muon.entre_plan((N_plan)*intervalle);
		// Verifions que le muon passe bien par le dernier plan.
		if ( abs(muon.Getx())< demi_l_2 && abs(muon.Gety())<demi_L)
			{
			n2++;
			}
		
		muon.init(x_3, y, phi, theta);
		muon.entre_plan((N_plan)*intervalle);
		// Verifions que le muon passe bien par le dernier plan.
		if ( abs(muon.Getx())< demi_l_3 && abs(muon.Gety())<demi_L)
			{
			n3++;
			}
		
		muon.init(x_4, y, phi, theta);
		muon.entre_plan((N_plan)*intervalle);
		// Verifions que le muon passe bien par le dernier plan.
		if ( abs(muon.Getx())< demi_l_4 && abs(muon.Gety())<demi_L)
			{
			n4++;
			}
		
		muon.init(x_5, y, phi, theta);
		muon.entre_plan((N_plan)*intervalle);
		// Verifions que le muon passe bien par le dernier plan.
		if ( abs(muon.Getx())< demi_l_5 && abs(muon.Gety())<demi_L)
			{
			n5++;
			}
		muon.init(x_6, y, phi, theta);
		muon.entre_plan((N_plan)*intervalle);
		// Verifions que le muon passe bien par le dernier plan.
		if ( abs(muon.Getx())< demi_l_6 && abs(muon.Gety())<demi_L)
			{
			n6++;
			}
			muon.init(x_7, y, phi, theta);
		muon.entre_plan((N_plan)*intervalle);
		// Verifions que le muon passe bien par le dernier plan.
		if ( abs(muon.Getx())< demi_l_7 && abs(muon.Gety())<demi_L)
			{
			n7++;
			}
		muon.init(x_8, y, phi, theta);
		muon.entre_plan((N_plan)*intervalle);
		// Verifions que le muon passe bien par le dernier plan.
		if ( abs(muon.Getx())< demi_l_8 && abs(muon.Gety())<demi_L)
			{
			n8++;
			}
	}
	
	flux_doc<<"#dimension    #comptage"<<endl;
	flux_doc<<2*demi_l_1<<"  "<<n1<<endl;
	flux_doc<<2*demi_l_2<<"  "<<n2<<endl;
	flux_doc<<2*demi_l_3<<"  "<<n3<<endl;
	flux_doc<<2*demi_l_4<<"  "<<n4<<endl;
	flux_doc<<2*demi_l_5<<"  "<<n5<<endl;
	flux_doc<<2*demi_l_6<<"  "<<n6<<endl;
	flux_doc<<2*demi_l_7<<"  "<<n7<<endl;
	flux_doc<<2*demi_l_8<<"  "<<n8<<endl;
}	
	

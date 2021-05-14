#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <math.h>
#include <fstream>



using namespace std;

// fonction calculant l'angle solide.
double angle_solide(double p, double q, double h){
	double omega = 4*asin(p*q /(sqrt(p*p+h*h)*sqrt(q*q+h*h)));
	return omega;
	}
	
// fonction calculant la surface.
double surface(double p, double q){
	double S = p*q;
	return S;
	}
	
int main(){
	// chargeons les donnes sur le systeme. Ces variables sont expliquees dans le document donne.txt.
	int P,N;
	double demi_l,demi_L, d_plan,intervalle;
	ifstream donne("donne.txt");
	donne>>P>>N>>demi_l>>demi_L>>d_plan>>intervalle;
	
	// fichier qui recupere les temps pour un certain nombre de particules.
	ofstream tempsdoc("time.txt");
	
	
	P = 100; // initialisation.
	double surface(double,double);
	double angle_solide(double,double,double);
	double h = (N-1)*intervalle; // calcul de la hauteur pour l'angle solide.
	double flux = 0.017; // flux de muon au niveau de la mer : en cm-2. s-1
	double S = surface(2*demi_l,2*demi_L);
	double interval = 100; // incrementation.
	double omega = angle_solide(demi_l, demi_L, h) ; // calcul de l'angle solide.
	tempsdoc<<"#Particules        #temps"<<endl;
	
	while (P<15000){
		double t =  P/( omega*S*flux);
		tempsdoc<<P<<"            "<<t<<endl;
		P+= interval;
		}
	}
		

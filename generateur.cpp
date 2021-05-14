#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <math.h>
#include <fstream>

#include "Muon.h"


using namespace std;

//equation qui sert pour generer les angles par la methode des rejets.
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
	
	//ces parametres sont detailles dans donne.txt
	int P,N; 
	double  demi_l,demi_L;
	ifstream donne("donne.txt");
	donne>>P>>N>>demi_l>>demi_L;
	
		
	//ce fichier recupere chaque muons generes.
	ofstream particules("particules.txt");//fichier recuperant les muons generes.
	
	
	
	// generation aleatoire des particules avec une loi uniforme et la methode des rejets..
	double x, y, phi, theta;
	double pi = 4.*atan(1);
	double I;
	double I_0 = 0.8; 
	srand(time(NULL)); 
	for (int i=0; i<P; i++)
	{
		x = uniforme(0,2*demi_l)-demi_l;
		y = uniforme(0,2*demi_L)-demi_L;
		phi = uniforme(0,2*pi);
		
		//generation de theta par la methode des rejets.
		theta = uniforme(0,pi/2.);
		I = uniforme(0, 2*I_0) - I_0;
		while (I<equation_flux(theta))
		{
			theta = uniforme(0,pi/2.);
			I = uniforme(0, 2*I_0) - I_0;
		}
		particules<<x<<"  "<<y<<"  "<<phi<<"  "<<theta<<endl;
	}	
	
	
}
	
	






	

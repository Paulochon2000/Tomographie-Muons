#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>

#include "Muon.h"

using namespace std;

double uni(double a, double b){
	double v_max = b-a;
	double valeur = rand()*1./RAND_MAX*v_max;
	valeur+=a;
	return valeur;
	}




int main(){
	//chargeons les caracteristiques du systeme. es variables sont expliquees dans le document donne.txt.
	ifstream donne("donne.txt");
	int P,N;
	double demi_l, demi_L, d_plan, intervalle, n, m;
	donne>>P>>N>>demi_l>>demi_L>>d_plan>>intervalle>>n>>m;
	
	
	double l = 2.*demi_l; // largeur du detecteur
	double L = 2.*demi_L; // longueur du detecteur
	
	double l_pix = l/m;  //dx : largeur du pixel
	double L_pix = L/n;  //dy : longueuer du pixel
	
	double dx =l_pix/sqrt(12); //incertitude sur la largeur
	double dy = L_pix/sqrt(12); //incertitude sur la longueur
	
	// chargeons les particules des deux plans extremes.
	ifstream x_doc("x.txt");
	ifstream y_doc("y.txt");
	
	double x,y;
	
	// ces fichiers sont pour les particules avec les pixels
	ofstream x_pixels("x_pixels.txt");
	ofstream y_pixels("y_pixels.txt");
	
	//ce fichier reprend les caracteristiques du pixel.
	ofstream pixel("pixel.txt");
	
	double n_l,n_L; //indices du pixel 
	
	
	double uni(double,double);
	srand(time(NULL));	
	while (!x_doc.eof())
	{
		for (int i=0; i<N; i++)
		{
			x_doc>>x;
			y_doc>>y;
			x += demi_l;
			y += demi_L;
	
	
			n_l = int(x/l_pix); 
			n_L = int(y/L_pix);
	
	
			//genere les coordonnees de facon aleatoire sur le pixel.
			x = uni(n_l*l_pix, (n_l+1)*l_pix) - demi_l; 
			y = uni(n_L*L_pix, (n_L+1)*L_pix) - demi_L;
	
			
			
	
			//la lesture du fichier a tendance a prendre en compte la ligne vide : creant une fausse valeur. Cette verification permet de l'eliminer.
			if ((n_l < m) || (n_L < n)){
				x_pixels<<x<<"  ";
				y_pixels<<y<<"  ";
				}
		}
	
		x_pixels<<" "<<endl;
		y_pixels<<" "<<endl;
	}
	pixel<<n<<"  "<<m<<"  "<<L_pix<<"  "<<l_pix<<endl;
}	
	
	
	

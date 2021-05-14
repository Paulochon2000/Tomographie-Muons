#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>

#include "Muon.h"

using namespace std;



int main(){
	//chargeons les donnes. Ces variables sont expliquees dans le document donne.txt.
	ifstream donne("donne.txt");
	int P,N;
	double d_plan,demi_l, demi_L,intervalle;	
	donne>>P>>N>>demi_l>>demi_L>>d_plan>>intervalle;
	
	//chargeons les donnees des pixels sur les deux plans extremes et celles sur le pixel en general.
	ifstream premier_pixel("premier_pixels_sans_obj.txt");
	ifstream dernier_pixel("dernier_pixels_sans_obj.txt");
	ifstream pixel("pixel.txt");
	
	int n,m;
	double dx,dy;
	pixel>>n>>m>>dy>>dx;
	
	double incertitude_x, incertitude_y, incertitude_phi, incertitude_theta;
	incertitude_x = dx/sqrt(12.);
	incertitude_y = dy/sqrt(12.);
	
	double x_i,y_i; //coordonnees du premier plan : i pour initial.
	double x_f,y_f; //coordonnees du dernier plan : f pour final.
	
	// ce fichier sert a recuperer les angles.
	ofstream angle("angles_rec_sans_obj.txt");
	double phi, theta;
	
	double pi = 4.*atan(1.);
	
	
	//pour calculer plus facilement les incertitudes.
	double derive1, derive2,derive3,derive4;
	
	
	while (!premier_pixel.eof())
	{
	premier_pixel>>x_i>>y_i;
	dernier_pixel>>x_f>>y_f;
	
	
	//le but est d'eviter de travailler avec des valeurs negatives.
	x_i += demi_l;
	y_i += demi_L;
	x_f += demi_l;
	y_f += demi_L;
	
	phi = atan((y_f - y_i)/(x_f - x_i));
	
	
	//deux cas pour calculer theta selon la valeur de l'angle phi.	
	if (sin(phi)!=0){
	theta = abs(atan((y_f - y_i)/(sin(phi)*(N-1)*intervalle)));
		}
	else {
		theta = abs(atan((x_f - x_i)/(cos(phi)*(N-1)*intervalle)));
		}
		
	// les manipulations suivantes permettent de retrouver les bons domaines de definition de l'angle phi. On passe de -pi/2 jusqu'a pi/2  a 0 jusque 2pi.
	if (((x_i-x_f)<0) && ((y_i-y_f)>0)){
		phi+=2*pi;
		}
	if (((x_i-x_f)>0) && ((y_i-y_f)>0)){
		phi+=pi;
		}	
	if (((x_i-x_f)<0) && ((y_i-y_f)>0)){
		phi+=pi;
		}
	if (phi>2*pi){
		phi-=pi;
		}
		
	if (phi<0){
		phi+=pi;
		}


	//calcul de l'incertitude sur l'angle phi.	
	derive1 = (y_f-y_i)/( pow(x_i,2) + pow(x_i*(y_f-y_i) / (x_f-x_i),2) );
	derive2 =  -(y_f-y_i)/( pow(x_f,2) + pow(x_f*(y_f-y_i) / (x_f-x_i),2) );
	derive3 =  (1./1.+ pow((y_f-y_i)/(x_f-x_i),2)) / (x_f-x_i);
	derive4 = (-1./1.+ pow((y_f-y_i)/(x_f-x_i),2)) / (x_f-x_i);
	incertitude_phi =  sqrt( (derive1*derive1+derive2*derive2)*incertitude_x*incertitude_x + (derive3*derive3+derive4*derive4)*incertitude_y*incertitude_y);
	
	//deux cas pour calculer l'incertitude sur theta selon la valeur de l'ange phi.
	if (sin(phi)!=0){
		derive1 = ((y_i-y_f)*cos(phi)/((N-1)*intervalle*sin(phi)*sin(phi)))/(1.+ pow((y_f - y_i)/(sin(phi)*(N-1)*intervalle),2));
		derive2 = (1.+ pow((y_f - y_i)/(sin(phi)*(N-1)*intervalle),2)*(1./(sin(phi)*(N-1)*intervalle)));
		derive3 = -(1.+ pow((y_f - y_i)/(sin(phi)*(N-1)*intervalle),2)*(1./(sin(phi)*(N-1)*intervalle)));
		incertitude_theta = sqrt( derive1*derive1*incertitude_phi*incertitude_phi + incertitude_y*incertitude_y*(derive2*derive2+derive3*derive3));
		}
	
	else {
		derive1 = ((x_i-x_f)*sin(phi)/((N-1)*intervalle*cos(phi)*cos(phi)))/(1.+ pow((y_f - y_i)/(cos(phi)*(N-1)*intervalle),2));
		derive2 = (1.+ pow((x_f - x_i)/(cos(phi)*(N-1)*intervalle),2)*(1./(cos(phi)*(N-1)*intervalle)));
		derive3 = -(1.+ pow((x_f - x_i)/(cos(phi)*(N-1)*intervalle),2)*(1./(cos(phi)*(N-1)*intervalle)));
		incertitude_theta = sqrt( derive1*derive1*incertitude_phi*incertitude_phi + incertitude_x*incertitude_x*(derive2*derive2+derive3*derive3));
		}
		
	
	angle<<phi<<"  "<<incertitude_phi<<"  "<<theta<<"   "<<incertitude_theta<<endl;
	
	
	}
	
}

#include <time.h>
#include <iostream>
#include <random>
#include <math.h>
#include <fstream>

#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TAxis.h"




using namespace std;


int main(){
	int nbins =100; //nombre de bins pour l'histogramme.
	TCanvas graph; // cree une fenetre.
	double pi = 4*atan(1);
	TH1F prod("prod","ecart relatif entre phi simule et reconstruit",nbins,-1,1); // creer un histogramme.
	TLegend leg(0.75,0.75,0.9,0.9); // creation de la legende.
	
	
	double phi,theta;
	double phi_rec, error_phi, theta_rec, error_theta; 
	double ecart; // variable de l'ecart relatif pour quatifier l ecart entre les angles.
	
	
	
	//fichier avec les angles reconstruits.
	ifstream recdoc("angles.txt");
	//fichier avec les angles simulee.
	ifstream simudoc("angles_simule.txt");
	
	
	
	while (!simudoc.eof()){
		simudoc>>phi>>theta;
		recdoc>>phi_rec>>error_phi>>theta_rec>>error_theta;

		
		ecart = (phi_rec - phi)/phi; // definition de l'ecart relatif.
		prod.Fill(ecart); // remplissage de l'histogramme.
		
	}
	
	
	graph.cd(); 
	
	prod.SetLineColor(8); //choix de la couleur
	prod.Draw(); // tracer l'histogramme.
	
	// nom des axes.
	prod.GetXaxis()->SetTitle("ecart relatif sur phi");
	prod.GetYaxis()->SetTitle("nombre d'apparition");
	
	
	

	
	graph.Print("phi_ecart.png"); // afficher et enregistrer l'image.
}

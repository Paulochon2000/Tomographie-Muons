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
	TH1F prod("prod","erreur sur l'angle theta",nbins,0,1); // creer un histogramme.
	TLegend leg(0.75,0.75,0.9,0.9); // creation de la legende.
	
	
	
	double phi_rec, error_phi, theta_rec, error_theta; 
	
	
	
	
	//fichier avec les angles reconstruits.
	ifstream recdoc("angles.txt");
	
	
	
	
	while (!recdoc.eof()){
		
		recdoc>>phi_rec>>error_phi>>theta_rec>>error_theta;

		
		
		prod.Fill(error_theta); // remplissage de l'histogramme.
		
	}
	
	
	graph.cd(); 
	
	prod.SetLineColor(8); //choix de la couleur
	prod.Draw(); // tracer l'histogramme.
	
	// nom des axes.
	prod.GetXaxis()->SetTitle("erreur sur theta");
	prod.GetYaxis()->SetTitle("nombre d'apparition");
	
	
	

	
	graph.Print("theta_erreur.png"); // afficher et enregistrer l'image.
}

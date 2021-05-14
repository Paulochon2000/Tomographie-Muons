#include <time.h>
#include <iostream>
#include <random>
#include <math.h>
#include <fstream>

#include "TH1F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TAxis.h"

// g++ graph_theta.cpp `root-config --cflags --glibs` -o graph_theta.exe


using namespace std;


int main(){
	int nbins =100; //nombre de bins pour l'histogramme.
	TCanvas graph;  // cree une fenetre.
	double pi = 4*atan(1);
	// on cree deux histogrammes.
	TH1F prod1("prod1","Comparaison des angles",nbins,0,pi/2.);
	TH1F prod2("prod2","Comparaison des angles",nbins,0,pi/2.);
	TLegend leg(0.75,0.75,0.9,0.9); // creation de la legende.
	
	double phi,theta;
	double phi_rec, error_phi_rec, theta_rec, error_theta_rec;//varibales pour les angles apres reconstruction.
	
	
	
	
	//fichier contenant les angles reconstruits.
	ifstream recdoc("angles.txt");
	//fichier contenant les angles simule.
	ifstream simudoc("angles_simule.txt");
	
	
	while (!simudoc.eof()){
		simudoc>>phi>>theta;
		recdoc>>phi_rec>>error_phi_rec>>theta_rec>>error_theta_rec;

		// remplissage des histogrammes.
		prod1.Fill(theta);
		prod2.Fill(theta_rec);
		
	}
	
	graph.cd();
	
	prod2.SetLineColor(8); // choix de la couleur.
	prod2.Draw(); // tracer l'histogramme.
	
	// nom des axes.
	prod2.GetXaxis()->SetTitle("angle theta en rad");
	prod2.GetYaxis()->SetTitle("nombre d'apparition");
	
	prod1.SetLineColor(4); //choix de la couleur.
	prod1.Draw("same"); // tracer l'histogramme sur le meme.
	
	
	// ajout d'element dans la legende.
	leg.AddEntry(&prod2,"theta reconstruit","l");
	leg.AddEntry(&prod1,"theta simule","l");
	leg.Draw("same"); // tracer la legende sur le meme/
	
	graph.Print("theta_comparaison.png");  // generer l'image et l'enregistrer sous ce nom.
}

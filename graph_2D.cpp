#include <time.h>
#include <iostream>
#include <random>
#include <math.h>
#include <fstream>

#include "TH2F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TAxis.h"



using namespace std;


int main(){
	int nbins =100; // nombre de bins.
	TCanvas graph; // cree une fenetre.
	double pi = 4*atan(1);
	//creation d'histogramme en deux dimensions.
	TH2F prod1("prod1","Sans objet",nbins,0,2*pi,nbins,0,pi/2.); 
	TH2F prod2("prod2","Avec objet",nbins,0,2*pi,nbins,0,pi/2.);
	TLegend leg(0.75,0.75,0.9,0.9); // creation de la legende.
	
	double phi,error_phi,theta,error_theta;
	double phi_rec, error_phi_rec, theta_rec, error_theta_rec;//varibales pour les angles apres reconstruction avec objet.
	
	graph.Divide(1,2);//division de la fenetre en deux.
	
	//fichier contenant les angles reconstruits avec objet.
	ifstream recdoc("angles.txt");
	//fichier contenant les angles reconstruits sans objet.
	ifstream sansdoc("angles_rec_sans_obj.txt");
	
	
	while (!recdoc.eof()){
		
		recdoc>>phi_rec>>error_phi_rec>>theta_rec>>error_theta_rec;

		
		
		prod2.Fill(phi_rec,theta_rec);// remplissage de l'histogramme.
		
	}
	while (!sansdoc.eof()){
		sansdoc>>phi>>error_phi>>theta>>error_theta;
		

		
		prod1.Fill(phi,theta); // remplissage de l'histogramme.
		
		
	}
	
	
	graph.cd(2); // placer dans le deuxieme emplacement.
	
	prod2.SetLineColor(8); //choix de la couleur.
	prod2.Draw(); //tracer l'histogramme.
		
	// nom des axes
	prod2.GetXaxis()->SetTitle("angle phi en rad");
	prod2.GetYaxis()->SetTitle("angle theta en rad");
	
	graph.cd(1);// placer dans le premier emplacement.
	
	prod1.SetLineColor(4); //choiox de la couleur.
	prod1.Draw(); // tracer l'histogramme.
	
	//nom des axes.
	prod1.GetXaxis()->SetTitle("angle phi en rad");
	prod1.GetYaxis()->SetTitle("angle theta en rad");

	
	graph.Print("graph_2D.png");  //generer et enregistrer sous ce nom.
}

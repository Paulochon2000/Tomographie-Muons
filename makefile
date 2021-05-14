
chemin = ./runs/

all : compil execute graphs_flux graphs_angles graphs_time deplace clean 


compil: class generation obj plan_1 plans_suivant espace dimension pixels  ajust angle graph_phi graph_theta ecart_phi ecart_theta plans_suivant_sans_obj pixels_sans_obj  ajust_sans_obj angle_sans_obj graph_phi_sans_obj graph_theta_sans_obj 2D temps erreur_phi erreur_theta

class : Muon.cc 
	g++ -c Muon.cc -o Muon.o	
	
generation : generateur.cpp Muon.o
	g++ Muon.o generateur.cpp -o generateur.exe
	
obj : objet.cpp Muon.o
	g++ Muon.o objet.cpp -o objet.exe
	
plan_1 : plan_1.cpp  Muon.o
	g++  Muon.o  plan_1.cpp -o plan_1.exe

plans_suivant: plans_suivant.cpp Muon.o 
	g++  Muon.o  plans_suivant.cpp -o plans_suivant.exe

plans_suivant_sans_obj: plans_suivant_sans_obj.cpp Muon.o 
	g++  Muon.o  plans_suivant_sans_obj.cpp -o plans_suivant_sans_obj.exe

espace : flux_espacement.cpp Muon.o
	g++ Muon.o flux_espacement.cpp -o flux_espacement.exe

dimension : flux_dimension.cpp Muon.o
	g++ Muon.o flux_dimension.cpp -o flux_dimension.exe

pixels : resolution_pixel.cpp
	g++ -o resolution_pixel.exe resolution_pixel.cpp 
	
pixels_sans_obj : resolution_pixel_sans_obj.cpp
	g++ -o resolution_pixel_sans_obj.exe resolution_pixel_sans_obj.cpp 
	
angle : reconstructions_angles.cpp
	g++ -o reconstructions_angles.exe reconstructions_angles.cpp

angle_sans_obj : reconstructions_angles_sans_obj.cpp
	g++ -o reconstructions_angles_sans_obj.exe reconstructions_angles_sans_obj.cpp	

ajust : ajust_lin.cpp
	g++ -o ajust_lin.exe ajust_lin.cpp

ajust_sans_obj : ajust_lin_sans_obj.cpp
	g++ -o ajust_lin_sans_obj.exe ajust_lin_sans_obj.cpp

graph_phi : graph_phi.cpp 	
	g++ graph_phi.cpp `root-config --cflags --glibs` -o graph_phi.exe

graph_theta : graph_theta.cpp
	g++ graph_theta.cpp `root-config --cflags --glibs` -o graph_theta.exe

graph_phi_sans_obj : graph_phi_sans_obj.cpp 	
	g++ graph_phi_sans_obj.cpp `root-config --cflags --glibs` -o graph_phi_sans_obj.exe

graph_theta_sans_obj : graph_theta_sans_obj.cpp
	g++ graph_theta_sans_obj.cpp `root-config --cflags --glibs` -o graph_theta_sans_obj.exe
	

ecart_phi : ecart_phi.cpp
	g++ ecart_phi.cpp `root-config --cflags --glibs` -o ecart_phi.exe
	
ecart_theta : ecart_theta.cpp
	g++ ecart_theta.cpp `root-config --cflags --glibs` -o ecart_theta.exe

erreur_phi : phi_erreur.cpp
	g++ phi_erreur.cpp `root-config --cflags --glibs` -o phi_erreur.exe

erreur_theta : theta_erreur.cpp
	g++ theta_erreur.cpp `root-config --cflags --glibs` -o theta_erreur.exe

2D : graph_2D.cpp
	g++ graph_2D.cpp `root-config --cflags --glibs` -o graph_2D.exe

temps : time.cpp
	g++ -o time.exe time.cpp

	
execute : generateur.exe objet.exe plan_1.exe plans_suivant.exe resolution_pixel.exe ajust_lin.exe reconstructions_angles.exe plans_suivant_sans_obj.exe resolution_pixel_sans_obj.exe ajust_lin_sans_obj.exe reconstructions_angles_sans_obj.exe
	./generateur.exe
	./objet.exe
	./plan_1.exe
	./plans_suivant.exe
	./resolution_pixel.exe
	./ajust_lin.exe
	./reconstructions_angles.exe
	./plans_suivant_sans_obj.exe
	./resolution_pixel_sans_obj.exe
	./ajust_lin_sans_obj.exe
	./reconstructions_angles_sans_obj.exe
	
	
	

graphs_flux : flux_espacement.exe flux_dimension.exe 
	./flux_espacement.exe
	gnuplot flux_esp.gpi
	./flux_dimension.exe
	gnuplot flux_dim.gpi
	
graphs_angles: graph_phi.exe graph_theta.exe ecart_phi.exe ecart_theta.exe graph_phi_sans_obj.exe graph_theta_sans_obj.exe graph_2D.exe phi_erreur.exe theta_erreur.exe
	./graph_phi.exe
	./graph_theta.exe
	./ecart_phi.exe
	./ecart_theta.exe
	./graph_phi_sans_obj.exe
	./graph_theta_sans_obj.exe
	./graph_2D.exe
	./phi_erreur.exe
	./theta_erreur.exe
 
graphs_time : time.exe time.gpi
	./time.exe
	gnuplot time.gpi

open_flux : 
	display ./flux_espacement.png &
	display ./flux_dimension.png &

open_angles:	
	display ./phi_comparaison.png &
	display ./theta_comparaison.png &
	display ./phi_ecart.png &
	display ./theta_ecart.png &
	display ./phi_objet.png &
	display ./theta_objet.png &
	display ./graph_2D.png &
	display ./phi_erreur.png &
	display ./theta_erreur.png &

open_time :
	display ./time.png &
	
deplace : 
	mv -f flux_dim.txt $(chemin)
	mv -f donne_flux.txt $(chemin)flux_espace.txt
	mv -f angles_simule.txt $(chemin)
	mv -f pixel.txt $(chemin)
	mv -f x.txt $(chemin)
	mv -f y.txt $(chemin)
	mv -f x_pixels.txt $(chemin)
	mv -f y_pixels.txt $(chemin)
	mv -f premier_pixels.txt $(chemin)
	mv -f dernier_pixels.txt $(chemin)
	mv -f angles.txt $(chemin)angles_reconstruits.txt
	mv -f angles_rec_sans_obj.txt $(chemin)
	mv -f angles_simule_sans_obj.txt $(chemin)
	mv -f dernier_pixels_sans_obj.txt $(chemin)
	mv -f premier_pixels_sans_obj.txt $(chemin)
	mv -f x_pixels_sans_obj.txt $(chemin)
	mv -f x_sans_obj.txt $(chemin)
	mv -f y_pixels_sans_obj.txt $(chemin)
	mv -f y_sans_obj.txt $(chemin)
	mv -f time.txt $(chemin)
	
clean : 
	rm -f prog *.o
	rm -rf muons_in.txt 
	rm -rf muons_out.txt
	rm -rf nombres.txt
	rm -rf plan_1.txt

running :execute graphs_flux graphs_angles graphs_time deplace clean 

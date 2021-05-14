#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <string>



using namespace std;



int main(){
	
	//recuperons l'ensemble des coordonnees sur les  pixels et sur le pixel en general.
	ifstream x_doc("x_pixels_sans_obj.txt");
	ifstream y_doc("y_pixels_sans_obj.txt");
	ifstream pixel("pixel.txt");
	
	
	// ces fichiers recuperent les coordonnees servant a reconstruire les angles.
	ofstream premier_pixel("premier_pixels_sans_obj.txt");
	ofstream dernier_pixel("dernier_pixels_sans_obj.txt");
	
	//recuperons les donnes sur le systeme. Ces variables sont expliquees dans le document donne.txt.
	int P,N;
	double demi_l, demi_L;
	ifstream donne("donne.txt");
	donne>>P>>N>>demi_l>>demi_L;
	
	double n,m,dx,dy;
	pixel>>n>>m>>dy>>dx;
	dy =dy/sqrt(12);
	double x,y;
	
	//on effectue un ajustement lineaire de la coordonnee y selon celle sur x avec la methode des moindres carres.
	double S, S_x, S_y, S_xx,S_xy;
	double a,b; // coefficients tels que y = a*x+b.
	
	double x_1, x_N; // coordonnees selon x pour le premier et dernier plan.
	double y_1, y_N; // coordonnees selon y pour le premier et dernier plan.
	
	while (!x_doc.eof())
	{
		S = 0;
		S_x = 0;
		S_y = 0;
		S_xx = 0;
		S_xy = 0;
		for (int i=0; i<N;i++)
		{
		
			x_doc>>x;
			y_doc>>y;
			
			if (i==0)
			{
				x_1 = x;
			}
			if (i==N-1)
			{
				x_N=x;
			}
			
			x+=demi_l;
			y+=demi_L;
			
			S += 1./(dy*dy);
			S_x += x / (dy*dy);
			S_y += y / (dy*dy);
			S_xx += x*x / (dy*dy);
			S_xy += y*x /(dy*dy);
		}
	
	
		//on determine les coefficients a et b.
	 	a = (S*S_xy-S_x*S_y)/(S*S_xx-S_x*S_x);
	 	b = (S_xx*S_y - S_x*S_xy)/(S*S_xx- S_x*S_x)-demi_L;
	 	
		//on calcule y_1 et y_N avec l'ajustment lineaire.
	 	y_1 = a*x_1+b;
		y_N = a*x_N+b;	
			
		premier_pixel<<x_1<<"  "<<y_1<<endl;
		dernier_pixel<<x_N<<"  "<<y_N<<endl; 
	 }
}
	  
	 

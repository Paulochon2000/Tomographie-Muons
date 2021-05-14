#ifndef Header_h // identifier
#define Header_h

class Muon{
	private:
	//definition des coordonnees
	double x_;
	double y_;
	//definition des angles
	double phi_;
	double theta_;
	
	public: 
	//constructeur et destructeur.
	Muon(){};
	Muon(double,double,double,double);
	~Muon(){};
	//fonctions
	void init(double,double,double,double); //initialise le muon.
	void avant_plan(double); //permet de deplacer le muon entre l objet et le plan 1.
	void entre_plan(double); // permet de deplacer le muon entre les plans.
	
	
	//Accesseurs
	double Getx() const {return x_;}
	double Gety() const {return y_;}
	double Getphi() const {return phi_;}
	double Gettheta() const {return theta_;}
	};
	
#endif

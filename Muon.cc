#include <iostream>
#include <stdio.h>
#include <cmath>
#include "Muon.h"

using namespace std;

Muon::Muon(double x, double y, double phi, double theta){
	x_ = x;
	y_ = y;
	phi_ = phi;
	theta_ =theta;
	}




void Muon::init(double x, double y,double phi, double theta)
{
	x_ = x;
	y_ = y;
	phi_ = phi;
	theta_ =theta;
	}
	
void Muon::avant_plan(double d_plan)
{
	x_ += cos(phi_)*tan(theta_)*d_plan;
	y_ += sin(phi_)*tan(theta_)*d_plan;
	}
	
void Muon::entre_plan(double intervalle)
{
	x_ += cos(phi_)*tan(theta_)*intervalle;
	y_ += sin(phi_)*tan(theta_)*intervalle;
	}
	


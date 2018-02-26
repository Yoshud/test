#pragma once
#include "Stale.h"
#include "wektor_2D.h"
#include <vector>
////#include "obj_fiz.h"
//#include "obj_fiz_typ.h"
//class obj_fiz;
//class obj_fiz_typ;
class Srodowisko
{
public:
	Srodowisko(double x_min = -pc_to_m, double x_max = pc_to_m, double y_min = -pc_to_m, double y_max = pc_to_m);
	~Srodowisko();
	//sprawdz czy obiekty mieszcza sie w srodowisku
	bool czy_punkt_miesci_sie_w_srodowisku(wektor_2D<double> srodek, double r = 0);
	//bool czy_obiekty_mieszcza_sie_w_srodowisku(vector<obj_fiz*>& obiekty);
protected:
	//granice srodowiska
	double x_min;
	double x_max;
	double y_min;
	double y_max;
};


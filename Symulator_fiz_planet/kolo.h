#pragma once
#include "ksztalt_prosty.h"
class kolo :
	public ksztalt_prosty
{
public:
	//bool sprawdz_zderzenie( kolo* drugi_obj);
	kolo(wektor_2D<double> pozycja = wektor_2D<double>(0,0), double r=0) : ksztalt_prosty(zbior_punktow_opisujacych_figure(pozycja, r)) {}
	~kolo();
protected:
	//wektor_2D<double> polozenie_srodka;
	//double r;
};
 
//kolo adam;

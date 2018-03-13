#pragma once
#include "punkt_materialny_pomocniczy.h"
#include "ksztalt.h"
#include "wektor_2D.h"
#include "kolo.h"
class dane_init_obj_fiz
{
public:
	dane_init_obj_fiz(ksztalt* ksztalt_obiektu, zbior_punktow_materialnych_pomocniczy* punkty_materialne, wektor_2D<double> V = wektor_2D<double>(), double w = 0) : V(V), w(w), ksztalt_obiektu(ksztalt_obiektu), punkty_materialne(punkty_materialne) {}
	dane_init_obj_fiz(wektor_2D<double> polozenie, double masa ,double r, wektor_2D<double> V = wektor_2D<double>(), double w = 0) : V(V), w(w)
	{
		ksztalt_obiektu = new kolo(polozenie, r);
		punkty_materialne = new zbior_punktow_materialnych_pomocniczy(polozenie, masa);
	}
	virtual ~dane_init_obj_fiz() 
	{
		delete ksztalt_obiektu;
	}
	wektor_2D<double> V;
	double w;
	ksztalt* ksztalt_obiektu;
	zbior_punktow_materialnych_pomocniczy* punkty_materialne;
};


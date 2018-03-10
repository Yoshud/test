#pragma once
#include "punkt_materialny_pomocniczy.h"
#include "ksztalt.h"
#include "wektor_2D.h"
class dane_init_obj_fiz
{
public:
	dane_init_obj_fiz(wektor_2D<double> V, double w, ksztalt* ksztalt_obiektu, zbior_punktow_materialnych_pomocniczy* punkty_materialne) : V(V), w(w), ksztalt_obiektu(ksztalt_obiektu), punkty_materialne(punkty_materialne) {}
	virtual ~dane_init_obj_fiz() 
	{
		delete ksztalt_obiektu;
	}
	wektor_2D<double> V;
	double w;
	ksztalt* ksztalt_obiektu;
	zbior_punktow_materialnych_pomocniczy* punkty_materialne;
};


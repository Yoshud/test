#pragma once
#include "wektor_2D.h"
#include <vector>
class punkt_materialny_pomocniczy
{
public:
	punkt_materialny_pomocniczy(double masa, wektor_2D<double> punkt) : masa(masa), punkt(punkt) {}
	punkt_materialny_pomocniczy(): masa(0.0), punkt(wektor_2D<double>()){}
	~punkt_materialny_pomocniczy();
	double masa;
	wektor_2D<double> punkt;
	wektor_2D<double> F_vect;
	
};

class zbior_punktow_materialnych_pomocniczy
{
public:
	zbior_punktow_materialnych_pomocniczy(vector<punkt_materialny_pomocniczy> punkty_materialne) : punkty_materialne(punkty_materialne){}
	//~zbior_punktow_materialnych_pomocniczy();
	
	vector<punkt_materialny_pomocniczy> punkty_materialne;
};

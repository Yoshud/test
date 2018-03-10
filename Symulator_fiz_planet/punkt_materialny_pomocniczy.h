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
	int size() //jesli istnieje wektor zwraca jego rozmiar, jesli nie istnieje zwraca -1
	{ 
		try { return punkty_materialne.size(); }
		catch (...) { return -1; }
	} 
	punkt_materialny_pomocniczy& operator[](int indeks)
	{
		if (size() >= 0 && indeks < size())
			return punkty_materialne[indeks];
		else throw out_of_range(string("Wykroczono poza indeks w zbior_punktow_materialnych_pomocznyczy"));
	}
	vector<punkt_materialny_pomocniczy> punkty_materialne;
};

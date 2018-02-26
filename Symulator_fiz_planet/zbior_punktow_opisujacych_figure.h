#pragma once
#include <vector>
#include "wektor_2D.h"
#include <algorithm>
#include "Srodowisko.h"
//class Srodowisko;
struct kolo_punkt
{
	kolo_punkt(wektor_2D<double> punkt, double r) : punkt(punkt), r(r) {}
	wektor_2D<double> punkt;
	double r;
};

class odcinek
{
public:
	odcinek(wektor_2D<double>* punkt_1, wektor_2D<double>* punkt_2) : punkt_1(punkt_1), punkt_2(punkt_2)
	{
		wspolczynniki();
	}
	wektor_2D<double>* punkt_1;
	wektor_2D<double>* punkt_2;
	double a;
	double b;
	/*	(x1,y1) (x2,y2)
	y1 = ax1 + b
	y2 = ax2 + b
	y1 - y2 = a(x1 - x2)
	a =  (y1 - y2)/(x1-x2)*/

	bool przeciecie(odcinek& drugi_odc)
	{
		//y1 = a1x + b1
		//y2 = a2x + b2
		//a2x + b2 = a1x+b1
		//x = (b1 - b2)/(a2-a1)

		double x = (b - drugi_odc.b) / (drugi_odc.a - a);
		if (nalezy_x(x))
		{
			double y = a * x + b;
			if (nalezy_y(y))
				return true;
		}
		else return false;
	}
	/*bool przeciecie(wektor_2D<double>& punkt)
	{
		if (punkt.get_y() == a * punkt.get_x() + b)
			return true;
		else return false;
	}*/ //do przemyslenia
private:
	void wspolczynniki()
	{
		double a = (punkt_1->get_y() - punkt_2->get_y()) / (punkt_1->get_x() - punkt_2->get_x());
		b = punkt_1->get_y() - a*punkt_1->get_x();
	}

	bool nalezy_x(double x_s)
	{

		if (x_s >= min(punkt_1->get_x(), punkt_2->get_x()) && x_s <= min(punkt_1->get_x(), punkt_2->get_x()))
			return true;
		else
			return false;
	}

	bool nalezy_y(double y_s)
	{
		if (y_s >= min(punkt_1->get_y(), punkt_2->get_y()) && y_s <= min(punkt_1->get_y(), punkt_2->get_y()))
			return true;
		else
			return false;
	}

};


class zbior_punktow_opisujacych_figure
{
public:
	zbior_punktow_opisujacych_figure();
	zbior_punktow_opisujacych_figure(vector<kolo_punkt> punkty): punkty(punkty) {}
	zbior_punktow_opisujacych_figure(wektor_2D<double> pozycja, double r = 0);
	~zbior_punktow_opisujacych_figure();
	vector<kolo_punkt> punkty;
	bool przeciecie(const zbior_punktow_opisujacych_figure& druga_fig); //zdefiniowane tylko dla kol 
	bool sprawdz_wyjscie_poza_granice(Srodowisko& granice);
private:
	//void podziel(vector<>)
};


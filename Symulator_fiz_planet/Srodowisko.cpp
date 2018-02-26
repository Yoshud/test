#include "Srodowisko.h"
#include <string>
using namespace std;


Srodowisko::Srodowisko(double x_min, double x_max, double y_min, double y_max)
{
	if (x_min < x_max)
	{
		this->x_min = x_min;
		this->x_max = x_max;
	}
	else if (x_min > x_max)
	{
		this->x_min = x_max;
		this->x_max = x_min;
	}
	else
		throw string("Niepoprawne wymiary srodowiska (x)");

	if (y_min < y_max)
	{
		this->y_min = y_min;
		this->y_max = y_max;
	}
	else if (y_min > y_max)
	{
		this->y_min = y_max;
		this->y_max = y_min;
	}
	else
		throw string("Niepoprawne wymiary srodowiska (y)");

}

Srodowisko::~Srodowisko()
{
}

bool Srodowisko::czy_punkt_miesci_sie_w_srodowisku(wektor_2D<double> srodek, double r)
{
	if (srodek.get_x() + r < x_max && srodek.get_x() - r > x_min && srodek.get_y() + r < y_max && srodek.get_y() - r > y_min)
		return true;
	else return false;
}
//
//bool Srodowisko::czy_obiekty_mieszcza_sie_w_srodowisku(vector<obj_fiz*>& obiekty)
//{
//	bool flaga = true;
//	for (int i = 0; i < obiekty.size(); i++)
//	{
//	//	if (obiekty[i].)
//		((obj_fiz_typ*)obiekty[i])->sprawdz_wyjscie_poza_granice(this);
//	}
//	return false;
//}
//

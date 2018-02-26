#pragma once
#include "obj_fiz_typ.h"
#include "ksztalt_prosty.h"
#include "kolo.h"
class obiekt_kolowy :
	public obj_fiz_typ
{
public:
	obiekt_kolowy();
	obiekt_kolowy(wektor_2D<double> polozenie, double masa, double r,wektor_2D<double> V_p, double w_p =0);
	//virtual void zaktualizuj_dane(sf::Time& delta_time);
	virtual void zaktualizuj_dane();

	~obiekt_kolowy();
protected: 
	void wylicz_J();
	double r;
};


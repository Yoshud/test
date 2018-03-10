#pragma once
#include "obj_fiz_typ.h"
#include "ksztalt_prosty.h"
#include "kolo.h"
#include "dane_init_obj_fiz.h"
class obiekt_kolowy :
	public obj_fiz_typ
{
public:
	obiekt_kolowy();
	obiekt_kolowy(wektor_2D<double> polozenie, double masa, double r,wektor_2D<double> V_p, double w_p =0);
	obiekt_kolowy(dane_init_obj_fiz dane_init);
	virtual void zaktualizuj_dane();

	~obiekt_kolowy();
protected: 
	void wylicz_J();
	double r;
};


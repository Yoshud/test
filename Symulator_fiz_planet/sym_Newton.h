#pragma once
#include "obj_fiz_sym.h"
#include <cmath>
class sym_Newton :
	public obj_fiz_sym
{
public:
	sym_Newton();
	virtual ~sym_Newton();
	virtual void policz_przemieszczenie();
protected:
	wektor_2D<double> odzialywanie_miedzy_punktami(const punkt_materialny_pomocniczy& punkt_1, const punkt_materialny_pomocniczy& punkt_2); //zwraca wektor bedacy sila dzialajaca na pierwszy punkt, na drugi punkt - przeciwna sila;
};

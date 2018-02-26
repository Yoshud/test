#pragma once
#include "sym_Newton_prosta.h"
#include "sym_Newton_z_skonczona_predkoscia_grawitacji.h"
#include "obiekt_kolowy.h"
class planeta_Newton_prosty :
	public sym_Newton_prosta, 
	public obiekt_kolowy
{
public:
	planeta_Newton_prosty();
	planeta_Newton_prosty(wektor_2D<double> polozenie, double masa, double r, wektor_2D<double> V_p, double w = 0);
	~planeta_Newton_prosty();
};


class planeta_Newton_zloz :
	public sym_Newton_z_skonczona_predkoscia_grawitacji,
	public obiekt_kolowy
{
public:
	planeta_Newton_zloz() {}
	planeta_Newton_zloz(wektor_2D<double> polozenie, double masa, double r, wektor_2D<double> V_p, double w = 0) : obiekt_kolowy(polozenie, masa, r, V_p, w) {}

};
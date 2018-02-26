#include "planeta_Newton_prosty.h"



planeta_Newton_prosty::planeta_Newton_prosty()
{
}

planeta_Newton_prosty::planeta_Newton_prosty(wektor_2D<double> polozenie, double masa, double r, wektor_2D<double> V_p, double w): obiekt_kolowy(polozenie, masa, r, V_p, w)
{
}


planeta_Newton_prosty::~planeta_Newton_prosty()
{
}

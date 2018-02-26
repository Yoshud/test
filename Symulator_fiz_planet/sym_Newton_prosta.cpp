#include "sym_Newton_prosta.h"

sym_Newton_prosta::sym_Newton_prosta()
{
}


void sym_Newton_prosta::oblicz_F(obj_fiz & drugi_obj)
{
	for (int i = 0; i < dane.opisujace_punkty->punkty_materialne.size(); i++)
	{

		for (int j = 0; j < drugi_obj.zwroc_dane().opisujace_punkty->punkty_materialne.size(); j++)
		{
			dane.opisujace_punkty->punkty_materialne[i].F_vect = dane.opisujace_punkty->punkty_materialne[i].F_vect + odzialywanie_miedzy_punktami(dane.opisujace_punkty->punkty_materialne[i], drugi_obj.zwroc_dane().opisujace_punkty->punkty_materialne[j]);
		}
	}
}

void sym_Newton_prosta::zakoncz_cykl_sym()
{
	for (int i = 0; i < dane.opisujace_punkty->punkty_materialne.size(); i++)
	{
		dane.opisujace_punkty->punkty_materialne[i].F_vect = wektor_2D<double>(0, 0);
	}
}



sym_Newton_prosta::~sym_Newton_prosta()
{
}

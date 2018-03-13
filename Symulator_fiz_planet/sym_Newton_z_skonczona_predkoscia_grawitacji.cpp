#include "sym_Newton_z_skonczona_predkoscia_grawitacji.h"



sym_Newton_z_skonczona_predkoscia_grawitacji::sym_Newton_z_skonczona_predkoscia_grawitacji()
{
}


void sym_Newton_z_skonczona_predkoscia_grawitacji::oblicz_F(obj_fiz & drugi_obj)
{
	auto it_1 = dane.opisujace_punkty->punkty_materialne.begin();
	auto tmp = (dynamic_cast <sym_Newton_z_skonczona_predkoscia_grawitacji&> (drugi_obj)).zwroc_stara_pozycje(dane.srodek_masy);
	auto it_2 = tmp.begin();
	auto it_2_end = tmp.end();

	

	for (; it_1 != dane.opisujace_punkty->punkty_materialne.end(); it_1++)
	{
		for (; it_2 != it_2_end; it_2++)
		{
			it_1->F_vect += odzialywanie_miedzy_punktami(*it_1, *it_2);
		}
	}
}

void sym_Newton_z_skonczona_predkoscia_grawitacji::przygotuj_do_symulacji_sym()
{
	aktualne_opoznienie = opoznienie(*dane.opisujace_punkty, delta_time);
}




vector<punkt_materialny_pomocniczy>  sym_Newton_z_skonczona_predkoscia_grawitacji::zwroc_stara_pozycje(const wektor_2D<double>& punkt) 
{
	double d_t = dane.srodek_masy.norma_2(punkt) / c;
	if (opoznienie_maks < sf::seconds(d_t)) opoznienie_maks  = sf::seconds(d_t);
	return aktualne_opoznienie.zwroc_element(sf::seconds(d_t)).punkty_materialne;
}
void sym_Newton_z_skonczona_predkoscia_grawitacji::zakoncz_cykl_sym()
{
	aktualne_opoznienie.dodaj_element(*dane.opisujace_punkty, delta_time);
	for (int i = 0; i < dane.opisujace_punkty->punkty_materialne.size(); i++)
	{
		dane.opisujace_punkty->punkty_materialne[i].F_vect = wektor_2D<double>(0, 0);
	}
	aktualne_opoznienie.usun_zbedne(opoznienie_maks); //przy zalozeniu ze predkosc oddalania sie obiektow nie moze przekroczyc predkosci swiatla 

}

sym_Newton_z_skonczona_predkoscia_grawitacji::~sym_Newton_z_skonczona_predkoscia_grawitacji()
{
}

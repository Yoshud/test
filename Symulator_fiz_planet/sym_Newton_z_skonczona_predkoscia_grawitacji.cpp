#include "sym_Newton_z_skonczona_predkoscia_grawitacji.h"



sym_Newton_z_skonczona_predkoscia_grawitacji::sym_Newton_z_skonczona_predkoscia_grawitacji()
{
//	this->wyznacz_dane();
//	aktualne_opoznienie = opoznienie(*dane.opisujace_punkty);
}

//void sym_Newton_z_skonczona_predkoscia_grawitacji::oblicz_F(obj_fiz & drugi_obj, sf::Time& sym_time)
void sym_Newton_z_skonczona_predkoscia_grawitacji::oblicz_F(obj_fiz & drugi_obj)
{
	auto it_1 = dane.opisujace_punkty->punkty_materialne.begin();
	//auto tmp = (dynamic_cast <sym_Newton_z_skonczona_predkoscia_grawitacji&> (drugi_obj)).zwroc_stara_pozycje(dane.srodek_masy, sym_time).punkty_materialne;
	//auto tmp = (dynamic_cast <sym_Newton_z_skonczona_predkoscia_grawitacji&> (drugi_obj)).zwroc_stara_pozycje(dane.srodek_masy).punkty_materialne;
	auto tmp = (dynamic_cast <sym_Newton_z_skonczona_predkoscia_grawitacji&> (drugi_obj)).zwroc_stara_pozycje(dane.srodek_masy);
	auto it_2 = tmp.begin();
	auto it_2_end = tmp.end();

	

	for (; it_1 != dane.opisujace_punkty->punkty_materialne.end(); it_1++)
	{
		for (; it_2 != it_2_end; it_2++)
		{
			//dane.opisujace_punkty->punkty_materialne[i].F_vect = dane.opisujace_punkty->punkty_materialne[i].F_vect + odzialywanie_miedzy_punktami(dane.opisujace_punkty->punkty_materialne[i], drugi_obj.zwroc_dane().opisujace_punkty->punkty_materialne[j]);
			it_1->F_vect += odzialywanie_miedzy_punktami(*it_1, *it_2);
		}
	}
}

void sym_Newton_z_skonczona_predkoscia_grawitacji::przygotuj_do_symulacji_sym()
{
	aktualne_opoznienie = opoznienie(*dane.opisujace_punkty, delta_time);
}


//zbior_punktow_materialnych_pomocniczy  sym_Newton_z_skonczona_predkoscia_grawitacji::zwroc_stara_pozycje(const wektor_2D<double>& punkt, sf::Time& sym_time) const
//zbior_punktow_materialnych_pomocniczy  sym_Newton_z_skonczona_predkoscia_grawitacji::zwroc_stara_pozycje(const wektor_2D<double>& punkt) const
//{
//	double d_t = dane.srodek_masy.norma_2(punkt) / c;  
//	//return aktualne_opoznienie.zwroc_element(sym_time - sf::seconds(d_t));
//	return aktualne_opoznienie.zwroc_element(sf::seconds(d_t));
//}

vector<punkt_materialny_pomocniczy>  sym_Newton_z_skonczona_predkoscia_grawitacji::zwroc_stara_pozycje(const wektor_2D<double>& punkt) const
{
	double d_t = dane.srodek_masy.norma_2(punkt) / c;
	//return aktualne_opoznienie.zwroc_element(sym_time - sf::seconds(d_t));
	return aktualne_opoznienie.zwroc_element(sf::seconds(d_t)).punkty_materialne;
}
void sym_Newton_z_skonczona_predkoscia_grawitacji::zakoncz_cykl_sym()
{
	aktualne_opoznienie.dodaj_element(*dane.opisujace_punkty, delta_time);
	for (int i = 0; i < dane.opisujace_punkty->punkty_materialne.size(); i++)
	{
		//dane.opisujace_punkty->punkty_materialne[i];
		//aktualne_opoznienie.dodaj_element( *dane.opisujace_punkty)
		dane.opisujace_punkty->punkty_materialne[i].F_vect = wektor_2D<double>(0, 0);
	}

	//aktualne_opoznienie.usun_zbedne(opoznienie_maks);
	//opoznienie_maks = sf::Time::Zero;
}

sym_Newton_z_skonczona_predkoscia_grawitacji::~sym_Newton_z_skonczona_predkoscia_grawitacji()
{
}

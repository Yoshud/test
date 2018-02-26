#pragma once
#include "sym_Newton.h"
#include "opoznienie.h"
class sym_Newton_z_skonczona_predkoscia_grawitacji :
	public sym_Newton
{
public:
	sym_Newton_z_skonczona_predkoscia_grawitacji();
	//virtual void oblicz_F(obj_fiz& drugi_obj, sf::Time& sym_time);
	virtual void oblicz_F(obj_fiz& drugi_obj);
	virtual void przygotuj_do_symulacji_sym();
	//vector<punkt_materialny_pomocniczy>& zwroc_stara_pozycje(const wektor_2D<double>& punkt) const;
	//zbior_punktow_materialnych_pomocniczy zwroc_stara_pozycje(const wektor_2D<double>& punkt, sf::Time& sym_time) const;
	//zbior_punktow_materialnych_pomocniczy zwroc_stara_pozycje(const wektor_2D<double>& punkt) const;
	vector<punkt_materialny_pomocniczy> zwroc_stara_pozycje( const wektor_2D<double>& punkt) const;
	virtual void zakoncz_cykl_sym(); //potrzebny jest do usuwania pozycji i dodawania kolejnych
	~sym_Newton_z_skonczona_predkoscia_grawitacji();
protected:
	//czas maksymalny - ostatnia probka 
	opoznienie aktualne_opoznienie;
	sf::Time opoznienie_maks;
};


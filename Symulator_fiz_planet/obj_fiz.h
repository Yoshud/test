#pragma once
#include "dane_obj.h"
#include "Stale.h"
#include "Srodowisko.h"
#include "przemieszczenie.h"

 class obj_fiz
{
public:
	//virtual ~obj_fiz();

	//zwroc srodek masy, moment pedu, opisujace punkty materialne, czas  (jedna klasa to definiujaca?) 
	virtual void przygotuj_do_symulacji() 
	{
		this->przygotuj_do_symulacji_sym();
		this->przygotuj_do_symulacji_typ();
	}

	// symulacja:
//	virtual void oblicz_F(obj_fiz& drugi_obj, sf::Time& sym_time) = 0;
	virtual void oblicz_F(obj_fiz& drugi_obj) = 0;
//	virtual void policz_przemieszczenie(sf::Time& delta_time) = 0;
	virtual void policz_przemieszczenie() = 0;
	virtual void zakoncz_cykl_sym() = 0;
	virtual void przygotuj_do_symulacji_sym() {}

	//typ:
	//virtual void zaktualizuj_dane(sf::Time& delta_time) = 0; //przemieszczenie obiektu wg. fizyki
	virtual void zaktualizuj_dane() = 0; //przemieszczenie obiektu wg. fizyki
	virtual bool sprawdz_wyjscie_poza_granice(Srodowisko& granice) = 0; //true jesli wyszedl poza
	virtual bool sprawdz_zderzenie(obj_fiz& drugi_obj) = 0;
	virtual void przygotuj_do_symulacji_typ() {}
	//virtual void wyznacz_dane() = 0;
	virtual void zakoncz_cykl_typ() = 0;


	//ogolne:
	static void ustaw_czasy(sf::Time& sym_Time, sf::Time& d_Time)
	{
		sym_time = sym_Time;
		delta_time = d_Time; 
	}
	virtual const dane_obj& zwroc_dane();
	przemieszczenie dane_o_przemieszczeniu; //pozniej przeniesc tylko w celach debug jest tu



	static sf::Time sym_time;
	static sf::Time delta_time;
protected:
	//virtual dane_obj& zwroc_dane();
	dane_obj dane;
	obj_fiz();
	//podstawowe dane obiektu
};


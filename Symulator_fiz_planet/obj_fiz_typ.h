#pragma once
#include "obj_fiz.h"
//#include "Srodowisko.h"
#include "ksztalt.h"
//class Srodowisko;

class obj_fiz_typ: virtual public obj_fiz
{
public:
	obj_fiz_typ();
	//virtual void zaktualizuj_dane(sf::Time& delta_time) = 0; //przemieszczenie obiektu wg. fizyki
	virtual bool sprawdz_wyjscie_poza_granice(Srodowisko& granice);
	virtual bool sprawdz_zderzenie(obj_fiz& drugi_obj);
	virtual void zakoncz_cykl_typ() {}


	//virtual void wyznacz_dane() //funkcja wywolywana zaraz po utworzeniu obiektu, tak by nie bylo mozliwe nie okreslenie danych, problem stanowi nie dziedziczenie kontruktorow i ta funkca sluzy za taki interfejs
	//{
		//this->policz_mase();
		//this->wylicz_J();
		//this->znajdz_srodek();
	//}
	
	//trait - do zrobienia ze dana klasa bedzie cos miala 

	//zwroc opisujace punkty materialne
	//przemiesc 
	//zaktualizuj dane

	virtual ~obj_fiz_typ();
protected:
	ksztalt *ksztalt_opisujacy;
	//virtual void znajdz_srodek()=0;
	//virtual void wylicz_J() = 0;
	//virtual void policz_mase() = 0;
};


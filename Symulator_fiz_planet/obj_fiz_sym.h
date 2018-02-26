#pragma once
#include "obj_fiz.h"
class obj_fiz_sym: virtual public obj_fiz
{
public:
	obj_fiz_sym();
	//policz odzialywania grawitacyjne
	//wektor_2D<double> oblicz_F(); //moze wpisanie do zbioru_punktow 
	//virtual void oblicz_F(obj_fiz& drugi_obj, sf::Time& sym_time) = 0; //moze wpisanie do zbioru_punktow 
	//virtual void policz_przemieszczenie(sf::Time& delta_time) = 0;
	virtual void zakoncz_cykl_sym() {}
	virtual ~obj_fiz_sym();


};


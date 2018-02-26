#pragma once
#include "ksztalt.h"
#include "zbior_punktow_opisujacych_figure.h"
class ksztalt_prosty :
	public ksztalt
{
public:
	virtual ~ksztalt_prosty();
//protected:
	ksztalt_prosty();
	ksztalt_prosty(zbior_punktow_opisujacych_figure zbior) : zbior_punktow(zbior){}
	bool sprawdz_zderzenie(ksztalt* drugi_obj);
	virtual bool sprawdz_wyjscie_poza_granice(Srodowisko& granice);

protected:
	bool sprawdz_zderzenie_z(zbior_punktow_opisujacych_figure& fig);
	zbior_punktow_opisujacych_figure zbior_punktow;
};


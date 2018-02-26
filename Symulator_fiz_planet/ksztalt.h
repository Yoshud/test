#pragma once
#include "wektor_2D.h"
#include "Srodowisko.h"
#include <vector>
#include "zbior_punktow_opisujacych_figure.h"
using namespace std;


class ksztalt
{
public:
	virtual bool sprawdz_zderzenie(ksztalt* drugi_obj) = 0;
	virtual bool sprawdz_zderzenie_z(zbior_punktow_opisujacych_figure& fig) = 0;

	virtual bool sprawdz_wyjscie_poza_granice(Srodowisko& granice) = 0;
	//wyswietl
	virtual ~ksztalt();
protected:
	ksztalt();
};


#pragma once
#include "obj_fiz.h"
#include "ksztalt.h"


class obj_fiz_typ: virtual public obj_fiz
{
public:
	obj_fiz_typ();
	virtual bool sprawdz_wyjscie_poza_granice(Srodowisko& granice);
	virtual bool sprawdz_zderzenie(obj_fiz& drugi_obj);
	virtual void zakoncz_cykl_typ() {}


	virtual ~obj_fiz_typ();
protected:
	ksztalt *ksztalt_opisujacy;
};


#include "obj_fiz_typ.h"



obj_fiz_typ::obj_fiz_typ()
{
}

bool obj_fiz_typ::sprawdz_wyjscie_poza_granice(Srodowisko& granice) //true jesli wyszedl
{
	return ksztalt_opisujacy->sprawdz_wyjscie_poza_granice(granice);
}

bool obj_fiz_typ::sprawdz_zderzenie(obj_fiz & drugi_obj)
{
	return ksztalt_opisujacy->sprawdz_zderzenie( (dynamic_cast<obj_fiz_typ&>(drugi_obj)).ksztalt_opisujacy); //true gdy wystepuje
}


obj_fiz_typ::~obj_fiz_typ()
{
	delete ksztalt_opisujacy;
}

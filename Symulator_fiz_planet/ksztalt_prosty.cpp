#include "ksztalt_prosty.h"



ksztalt_prosty::ksztalt_prosty()
{
}


ksztalt_prosty::~ksztalt_prosty()
{
}

bool ksztalt_prosty::sprawdz_zderzenie(ksztalt * drugi_obj)
{
	return drugi_obj->sprawdz_zderzenie_z(zbior_punktow);
}

bool ksztalt_prosty::sprawdz_wyjscie_poza_granice(Srodowisko & granice)
{
	return zbior_punktow.sprawdz_wyjscie_poza_granice(granice); 
}

bool ksztalt_prosty::sprawdz_zderzenie_z(zbior_punktow_opisujacych_figure & fig)
{
	return fig.przeciecie(zbior_punktow); //ksztalt zlozony sprawdza dla wszystkich 
}



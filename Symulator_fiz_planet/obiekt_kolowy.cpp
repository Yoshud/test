#include "obiekt_kolowy.h"



obiekt_kolowy::obiekt_kolowy()
{
}


obiekt_kolowy::obiekt_kolowy(wektor_2D<double> polozenie, double masa, double r, wektor_2D<double> V_p, double w_p) :r(r)
{
	dane.srodek_masy = polozenie;
	dane.masa = masa;
	dane_o_przemieszczeniu.v = V_p;
	dane_o_przemieszczeniu.w = w_p;
	dane.opisujace_punkty = new zbior_punktow_materialnych_pomocniczy(vector<punkt_materialny_pomocniczy> {punkt_materialny_pomocniczy(masa, polozenie)});
	ksztalt_opisujacy = new kolo(polozenie, r);
	wylicz_J();
}

obiekt_kolowy::obiekt_kolowy(dane_init_obj_fiz dane_init)
{
	if (dane_init.punkty_materialne->size() != 1);
		//throw <jakis_wyjatek>
	else
	{
		dane.masa = (*dane_init.punkty_materialne)[0].masa;
		dane.srodek_masy = (*dane_init.punkty_materialne)[0].punkt;
		dane_o_przemieszczeniu.v = dane_init.V;
		dane_o_przemieszczeniu.w = dane_init.w;
		dane.opisujace_punkty = dane_init.punkty_materialne;
		ksztalt_opisujacy = dane_init.ksztalt_obiektu;
		wylicz_J();
	}
}

void obiekt_kolowy::zaktualizuj_dane()
{
	dane.srodek_masy += dane_o_przemieszczeniu.v * (double)delta_time.asSeconds();
	dane.opisujace_punkty->punkty_materialne[0].punkt += dane_o_przemieszczeniu.v * (double)delta_time.asSeconds();
}

obiekt_kolowy::~obiekt_kolowy()
{
}


void obiekt_kolowy::wylicz_J()
{
	dane.moment_pedu = 3.0 / 5.0 * r * r * dane.masa; //po policzeniu calki 
}



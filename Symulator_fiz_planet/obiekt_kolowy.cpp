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
	//dane.opisujace_punkty->punkty_materialne.push_back(punkt_materialny_pomocniczy(masa, polozenie));
	dane.opisujace_punkty = new zbior_punktow_materialnych_pomocniczy(vector<punkt_materialny_pomocniczy> {punkt_materialny_pomocniczy(masa, polozenie)});
	//ksztalt_opisujacy = new ksztalt_prosty(zbior_punktow_opisujacych_figure(vector<kolo_punkt> {kolo_punkt(polozenie, r)}));
	ksztalt_opisujacy = new kolo(polozenie, r);
	wylicz_J();
}

//void obiekt_kolowy::zaktualizuj_dane(sf::Time& delta_time)
void obiekt_kolowy::zaktualizuj_dane()
{
	//przemieszczenie obiektu
	//F = ma  a = f/m  v = a*t  v = f/m * t, r = r + v*t 
	dane.srodek_masy += dane_o_przemieszczeniu.v * (double)delta_time.asSeconds();
	dane.opisujace_punkty->punkty_materialne[0].punkt += dane_o_przemieszczeniu.v * (double)delta_time.asSeconds();
}

obiekt_kolowy::~obiekt_kolowy()
{
}


void obiekt_kolowy::wylicz_J()
{
	//dane.moment_pedu = 3.0 / 5.0 * (dynamic_cast<ksztalt_prosty*> (ksztalt_opisujacy))->  //  * r * r * m
	dane.moment_pedu = 3.0 / 5.0 * r * r * dane.masa; //po policzeniu calki 
}



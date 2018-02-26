#include "zbior_punktow_opisujacych_figure.h"
#include <string>
using namespace std;

zbior_punktow_opisujacych_figure::zbior_punktow_opisujacych_figure()
{
}


zbior_punktow_opisujacych_figure::zbior_punktow_opisujacych_figure(wektor_2D<double> pozycja, double r)
{
	//punkty.push_back(kolo_punkt(pozycja, r));
	punkty = vector<kolo_punkt>{kolo_punkt(pozycja,r)};
}

zbior_punktow_opisujacych_figure::~zbior_punktow_opisujacych_figure()
{
}

bool zbior_punktow_opisujacych_figure::przeciecie(const zbior_punktow_opisujacych_figure & druga_fig)
{
	druga_fig.punkty;
	if (punkty.size() < 1 || druga_fig.punkty.size() < 1)
		throw string("blad zwiazany z opisem figur");
	if ((punkty.size() == 1) && (druga_fig.punkty.size() == 1))
	{
		//dwa kola
		if (punkty[0].punkt.norma_2(druga_fig.punkty[0].punkt) < (punkty[0].r + druga_fig.punkty[0].r)) //odleglosc miedzy punktami mniejsza niz suma promieni
			return true;
		else
			return false;
	}
	//2 wielokaty	
	else if ((punkty.size() > 1) && (druga_fig.punkty.size() > 1))
	{
		
		//utworzenie z obu figur vectora odcinkow i uzycie ich do sprawdzenia przeciec
	}
	else //wielokat i kolo
	{
		if (punkty.size() > 1); //pierwsza figura jest wielokatem
		else; //druga figura jest wielokatem

	}
	return false;
}

bool zbior_punktow_opisujacych_figure::sprawdz_wyjscie_poza_granice(Srodowisko& granice)
{
	for (int i = 0; i < punkty.size(); i++)
	{
		if (!(granice.czy_punkt_miesci_sie_w_srodowisku(punkty[i].punkt, punkty[i].r)))
			return true;
	}
	return false;
}

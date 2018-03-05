#include "Symulacja.h"


void Symulacja::symuluj()
{
	obj_fiz::ustaw_czasy(zegar_sym, krok);
	auto it_1 = obiekty.begin();
	auto it_2 = obiekty.begin();
	for (; it_1 != obiekty.end(); it_1++) (*it_1)->przygotuj_do_symulacji();
	while (warunki_stopu.czy_warunki_spelnione(obiekty, obszar, krok, zegar_sym))
	{
		it_1 = obiekty.begin();
		it_2 = obiekty.begin();
		obj_fiz::ustaw_czasy(zegar_sym, krok);
		//wlasciwa symulacja
		for (it_1 = obiekty.begin(); it_1 != obiekty.end(); it_1++)
		{
			for (it_2 = obiekty.begin(); it_2 != obiekty.end(); it_2++)
			{
				if (it_1 != it_2)
				(*it_1)->oblicz_F(*(*it_2));
			}
			
		}
		for (it_1 = obiekty.begin(); it_1 != obiekty.end(); it_1++)
		{
			(*it_1)->policz_przemieszczenie();
			(*it_1)->zaktualizuj_dane();
			(*it_1)->zakoncz_cykl_sym();
			(*it_1)->zakoncz_cykl_typ();
		}

		if (!((int)zegar_sym.asSeconds() % (3600 * 24)) || (int)zegar_sym.asSeconds() == 0)

			cout << zegar_sym.asSeconds() / 3600 / 24 << " , " << (*--it_1)->sym_time.asSeconds() / 3600 / 24 << " , " << (*(obiekty.end() - 1))->zwroc_dane().srodek_masy.get_x() / 1e11 << " , " << (*(obiekty.end() - 1))->zwroc_dane().srodek_masy.get_y() / 1e11 << " , " << (*(obiekty.end() - 2))->zwroc_dane().opisujace_punkty->punkty_materialne[0].F_vect.get_y() << endl;  //*obiekty.end())->zwroc_dane().srodek_masy.get_y()/1e11 
		zegar_sym += krok;
	}
}

Symulacja::~Symulacja()
{
}

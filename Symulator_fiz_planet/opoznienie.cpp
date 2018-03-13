#include "opoznienie.h"


opoznienie::opoznienie(zbior_punktow_materialnych_pomocniczy punkty, sf::Time d_time)
{
	zbior_poprzednich.push_back(element(punkty, d_time));
}

void opoznienie::dodaj_element(zbior_punktow_materialnych_pomocniczy punkty, sf::Time d_time)
{
	zbior_poprzednich.push_back(element(punkty, d_time));
}

zbior_punktow_materialnych_pomocniczy opoznienie::zwroc_element(sf::Time opoznienie_czas) const
{
	auto it = zbior_poprzednich.rbegin();
	sf::Time suma_opoznien;
	for (; it != zbior_poprzednich.rend(); it++)
	{
		suma_opoznien += it->d_time;
		if (opoznienie_czas < suma_opoznien)
		{
			break;
		}
	}
	if(it == zbior_poprzednich.rend())
		it--;
	auto debug = it->punkty;
	return debug;

}

void opoznienie::usun_zbedne(sf::Time d_t)
{
	if (zbior_poprzednich.size() > 1)
	{
		sf::Time suma_opoznien;
		auto it = --zbior_poprzednich.end();
		for (; it != zbior_poprzednich.begin(); it--)
		{
			suma_opoznien += it->d_time;
			if (d_t < suma_opoznien)
				break;
		}

		if (it != zbior_poprzednich.begin()) //nie usuwamy gdy doszlismy do konca bo byslmy usuwali zawsze, w najgorszym wypadku odwleczemy usuniêcie o parê iteracji
		{
			zbior_poprzednich.erase(zbior_poprzednich.begin(), it); 
		}
	}
	else return;
}


opoznienie::~opoznienie()
{
}

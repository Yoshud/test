#pragma once 
#include "punkt_materialny_pomocniczy.h"
#include "SFML/System.hpp"
#include <list>
class opoznienie
{
	class element
	{
	public:
		element(zbior_punktow_materialnych_pomocniczy punkty, sf::Time d_time) : punkty(punkty), d_time(d_time) {}
		/*zbior_punktow_materialnych_pomocniczy& opoznione_punkty()
		{
			return punkty;
		}*/

	//protected:
		zbior_punktow_materialnych_pomocniczy punkty;
		sf::Time d_time;
	};
public:
	opoznienie() {}
	opoznienie(zbior_punktow_materialnych_pomocniczy punkty, sf::Time d_time = sf::Time::Zero);
	void dodaj_element(zbior_punktow_materialnych_pomocniczy punkty, sf::Time d_time);
	zbior_punktow_materialnych_pomocniczy zwroc_element(sf::Time opoznienie_czas) const;
	void usun_zbedne(sf::Time d_t);
	~opoznienie();
protected:
	list<element> zbior_poprzednich;
	
};

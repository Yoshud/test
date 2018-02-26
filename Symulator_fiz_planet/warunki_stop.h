#pragma once
#include "obj_fiz.h"
#include <list>
#include <vector>
//#include <boost>
class warunek_stop
{
public:

	virtual int zwroc_numer() = 0;
	//virtual bool czy_spelniony(obj_fiz* obiekt) = 0;
	virtual bool czy_spelniony(vector<obj_fiz*>& obiekty, Srodowisko& granice, sf::Time& delta_time, sf::Time& sym_time) = 0; //true jesli kontynuowac symulacje
	

protected:
	warunek_stop() {}
};


class warunki_stop
{
public:
	warunki_stop() : suma_warunkow(0), warunki(list <warunek_stop*>()) {}
	void dodaj_warunek_stop( warunek_stop* nowy_warunek)
	{
		auto it = warunki.begin();
		for (; it != warunki.end(); it++)
		{
			if ((*it)->zwroc_numer() == nowy_warunek->zwroc_numer())
			{
				delete nowy_warunek;  //plus jakis wyjatek?
				cout << "Warunek tego typu juz istnieje" << endl;
				return;
			}
		}
		warunki.push_back(nowy_warunek);
	}
	~warunki_stop();
protected:
	int suma_warunkow;
	list <warunek_stop*> warunki; 
};


class wyjscie_poza_srodowisko: public warunek_stop
{
	const static int numer = 1;
public:
	virtual int zwroc_numer() { return numer; }
	virtual bool czy_spelniony(vector<obj_fiz*>& obiekty, Srodowisko& granice, sf::Time& delta_time, sf::Time& sym_time)
	{
		for (auto it = obiekty.begin(); it != obiekty.end(); it++)
		{
			if ((*it)->sprawdz_wyjscie_poza_granice(granice))  //jesli wyjdzie poza granice przerwij 
				return true;
		}
		return true;
	}
};

class limit_czasu : public warunek_stop
{
	const static int numer = 2;
public:
	limit_czasu(sf::Time limit) : limit(limit) {}
	virtual int zwroc_numer() { return numer; }
	virtual bool czy_spelniony(vector<obj_fiz*>& obiekty, Srodowisko& granice, sf::Time& delta_time, sf::Time& sym_time)
	{
		if (sym_time > limit)
			return false;
		else
			return true;
	}
private:
	sf::Time limit;
};

class zderzenia: public warunek_stop
{
	const static int numer = 4;
public:
	virtual int zwroc_numer() { return numer; }
	virtual bool czy_spelniony(vector<obj_fiz*>& obiekty, Srodowisko& granice, sf::Time& delta_time, sf::Time& sym_time)
	{
		if (obiekty.size() < 1)
			return true;
		auto it_1 = obiekty.begin();
		auto it_2 = obiekty.begin();
		it_2++;
		for (; it_1 != obiekty.end(); it_1++)
		{
			for (it_2 = (it_1 + 1); it_2 != obiekty.end(); it_2++)
			{
				if ((*it_1)->sprawdz_zderzenie(*(*it_2))) //jesli jakiekolwiek zderzenie wystepujeprerwij symulacje
					return false;
			}
		}
		return true;
	}
};
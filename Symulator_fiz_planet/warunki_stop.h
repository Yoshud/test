#pragma once
#include "obj_fiz.h"
#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class warunek_stop_unique
{
public:

	virtual string zwroc_klucz() const = 0; //wymagane jest by byly unikalne, najbezpieczniej jest definiowaæ stringi identyczne jak nazwa klasy gdy nastapi konflikt kompilatora to znaczy iz nalezy zmienic nazwe klasy i napis
	virtual bool czy_spelniony(vector<obj_fiz*>& obiekty, Srodowisko& granice, sf::Time& delta_time, sf::Time& sym_time) = 0; //true jesli kontynuowac symulacje
	bool operator<( const warunek_stop_unique& drugi_warunek)
	{
		if (this->zwroc_klucz() == drugi_warunek.zwroc_klucz())
			return true;
		return false;
	}

protected:
	warunek_stop_unique() {}
};


class warunki_stop //pozwala podpinac i odpinac warunki konca symulacji posluujac sie ich aliasami, umozliwia definiowanie wlasnych warunkow symulacji dzedzicz¹cych po warunek_stop_unique (tylko jeden taki warunek moze istniec na symulacje) (w przyszlosci rowniez warunek_stop_ununique)
{
public:
	warunki_stop() : suma_warunkow(0), warunki(unordered_map<string, warunek_stop_unique*>()) {}

	void dodaj_warunek_stop( warunek_stop_unique* nowy_warunek)
	{
		warunki[nowy_warunek->zwroc_klucz()] = nowy_warunek;
	}

	bool czy_warunki_spelnione(vector<obj_fiz*>& obiekty, Srodowisko& granice, sf::Time& delta_time, sf::Time& sym_time)
	{
		for each (auto warunek in warunki)
		{
			if (warunek.second->czy_spelniony(obiekty, granice, delta_time, sym_time)==false)
				return false;
		}
		return true; //kontynuowac symulacje jesli zaden z warunkow nie zwrocil false
	}

	void usun_warunek_stop(string alias)
	{
		warunki.erase(alias);
	}
	~warunki_stop();
protected:
	int suma_warunkow;
	unordered_map<string, warunek_stop_unique*> warunki; //uzycie map zamiast set pozwala uniknac potrzeby pisania funkcji compare przy uzywaniu wskaznikow ppotrzebnych do uzycia polimorfizmu. Pozwala ona na szybkie wyszukiwanie i aktualizacje warunków z wykorzystaniem aliasu (co mo¿e byæ przydatne gdybyœmy chcieli co iteracje zmieniaæ warunek), oraz zazwyczaj iterowanie po warunkach (zazwyczaj ich ilosc nie powinna byc wysoka) w czasie liniowym
};


class wyjscie_poza_srodowisko: public warunek_stop_unique
{
public:
	virtual string zwroc_klucz() const { return "wyjscie_poza_srodowisko"; }
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

class limit_czasu : public warunek_stop_unique
{
public:
	limit_czasu(sf::Time limit) : limit(limit) {}
	virtual string zwroc_klucz() const { return "limit_czasu"; }
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

class zderzenia: public warunek_stop_unique
{
public:
	virtual string zwroc_klucz() const { return "zderzenia"; }
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
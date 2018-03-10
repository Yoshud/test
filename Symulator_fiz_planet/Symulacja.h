#pragma once
#include "Stale.h"
#include "obj_fiz.h"
#include "planeta_Newton_prosty.h"
#include <vector>
#include "warunki_stop.h"
#include "SFML\System.hpp"
#include "dane_init_obj_fiz.h"
#include <unordered_map>
class dane_o_obj_do_bazy
{
public:
	dane_init_obj_fiz opis_obiektu;
	unsigned int indeks_obj; //stosujemy indeks poniewaz w przypadku vectora nie ma gwarancji sta�o�ci iteratora, a u�ywanie listy ze wzgl�du na rozrzucenie po pami�ci b�dzie wolniejsze (predyktor w procesorze znacznie lepiej radzi sobie z tablicami), dodawani i usuwanie obiektow bedzie rzadkim procesem
};

using namespace std;
class Symulacja
{
public:
	Symulacja() : zegar_sym(sf::Time::Zero), krok(sf::seconds(60)) {}
	void dodaj_obj(obj_fiz* obj) //metoda powsta�a na rzecz test�w, wraz z wprowadzeniem systemu zwi�zanego z map� kt�ra pozwoli przenie�c logik� do wn�trza tej klasy zniknie, bo jest b��dogenna
	{
		obiekty.push_back(obj);
	}
	void symuluj(); 
	void dodaj_warunek_stop(warunek_stop_unique* warunek) { warunki_stopu.dodaj_warunek_stop(warunek); } //wywoluje si� konstrukcj�:  new <nazwa klasy warunku stop>(<parametry wywolania warunku>) np. new limit_czasu(sf::hour = 24) 
	void usun_warunek(string alias) { warunki_stopu.usun_warunek_stop(alias); } //wywoluje sie podajac jako alias nazwe klasy warunku - analogicznie do python (chyba ze podczas definiowania wlasnego warunku uzna sie inaczej)
	void ustaw_krok_czasowy(const sf::Time& nowy_krok) { krok = nowy_krok; }
	//ustal typ symulacji
	//zmien typ symulacji
	virtual ~Symulacja();
private:
	unordered_map<string, dane_o_obj_do_bazy> baza; //prosta "baza danaych" obiektow oparta na tablicy heszuj�cej, aktualizacja danych w trakcie usuwania obiektu, dodawania, podgl�dania i zmianie typu symulacji, przez reszte czasu pelne(uszczegulowione do obj_fiz) dane trzyma vector z wzgledow wydajnosciowych 
	warunki_stop warunki_stopu;
	Srodowisko obszar;
	vector<obj_fiz*> obiekty;
	sf::Time zegar_sym;
	sf::Time krok;
};


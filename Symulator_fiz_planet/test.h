#pragma once
#include "Symulacja.h"
#include <assert.h>
class test
{
public:
	test();
	bool operator()();
	bool test_dodawania_2_obiektow();
	bool test_powrotu_Ziemi();
	bool test_dealokacji_pamieci();
	bool test_zmiany_typu_symulacji();
	bool test_kolizji();
	virtual ~test();
protected:
	Symulacja sym;
};


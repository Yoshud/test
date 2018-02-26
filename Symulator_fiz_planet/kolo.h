#pragma once
#include "ksztalt_prosty.h"
class kolo :
	public ksztalt_prosty
{
public:

	kolo(wektor_2D<double> pozycja = wektor_2D<double>(0,0), double r=0) : ksztalt_prosty(zbior_punktow_opisujacych_figure(pozycja, r)) {}
	~kolo();
protected:
};
 


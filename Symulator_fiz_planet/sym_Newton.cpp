#include "sym_Newton.h"



sym_Newton::sym_Newton()
{
}


sym_Newton::~sym_Newton()
{
}

//void sym_Newton::policz_przemieszczenie(sf::Time& delta_time)
void sym_Newton::policz_przemieszczenie()
{
	auto it = dane.opisujace_punkty->punkty_materialne.begin();
	//for (int i = 0; i < dane.opisujace_punkty->punkty_materialne.size(); i++)
	for (; it != dane.opisujace_punkty->punkty_materialne.end(); it++)
	{
		dane_o_przemieszczeniu.v += it->F_vect * ( delta_time.asSeconds() / dane.masa);  //V = F*t/m
		dane_o_przemieszczeniu.w += (it->punkt - dane.srodek_masy).iloczyn_wektorowy_2D(it->F_vect) / dane.moment_pedu; //dw = M/J, M = r x F, r = punkt - sr_masy //wektor od sr_masy do punktu 
	}

}

wektor_2D<double> sym_Newton::odzialywanie_miedzy_punktami(const punkt_materialny_pomocniczy& punkt_1, const punkt_materialny_pomocniczy& punkt_2)
{
	//Gm1m2/r^2
	//double debug = punkt_1.punkt.norma_2(punkt_2.punkt);
	//double dbug_2 = (pow(punkt_1.punkt.norma_2(punkt_2.punkt), 2));
	double F = -G * punkt_1.masa * punkt_2.masa / ( pow(punkt_1.punkt.norma_2(punkt_2.punkt), 2));
	return ((punkt_1.punkt - punkt_2.punkt).normalizuj() * F);
}

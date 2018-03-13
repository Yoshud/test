#include "test.h"



test::test()
{
}

bool test::operator()()
{
	sym = Symulacja();
	if (!(
		test_dodawania_2_obiektow() &&
		test_powrotu_Ziemi() &&
		test_dealokacji_pamieci() &&
		test_zmiany_typu_symulacji() &&
		test_kolizji()
		))
		return false;
	else return true;
}
bool test::test_dodawania_2_obiektow()
{
//	wektor_2D<double> V, double w, ksztalt* ksztalt_obiektu, zbior_punktow_materialnych_pomocniczy* punkty_materialne
	dane_init_obj_fiz Slonce(new kolo(wektor_2D<double>(0, 0),6.96342e8), new zbior_punktow_materialnych_pomocniczy(wektor_2D<double>(0, 0), 1.98855e30));
	dane_init_obj_fiz Ziemia(wektor_2D<double>(1.49504e11, 0), 5.96e24, 6.371e6, wektor_2D<double>(0, 2.978e4));
	sym.dodaj_obj("Slonce", Slonce);
	//try
	//{
	//	sym.dodaj_obj("Slonce", Ziemia);
	//	return false; //powinien byc wyrzucony wyjatek
	//}
	//catch (obiekt_o_aliasie_juz_istnieje())
	//	return true;
	//catch (...)
	//	return false;
}
bool test::test_powrotu_Ziemi()
{
	return false;
}
bool test::test_dealokacji_pamieci()
{
	return false;
}
bool test::test_zmiany_typu_symulacji()
{
	return false;
}
bool test::test_kolizji()
{
	return false;
}
test::~test()
{
}

#include <vector>
#include "wektor_3D.h"
#include "wektor_2D.h"
#include "Symulacja.h"
#include <iostream>
#include "planeta_Newton_prosty.h"
#include <SFML/Graphics.hpp>


/*
Prosty projekt, rozwijany samodzielnie w czasie wolnym w ramach nauki programowania obiektowego (akurat w C++). Na chwil� obecn� pracuj� nad sensownym interfejsem klasy Symulacja i chc� wprowadzi� pewne testy automatyczne. 
Za�o�eniami projektu by�o stworzenie prostego symulatora fizyki (na chwil� obecn� to okre�lenie jest sporo na wyrost, gdy� jedyn� symulowan� si�� jest grawitacja),
kt�ry b�dzie z zewn�trz widoczny na takim poziomie abstrakcji by mo�na by�o �atwo zmieni� typ symulacji i spos�b jej dzia�ania,
lub doda� nowet typy obiekt�w (w planach jest algorytm kt�ry rekurencyjnie b�dzie potrafi� dzieli� obiekty na mniejsze (uproszczona wersja metody element�w sko�czonych)).
St�d podzia� na dwie oddzielne klasy, kt�ry ma na celu umo�liwienie �atwej zmiany i dodawania nowych rzeczy w dziedzinie symulacji b�d� definicji obiektu. (Wykorzystuje tu mieszank� i w�asn� woln� interpretacji� modeli projektowych:
fabryki (np. jeszcze nie stworzona funkcja dodaj_obiekt), builder(ca�e drzewo obj_fiz i Symulacja jako budowniczy), czy strategii (ca�a Symulacja z zewn�trz jest postrzegana wg. tego wzorca projektowego)
Na chwil� obecn� brakuje (ale s� w planach): wielu komentarzy, obs�ugi wyj�tk�w, interfejsu klasy Symulacja, test�w automatycznych, przeniesienia tego na automatyczne wska�niki. 
Dodatkowe featery planowane do dodania to: wy�wietlanie tego z wykorzystaniem biblioteki SFML, dodanie symulacji FES, dodanie symulacji relatywistycznej, stworzenie fizyki zderze�, stworzenie klasy odpowiedzialnej za UI

*/

using namespace std;
int main()
{
//	planeta_Newton_prosty Slonce (wektor_2D<double> (0, 0), 1.98855e30, 6.96342e8, wektor_2D<double>(0, 0));  //1.49504e11
//	planeta_Newton_prosty Ziemia(wektor_2D<double>(1.49504e11, 0), 5.96e24, 6.371e6, wektor_2D<double>(0, 2.978e4));
	planeta_Newton_zloz Slonce(wektor_2D<double>(0, 0), 1.98855e30, 6.96342e8, wektor_2D<double>(0, 0)); 
	planeta_Newton_zloz Ziemia(wektor_2D<double>(1.49504e11, 0), 5.96e24, 6.371e6, wektor_2D<double>(0, 2.978e4));
	planeta_Newton_zloz Mars(wektor_2D<double>(2.2792e11, 0), 6.417e23, 3.396e6, wektor_2D<double>(0, 2.407e4));
	Symulacja sym;
	sym.dodaj_obj(&Slonce); //taki spos�b dodawania zniknie w trakcie rozwoju na rzecz bardziej zhermetyzowanego rozwi�zania 
	sym.dodaj_obj(&Ziemia);
	sym.dodaj_obj(&Mars);
	sym.symuluj();

	// proba SFML (osi�galna po wyj�ciu z p�tli w symuluj)
	
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}


	system("PAUSE");
	return 0;
}
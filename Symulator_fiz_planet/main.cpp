#include <vector>
#include "wektor_3D.h"
#include "wektor_2D.h"
#include "Symulacja.h"
#include <iostream>
#include "planeta_Newton_prosty.h"
#include <SFML/Graphics.hpp>


/*
Prosty projekt, rozwijany samodzielnie w czasie wolnym w ramach nauki programowania obiektowego (akurat w C++). Na chwilê obecn¹ pracujê nad sensownym interfejsem klasy Symulacja i chcê wprowadziæ pewne testy automatyczne. 
Za³o¿eniami projektu by³o stworzenie prostego symulatora fizyki (na chwilê obecn¹ to okreœlenie jest sporo na wyrost, gdy¿ jedyn¹ symulowan¹ si³¹ jest grawitacja),
który bêdzie z zewn¹trz widoczny na takim poziomie abstrakcji by mo¿na by³o ³atwo zmieniæ typ symulacji i sposób jej dzia³ania,
lub dodaæ nowet typy obiektów (w planach jest algorytm który rekurencyjnie bêdzie potrafi³ dzieliæ obiekty na mniejsze (uproszczona wersja metody elementów skoñczonych)).
St¹d podzia³ na dwie oddzielne klasy, który ma na celu umo¿liwienie ³atwej zmiany i dodawania nowych rzeczy w dziedzinie symulacji b¹dŸ definicji obiektu. (Wykorzystuje tu mieszankê i w³asn¹ woln¹ interpretacjiê modeli projektowych:
fabryki (np. jeszcze nie stworzona funkcja dodaj_obiekt), builder(ca³e drzewo obj_fiz i Symulacja jako budowniczy), czy strategii (ca³a Symulacja z zewn¹trz jest postrzegana wg. tego wzorca projektowego)
Na chwilê obecn¹ brakuje (ale s¹ w planach): wielu komentarzy, obs³ugi wyj¹tków, interfejsu klasy Symulacja, testów automatycznych, przeniesienia tego na automatyczne wskaŸniki. 
Dodatkowe featery planowane do dodania to: wyœwietlanie tego z wykorzystaniem biblioteki SFML, dodanie symulacji FES, dodanie symulacji relatywistycznej, stworzenie fizyki zderzeñ, stworzenie klasy odpowiedzialnej za UI

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
	sym.dodaj_obj(&Slonce); //taki sposób dodawania zniknie w trakcie rozwoju na rzecz bardziej zhermetyzowanego rozwi¹zania 
	sym.dodaj_obj(&Ziemia);
	sym.dodaj_obj(&Mars);
	sym.symuluj();

	// proba SFML (osi¹galna po wyjœciu z pêtli w symuluj)
	
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
#include <vector>
#include "wektor_3D.h"
#include "wektor_2D.h"
#include "Symulacja.h"
#include <iostream>
#include "planeta_Newton_prosty.h"
//#include <time.h>
#include <SFML/Graphics.hpp>
using namespace std;
int main()
{
//	planeta_Newton_prosty Slonce (wektor_2D<double> (0, 0), 1.98855e30, 6.96342e8, wektor_2D<double>(0, 0));  //1.49504e11
//	planeta_Newton_prosty Ziemia(wektor_2D<double>(1.49504e11, 0), 5.96e24, 6.371e6, wektor_2D<double>(0, 2.978e4));
	planeta_Newton_zloz Slonce(wektor_2D<double>(0, 0), 1.98855e30, 6.96342e8, wektor_2D<double>(0, 0));  //1.49504e11
	planeta_Newton_zloz Ziemia(wektor_2D<double>(1.49504e11, 0), 5.96e24, 6.371e6, wektor_2D<double>(0, 2.978e4));
	planeta_Newton_zloz Mars(wektor_2D<double>(2.2792e11, 0), 6.417e23, 3.396e6, wektor_2D<double>(0, 2.407e4));
	Symulacja sym;
	sym.dodaj_obj(&Slonce);
	sym.dodaj_obj(&Ziemia);
	sym.dodaj_obj(&Mars);
	sym.symuluj();

	// proba
	
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
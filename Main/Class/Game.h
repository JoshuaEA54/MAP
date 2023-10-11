#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct Game
{
	RenderWindow window;
	Sprite sMap;
	Texture mapTex;
	RectangleShape addRoute;
	Event event;

	void map() {
		
		window.create(VideoMode(1368, 767), "Map", Style::Default);
		window.setSize(Vector2u(1368, 690));

		mapTex.loadFromFile("Images/MyMap.jpg");

		 sMap = Sprite(mapTex);

		addRoute = RectangleShape(Vector2f(200, 80));
		addRoute.setPosition(30, 660);
		addRoute.setOutlineColor(Color::Black);
		addRoute.setOutlineThickness(2.5);
		addRoute.setFillColor(Color(25, 25, 110, 230));

		while (window.isOpen()) {

			while (window.pollEvent(event)) {

				if (event.type == Event::Closed) {
					window.close();
				}

			}

			window.clear();

			window.draw(sMap);
			window.draw(addRoute);

			window.display();
		}

	}

};

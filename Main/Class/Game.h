#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


struct Map
{

	void map() {
		
		RenderWindow window;
		window.create(VideoMode(1368, 767), "Map", Style::Default);
		window.setSize(Vector2u(1368, 690));

		Texture mapTex;
		mapTex.loadFromFile("Images/MyMap.jpg");

		Sprite sMap = Sprite(mapTex);

		RectangleShape addRoute = RectangleShape(Vector2f(200, 80));
		addRoute.setPosition(30, 660);//30 660
		addRoute.setOutlineColor(Color::Black);
		addRoute.setOutlineThickness(2.5);
		addRoute.setFillColor(Color(25, 25, 110, 230));

		Font font;
		font.loadFromFile("Images/arial_narrow_7.ttf");
		Text buttonText = Text("Add Route", font, 28);
		buttonText.setPosition(70, 680);
		buttonText.setFillColor(Color::Black);

		

		Event event;
		
		while (window.isOpen()) {

			Vector2i mousePosition = Mouse::getPosition(window);
			Vector2f worldPosition = window.mapPixelToCoords(mousePosition);

			while (window.pollEvent(event)) {

				if (event.type == Event::Closed) {
					window.close();
				}

				IluminateAddRouteButton(addRoute, worldPosition);

				if (event.type == Event::MouseButtonPressed) {

					if (addRoute.getGlobalBounds().contains(worldPosition)) {
						// it would get inside the editor mode
						

					}

				}
			}

			window.clear();

			window.draw(sMap);
			window.draw(addRoute);
			window.draw(buttonText);

			window.display();
		}

	}

	void IluminateAddRouteButton(RectangleShape& addRoute, Vector2f& worldPosition)
	{
		if (addRoute.getGlobalBounds().contains(worldPosition)) {
			addRoute.setFillColor(Color(25, 25, 110, 220));
		}
		else {
			addRoute.setFillColor(Color(25, 25, 110, 250));
		}
	}

};

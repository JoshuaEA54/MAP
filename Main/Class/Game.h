#pragma once

#include "Route.h"

template<typename T>
class Map
{
private:

	struct Nodo {
		T route;
		Nodo* next;
		Nodo* prev;
		Nodo(T _route) : route(_route), next(nullptr), prev(nullptr) {}
	};
	Nodo* header;

	int amountOfRoutes;

public:
	Map() : header(nullptr), amountOfRoutes(0) {}

	Nodo* getHeader() { return header; }
	int getAmountOfRoutes() { return amountOfRoutes; }

	void setAmountOfRoutes(int _amountOfRoutes) { this->amountOfRoutes = _amountOfRoutes; }

	void addRouteInTheList(T _route) {
		Nodo* nodoAdded = new Nodo(_route);
		Nodo* aux = header;

		if (!header) {
			header = nodoAdded;
		}
		else {// means that the head next is with a nodo
			while (aux->next) {
				aux = aux->next;
			}
			aux->next = nodoAdded;
			aux->next->prev = aux;
		}
		amountOfRoutes += 1;

		//memory part
		nodoAdded = nullptr;
		delete nodoAdded;
		aux = nullptr;
		delete aux;
	}

	void gameMethod() {

		RenderWindow window;
		window.create(VideoMode(1368, 767), "Map", Style::Default);
		window.setSize(Vector2u(1368, 690));

		Texture mapTex;
		mapTex.loadFromFile("Images/MyMap.jpg");
		Sprite sMap = Sprite(mapTex);

		//boton de agregar ruta
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

		//boton de finalizar ruta
		RectangleShape endRoute = RectangleShape(Vector2f(200, 80));
		endRoute.setPosition(1120, 660);//30 660
		endRoute.setOutlineColor(Color::Black);
		endRoute.setOutlineThickness(2.5);
		endRoute.setFillColor(Color(25, 25, 110, 230));

		Font font2;
		font2.loadFromFile("Images/arial_narrow_7.ttf");
		Text buttonText2 = Text("End Route", font2, 28);
		buttonText2.setPosition(1160, 680);
		buttonText2.setFillColor(Color::Black);

		bool editorMode = false;
		string auxNameOfRoute = "";

		Event event;

		Route<coordenates> newRoute;

		while (window.isOpen()) {

			Vector2i mousePosition = Mouse::getPosition(window);
			Vector2f mapPosition = window.mapPixelToCoords(mousePosition);

			while (window.pollEvent(event)) {

				if (event.type == Event::Closed) {
					window.close();
				}
				if (!editorMode) {
					IluminateButton(addRoute, mapPosition);

					if (event.type == Event::MouseButtonPressed && addRoute.getGlobalBounds().contains(mapPosition)) {

						cout << " Digite el nombre de la nueva ruta: ";
						cin >> auxNameOfRoute;

						Route<coordenates> aux;
						newRoute = aux;

						cout << " Ahora digite el inicio de la nueva ruta en el mapa..." << endl;
						// it would get inside the editor mode
						editorMode = true;


					}
				}
				else {
					IluminateButton(endRoute, mapPosition);

					if (event.type == Event::MouseButtonPressed) {
						coordenates coords(mapPosition.x, mapPosition.y);
						cout << coords.getX() << " " << coords.getY() << endl;

						newRoute.setNameOfRoute(auxNameOfRoute);
						newRoute.addNodoInTheEnd(coords);
					}
					if (endRoute.getGlobalBounds().contains(mapPosition) && event.type == Event::MouseButtonPressed) {
						
						editorMode = false;
                        // ya cuando tengo la ruta completamente creada y le doy al boton guardar
					    // llamar al metodo addRouteInTheList(newRoute);
					}
					
				}
			}

			window.clear();

			window.draw(sMap);
			window.draw(addRoute);
			window.draw(endRoute);
			window.draw(buttonText);
			window.draw(buttonText2);

			window.display();
		}
	}

	void IluminateButton(RectangleShape& addRoute, Vector2f& mapPosition)
	{
		if (addRoute.getGlobalBounds().contains(mapPosition)) {
			addRoute.setFillColor(Color(25, 25, 110, 220));
		}
		else {
			addRoute.setFillColor(Color(25, 25, 110, 250));
		}
	}

};






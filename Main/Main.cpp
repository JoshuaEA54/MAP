

#include "Class/Game.h"


int main()
{

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

	bool editorMode = false;

	Event event;

	while (window.isOpen()) {

		Vector2i mousePosition = Mouse::getPosition(window);
		Vector2f mapPosition = window.mapPixelToCoords(mousePosition);
		// cada iteracion hacer un set del atributo map de mapPositionk que tiene las coordenadas del mouse en el mapa
		
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				window.close();
			}
			if (!editorMode) {
				IluminateAddRouteButton(addRoute, mapPosition);

				if (event.type == Event::MouseButtonPressed) {

					if (addRoute.getGlobalBounds().contains(mapPosition)) {
						cout << " Digite el nombre de la nueva ruta: ";
						// it would get inside the editor mode
						editorMode = true;
					}

				}
			}
			else {
				//addRouteMethod(worldPosition);
				//put the condition that if the button 'finalizar' is pressed , editorMode is false
			}
		}

		window.clear();

		window.draw(sMap);
		window.draw(addRoute);
		window.draw(buttonText);

		window.display();
	}

    return 0;
}

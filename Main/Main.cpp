

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


int main()
{
    RenderWindow window;
    window.create(VideoMode(1366, 768), "Map", Style::Default);

	Event event;

	while (window.isOpen()) {

		while (window.pollEvent(event)) {

			if (event.type == Event::Closed) {
				window.close();
			}


		}

		window.clear();

		window.display();
	}

    return 0;
}

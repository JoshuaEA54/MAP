#pragma once

#include "Route.h"

template<typename T>
struct Map
{
	
	List<T>* listOfRoutes;
	int amountOfRoutes;
	
	Map() : listOfRoutes(nullptr), amountOfRoutes(0) {}

	void addRouteInTheList(Route<T>*& _route) {

		listOfRoutes->addNodoInTheEnd(_route);
		amountOfRoutes += 1;

	}


};

	void IluminateAddRouteButton(RectangleShape& addRoute, Vector2f& worldPosition)
	{
		if (addRoute.getGlobalBounds().contains(worldPosition)) {
			addRoute.setFillColor(Color(25, 25, 110, 220));
		}
		else {
			addRoute.setFillColor(Color(25, 25, 110, 250));
		}
	}

	

	
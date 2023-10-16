#pragma once

#include "List.h"

template<typename T>
class Route {

private:	
	List<T>* route;
	String nameOfRoute;
	Color color;

public:
	Route(): route(nullptr), nameOfRoute(""), color(Color::Transparent){}

	void setRoute(List<T>*& _route) { this->route = _route; }
    void setColor(Color _color) { this->color = _color; }
	void setNameOfRoute(string _nameOfRoute) { this->nameOfRoute = _nameOfRoute; }

	string getNameOfRoute() { return nameOfRoute; }
	Color getColor() { return color; }
	List<T>* getRoute() { return route; }

	

};

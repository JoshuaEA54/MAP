#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

template<typename T>
class Route {

private:	
	
	struct Nodo {
		T data;//coordenates for each nodo
		Nodo* next;
		Nodo* prev;
		Nodo(T _data) : data(_data), next(nullptr), prev(nullptr) {}

	};
	Nodo* header;
	
	String nameOfRoute;
	Color color;

public:
	Route(): header(nullptr), nameOfRoute(""), color(Color::Red){} 
	~Route() {
		while (header) {
			Nodo* temp = header;
			header = header->next;
			temp = nullptr;
			delete temp;
		}

	}

    void setColor(Color _color) { this->color = _color; }
	void setNameOfRoute(string _nameOfRoute) { this->nameOfRoute = _nameOfRoute; }

	string getNameOfRoute() { return nameOfRoute; }
	Color getColor() { return color; }
	Nodo* getHeader() { return header; }

	void addNodoInTheEnd(T value) {
		Nodo* nodoAdded = new Nodo(value);
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

		nodoAdded = nullptr;
		delete nodoAdded;
		aux = nullptr;
		delete aux;
	}
	

};

struct coordenates {
	float x;
	float y;
	coordenates() { x = -1; y = -1; }
	coordenates(float _x, float _y) : x(_x), y(_y) {}
	void setX(float _x) { this->x = _x; }
	void setY(float _y) { this->y = _y; }
	float getX() { return x; }
	float getY() { return y; }
};
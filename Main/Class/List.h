#pragma once

#include "Game.h"

template<typename T>
class Route {
private:
	struct Nodo {
		T data;//put here the info that I will need in each nodo
		Nodo* next;
		Nodo* prev;
		Nodo(T _data) : data(_data), next(nullptr), prev(nullptr) {}
		
	};

	Nodo* header;
	String nameOfRoute;
	Color color;

public:
	Route() :header(nullptr), nameOfRoute(""), color(Color::Red) {}

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

	void addNodoInTheEnd(T value) {
		Nodo* nodoAdded = new Nodo(value);
		Nodo* aux;

		if (!header) {
			header = nodoAdded;
		}
		else {// means that the head next is with a nodo
			aux = header;
			while (aux->next) {
				aux = aux->next;
			}
			aux->next = nodoAdded;
		}
	}


};

struct coordenates {
	float x;
	float y;
	coordenates(float _x, float _y) : x(_x), y(_y){}
};

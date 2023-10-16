#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

template<typename T>
class List {
private:
	struct Nodo {
		T data;//coordenates for each nodo
		Nodo* next;
		Nodo* prev;
		Nodo(T _data) : data(_data), next(nullptr), prev(nullptr) {}
		
	};

	Nodo* header;
	
public:
	List() :header(nullptr) {}

	~List() {
		while (header) {
			Nodo* temp = header;
			header = header->next;
			temp = nullptr;
			delete temp;
		}

	}

	Nodo* getHeader() { return header; }

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
	coordenates() { x = -1; y = -1; }
	coordenates(float _x, float _y) : x(_x), y(_y){}
};

#pragma once

#include "Game.h"

template<typename T>
class List {
private:
	struct Nodo {
		T data;//put here the info that I will need in each nodo
		int x;//coordenates
		int y;
		Nodo* next;
		Nodo* prev;
		Nodo(T _data, int _x, int _y) : data(_data), x(_x), y(_y), next(nullptr), prev(nullptr) {}
	};

	Nodo* header;

public:
	List() :header(nullptr) {}

	~List() {
		while (header) {
			Nodo* temp = header;
			header = header->siguiente;
			temp = nullptr;
			delete temp;
		}

	}



};

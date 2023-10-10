#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

template<typename T>
class List {
private:
	struct Nodo {
		T data;//put here the info that I will need in each nodo

		Nodo* next;
		Nodo* prev;
		Nodo(T _data) : data(_data), next(nullptr), prev(nullptr) {}
	};

	Nodo* header;

public:
	List() :header(nullptr) {}

	~List() {
		while (header) {
			Nodo* temp = cabeza;
			cabeza = cabeza->siguiente;
			temp = nullptr;
			delete temp;
		}

	}


};

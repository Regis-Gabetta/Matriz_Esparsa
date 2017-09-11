#ifndef MATRIZ
#define MATRIZ

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Vetor.h"

using namespace std;

template<typename T>
class Matriz {

	friend class Vetor<T>;
public:
	Matriz(T t0);
	~Matriz();
	Vetor<T>* get(unsigned int i);
	Vetor<T> & operator [](unsigned int i);

private:
	T default0;
	Vetor< Vetor<T>* > vetor;
	Vetor<T>* temp;
	int linAnt = -1;
};


template<typename T>
Matriz<T>::Matriz(T d0) {
	default0 = d0;
	Vetor<T>* dp0 = NULL;
	vetor = Vetor< Vetor<T>* >(dp0);
	temp = (Vetor<T>*)malloc(sizeof(Vetor<T>));
}

template<typename T>
Matriz<T>::~Matriz() {
}

template<typename T>
Vetor<T>* Matriz<T>::get(unsigned int i) {
	Vetor<T>* vp = vetor.get(i);

	if (vp == NULL) {
		Vetor<T>* v = new Vetor<T>(default0);
		vetor.set(i, v);
		return v;
	}

	return vp;
}


template<typename T>
Vetor<T> & Matriz<T>::operator [](unsigned int i) {
	if (temp->getCol() != -1 && linAnt != -1)
		this->get(linAnt)->set(temp->getCol(),temp->getTemp());
	temp = get(i);
	linAnt = i;
	return *temp;
}

#endif // MATRIZ


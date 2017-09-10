#ifndef VETOR
#define VETOR

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "No.h"
#include "Arvore.h"

using namespace std;

template<typename T>
class Vetor {

public:
	Vetor(T t0);
//	Vetor(T t0, Matriz<T> mat);
	Vetor();
	~Vetor();
	void set(unsigned int i, T o);
	int getCol() const;
	T get(unsigned int i) const;
	T getTemp() const;
	T operator [](unsigned int  i) const;
	T & operator [](unsigned int  i);

private:
	T default0;
	Arvore<No <T> > arv;
	T temp;
	int col;
//	Matriz<T> m;
};

//template<typename T>
//Vetor<T>::Vetor(T t0, Matriz<T> mat) {
//	default0 = t0;
//	m = mat;
//	arv = Arvore<No <T> >();
//}

template<typename T>
Vetor<T>::Vetor(T t0) {
	default0 = t0;
	arv = Arvore<No <T> >();
	col = -1;
}

template<typename T>
Vetor<T>::Vetor() {
	col = -1;
}

template<typename T>
Vetor<T>::~Vetor() {
}

template<typename T>
void Vetor<T>::set(unsigned int i, T o) {

	if (o != default0) {
		No<T> n = No<T>(o, i);
		arv.insert(n);
	}

	else {
		No<T> n = No<T>(i);
		arv.remove(n);
	}
}

template<typename T>
T Vetor<T>::get(unsigned int i) const {
	No<T> n = No<T>(i);
	No<T> ng = arv.get(n);

	No<T> n0 = No<T>(-1);

	if (ng != n0)
		return ng.info;

	return default0;
}


template<typename T>
T Vetor<T>::getTemp() const {
	return temp;
}

template<typename T>
int Vetor<T>::getCol() const {
	return col;
}

template<typename T>
T Vetor<T>::operator [](unsigned int i) const {

	return this->get(i);
}

template<typename T>
T & Vetor<T>::operator [](unsigned int i) {
	temp = this->get(i);
	col = i;
	return temp;
}

#endif // VETOR


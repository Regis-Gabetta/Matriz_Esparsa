#ifndef MATRIZ
#define MATRIZ

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Vetor.h"

using namespace std;

template<typename T>
class Matriz{

 public:
	Matriz(T t0);
	~Matriz();
	Vetor<T>* get(unsigned int i);
	
	Vetor<T> & operator [](unsigned int i);

 private:
	T default0;
	Vetor< Vetor<T>* > vetor;
	Vetor<T>* temp;
};


template<typename T>
Matriz<T>::Matriz(T d0){
	default0 = d0;
	Vetor<T>* dp0 = NULL;
	vetor = Vetor< Vetor<T>* >(dp0);
}

template<typename T>
Matriz<T>::~Matriz(){
}

template<typename T>
Vetor<T>* Matriz<T>::get(unsigned int i) {
	Vetor<T>* vp = vetor.get(i);
	
	if (vp == NULL){
		Vetor<T>* v = new Vetor<T>(default0);
		vetor.set(i, v);
		return v;
	}
	
	return vp;
}

template<typename T>
Vetor<T> & Matriz<T>::operator [](unsigned int i){
	temp = get(i);
	return *temp;
}

#endif // MATRIZ


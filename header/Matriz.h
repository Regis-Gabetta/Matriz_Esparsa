#ifndef MATRIZ
#define MATRIZ

#include <stdlib.h>
#include <stdio.h>
#include "Vetor.h"

using namespace std;

template<typename T>
class Matriz{

 public:
	Matriz(T t0);
	~Matriz();
	void set(unsigned int i, unsigned int j, T o);
	T get(unsigned int i, unsigned int j);

 private:
	T default0;
	Vetor< Vetor<T> > vetor;
};


template<typename T>
Matriz<T>::Matriz(T t0){
	default0 = t0;
	vetor = Vetor< Vetor<T> >();
}

template<typename T>
Matriz<T>::~Matriz(){
}

template<typename T>
void Matriz<T>::set(unsigned int i, T o){
}

template<typename T>
T Matriz<T>::get(unsigned int i){
}

#endif // MATRIZ


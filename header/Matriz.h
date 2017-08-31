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
	T get(unsigned int i, unsigned int j);
	
	Vetor<T>* operator [](unsigned int i) const;

 private:
	T default0;
	Vetor< Vetor<T>* > vetor;
};


template<typename T>
Matriz<T>::Matriz(T d0){
	default0 = d0;
	vetor = Vetor< Vetor<T>* >(NULL);
}

template<typename T>
Matriz<T>::~Matriz(){
}

template<typename T>
T Matriz<T>::get(unsigned int i){
}

template<typename T>
Vetor<T>* Matriz<T>::operator [](unsigned int i) const{
	Vetor<T>* vp = this->get(i);
	
	if (vp == NULL){
		Vetor<T>* v = new Vetor<T>(default0);
		vetor.set(i, v);
		return v;
	}
	
	return vp;
}

#endif // MATRIZ


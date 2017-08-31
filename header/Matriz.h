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
	Vetor<T>* get(unsigned int i);
	
	//Vetor<T>* operator [](unsigned int i) const;

 private:
	T default0;
	Vetor<Vetor<T>> vetor;
	Vetor<T> buffer;
};


template<typename T>
Matriz<T>::Matriz(T t0){
	default0 = t0;
	vetor = Vetor<Vetor<T>>();
	buffer = Vetor<int>(0);
}

template<typename T>
Matriz<T>::~Matriz(){
}


//template<typename T>
//Vetor<T>* Matriz<T>::operator [](unsigned int i) const{
//	Vetor<T>* vp = this->get(i);
//	
//	if (vp == NULL){
//		Vetor<T>* v = new Vetor<T>(default0);
//		vetor.set(i, v);
//		return v;
//	}
//	
//	return vp;



template<typename T>
T Matriz<T>::get(unsigned int i, unsigned int j){
	return buffer.get(j);
}

template<typename T>
Vetor<T>* Matriz<T>::get(unsigned int i) {
	return &buffer;
}

#endif // MATRIZ


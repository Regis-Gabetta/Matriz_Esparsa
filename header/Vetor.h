#ifndef VETOR
#define VETOR

#include <stdlib.h>
#include <stdio.h>
#include "No.h"
#include "Arvore.h"

using namespace std;

template<typename T>
class Vetor{

 public:
	Vetor(T t0);
	~Vetor();
	void set(unsigned int i, T o);
	T* get(unsigned int i);

 private:
	T default0;
	Arvore<No <T> > arv;
};


template<typename T>
Vetor<T>::Vetor(T t0){
	default0 = t0;
	arv = Arvore<No <T> >();
}

template<typename T>
Vetor<T>::~Vetor(){
}

template<typename T>
void Vetor<T>::set(unsigned int i, T o){
	
	if (o != default0){
		No<T> n = No<T>(o, i);
		arv.insert(n);
	}
	
	else{
		No<T> n = No<T>(i);
		arv.remove(n);
	}
}

template<typename T>
T* Vetor<T>::get(unsigned int i){
	No<T> n = No<T>(i);
	No<T>* ng = arv.get(n)->info;
	
	if (ng != NULL)
		return &(ng->info);
	
	return NULL;
}

#endif // VETOR


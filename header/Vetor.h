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
	Vetor();
	~Vetor();
	void set(unsigned int i, T o);
	void add(unsigned int i, T o);
	T get(unsigned int i);

	T operator [](unsigned int  i) const;
  T & operator [](unsigned int  i);
	
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
Vetor<T>::Vetor() {
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
T Vetor<T>::get(unsigned int i){
	No<T> n = No<T>(i);
	No<T> ng = arv.get(n);
	
	No<T> n0 = 0;
	
	if (ng != n0)
		return ng.info;
	
	return default0;
}

template<typename T>
T Vetor<T>::operator [](unsigned int i) const{
	return this->get(i);
}

template<typename T>
T & Vetor<T>::operator [](unsigned int i){
	return &(this->get(i));
}

#endif // VETOR


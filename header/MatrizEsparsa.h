#ifndef MATRIZESPARSA
#define MATRIZESPARSA

#include <stdlib.h>
#include <stdio.h>
#include "No.h"
#include "Arvore.h"

using namespace std;

template<typename T>
class MatrizEsparsa{

 public:
	MatrizEsparsa(T t0);
	~MatrizEsparsa();
	inserir(unsigned int i, unsigned int j, T o);

 private:
	T default0;
	Arvore<No<Arvore<No<T>>>> arv;
};


template<typename T>
MatrizEsparsa::MatrizEsparsa(T t0){
	default0 = t0;
	arv = Arvore<No<Arvore<No<T>>>>();
}

template<typename T>
MatrizEsparsa::~MatrizEsparsa(T t0){
}

template<typename T>
MatrizEsparsa::inserir(unsigned int i, unsigned int j, T o){

}

#endif // MATRIZESPARSA


#ifndef COLUNAS
#define COLUNAS

#include <stdlib.h>
#include <stdio.h>
#include "ArvoreCol.h"

template <typename T>
class Colunas
{

public:
	bool existeColuna(int i);
	void inserir(int i,T info);

private:
	ArvoreCol<int> colunas;
	T info;
	
};



#endif // COLUNAS
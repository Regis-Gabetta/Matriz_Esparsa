#ifndef MATRIZESPARSA
#define MATRIZESPARSA

#include <stdlib.h>
#include <stdio.h>
#include "Colunas.h"
#include "ArvoreCol.h"
#include "ArvoreLin.h"

using namespace std;

template<typename T>
class MatrizEsparsa
{

public:


private:
	ArvoreLin<T> mat;
	Colunas<T> c;
	int linha;
};

#endif // MATRIZESPARSA


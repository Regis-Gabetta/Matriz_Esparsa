#include "Arvore.h"
#include "Vetor.h"
#include "Matriz.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

int main(){
	
	Matriz<int> m = Matriz<int>(0);
	
	Vetor<int>* v = m.get(0);
	v->set(0, 4);
	
	m.get(10)->set(4, 777);
	m[10]->set(5, 99);
	
	int i = (*m[10])[5];
	cout << i;
	
  return 0;
}


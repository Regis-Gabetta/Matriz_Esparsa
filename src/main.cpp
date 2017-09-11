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
	
	m[10].set(5, 99);
	
	m[7][7] = 123;
	
	int i = m[7][7];
	int i2 = m[10][5];
	int i3 = m[10][5];
	int i4 = m[11][6];

	m.get(14)->set(100, 433);

	int i5 = m[14][100];
	cout << i  << '\n';
	cout << i2 << '\n';
	cout << i3 << '\n';
	cout << i4 << '\n';
	cout << i5 << '\n';
	
  return 0;
}


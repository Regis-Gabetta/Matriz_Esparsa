#include "Arvore.h"
#include "Vetor.h"
#include "Matriz.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

int main(){
	Vetor<int> v = Vetor<int>(0);
	Matriz<int> m = Matriz<int>(0);

	char* c = (char*)malloc(5 * sizeof(char));
	
	m.get(0)->set(1,433);
	m.get(0)->set(3, 223);
	m.get(0)->set(6, 3643);
	m.get(3)->set(2, 231);

	v.set(0, 1);
	v.set(1, 2);
	v.set(2, 3);
	v.set(3, 0);
	v.set(4, 777);
	
	cout << m.get(0,1)  << '\n';
	cout << m.get(0, 3) << '\n';
	cout << m.get(3, 2) << '\n';
	cout << m.get(0, 6) << '\n';
	cout << m.get(111)->get(0) << '\n';
	cin >> c;
	
  return 0;
}


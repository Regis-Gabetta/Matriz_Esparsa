#include "Arvore.h"
#include "Vetor.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

int main(){
	Vetor<int> v = Vetor<int>(0);
	
	v.set(0, 1);
	v.set(1, 2);
	v.set(2, 3);
	v.set(3, 0);
	v.set(4, 777);
	
	cout << v.get(4);
	
  return 0;
}


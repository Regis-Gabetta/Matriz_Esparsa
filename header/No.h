#ifndef NO
#define NO

#include <stdlib.h>
#include <string>

#define max(n1,n2) (n1 > n2 ? n1 : n2)
#define height(n) (n == NULL ? 0 : n->h)
#define bf(n) (height(n->l) - height(n->r))

using namespace std;

template<typename T>
class Node{

public:
	T info;
	unsigned int i;
	
	// comparadores...

};
#endif //NO

#ifndef NO
#define NO

#include <stdlib.h>
#include <string>

#define max(n1,n2) (n1 > n2 ? n1 : n2)
#define height(n) (n == NULL ? 0 : n->h)
#define bf(n) (height(n->l) - height(n->r))

using namespace std;

template<typename T>
class No{

public:
	T info;
	unsigned int i;
	
	No(T o, int i);
	No(int i);
	No();
	
	bool operator== (const No<T> &n);
	bool operator> (const No<T> &n);
	bool operator< (const No<T> &n);
	bool operator<= (const No<T> &n);
	bool operator>= (const No<T> &n);
	bool operator!= (const No<T> &n);

};

template<typename T>
No<T>::No(T o, int i){
	info = o;
	this->i = i;
}

template<typename T>
No<T>::No(int i){
	this->i = i;
}

template<typename T>
No<T>::No(){
	this->i = -1;
}

template<typename T>
bool No<T>::operator== (const No<T> &n){
	return n.i == i;
}

template<typename T>
bool No<T>::operator> (const No<T> &n){
	return n.i > i;
}

template<typename T>
bool No<T>::operator< (const No<T> &n){
	return n.i < i;
}

template<typename T>
bool No<T>::operator<= (const No<T> &n){
	return n == this || n < this;
}

template<typename T>
bool No<T>::operator>= (const No<T> &n){
	return n == this || n > this;
}

template<typename T>
bool No<T>::operator!= (const No<T> &n){
	return !(n.i == i );
}

#endif //NO

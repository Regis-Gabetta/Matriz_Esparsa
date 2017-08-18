#ifndef ARVORECOL
#define ARVORECOL

#include <stdlib.h>
#include <string>

#define max(n1,n2) (n1 > n2 ? n1 : n2)
#define height(n) (n == NULL ? 0 : n->h)
#define bf(n) (height(n->l) - height(n->r))

using namespace std;

template<typename T>
class ArvoreCol{

	struct Node{
		T info;
		int numeroCol;
		Node *l;
		Node *r;
		Node *p;

		unsigned int h;
	};
 public:
  ArvoreCol();
  ~ArvoreCol();
  void arvoreCol_Destrutor(struct Node* raiz);
  ArvoreCol(const ArvoreCol<T> *a);
  unsigned int getCount() const;
  unsigned int getHeight() const;

  template<T>
  friend ostream& operator<< (ostream&, const ArvoreCol&);

  template<T>
  friend istream& operator >> (istream&, ArvoreCol&);


	void insert(T o);
	char remove(T o);


	int remove_Node(Node *raiz, T o) {
		if (raiz == NULL)
			return 0;
		int res;
		if (o < raiz->info)
		{
			if ((res = remove_Node(raiz->l, o)) == 1) {
				raiz->h = max(height(raiz->l), height(raiz->r)) + 1;
				int befao = bf(raiz);
				if (befao < -1)
				{
					if (height(raiz->r->l) <= height(raiz->r->r))
						rotateLeft(raiz);
					else
					{
						rotateRight(raiz->r);
						rotateLeft(raiz);
					}
				}
			}

		}

		if (o > raiz->info)
		{
			if ((res = remove_Node(raiz->r, o)) == 1) {
				raiz->h = max(height(raiz->l), height(raiz->r)) + 1;
				int befao = bf(raiz);
				if (befao > 1)
				{
					if (height(raiz->l->r) <= height(raiz->l->l))
						rotateLeft(raiz);
					else
					{
						rotateRight(raiz->r);
						rotateLeft(raiz);
					}
				}
			}
		}

		if (raiz->info == o)
		{
			if (raiz->l == NULL || raiz->r == NULL)
			{
				struct Node *old = raiz;
				if (raiz->l != NULL)
					raiz = raiz->l;
				else
				{
					Node* pai = raiz->p;
					raiz = raiz->r;
					if (raiz != NULL)
					{
						raiz->h = max(height(raiz->l), height(raiz->r)) + 1;
						raiz->p = pai;
					}						
				}
					
				freeNode(old, raiz);
				
			}
			else
			{
				struct Node *no1 = raiz->r;
				struct Node *no2 = raiz->r->l;
				while (no2 != NULL) {
					no1 = no2;
					no2 = no2->l;
				}
				struct Node* temp = no1;
				raiz->info = temp->info;
				remove_Node(raiz->r, temp->info);
				int befao = bf(raiz);
				if (befao > 1)
				{
					if (height(raiz->l->r) <= height(raiz->l->l))
						rotateRight(raiz);
					else
					{
						rotateLeft(raiz->l);
						rotateRight(raiz);
					}
				}
				raiz->h = max(height(raiz->l), height(raiz->r)) + 1;
			}
			return 1;
		}
		return res;
	}
	std::string toString() const;
	Node *root;
	
 protected:

	unsigned int count;
	std::string toStringAux(const Node *no) const;
	
	void rotateLeft(Node *x);
	void rotateRight(Node *y);
	void copyNode(Node *n1, Node *n2);
	void freeNode(Node *n1, Node* noR);
};

template<typename T>
ArvoreCol<T>::ArvoreCol(){
  root = NULL; 
	count= 0;
}

template<typename T>
ArvoreCol<T>::ArvoreCol(const ArvoreCol<T> *a){
	
}

template<typename T>
unsigned int ArvoreCol<T>::getHeight() const{
	return height(root);
}

template<typename T>
unsigned int ArvoreCol<T>::getCount() const{
	return count;
}

template<typename T>
ostream& operator <<(ostream& OS, const ArvoreCol<T>& S)
{
	return (OS << S.toString());
}

template<typename T>
istream& operator >>(istream& IS, ArvoreCol<T>& S)
{
	IS >> S.toString();

	return IS;
}

template<typename T>
std::string ArvoreCol<T>::toString() const{
	return toStringAux(root);
}

template<typename T>
std::string ArvoreCol<T>::toStringAux(const Node *no) const {

	std::string str = "";
	
	if (no != NULL){
		str += "(";
		
		str += toStringAux(no->l);

		str += no->info;

		str += toStringAux(no->r);

		str += ")";
	}

	return str;
}

template<typename T>
ArvoreCol<T>::~ArvoreCol(){

	arvoreCol_Destrutor(root);

}

template<typename T>
void ArvoreCol<T>::arvoreCol_Destrutor(struct Node *raiz)
{
	if (raiz != NULL)
	{
		arvoreCol_Destrutor(raiz->l);
		arvoreCol_Destrutor(raiz->r);
		free(raiz) ;
		raiz = NULL;
	}
}

//template<typename T>
//struct Node* ArvoreCol<T>::procuraMenor(struct Node *atual){
//	struct Node *no1 = atual;
//	struct Node *no2 = atual->l;
//	while(no2 != NULL){
//		no1 = no2;
//		no2 = no2->l;
//	}
//	return no1;
//}


template<typename T>
char ArvoreCol<T>::remove(T o){
	Node* nor = root;
	while(nor != NULL){
		if (nor->info == o)
			break;
		
		else
			if (o < nor->info)
				nor = nor->l;
			else
				nor = nor->r;
	}
	
	if (nor != NULL){
		Node* no = nor->p;
		Node* nop = no;
		delete nor; // NAAAAAAAAAAO
								// ERRRADDDDDOOOO
		
	}
	
	return 0;
}

template<typename T>
void ArvoreCol<T>::copyNode(Node *n1, Node* n2){
	n2->l = n1->l;
	n2->r = n1->r;
	n2->p = n1->p;
	n2->info = n1->info;
	n2->h = n1->h;
}

template<typename T>
void ArvoreCol<T>::freeNode(Node *n1, Node* noR) {
	if (n1->p != NULL) {
		if (n1->p->l != NULL)
			if (n1->p->l->info == n1->info)
				n1->p->l = noR;

		if(n1->p->r != NULL)
			if (n1->p->r->info == n1->info)
				n1->p->r = noR;
	}
	
	free(n1);
	count--;
}

template<typename T>
void ArvoreCol<T>::rotateRight(Node *y){
	Node* temp = (Node*) malloc(sizeof(Node));
	copyNode(y, temp);
	
	Node* x = y->l;
	Node* xr = x->r;
	Node* yp = y->p;
	copyNode(x, y);
	y->p = yp;
	
	if(y->l != NULL)
		y->l->p = y;
	
	copyNode(temp, x);
	y->r = x;
	x->p = y;
	
	x->l = xr;
	
	if (xr != NULL)
		xr->p = x;

	if (x->l != NULL)
		x->l->p = x;

	if (x->r != NULL)
		x->r->p = x;
	
	x->h = max(height(x->l),height(x->r)) + 1;
	y->h = max(height(x->l),height(x->r)) + 1;

	delete temp;
}

template<typename T>
void ArvoreCol<T>::rotateLeft(Node *x){
	Node* temp = (Node*) malloc(sizeof(Node));
	copyNode(x, temp);
	
	Node* y = x->r;
	Node* yl = y->l;
	Node* xp = x->p;
	copyNode(y, x);
	x->p = xp;
	
	if (x->r != NULL)
		x->r->p = x;
	
	copyNode(temp, y);
	x->l = y;
	y->p = x;
	
	y->r = yl;
	
	if (yl != NULL)
		yl->p = y;

	if (y->l != NULL)
		y->l->p = y;

	if (y->r != NULL)
		y->r->p = y;
	
	y->h = max(height(y->l),height(y->r)) + 1;
	x->h = max(height(x->l),height(x->r)) + 1;

	delete temp;
}

template<typename T>
void ArvoreCol<T>::insert(T o){
	Node *no = root;
	
	if (root == NULL){
		root = (Node*) malloc(sizeof(Node));
		root->p = NULL;
		root->l = NULL;
		root->r = NULL;
		root->info = o;
		root->h = 1;
		no = root;
		count++;
	}

	else
		while(1){
			if (o < no->info){
				if (no->l == NULL){
					no->l =	(Node*) malloc(sizeof(Node));
					no->l->info = o;
					no->l->l = NULL;
					no->l->r = NULL;
					no->l->p = no;
					
					no = no->l;
					count++;
					break;
				}
				no = no->l;
				continue;
			}

			if (o > no->info){
				if (no->r == NULL){
					no->r =	(Node*) malloc(sizeof(Node));
					no->r->info = o;
					no->r->l = NULL;
					no->r->r = NULL;
					no->r->p = no;
					
					no = no->r;
					count++;
					break;
				}

				no = no->r;
				continue;
			 }

			return;
		}

	Node* nop = no;
	
	while(no != NULL){
		no->h = max(height(no->l),height(no->r)) + 1;

		int balanceF = bf(no);
		
		if (balanceF > 1){
		 	if(o < no->l->info){
		 		rotateRight(no);
		 	}

		 	else{
		 		rotateLeft(no->l);
				rotateRight(no);
			}
			
			continue;
		}

		else if (balanceF < -1){
		 	if(o > no->r->info){
		 		rotateLeft(no);
		 	}

		 	else{
		 		rotateRight(no->r);
				rotateLeft(no);
			}
			
			continue;
		}
		
		
		nop = no;
		no = no->p;
	}
	
	root = nop;
}
#endif //ARVORECOL

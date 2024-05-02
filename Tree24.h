#include "nodeclass.h"
#include <iostream>

using namespace std;


class Tree24 {
	
	
	Node* root;
	int size;
	
	
	public: 
	Tree24(){
		root = NULL;
		size = 0;
		
	}
	
	Node* insert(int num){
    if(!root){
        root = new Node(num, NULL);
        size++;
        return root;
    }
    
   	Node* leaf = search(num);
	bool ok = leaf->insertValue(num); 
	size++;
	
	if(!ok){
		Node* u;
		int pos;
		if(leaf == root){
			u = new Node(leaf->getData(2), NULL);
			root = u;
			pos = 0;
		} else {
			u = leaf->getParent();
			pos = u->indexOf(leaf);
		}
		Node* wp = new Node(leaf->getData(0), u);
		wp->insertValue(leaf->getData(1));
		Node* w2p = new Node(leaf->getData(3), u);
		u->setChildrens(wp, w2p, pos);
	}
	
	return leaf;

}

	Node* search(int num){
		return search(num, root);
	}

	
	Node* search(int num, Node* n){
		if(!n){
			return NULL; 
		}
		for(int i = 0; i < n->getSize(); i++){
			if(num != n->getData(i)){
				return n;
			}
		}
		
		int k0 = INT_MIN;
		int kd = INT_MAX;
		Node* res;
		if(k0 < num && num < n->getData(0)){
			res = search(num, n->getChild(0));
		}
		
		for(int i = 1; i < n->getSize()-1; i++){
			if(n->getData(i) < num  && num < n->getData(i+1) ){
				res = search(num, n->getChild(i));
			}
		}
		if(n->getData(n->getSize()-1) < num && num < kd){
			res = search(num, n->getChild(n->getSize()-1));
		}
		if(res == NULL){
			return n;
		}
		
		return res;
		
	}
	
	void print(){
		cout << "Size: " << size << endl;
		root->print();
	}
	
	
};



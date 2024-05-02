#include <iostream>
#include <cstdlib>
#include <string>     
#include <bits/stdc++.h>

using namespace std;

class Node {

	Node* parent;
	int size;
	int* data;
	Node** children;
	
	public:
	Node(int num, Node* parent){
		data = (int*)malloc(4 * sizeof(int));
		data[0] = num;
		size = 1;
		children = (Node**)calloc(5, sizeof(Node*));
		this->parent = parent;
	}
	
	void print() {
    print("");
	}

	void print(string prefix) {
    if (size == 0) {
        cout << prefix << "- Empty\n";
        return;
    }
    
    cout << prefix;
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    for (int i = 0; i <= size; i++) {
        if (children[i]){
        	 children[i]->print(prefix + "--");
		} 
  	  }
	}

	
	void setChildrens(Node* wp, Node* w2p, int pos){
		for(int i = size; i >= pos; i--){
			children[i+1] = children[i];
		}
		children[pos] = wp;
		children[pos+1] = w2p;	
	
	}
	Node* getChild(int i){
		return children[i];
	
	}
	
	Node* getParent(){
		return parent;
	}
	
	int indexOf(Node* child){
		for(int i = 0; i < size; i++){
			if(child == children[i]){
				return i;
			}
		}
	}
	int getData(int i){
		return data[i];
	}
	int getSize(){
		return size;
	}
	
	bool insertValue(int num){
		int i;
		for(i = size; i > 0; i--){
			if(data[i-1] > num){
				data[i] = data[i-1];
			}
			else {
				break;
			}
		}
		data[i] = num;
		return ++size != 4;
		
	}
};

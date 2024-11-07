#include "MyHashTable.h"
#include "MyLinkedList.h"
#include <string>
#include <cmath>
#include <functional>

using namespace std;

MyHashTable::MyHashTable(){ //O(1)
    this->size=0;
    this->sizeA=11;
    this->tabla=new MyLinkedList[this->sizeA];
}

MyHashTable::~MyHashTable(){ //O(n)
    delete[] this->tabla;
}

bool MyHashTable::isEmpty(){ //O(1)
    if(this->size==0){
        return true;
    }else{
        return false;
    }
}

int MyHashTable::getpos(string key){ //O(1)
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}

void MyHashTable::put(string key,int value){ //O(1) en el peor de los casos O(n)
    int pos=this->getpos(key);
    this->tabla[pos].insertFirst(key,value);
    this->size++;
    if(this->size>0.75*this->sizeA){
        this->rehashing();
    }
}

int MyHashTable::get(string key){ //O(1) en el peor de los casos O(n)
    int pos=this->getpos(key);
    return this->tabla[pos].getAt(key);
}

void MyHashTable::remove(string key){ //O(1) en el peor de los casos O(n)
    int pos=this->getpos(key);
    this->tabla[pos].removeAt(key);
    this->size--;
}

void MyHashTable::rehashing(){ //O(n)
    MyLinkedList*tmp=this->tabla;
    int tmpSizeA=this->sizeA;
    this->sizeA=2*this->sizeA+1;
    this->tabla=new MyLinkedList[this->sizeA];
    for(int i=0;i<tmpSizeA;i++){
        MyNodoLL*current=tmp[i].head;
        while(current!=nullptr){
            this->put(current->key,current->data);
            current=current->next;
        }
    }
    delete[] tmp;
}


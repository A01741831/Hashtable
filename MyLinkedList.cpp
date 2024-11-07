#include "MyLinkedList.h"
#include <stdexcept>
using namespace std;

MyLinkedList::MyLinkedList(){ //O(1)
    this->size=0;
    this->head=this->tail=nullptr;
}

MyLinkedList::~MyLinkedList(){ //O(n)
    while(this->size>0){
        this->removeFirst();
    }
}

int MyLinkedList::length(){ //O(1)
   return this->size;
}

bool MyLinkedList::isEmpty(){ //O(1)
    return this->size==0;
}

int MyLinkedList::getAt(string key){ //O(n)
    MyNodoLL* current=this->head;    //Regresar el valor asociado a la llave
    while(current!=nullptr){
        if(current->key==key){
            return current->data;
        }
        current=current->next;
    }
    throw invalid_argument("No se encontro la llave "+key+" en la tabla");
}

void MyLinkedList::insertFirst(string key,int data){ //O(1)
    MyNodoLL* nvo=new MyNodoLL(key,data,this->head);
    this->head=nvo;
    if (this->size==0){
        this->tail=nvo;
    }
    this->size++;
}

void MyLinkedList::removeFirst(){ //O(1)
    if(this->size>0){
    MyNodoLL*tmp=this->head;
    this->head=this->head->next;
    delete tmp;
    this->size--;
    if(this->size==0){
        this->tail=nullptr;
    }
    }else{
        throw invalid_argument("No se puede eliminar el primer elemento de una lista vacia");
    }
}

void MyLinkedList::removeAt(string key){ //O(n)
    if(this->size>0){
        if(this->head->key==key){
            this->removeFirst();
        }
        else{
            MyNodoLL*tmp=this->head;
            while(tmp->next!=nullptr && tmp->next->key!=key){
                tmp=tmp->next;
            }
            if(tmp->next!=nullptr){
                MyNodoLL*tmp2=tmp->next;
                tmp->next=tmp2->next;
                delete tmp2;
                this->size--;
            }
            else{
                throw invalid_argument("No se encontro la llave "+key+"en la tabla");
            }
        }
    }
    else{
        throw invalid_argument("No se puede eliminar un elemento de una lista vacia");
    }
}
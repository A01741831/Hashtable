#include "MyLinkedList.h"
#include <stdexcept>
using namespace std;

MyLinkedList::MyLinkedList(){
    this->size=0;
    this->head=this->tail=nullptr;
}

MyLinkedList::~MyLinkedList(){
    while(this->size>0){
        this->removeFirst();
    }
}

int MyLinkedList::length(){
   return this->size;
}

bool MyLinkedList::isEmpty(){
    return this->size==0;
}

int MyLinkedList::getAt(string key){ //Regrsar el valor asociado a la llave
    MyNodoLL* current=this->head;
    while(current!=nullptr){
        if(current->key==key){
            return current->data;
        }
    }
    throw invalid_argument("No se encontro la llave "+key+" en la tabla");
}

/*void MyLinkedList::setAt(int pos,int data){
    if(this->size>0){
    MyNodoLL*tmp=this->head;
    for(int i=0;i<pos;i++){
        tmp=tmp->next;
    }
    tmp->data=data;
    }else{
        throw invalid_argument("No se puede modificar un elemento de una lista vacia");
    }
}*/

void MyLinkedList::insertFirst(string key,int data){
    MyNodoLL* nvo=new MyNodoLL(key,data,this->head);
    nvo->next=this->head;
    this->head=nvo;
    this->size++;
}

void MyLinkedList::removeFirst(){
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

/*void MyLinkedList::removeLast(){
    if(this->size>0){
    if(this->size==1){
        delete this->head;
        this->head=this->tail=nullptr;
    }else{
        MyNodoLL*tmp=this->head;
        while(tmp->next!=this->tail){
            tmp=tmp->next;
        }
        delete this->tail;
        this->tail=tmp;
        this->tail->next=nullptr;
    }
    this->size--;
    }else{
        throw invalid_argument("No se puede eliminar el ultimo elemento de una lista vacia");
    }
}*/

void MyLinkedList::removeAt(string key){
    if(this->size>0){
    if(pos==0){
        this->removeFirst();
    }else if(pos==this->size-1){
        this->removeLast();
    }else{
        MyNodoLL*tmp=this->head;
        for(int i=0;i<pos-1;i++){
            tmp=tmp->next;
        }
        MyNodoLL*tmp2=tmp->next;
        tmp->next=tmp2->next;
        delete tmp2;
        this->size--;
    }
    }else{
        throw invalid_argument("No se puede eliminar un elemento de una lista vacia");
    }
}
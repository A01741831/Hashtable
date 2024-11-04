#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H
#include <string>
#include <iostream>

using namespace std;

struct MyNodoLL{
    string key;
    int data;
    MyNodoLL*next;

    MyNodoLL(string key,int data,MyNodoLL*next){
        this->key=key;
        this->data=data;
        this->next=next;
    }

    MyNodoLL(string key,int data):MyNodoLL(key,data,nullptr){}
};

class MyLinkedList{
    public:
        int size;
        MyNodoLL*head;
        MyNodoLL*tail;
    //public:
        MyLinkedList(); //
        ~MyLinkedList();
        int length(); //
        bool isEmpty(); //
        int getAt(string key);
        //void setAt(int pos,int data);
        void insertFirst(string key,int data); //
        void removeFirst(); //
        //void removeLast();
        void removeAt(string key);
        friend ostream& operator<<(ostream& os, const MyLinkedList& l){
        MyNodoLL* current=l.head;
        for(int i=0;i<l.size;i++){
            os<<"["<<current->key<<","<<current->data<<"]";
            current=current->next;
        }
        return os;
        }
};

#endif
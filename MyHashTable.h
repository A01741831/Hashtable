#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include <string>
#include "MyLinkedList.h"

using namespace std;

class MyHashTable{
    public:
    int size; //# de elementos almacenados en la hash table
    int sizeA; //tamaño del arreglo
    MyLinkedList* tabla; //Arreglo de Listas enlazadas

    void rehashing(); // se llama cuando al hacer el put el factor de carga el mayor a 0.75
    int getpos(string key);

    MyHashTable();
    ~MyHashTable();
    bool isEmpty();
    void put(string key,int value);
    int get(string key);
    void remove(string key);
};

#endif
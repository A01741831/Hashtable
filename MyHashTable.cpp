#include "MyHashTable.h"
#include "MyLinkedList.h"
#include <string>
#include <cmath>
#include <functional>

using namespace std;

MyHashTable::MyHashTable(){
    this->size=0;
    this->sizeA=11;
    this->tabla=new MyLinkedList[this->sizeA];
}

MyHashTable::~MyHashTable(){

}

int MyHashTable::getpos(string key){
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}
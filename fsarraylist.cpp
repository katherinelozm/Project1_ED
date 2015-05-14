#include "object.h"
#include "tdalist.h"
#include "FSArrayList.h"
#include <stddef.h>

FSArrayList::FSArrayList(int capacity){
    this->capacity = capacity;
    data = new Object*[capacity];
}

FSArrayList::~FSArrayList(){
    for (int i = 0; i < size; i++){
        delete data[i];
    }
    delete[] data;
}

bool FSArrayList::insert(Object* E, int pos) {
    if (pos < 0 || pos > size)
        return false;
    if (size ==  capacity)
        return false;
    if (pos != size)
        for (int i = size; i > pos; i--)
            data[i] = data[i-1];
        data[pos] = E;
        size++;
        return true;
}

int FSArrayList::indexOf(Object* other)const {
    for (int i=0; i < size; i++){
        if (data[i]->equals(other))
                return i;
    }
    return -1;
}

Object* FSArrayList::get(unsigned index)const {
    if (index < 0 || index >= size)
        return NULL;
    return data[index];
}

bool FSArrayList::erase(unsigned pos) {
    if (pos < 0 || pos > size){
        return false;
    }
    if (pos == size - 1){
        data[pos] = NULL;
        size--;
        return true;
    } else {
        for (int i = pos; i < size-1; i++){
            data[i] =  data[i+1];
        }
        data[size-1] = NULL;
        size--;
        return true;
    }
    return false;
}

int FSArrayList::prev(int pos) const {
    return -1;
}

int FSArrayList::next(int pos) const {
    return -1;
}

void FSArrayList::reset() {
    for (int i = 0; i < size; i++){
        delete data[i];
    }
    delete[] data;
    data = new Object*[capacity];
    size = 0;
}

Object* FSArrayList::first()const {
    if (size>0)
        return data[0];
    return NULL;
}

Object* FSArrayList::last()const {
    if (size>0)
        return data[size-1];
    return NULL;
}

void FSArrayList::print()const {
    for (int i=0; i < size; i++){
        data[i]->print();
    }
}

bool FSArrayList::isFull()const {
    if (size == capacity){
        return true;
    } else {
        return false;
    }
}

int FSArrayList::getCapacity()const{
    return capacity;
}

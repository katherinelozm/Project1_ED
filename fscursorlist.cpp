#include "object.h"
#include "tdalist.h"
#include <stddef.h>
#include "fscursorlist.h"

FSCursorList::FSCursorList(int capacity){
	this->capacity=capacity;
	rows = new Row[capacity];
	head = -1;
}

FSCursorList::~FSCursorList(){
	delete[] rows;
}

bool FSCursorList::insert(Object* E, int p){
	if (p<0 || p>size){
		return false;
	}
	if (size==capacity){
		return false;
	}
	int neo = nextAvail();
	if (p==0){
		if (head == -1){
			head = neo;
			rows[head].next = -1;
			rows[head].data = E;
		} else {
			rows[neo].next = head;
			head = neo;
			rows[head].data = E;
		}
	} else {
		int temp = head;
		for (int i = 0; i < p-1; i++){
			temp = rows[temp].next;
		}
		rows[neo].next = rows[temp].next;
		rows[temp].next = neo;
		rows[neo].data = E;
	}
	size++;
	return true;
}

int FSCursorList::indexOf(Object* E)const{
	int tmp = head;
	for(int i=0; i<size;i++){
		if(rows[tmp].data==E){
			return i;
		}
		tmp = rows[tmp].next;
	}
	return -1;
}

Object* FSCursorList::get(unsigned p)const{
	if(p<0||p>size){
		return NULL;
	}
	int tmp = head;
	for(int i=0; i<p;i++){
		tmp = rows[tmp].next;
	}
	return rows[tmp].data;
}

Object* FSCursorList::erase(unsigned p){
	if (p<0 || p>=size){
		return NULL;
	}
	Object* E = rows[p].data;
	if (p == size-1){
		rows[p].data = NULL;
	} else if (p == 0){
		head = rows[p].next;
		rows[p].next = -1;
		rows[p].data = NULL;
	} else {
		int temp = head;
		for (int i = 0; i < p; i++){
			temp = rows[temp].next;
		}
		rows[temp].next = rows[p].next;
		rows[p].next = -1;
		rows[p].data = NULL;
	}
	size--;
	return E;
}

int FSCursorList::prev(int pos) const{
	return -1;
}

int FSCursorList::next(int pos) const{
	int tmp = head;
	for(int i=0; i<pos; i++){
		tmp = rows[tmp].next;
	}
	return rows[tmp].next;
}

void FSCursorList::reset(){
	delete[] rows;
	rows = new Row[capacity];
	size = 0;
}

Object* FSCursorList::first()const{
	if(head==-1)
		return NULL;
	return rows[head].data;
}

Object* FSCursorList::last()const{
	int tmp = head;
	for(int i=0; i<size;i++){
		tmp = rows[tmp].next;
	}
	return rows[tmp].data;
}

void FSCursorList::print()const{
	int tmp = head;
	for(int i = 0; i< size;i++){
		rows[tmp].data->print();
		tmp = rows[tmp].next;
	}
}

bool FSCursorList::isEmpty()const{
	return size==0;
}

bool FSCursorList::isFull()const{
	return size==capacity;
}

int FSCursorList::getCapacity()const{
	return capacity;
} 

int FSCursorList::nextAvail(){
	for (int i = 0; i < size; i++){
		if (rows[i].data == NULL){
			return i;
		}
	}
	return size;
}
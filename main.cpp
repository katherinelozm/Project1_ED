#include <iostream>
#include <cstdlib>
#include "tdalist.h"
#include "fsarraylist.h"
#include "linkedlist.h"
#include "fscursorlist.h"
#include "integer.h"
#include <ctime>
#include <cstdio>

using namespace std;

void insertList(TDAList* list);
void eraseList(TDAList* list);
void getList(TDAList* list);
void indexOfList(TDAList* list);
void firstList(TDAList* list);
void lastList(TDAList* list);

int main(int argc, char *argv[]){
  srand (time(0));
  TDAList* lista = new FSArrayList(1000);
  TDAList* lista2 = new LinkedList();
  TDAList* lista3 = new FSCursorList(1000);
  
  //INSERT
  cout << "INSERT" << endl;
  insertList(lista);
  cout << endl << endl << endl;
  insertList(lista2);
  cout << endl << endl << endl;
  insertList(lista3);
  cout << endl << endl << endl;
  //ERASE
  cout << "ERASE" << endl;
  eraseList(lista);
  cout << endl << endl << endl;
  eraseList(lista2);
  cout << endl << endl << endl;
  eraseList(lista3);
  cout << endl << endl << endl;
  //GET
  cout << "GET" << endl;
  getList(lista);
  cout << endl << endl << endl;
  getList(lista2);
  cout << endl << endl << endl;
  getList(lista3);
  cout << endl << endl << endl;
  //INDEXOF
  cout << "INDEXOF" << endl;
  indexOfList(lista);
  cout << endl << endl << endl;
  indexOfList(lista2);
  cout << endl << endl << endl;
  indexOfList(lista3);
  cout << endl << endl << endl;
  //FIRST
  cout << "FIRST" << endl;
  firstList(lista);
  cout << endl << endl << endl;
  firstList(lista2);
  cout << endl << endl << endl;
  firstList(lista3);
  cout << endl << endl << endl;
  //LAST
  cout << "LAST" << endl;
  lastList(lista);
  cout << endl << endl << endl;
  lastList(lista2);
  cout << endl << endl << endl;
  lastList(lista3);
  cout << endl << endl << endl;

  delete lista;
  delete lista2;
  delete lista3;
  return 0;
}

void insertList(TDAList* list){
  int val = 1000 + rand() % 1000;
  clock_t t = clock();
  list->insert(new Integer(val), 0);
  t = clock() - t;
  printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
  for (int i = 0; i < 999; i++){
    int val = 1000 + rand() % 1000;
    t = clock();
    list->insert(new Integer(val), rand() % list->getSize());
    t = clock() - t;
    printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
  }
}

void eraseList(TDAList* list){
  insertList(list);
  for (int i = 0; i < 1000; i++){
    clock_t t;
    t = clock();
    list->erase(rand() % list->getSize());
    t = clock() - t;
    printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
  }
}

void getList(TDAList* list){
  insertList(list);
  for (int i = 0; i < 1000; i++){
    clock_t t = clock();
    list->get(rand() % list->getSize());
    t = clock() - t;
    printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
  }
}

void indexOfList(TDAList* list){
  for (int i = 0; i < 1000; i++){
    clock_t t;
    int val = 1000 + rand() % 1000;
    t = clock();
    list->indexOf(new Integer(val));
    t = clock() - t;
    printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
  }
}

void firstList(TDAList* list){
  int val = 1000 + rand() % 1000;
  list->insert(new Integer(val), 0);
  clock_t t = clock();
  list->first();
  t = clock() - t;
  printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
  for (int i = 0; i < 999; i++){
    val = 1000 + rand() % 1000;
    list->insert(new Integer(val), list->getSize());
    t = clock();
    list->first();
    t = clock() - t;
    printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
  }
}

void lastList(TDAList* list){
  int val = 1000 + rand() % 1000;
  list->insert(new Integer(val), 0);
  clock_t t = clock();
  list->last();
  t = clock() - t;
  printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
  for (int i = 0; i < 999; i++){
    val = 1000 + rand() % 1000;
    list->insert(new Integer(val), list->getSize());
    t = clock();
    list->last();
    t = clock() - t;
    printf ("%f\n",((float)t)/CLOCKS_PER_SEC);
  }
}


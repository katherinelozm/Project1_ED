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

int main(int argc, char *argv[]){
  srand (time(0));
  TDAList* lista = new FSArrayList(1000);
  TDAList* lista2 = new LinkedList();
  TDAList* lista3 = new FSCursorList(1000);
  cout << endl << endl << endl << "INSERT" << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    int val = 1000 + rand() % 1000;
    t = clock();
    lista->insert(new Integer(val), rand() % lista->getSize());
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    int val = 1000 + rand() % 1000;
    t = clock();
    lista2->insert(new Integer(val), rand() % lista2->getSize());
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    int val = 1000 + rand() % 1000;
    t = clock();
    lista3->insert(new Integer(val), rand() % lista3->getSize());
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl << "ERASE" << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    t = clock();
    lista->erase(rand() % lista->getSize());
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    t = clock();
    lista2->erase(rand() % lista2->getSize());
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    t = clock();
    lista3->erase(rand() % lista3->getSize());
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl << "GET" << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    t = clock();
    lista->get(rand() % lista->getSize());
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    t = clock();
    lista2->get(rand() % lista2->getSize());
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    t = clock();
    lista3->get(rand() % lista3->getSize());
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl << "INDEXOF" << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    int val = 1000 + rand() % 1000;
    t = clock();
    lista->indexOf(new Integer(val));
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    int val = 1000 + rand() % 1000;
    t = clock();
    lista2->indexOf(new Integer(val));
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    int val = 1000 + rand() % 1000;
    t = clock();
    lista3->indexOf(new Integer(val));
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl << "FIRST" << endl << endl << endl;
  lista = new FSArrayList(1000);
  lista2 = new LinkedList();
  lista3 = new FSCursorList(1000);
  for (int i = 0; i < 1000; i++){
    clock_t t;
    int val = 1000 + rand() % 1000;
    lista->insert(new Integer(val), 0);
    t = clock();
    lista->first();
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    int val = 1000 + rand() % 1000;
    lista2->insert(new Integer(val), 0);
    t = clock();
    lista2->first();
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    int val = 1000 + rand() % 1000;
    lista3->insert(new Integer(val), 0);
    t = clock();
    lista3->first();
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl << "LAST" << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    t = clock();
    lista->erase(lista->getSize()-1);
    lista->last();
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    t = clock();
    lista2->erase(lista2->getSize()-1);
    lista2->last();
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  cout << endl << endl << endl;
  for (int i = 0; i < 1000; i++){
    clock_t t;
    t = clock();
    lista3->erase(lista3->getSize()-1);
    lista3->last();
    t = clock() - t;
    printf ("(%f seconds).\n",((float)t)/CLOCKS_PER_SEC);
  }
  delete lista;
  delete lista2;
  delete lista3;
  return 0;
}

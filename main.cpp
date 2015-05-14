#include <iostream>
#include <cstdlib>
#include "tdalist.h"
#include "linkedlist.h"
#include "integer.h"

using namespace std;

/*
* Programa de Prueba para el TDALista implementado con LinkedList
* -- Listas Doblemente Enlazadas --
* Se prueban las siguientes operaciones:
*  - Inserci�n
*  - Eliminaci�n
*  - Listado
*  - B�squeda
*/


int menu();

int main(int argc, char *argv[])
{
    // En el caso de que quisieramos utilizar otra implementaci�n
    // S�LO se tendr�a que cambiar esta l�nea.
    TDAList* lista = new LinkedList();
    Integer* intTemp;
    int val, pos;
    bool flag = true;
    while (flag)
    {
        switch(menu())
        {
           case 1:
               cout << "Valor a Insertar: " ;
               cin >> val;
               cout << "Posicion a Insertar: ";
               cin >> pos;
               if (lista->insert(new Integer(val), pos))
                  cout << "Exito en la Insercion" << endl;
               else
                  cout << "Fracaso en la Insercion" << endl;
               break;
           case 2:
               cout << "Posicion de la que quiere Borrar: ";
               cin >> pos;
               if (lista->erase(pos))
                  cout << "Exito en el Borrado" << endl;
               else
                  cout << "Fracaso en el Borrado" << endl;
               break;
           case 3:
               lista->print();
               break;
           case 4:
               cout << "Valor del Elemento a Buscar: ";
               cin >> val;
               intTemp = new Integer(val);
               pos = lista->indexOf(intTemp);
               delete intTemp;
               cout << "El Elemento esta en la posicion = " << pos << endl;
               break;
           case 9:
               flag = false;
        }
    }
    delete lista;

    return 0;
}
int menu()
{
    cout << "1. Insertar "  << endl;
    cout << "2. Borrar "  << endl;
    cout << "3. Listar " << endl;
    cout << "4. Buscar " << endl;
    cout << "9. Salir " << endl;
    cout << endl << "Opcion? ";
    int opcion;
    cin >> opcion;
    return opcion;
}

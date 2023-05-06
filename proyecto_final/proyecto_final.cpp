// proyecto_final.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Lista.h"
using namespace std;
using namespace std;



int main()
{

    Lista* list = new Lista;
    int resp, buscar_id;
    do {
        cout << "*** Almacen de libros ***" << endl;
        cout << "1. Altas" << endl;
        cout << "2. Bajas" << endl;
        cout << "3. Consultar" << endl;
        cout << "4. Modificar registro" << endl;
        cout << "5. Salir" << endl;
        cin >> resp;
        switch (resp) {
        case 1: {
            cout << "*** ALTAS ***" << endl;
            cout << "1. Insertar al inicio" << endl;
            cout << "2. Insertar por posicion" << endl;
            cout << "3. Insertar al final" << endl;
            cin >> resp;
            switch (resp) {
            case 1: {


                break;
            }case 2: {

                break;
            }case 3: {


                break;
            }default: {

                cout << "Ingrese una opcion valida" << endl;
                break;
            }       
            }
            resp = 0;
            break;
        }case 2: {
            cout << "*** Bajas ***" << endl;
            cout << "1. Eliminar libro" << endl;
            cout << "2. Vaciar lista" << endl;
            cin >> resp;
            switch (resp) {
            case 1: {


                break;
            }case 2: {

                break;
            }default: {

                cout << "Ingrese una opcion valida" << endl;
                break;
            }
            }
            resp = 0;

            break;
        }case 3: {
            cout << "*** CONSULTAR ***" << endl;
            cout << "Ingrese el ID del libro que desea buscar: ";
            cin >> buscar_id;


            break;
        }case 4: {
 
            cout << "MODIFICAR REGISTRO" << endl;
            cout << "Ingrese el ID del libro que desea modificar: ";
            cin >> buscar_id;

            break;
        }case 5: {

            cout << "Saliendo del programa..." << endl;
            break;

        }default: {
            cout << "Ingrese una opcion correcta!" << endl;
            break;
        }
        }
        
    } while (resp != 5);
    cout << "Hello World!\n";



}

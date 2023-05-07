// proyecto_final.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Lista.h"
using namespace std;
using namespace std;



int main()
{

    Lista* list = new Lista;
    libro book;
    int resp, buscar_id, id, paginas, posicion;
    char autor[30], titulo[30];
    float precio;
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
                cout << "*** Insertar producto al inicio ***" << endl;
                id = rand();
                book.setId(id);
                cout << "Ingrese el precio del libro: ";
                cin >> precio;
                book.setPrecio(precio);
                cout << "Ingrese el numero de paginas del libro: ";
                cin >> paginas;
                book.setPaginas(paginas);
                cout << "Ingrese el titulo del libro: ";
                cin.ignore();
                cin.getline(titulo, 30);
                book.setTitulo(titulo);
                //cin.ignore();
                cout << "Ingrese el nombre del autor del libro: ";
                cin.getline(autor, 30);
                book.setAutor(autor);
                list->insertarInicio(book);
                cout << "Producto ingresado con exito!" << endl;

                break;
            }case 2: {
                cout << "*** Insertar producto por posicion ***" << endl;
                if (list->vacia() == false) {
                    cout << "Escriba la posicion en la que quiere insertar el elemento: ";
                    cin >> posicion;
                    if (posicion > 0 && posicion <= list->tamanoLista()) {
                        id = rand();
                        book.setId(id);
                        cout << "Ingrese la posicion a la que desea ingresar un libro: ";
                        cin >> posicion;
                        cout << "Ingrese el precio del libro: ";
                        cin >> precio;
                        book.setPrecio(precio);
                        cout << "Ingrese el numero de paginas del libro: ";
                        cin >> paginas;
                        book.setPaginas(paginas);
                        cout << "Ingrese el titulo del libro: ";
                        cin.ignore();
                        cin.getline(titulo, 30);
                        book.setTitulo(titulo);
                        
                        cout << "Ingrese el nombre del autor del libro: ";
                        cin.getline(autor, 30);
                        book.setAutor(autor);
                        list->insertarPosicion(posicion, book);
                        cout << "Producto ingresado con exito!" << endl;
                    }if (posicion == list->tamanoLista() + 1) {
                        
                        id = rand();
                        book.setId(id);
                        cout << "Ingrese el precio del libro: ";
                        cin >> precio;
                        book.setPrecio(precio);
                        cout << "Ingrese el numero de paginas del libro: ";
                        cin >> paginas;
                        book.setPaginas(paginas);
                        cout << "Ingrese el titulo del libro: ";
                        cin.ignore();
                        cin.getline(titulo, 30);
                        book.setTitulo(titulo);
                        
                        cout << "Ingrese el nombre del autor del libro: ";
                        cin.getline(autor, 30);
                        book.setAutor(autor);
                        cout << "Producto ingresado con exito!" << endl;
                        list->insertarFinal(book);
                    }
                    else {
                        cout << "La posicion deseada no es valida" << endl;
                    }
                }
                break;
            }case 3: {
                cout << "*** Insertar al final ***" << endl;
                id = rand();
                book.setId(id);
                cout << "Ingrese el precio del libro: ";
                cin >> precio;
                book.setPrecio(precio);
                cout << "Ingrese el numero de paginas del libro: ";
                cin >> paginas;
                book.setPaginas(paginas);
                cout << "Ingrese el titulo del libro: ";
                cin.ignore();
                cin.getline(titulo, 30);
                book.setTitulo(titulo);

                cout << "Ingrese el nombre del autor del libro: ";
                cin.getline(autor, 30);
                book.setAutor(autor);
                cout << "Producto ingresado con exito!" << endl;
                list->insertarFinal(book);

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
                cout << "*** Eliminar libro ***" << endl;
                if (list->vacia() == false) {

                    cout << "Ingrese el id del libro: ";
                    cin >> id;
                    book.setId(id);

                    list->eliminar(book);
                }

                break;
            }case 2: {
                cout << "*** Eliminando todo ***" << endl;
                cout << endl;
                if (list->vacia() == false) {
                    list->eliminarTodo();
                }


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
            cout << "1. Mostrar todo" << endl;
            cout << "2. Mostrar libro" << endl;
            cin >> resp;
            switch (resp) {
            case 1: {
                list->mostrar();
                break;
            }case 2: {
            cout << "Ingrese el titulo del libro: ";
            cin.ignore();
            cin.getline(titulo, 30);
            book.setTitulo(titulo);
        
            cout << "Ingrese el nombre del autor del libro: ";
            cin.getline(autor, 30);
            book.setAutor(autor);
            
            list->mostrarLibro( book);

                break;
            }default: {
                cout << "Ingresa una opcion valida" << endl;
            }
            }
            resp = 0;
            break;
        }case 4: {
 
            cout << "MODIFICAR REGISTRO" << endl;
            cout << "Ingrese el ID del libro que desea modificar: ";
            cin >> buscar_id;
            book.setId(buscar_id);
            list->modificarRegistro(book);
            cout << "Registro modificado" << endl;
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
  



}

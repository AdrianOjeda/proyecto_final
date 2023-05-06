#include "Lista.h"
#include <iostream>
using namespace std;


Lista::Lista() {
	header = nullptr;
	tail = nullptr;

}
Lista::Lista(Nodo* ptr, Nodo* ptrtail) {
	header = ptr;
	tail = ptrtail;

}


void Lista::insertarInicio(libro book) {
	Nodo* temp = new Nodo(book, nullptr, nullptr);
	if (!header) {
		header = temp;
		tail = temp;

	}
	else {
		
		temp->sig = header;
		header->ant = temp;
		header = temp;
	}
}

void Lista::mostrar() {
	Nodo* aux = header;

	if (header) {
		while (aux != tail->sig) {
			cout << "Titulo: " << aux->book.getTitulo() << "Autor: " << aux->book.getAutor() << " | Precio: " << aux->book.getPrecio() << "Paginas: " << aux->book.getPaginas() << " | Id: " << aux->book.getId() << endl;
			aux = aux->sig;
		}
		cout << endl;
	}
	else {
		cout << endl << "Lista vacia" << endl;
	}

}

void Lista::eliminarTodo() {

	Nodo* aux = header;
	while (aux != nullptr) {
		Nodo* temp = aux;
		aux = aux->sig;
		delete temp;
	}
	header = nullptr;
	tail = nullptr;
	delete aux;
	cout << "Lista eliminada con exito!" << endl;
}

void Lista::insertarFinal(libro book) {
	Nodo* temp = new Nodo(book, nullptr, nullptr);
	Nodo* ultimo = header;
	temp->ant = tail;
	
	tail->sig = temp;
	tail = temp;
	tail->sig = nullptr;
	cout << "Libro ingresado con exito!" << endl;

}
void Lista::eliminar(libro book) {

	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	bool bandera = true;
	if (header != nullptr) {
		while (aux && bandera) {
			if (book.getId() == aux->book.getId()) {
				bandera = false;
			}
			else {
				auxAnterior = aux;
				aux = aux->sig;

			}
		}
		if (aux == nullptr) {
			cout << "No se encontro el libro" << endl;

		}
		else if (aux == header) {
			header = header->sig;
			//header->ant->sig = nullptr;
			delete aux;
			cout << "Libro eliminado con exito!" << endl;

		}
		else if (aux->sig == nullptr) {
			tail = tail->ant;
			tail->sig = nullptr;
			//aux->ant->sig=nullptr;

			//auxAnterior->sig = nullptr;
			delete aux;
			cout << "Libro eliminado con exito!" << endl;

		}
		else {

			aux->ant->sig = aux->sig;
			aux->sig->ant = aux->ant;
			//auxAnterior->sig = aux->sig;
			delete aux;
			cout << "Libro eliminado con exito!" << endl;
		}

	}
}

bool Lista::vacia() {

	if (header) {
		//cout << "hola" << endl;
		return false;
	}
	else {
		cout << endl << "Lista vacia" << endl;
		return true;
	}

}

int Lista::tamanoLista() {
	int contador = 0;
	Nodo* aux = header;
	while (aux != nullptr) {
		aux = aux->sig;
		contador++;

	}
	return contador;
}

void Lista::insertarPosicion(int posicion, libro book) {
	int contador = 0;
	Nodo* aux = header;
	//Nodo* auxAnterior = nullptr;
	Nodo* temp = new Nodo(book, nullptr, nullptr);
	if (posicion == 1) {
		temp->sig = header;
		header->ant = temp;
		header = temp;

		cout << "Libro ingresado con exito!" << endl;
	}
	else {
		while (contador < posicion - 1) {

			aux = aux->sig;
			contador++;

		}
		temp->sig = aux;
		temp->ant = aux->ant;
		aux->ant->sig = temp;
		aux->ant = temp;
		cout << "Libro ingresado con exito!" << endl;
	}

}

int Lista::buscar(libro book) {
	Nodo* aux = header;
	Nodo* auxAnterior = nullptr;
	int contador = 1;
	bool bandera = true;
	while (aux && bandera) {
		if (book.getId() == aux->book.getId()) {
			bandera = false;
		}
		else {
			auxAnterior = aux;
			aux = aux->sig;
			contador++;
		}
	}
	return contador;
}




void Lista::mergeSort(int contador, Lista* list) {
	Lista* derecha = new Lista;
	Lista* izquierda = new Lista;
	Nodo* aux = list->header;
	int med = contador / 2;
	int dif = contador % 2;
	int i, j;

	if (list->tamanoLista() > 1) {
		i = 0;
		while (aux && i < med) {
			izquierda->insertarInicio(aux->book);
			i++;
			aux = aux->sig;
		}
		j = 0;
		while (aux && j < med + dif) {
			derecha->insertarInicio(aux->book);
			j++;
			aux = aux->sig;
		}
		mergeSort(izquierda->tamanoLista(), izquierda);
		mergeSort(derecha->tamanoLista(), derecha);


		Nodo* iz = izquierda->header;
		Nodo* de = derecha->header;
		aux = list->header;
		i = 0;
		while (aux && iz && de) {
			if (iz->book.getId() < de->book.getId()) {
				aux->book = iz->book;
				iz = iz->sig;
				aux = aux->sig;
			}
			else {
				aux->book = de->book;
				de = de->sig;
				aux = aux->sig;

			}
		}
		if (iz) {
			while (iz) {
				aux->book = iz->book;
				iz = iz->sig;
				aux = aux->sig;


			}
		}
		if (de) {
			while (de) {
				aux->book = de->book;
				de = de->sig;
				aux = aux->sig;

			}

		}
	}

}
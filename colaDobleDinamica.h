//		Marcos Omar Martinez Navarro
//		207541732
//		i5887 - Sem. de Sol. de Estructura de Datos
//		D13
//		2017A

// 			Clase Cola heredando la clase Lista
#ifndef COLA_H
#define COLA_H

#include "listaDobleDinamica.h"

template <class Dato>
class Cola : public Lista<Dato>{
private:
	int frente;
	int fin;
public:
		Cola();
	int vacia( );
	int llena( );
	void encolar( Dato );
	Dato desencolar( );
	void eliminarNodo( int pos );
};

template <class Dato>
Cola<Dato>::Cola( ){
	frente = -1;
	fin = -1;
}

template <class Dato>
int Cola<Dato>::llena( ){
	return ( (fin + 1) % MAX ) == frente;
}

template <class Dato>
int Cola<Dato>::vacia( ){
	return frente == -1;
}

template <class Dato>
void Cola<Dato>::encolar( Dato d ){
	if( !llena( ) ){
		fin = ( (fin + 1) % MAX );
		this->agregar_final( d );
		if( frente == -1 )
			frente = 0;
	}
}

template <class Dato>
Dato Cola<Dato>::desencolar( ){
	Dato d;
	Nodo<Dato> *tmp;
	if( vacia( ) ) return d;
	else{
		
		d = this->getDato( frente );
		eliminarNodo( frente );
		if( frente == fin ){
			frente = -1;
			fin = -1;
		}else
			frente = ( frente + 1 ) % MAX;
		return d;
	}
}

template <class Dato>
void Cola<Dato>::eliminarNodo( int pos ){
	Nodo<Dato> *actual = this->posicion( pos );
	delete &actual->dato;
}
#endif

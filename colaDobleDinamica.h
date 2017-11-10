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
	Nodo<Dato> *frente;
	Nodo<Dato> *fin;
public:
		Cola();
	bool vacia( );
	bool llena( );
	void encolar( Dato );
	Dato desencolar( );
};

template <class Dato>
Cola<Dato>::Cola( ){
	frente = nullptr;
	fin = nullptr;
}

template <class Dato>
bool Cola<Dato>::llena( ){
	return this->llena();
}

template <class Dato>
bool Cola<Dato>::vacia( ){
	return this->vacia();
}

template <class Dato>
void Cola<Dato>::encolar( Dato d ){
	if( !llena( ) ){
	    this->agregar_final( d );

		if( this->getLongitud() == 1 ){
            frente = this->primer();
            fin = this->primer();
		}else{
		    fin = this->ultimo();
		}
	}
}

template <class Dato>
Dato Cola<Dato>::desencolar( ){
	Dato d;
	if( vacia( ) ) return d;
	else{
	    Nodo<Dato> *tmp = frente;
		d = frente->dato;
		frente = frente->der;
		fin->der = frente;
		this->eliminarDato( this->getLongitud() - 1);
        return d;
	}
}
#endif

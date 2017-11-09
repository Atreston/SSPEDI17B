//	Marcos Omar Martinez Navarro
//	207541732
//	i5887 - Sem. de Sol. de Estructura de Datos
//	D13
//	2017B
//	

#ifndef PILASIMPLEDINAMICA_H
#define PILASIMPLEDINAMICA_H

#include "listaDobleDinamica.h"

template <class T>
class Pila : public Lista<T>{
public:
	Pila();
	void apilar(T dato);
	T desapilar();
	T tope( );
};

template <class T>
Pila<T>::Pila(){
	
}
template <class T>
void Pila<T>::apilar(T dato){
	this->agregar(dato);
}
template <class T>
T Pila<T>::desapilar(){
	T tmp;
	tmp = this->getDato(this->getLongitud()-1);
	this->eliminarDato(this->getLongitud()-1);
	return tmp;
}

template <class T>
T Pila<T>::tope( ){
	T dato;
	dato = this->getDato(this->getLongitud()-1);
	return dato;
}

#endif

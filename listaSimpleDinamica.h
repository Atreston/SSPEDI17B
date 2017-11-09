//	Marcos Omar Martinez Navarro
//	207541732
//	i5887 - Sem. de Sol. de Estructura de Datos
//	D13
//	2017B
//	


#ifndef LISTASD_H
#define LISTASD_H

#define MAX 10
#define nullptr NULL

template <class T>
class Nodo{
public:
	T dato;
	Nodo * der;
	Nodo( ){
        der = nullptr;
    }
    Nodo( T d ){
        dato = d;
        der = nullptr;
    }
};

template <class T>
class Lista
	{
	public:
		Lista();
		bool vacia( );
		bool ultimo( );
		bool Primero( );
		Nodo<T>* posicion( unsigned int );
		T Actual( );
		void agregar( T );
		T getDato( unsigned int );
		unsigned int getLongitud();
		unsigned int capacidad( );
		bool eliminarDato(int);
		void intercambio(unsigned int pos1, unsigned int pos2);
		void intercambio2(unsigned int pos1, unsigned int pos2);
		void ordenarBurbuja( );
		void quicksort( int, int );
		int busquedaLineal( T clave );
		int busquedaBinaria( T clave, int Iabajo, int Iarriba ); 
		Nodo<T>* operator[]( unsigned int pos );
	private:
		Nodo<T> *primero;
		Nodo<T> *actual;
		unsigned int indice;
	};

//					Constructor
template <class T>
Lista<T>::Lista(){
	indice = 0;
	primero = nullptr;
	actual = nullptr;
}

//					Vacia
template <class T>
bool Lista<T>::vacia( ){
	if( primero == nullptr )
		return true;
	else
		return false;
}

//					Reccorrer hasta ultima posicion
template <class T>
bool Lista<T>::ultimo( ){
	if( !vacia( ) ){
		actual = primero;
		while( actual->der != nullptr )
			actual = actual->der;
		return true;
	}else
		return false;
}

//					Devolver primera posicion
template <class T>
bool Lista<T>::Primero( ){
	if( !vacia( ) ){
		actual = primero;
		return true;
	}else	return false;
}

//					Recorrer a la posicion marcada
template <class T>
Nodo<T>* Lista<T>::posicion( unsigned int pos ){
	if( !vacia( ) && pos < indice ){
		actual = primero;
		for(int i = 0; i < pos; i++)
			actual = actual->der;
		return actual;
	}else return nullptr;
}

//					Obtener contenido de nodo actual
template <class T>
T Lista<T>::Actual( ){
	if( !vacia( ) ) return actual->dato;
}

//					Agregar
template <class T>
void Lista<T>::agregar(T dato){
	if( vacia() ){
		primero = new Nodo<T>( dato );
		indice++;
	}else{
		ultimo( );
		actual->der = new Nodo<T>( dato );
		indice++;
	}
}

template <class T>
T Lista<T>::getDato( unsigned int i ){
	return posicion(i)->dato;
}

//					obtener numero de datos
template <class T>
unsigned int Lista<T>::getLongitud(){
	return indice;
}

//				Retorna la capacidad de la lista
template <class T>
unsigned int Lista<T>::capacidad( ){
	return MAX;
}

//					Eliminar
template <class T>
bool Lista<T>::eliminarDato( int pos ){
	//validar si pos esta en el rango
	//recorrer el arreglo desde pos hasta indice
	//decrementar indice
	Nodo<T> *tmp;
	if( indice != 0 && pos < indice ){
		if( indice == 1 ){
			delete primero;
			actual = primero = nullptr;
		}else{
			tmp = posicion( pos - 1 );
			actual = posicion( pos );
			tmp->der = actual->der;
			delete actual;
		}
		indice--;
		return true;
	}
	else return false;
}

template<class T>
void Lista<T>::intercambio(unsigned int pos1, unsigned int pos2){
	T tmp = posicion(pos1)->dato;
	posicion(pos1)->dato = posicion(pos2)->dato;
	posicion(pos2)->dato = tmp;
}

template<class T>
void Lista<T>::intercambio2(unsigned int pos1, unsigned int pos2){
	if( pos1 == 0 ){
		Nodo<T> *ant = posicion(pos2 - 1);
		Nodo<T> *a = posicion(pos1);
		Nodo<T> *b = posicion(pos2);
		Nodo<T> *tmp = b->der;
		ant->der = a;
		b->der = a->der;
		a->der = tmp;
		primero = b;
	}else if( pos2 == 0 ){
		Nodo<T> *ant = posicion(pos2 - 1);
		Nodo<T> *a = posicion(pos1);
		Nodo<T> *b = posicion(pos2);
		Nodo<T> *tmp = a->der;
		ant->der = b;
		a->der = b->der;
		b->der = tmp;
		primero = b;
	}else{
		Nodo<T> *a, *ant_a, *b, *ant_b, *tmp;
		a = posicion(pos1);
		ant_a = posicion(pos1 - 1);
		b = posicion(pos2);
		ant_b = posicion(pos2 - 1);
		tmp = b->der;
		b->der = a->der;
		a->der = tmp;
		ant_a->der = b;
		ant_b->der = a;
	}
}

template <class T>
void Lista<T>::ordenarBurbuja( ){
	int i, j;
	if( indice > 1 ){
		for( i = 0; i < indice - 1; i++ ){ 
			for( j = 0; j < (indice - 1) - i; j++ ){
				if( posicion(j)->dato > posicion(j+1)->dato ){
					intercambio( j, j+1 );
				} 
			} 
		}
	}
}

template <class T>
void Lista<T>::quicksort( int aba, int arr ){
	T a, temp;
	int abajo, arriba;
	
	a       = posicion(aba)->dato;
	arriba  = arr;
	abajo   = aba;
	
	while( abajo <= arriba){
		while( posicion(abajo)->dato < a )
			abajo++;
		while( posicion(arriba)->dato > a)
			arriba--;
		if( abajo <= arriba ){
			intercambio(abajo, arriba);
			abajo++;
			arriba--;
		}
	}
	if( aba < arriba )
		quicksort( aba, arriba);
	if( abajo < arr )
		quicksort( abajo, arr );
}

template <class T>
int Lista<T>::busquedaLineal( T clave ){
	for (int i = 0; i < indice ; i++)
		if ( posicion(i)->dato == clave )
			return i;
	return -1;
}

template <class T>
int Lista<T>::busquedaBinaria( T clave, int Iabajo, int Iarriba ){
	int Icentro = ( Iarriba + Iabajo ) / 2;
	int ind = -1;
	if( !vacia( ) && ( Iabajo <= Iarriba ) ){
		if( posicion(Icentro)->dato == clave )
			return Icentro;
		else
			if( clave < posicion(Icentro)->dato )
				ind = busquedaBinaria( clave, Iabajo, Icentro - 1 );
			else
				ind = busquedaBinaria( clave, Icentro + 1, Iarriba );
	}
	return ind;
}

template <class T>
Nodo<T>* Lista<T>::operator[] ( unsigned int pos ){
	if( !vacia( ) ){
		return posicion( pos );
	}
}

#endif // LISTA_H

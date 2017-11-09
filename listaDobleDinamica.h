//	Marcos Omar Martinez Navarro
//	207541732
//	i5887 - Sem. de Sol. de Estructura de Datos
//	D13
//	2017B
//	


#ifndef LISTASD_H
#define LISTASD_H

#define MAX 10
#define nullptr 0

template <class T>
class Nodo{
public:
	T dato;
	Nodo * der;
	Nodo * izq;
	Nodo( ){
		izq = nullptr;
		der = nullptr;
	}
	Nodo( T d ){
		dato = d;
		der = nullptr;
		izq = nullptr;
	}
};

template <class T>
class Lista
	{
	public:
		Lista();
		bool vacia( );
		Nodo<T>* ultimo( );
		Nodo<T>* primer( );
		Nodo<T>* posicion( unsigned int );
		void agregar_final( T );
		void agregar_inicio(T dato);
		void agregar_posicion(T dato, unsigned int pos);
		T getDato( unsigned int );
		unsigned int getLongitud();
		unsigned int capacidad( );
		bool eliminarDato(int);
		void intercambio(unsigned int pos1, unsigned int pos2);
		void ordenarBurbuja( );
		void quicksort( int, int );
		int busquedaLineal( T clave );
		int busquedaBinaria( T clave, int Iabajo, int Iarriba ); 
		Nodo<T>* operator[]( unsigned int pos );
	private:
		Nodo<T> *primero;
		unsigned int indice;
	};

//					Constructor
template <class T>
Lista<T>::Lista(){
	indice = 0;
	primero = nullptr;
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
Nodo<T> * Lista<T>::ultimo( ){
	if( !vacia( ) ){
		Nodo<T> *actual;
		actual = primero;
		while( actual->der != nullptr )
			actual = actual->der;
		return actual;
	}else
		return nullptr;
}

//					Devolver primera posicion
template <class T>
Nodo<T>* Lista<T>::primer( ){
	if( !vacia( ) ){
		return primero;
	}else	
		return nullptr;
}

//					Recorrer a la posicion marcada
template <class T>
Nodo<T>* Lista<T>::posicion( unsigned int pos ){
	if( !vacia( ) && pos < indice && pos >= 0 ){
		Nodo<T> *actual = primero;
		for(int i = 0; i < pos; i++)
			actual = actual->der;
		return actual;
	}else return nullptr;
}

//					Agregar
template <class T>
void Lista<T>::agregar_final(T dato){
	if( vacia() ){
		primero = new Nodo<T>( dato );
		indice++;
	}else{
		Nodo<T> *actual = ultimo( );
		Nodo<T> *tmp = new Nodo<T>( dato );
		tmp->izq = actual;
		actual->der = tmp;
		indice++;
	}
}

template <class T>
void Lista<T>::agregar_inicio(T dato){
	if( vacia() ){
		primero = new Nodo<T>( dato );
		indice++;
	}else{
		Nodo<T> *actual = primero;
		Nodo<T> *tmp = new Nodo<T>( dato );
		actual->izq = tmp;
		tmp->der = actual;
		primero = tmp;
		indice++;
	}
}

template <class T>
void Lista<T>::agregar_posicion(T dato, unsigned int pos){
	if( pos <= indice || pos == 0 ){
		if( vacia() ){
			primero = new Nodo<T>( dato );
			indice++;
		}else{
			Nodo<T> *actual = posicion( pos );
			Nodo<T> *anterior = posicion( pos - 1);
			Nodo<T> *tmp = new Nodo<T>( dato );
			if( anterior != nullptr ) anterior->der = tmp;
			actual->izq = tmp;
			tmp->izq = anterior;
			tmp->der = actual;
			indice++;
		}
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

//					Eliminar
template <class T>
bool Lista<T>::eliminarDato( int pos ){
	//validar si pos esta en el rango
	//recorrer el arreglo desde pos hasta indice
	//decrementar indice
	
	if( !vacia( ) && pos < indice ){
		if( indice == 1 ){
			delete primero;
			primero = nullptr;
		}else{
			Nodo<T> *tmp = posicion( pos );
			Nodo<T> *anterior = tmp->izq;
			Nodo<T> *siguiente = tmp->der;
			if(anterior != nullptr ) anterior->der = siguiente;
			siguiente->izq = anterior;
			delete tmp;
		}
		indice--;
		return true;
	}
	else return false;
}

template<class T>
void Lista<T>::intercambio(unsigned int pos_a, unsigned int pos_b ){
		Nodo<T> *a = posicion( pos_a );
		Nodo<T> *b = posicion(pos_b);
		Nodo<T> *a_anterior = posicion(pos_a - 1);		//	solo si a no es el primero
		Nodo<T> *a_siguiente = posicion(pos_a + 1);		//	solo si a no es el ultimo
		Nodo<T> *b_anterior = posicion(pos_b - 1);		//	solo si b no es el primero
		Nodo<T> *b_siguiente = posicion(pos_b + 1);		//	solo si b no es el ultimo
	if( a_anterior != nullptr )
		a_anterior->der = b;						//	solo si a no es el primero
	if( a_siguiente != nullptr )
		a_siguiente->izq = b;						//	solo si a no es el ultimo
	if( b_anterior != nullptr )
		b_anterior->der = a;						//	solo si b no es el primero
	if( b_siguiente != nullptr )
		b_siguiente->izq = a;						//	solo si b no es el ultimo
	
		b->izq = a_anterior;
		b->der = a_siguiente;
		a->izq = b_anterior;
		a->der = b_siguiente;
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

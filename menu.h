//	Marcos Omar Martinez Navarro
//	207541732
//	i5887 - Sem. de Sol. de Estructura de Datos
//	D13
//	2017B
//	

//		clase menu
//	Sirve como auxiliar del menu principal, otorgando
//	funciones que encapsulan para que la funcion main
//	sea mas clara y facil de leer


#ifndef MENU_H
#define MENU_H

#include <fstream>
#include "estructuras.h"
#include "listaDobleDinamica.h"
#include "pilaSimpleDinamica.h"
#include "colaDobleDinamica.h"

class menuLista{
public:
	static void agregar( Lista<Alumno> &lista ){ 
		Alumno al; 
		cin >> al; 
		lista.agregar( al ); 
	}
	
	static void mostrar( Lista<Alumno> &lista, ostream &out ){
		Alumno tmp; 
		int i = 0; 
		while( i < lista.getLongitud( ) ){ 
			tmp = lista.getDato( i ); 
			out << tmp << endl; 
			out << "----------------------------------------" 
				<< endl; 
			i++; 
		} 
	}
	
	static void mostrarTodo(Lista<Alumno> &lista, ostream &out ){ 
		Alumno tmp; 
		int i = 0; 
		while( i < lista.getLongitud( ) ){ 
			tmp = lista.getDato( i ); 
			out << tmp << endl; 
			out << "----------------------------------------" 
				<< endl; 
			i++; 
		} 
	}
	
	static void buscarLineal( Lista<Alumno> &lista ){ 
		string tmp; 
		int indice; 
		Alumno clave; 
		
		lista.ordenarBurbuja( ); 
		cout << "Ingrese el codigo del alumno a buscar" << endl 
			<< "->"; 
		getline( cin, tmp ); 
		clave.setCodigo( tmp ); 
		
		indice = lista.busquedaLineal( clave ); 
		
		if( indice == -1 )
			cout << "No se encontro el elemento" << endl; 
		else 
			cout << "El elemento esta en la pocision " 
			<< indice << "de la lista" << endl; 
	}
	
	static void buscarBinaria( Lista<Alumno> &lista ){
		string tmp; 
		int indice; 
		Alumno clave; 
		
		lista.ordenarBurbuja( ); 
		cout << "Ingrese el codigo del alumno a buscar" << endl 
			<< "->"; 
		getline( cin, tmp ); 
		clave.setCodigo( tmp ); 
		
		indice = lista.busquedaBinaria( clave, 0, lista.getLongitud() ); 
		
		if( indice == -1 ) 
			cout << "No se encontro el elemento" << endl; 
		else 
			cout << "El elemento esta en la posicion " 
			<< indice << "de la lista" << endl; 
	}
	
	static void ordenar( Lista<Alumno> &lista ){
		lista.quicksort( 0, lista.getLongitud()-1 );
	}

	static void cargar( Lista<Alumno> &lista ){
		Alumno tmp;
		Fecha f;
		
		f = Fecha(24, 11, 1991);
		tmp = Alumno("Marcos Omar", "2075", f, "Electronica", 2);
		lista.agregar(tmp);
		
		f = Fecha(2, 1, 1987);
		tmp = Alumno("Albert Bouchard", "3059", f, "Computacion", 4);
		lista.agregar(tmp);
		
		f = Fecha(4, 4, 1970);
		tmp = Alumno("Joe Satriani", "2030", f, "Quimica", 1);
		lista.agregar(tmp);
		
		f = Fecha(8, 9, 1985);
		tmp = Alumno("Paul Guilbert", "3030", f, "Musica", 7);
		lista.agregar(tmp);
	}
	
};

class menuPila{
	static void agregar( Pila<Alumno> &lista ){ 
		Alumno al; 
		cin >> al; 
		lista.apilar( al ); 
	}
	static void mostrarTope( Pila<Alumno> &lista ){
		Alumno al;
		al = lista.tope();
		cout << al;
	}
	static void mostrar( Pila<Alumno> &lista ){
		Alumno al;
		al = lista.desapilar();
		cout << al;
	}
};

class menuCola{
	static void mostrarPrimero( Cola<Alumno> &lista ){
		Alumno al;
		al = lista.getDato( 0 );
		cout << al;
	}
	static void encolar( Cola<Alumno> &lista ){
		Alumno al; 
		cin >> al; 
		lista.encolar( al ); 
	}
	static void desencolar( Cola<Alumno> &lista ){
		Alumno al;
		al = lista.desencolar( al );
		cout << al;
	}
};

#endif

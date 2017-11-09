
//	Marcos Omar Martinez Navarro
//	207541732
//	i5887 - Sem. de Sol. de Estructura de Datos
//	D13
//	2017B
//	

//		main ( )

#include <iostream>
#include <string>
#include "estructuras.h"
//#include "lista.h"
#include "listaSimpleDinamica.h"
#include "pilaSimpleDinamica.h"
#include "alumno.h"
#include "materia.h"
#include "menu.h"

void menu_pila( );
void menu_cola( );
void menu_lista( );

using std::cout;
using std::cin;
using std::endl;

int main(){
	
	return 0;
}

void menu_pila( ){
	bool bandera = true;
	int opcion;
	Pila<Alumno> lista;
	
	while(bandera){
		
		cout << "---------------" << endl
			<< "MENU ALUMNOS" << endl
			<< "1 Agregar nuevo" << endl
			<< "2 Mostrar tope" << endl
			<< "3 desapilar" << endl
			<< "0 Salir"            << endl;
		
		opcion = Auxiliar::leerInt();
		switch(opcion){
		case 0:
			cout << "Saliendo.." << endl;
			bandera = false;
			break;
		case 1:
			menuPila::agregar( lista );
			break;
		case 2:
			menuPila::mostrarTope( lista );
			break;
		case 3:
			menuPila::mostrar( lista );
			break;
		}
	}
}

void menu_cola( ){
	bool bandera = true;
	int opcion;
	Cola<Alumno> lista;
	
	while(bandera){
		
		cout << "---------------" << endl
			<< "MENU ALUMNOS" << endl
			<< "1 Mostrar primero" << endl
			<< "2 encolar" << endl
			<< "3 desencolar" << endl
			<< "0 Salir"            << endl;
		
		opcion = Auxiliar::leerInt();
		switch(opcion){
		case 0:
			cout << "Saliendo.." << endl;
			bandera = false;
			break;
		case 1:
			menuCola::mostrarPrimero( lista );
			break;
		case 2:
			menuCola::encolar( lista );
			break;
		case 3:
			menuCola::desencolar( lista );
			break;
		case 4:
			break;
		}
	}
}

void menu_lista(){
	bool bandera = true;
	int opcion;
	Lista<Alumno> lista;
	Alumno al;
	
	while(bandera){
		cout  << "---------------" << endl
			<< "MENU ALUMNOS" << endl
			<< "1 Agregar nuevo" << endl
			<< "2 Mostrar todo " << endl
			<< "3 Busqueda lineal " << endl
			<< "4 Busqueda binaria " << endl
			<< "5 Ordenar con Quicksort" << endl
			<< "0 Salir"            << endl;
		
		opcion = Auxiliar::leerInt();
		
		switch(opcion){
		case 1:
			menuLista::agregar( lista );
			break;
		case 2:
			menuLista::mostrarTodo( lista, cout );
			break;
		case 3:
			menuLista::buscarLineal( lista );
			break;
		case 4:
			menuLista::buscarBinaria( lista );
			break;
		case 5:
			menuLista::ordenar( lista );
			break;
		case 0:
			cout << "Saliendo.." << endl;
			bandera = false;
			break;
		case 99:
			menuLista::cargar( lista );
			break;
		default:
			cout << "Opcion incorrecta" << endl;
		}
	}
}

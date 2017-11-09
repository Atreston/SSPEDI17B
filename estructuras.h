
//	Marcos Omar Martinez Navarro
//	207541732
//	i5887 - Sem. de Sol. de Estructura de Datos
//	D13
//	2017B

//		estructuras.h
//	Aqui se implementan metodos para la lectura de enteros
//	y caracteres que permiten un control de errores

#ifndef ESTRUCTURAS
#define ESTRUCTURAS

#include <iostream>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;

class Auxiliar{
public:
	static int leerInt( ){
		string linea;
		int salida;
		int flag = 0;
		while(flag == 0)
		{
			getline(cin, linea);
			for (unsigned int i = 0; i<linea.length(); i++)
			{
				if ( !isdigit(linea[i]))
				{
					cout <<" Error " << endl;
					flag = 0;
					break;
				}
				else
					{
						flag = 1;
					}
			}
		}
		stringstream(linea) >> salida;
		return salida;
	}
	static int leerInt( std::string &linea ){
		int salida;
		int flag = 0;
		while(flag == 0){
			for (unsigned int i = 0; i<linea.length(); i++){
				if ( !isdigit(linea[i])){
					flag = 0;
					break;
				}
				else
					flag = 1;
			}
		}
		stringstream(linea) >> salida;
		return salida;
	}
};

#endif

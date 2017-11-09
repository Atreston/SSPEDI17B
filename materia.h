
//	Marcos Omar Martinez Navarro
//	207541732
//	i5887 - Sem. de Sol. de Estructura de Datos
//	D13
//	2017B
//	

//		clase Materia
//	Clase materia que almacena las materias de los alumnos

#ifndef MATERIA_H
#define MATERIA_H

#include <string>

using std::string;
using std::istream;
using std::ostream;
using std::istringstream;

class Materia
{
	private:
	string nombre;
	float promedio;
	int semestre;
	public:
	Materia( ){
		nombre = "";
		promedio = 0;
	}
	//----------set y get Nombre----------
	string getNombre() const	{
		return nombre;
		}
	void setNombre(const string &value){
		nombre = value;
		}

	//----------set y get Promedio----------	
	float getPromedio() const{
		return promedio;	}
	void setPromedio(float value){
		promedio = value;
	}
	
	//----------set y get Semestre----------	
	int getSemestre(){
		return semestre;
	}
	void setSemestre(int value){
		semestre = value;
	}
void registrar(  ){
}
	
	//          Metodos auxiliares de lectura y escritura      
	friend ostream& operator<<(ostream &out, Materia &mat){
		out << "Nombre:   " << mat.getNombre() << endl
		<< "Promedio: " << mat.getPromedio() << endl;
		return out;
	}
//adaptar para evitar usar cout	
	friend istream& operator>>(istream &in, Materia &mat){
		string tmp;
		float value;
		cout << "Ingrese los datos de la materia:" << endl
		<< "Nombre:";
		getline(cin, tmp);
		mat.setNombre(tmp);
		cout << "Promedio: ";
		getline(cin,tmp);
		
		istringstream(tmp) >> value;
		mat.setPromedio(value);
		return in;
	}
};

#endif // MATERIA_H

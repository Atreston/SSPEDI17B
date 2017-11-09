
//	Marcos Omar Martinez Navarro
//	207541732
//	i5887 - Sem. de Sol. de Estructura de Datos
//	D13
//	2017B
//	

//		clase Alumno
//	Clase que almacena los datos de los alumnos

#ifndef ALUMNO_H
#define ALUMNO_H

#include "materia.h"
#include "fecha.h"
#define SIZE 10

using std::cout;
using std::cin;
using std::string;
using std::istream;
using std::ostream;
using std::getline;

class Materia;

char leerLetra();

class Alumno
{
private:
	string			nombre;
	string			codigo;
	int				edad;
	Fecha			nacimiento;
	string			carrera;
	unsigned int 	semestre;
	//Lista<Materia> mat;
	Pila<Materia> mat;
	
public:
//		Constructor
	Alumno();
	Alumno( string, string, Fecha, string, unsigned int );

//		Set y Get nombre
	string getNombre( ) const;
	void setNombre(const string& value);

//		Set y Get codigo	
	string getCodigo( ) const;
	void setCodigo( const string &value );

//		Set y Get carrera
	string getCarrera( ) const;
	void setCarrera( const string& value );

//		Set y get semestre	
	unsigned int getSemestre( ) const;
	void setSemestre( const unsigned int& value );

//		Set y Get materia	
	void setMateria( const Materia &val );
	Materia getMateria( int i );
	int sizeMaterias( );
	int capacidadMaterias( );
	int numMaterias( );

//		Set y Get Fecha de nacimiento	
	void setNacimiento( Fecha &fecha );
	void setNacimiento( int dd, int mm, int aa );
	Fecha getNacimiento( ) const;

//		Set y Get edad	
	void setEdad( );
	int getEdad( );

//		Metodos auxiliares
//	int registrar( );
//	int extraer( );	
	friend istream &operator >> ( istream &cin, Alumno &val );
	friend ostream &operator << ( ostream &out, Alumno &val );	
	friend bool operator < ( Alumno &a, Alumno &b ); 
	friend bool operator > ( Alumno &a, Alumno &b ); 
};

	Alumno::Alumno(){
		nombre		= "";
		codigo		= "";
		edad		= 0;
		carrera	= "";
		semestre	= 0;
		mat			= Pila<Materia>();
		//mat			= Lista<Materia>();	// El metodo constructor inicializa
										//en nulo toda la lista
	}
	
	Alumno::Alumno( string nom, string cod, Fecha f, string car, unsigned int sem){
		nombre = nom;
		codigo = cod;
		nacimiento = f;
		carrera = car;
		semestre = sem;
	}
	
	//--------Set y Get Nombre----------
	string Alumno::getNombre( ) const{
		return nombre;
	}
	void Alumno::setNombre(const string& value){
		nombre = value;
	}
	
	//--------Set y Get Codigo----------
	string Alumno::getCodigo( ) const{
		return codigo;
	}
	void Alumno::setCodigo( const string &value ){
		codigo = value;
	}
	//--------------Set y Get para Carrera--------------
	string Alumno::getCarrera( ) const{
		return carrera;
	}
	void Alumno::setCarrera( const string& value ){
		carrera = value;
	}
	
	//--------------Set y Get para semestre--------------
	unsigned int Alumno::getSemestre( ) const{
		return semestre;
	}
	void Alumno::setSemestre( const unsigned int& value ){
		semestre = value;
	}
	
	//--------------Set y Get para materias--------------
	void Alumno::setMateria( const Materia &val ){
		mat.agregar(val);
	}
	Materia Alumno::getMateria( int i ){
		return mat.getDato( i );
	}
	int Alumno::sizeMaterias( ){
		return mat.getLongitud( );
	}
	int Alumno::capacidadMaterias( ){
		return mat.capacidad( );
	}
	int Alumno::numMaterias( ){
		return mat.getLongitud( );
	}
	
	//-------Set y Get para fecha de nacimiento------
	void Alumno::setNacimiento( Fecha &fecha ){
		nacimiento = fecha;
		nacimiento.setDia( fecha.getDia( ) );
		nacimiento.setMes( fecha.getMes( ) );
		nacimiento.setA( fecha.getA( ) );
	}
	void Alumno::setNacimiento( int dd, int mm, int aa ){
		if( nacimiento.validar( dd, mm, aa ) ){
			nacimiento.setDia( dd );
			nacimiento.setMes( mm );
			nacimiento.setA( aa );
		}
		else{
			cout << "Fecha incorrecta" << endl
				<< "se guardo el valor por defecto"
				<< "1/1/2000" << endl;
			nacimiento.setDia( 1 );
			nacimiento.setMes( 1 );
			nacimiento.setA( 2000 );
		}
	}
	Fecha Alumno::getNacimiento( ) const{
		return nacimiento;
	}
	
	//----------Set y Get Edad----------
	void Alumno::setEdad( ){
		edad = nacimiento.lapsoA( 4, 10, 2017 );
	}
	int Alumno::getEdad( ){
		return edad;
	}
	// modificar alumno
// ingresar datos de alumno a buscar
// buscar
// si encontro copiar datos a buffer
// editar buffer
// guardar buffer en indice previamente encontrado
	//--------Metodos auxiliares para leer y mostrar--------
	istream &operator >> ( istream &cin, Alumno &val ){
		string tmp;
		Materia m;
		Fecha n;
		int i = 0;
		//			Leer Nombre
		cout << "Ingrese los datos del estudiante:" << endl
			<< "Nombre:	";
		getline(cin, tmp);
		val.setNombre(tmp);
		tmp = "";
		//			Leer Codigo
		cout << "Codigo:	" ;
		getline(cin, tmp);
		val.setCodigo(tmp);
		//			Leer semestre
		cout << "Semestre (con num entero): ";
		val.setSemestre( Auxiliar::leerInt() );
		//			Leer fecha de nacimiento
		cout << "Fecha de nacimiento: " << endl;
		cin >> n;
		val.setNacimiento( n );
		//			calcular edad
		val.setEdad( );
		//			Leer maerias
		cout << "Agregando materias" << endl;
		while( i < val.capacidadMaterias( ) ){
			cout << endl << "Materia " << i+1 << ":";
			cin >> m;
			//si el nombre de la materia es nulo, terminar bucle
			tmp = m.getNombre();
			if( tmp.size() > 0 )
				val.setMateria(m);
			else
				break;
		}
		return cin;
	}
	ostream &operator << ( ostream &out, Alumno &val ){
		Materia tmp;
		out << endl
			<< "-------------------------" << endl
			<< "Datos del estudiante" << endl
			<< "Nombre:   " << val.getNombre() << endl
			<< "Codigo:   " << val.getCodigo() << endl
			<< "Semestre: " << val.getSemestre() << endl
			<< "Edad: " << val.getEdad() << endl
			<< "Fecha de nacimiento: ";
		val.getNacimiento();
		out << endl
			<< "Lista de materias:" << endl
			<< "/-------------------------\\" << endl;
		for(int i = 0; i < val.numMaterias(); i++){
			out << "Materia: " << i+1 << endl;
			tmp = val.getMateria(i);
			out << tmp;
		}
		out << "\\_________________________/" << endl;
		return out;
	}

	bool operator > ( Alumno &a, Alumno &b ){ 
		return a.getCodigo( ) > b.getCodigo( ); 
	} 
	
	bool operator < ( Alumno &a, Alumno &b ){ 
		return a.getCodigo( ) < b.getCodigo( ); 
	} 
	
	bool operator == ( Alumno &a, Alumno &b ){ 
		return a.getCodigo( ) == b.getCodigo( ); 
	}
	
#endif // ALUMNO_H

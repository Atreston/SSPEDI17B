
//	Marcos Omar Martinez Navarro
//	207541732
//	i5887 - Sem. de Sol. de Estructura de Datos
//	D13
//	2017B
//	

//		clase Fecha
//	Clase fecha que almacena fechas y falida si son bien escritaaas


#ifndef FECHA
#define FECHA

#include "estructuras.h"

using std::istream;
using std::ostream;

class Fecha{
private:
	int dd;
	int mm;
	int aaaa;
	int dias;
	//t_time tiempo;
	string formato;
public:
	//--------------------Constructores--------------------
	Fecha(){
		dd = 0;
		mm = 0;
		aaaa = 0;
		dias = 0;
		formato = "";
	}
	Fecha(int d, int m, int a){
		if( validar( d, m, a ) ){
			dd = d;
			mm = m;
			aaaa = a;
			//formato = formatear atributos a cadena
		}
	}

	//--------------------setters y getters--------------------
	void setDia(const int & d){
		dd = d;
	}
	void setMes(const int & m){
		mm = m;
	}
	void setA(const int & a){
		aaaa = a;
	}
	int getDia(){
		return dd;
	}
	int getMes(){
		return mm;
	}
	int getA(){
		return aaaa;
	}
	//--------------------Validador de fechas--------------------
	bool validar(const int &d, const int &m, const int &a){
		bool bisiesto = false;
		//comprobamos si el año es bisiesto
		if(a%4==0 && a%100!=100 || a%400==0)
			bisiesto = true;

		//comprobamos que los datos ingresados esten en un rango valido
		if(d>0 && d<32 && m>0 && m<13 && a>0){
			if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			{
				return true;
			}
			else
				{
					if(m==2 && d<30 && bisiesto)
						return true;
					else if(m==2 && d<29 && !bisiesto)
						return true;
					else if(m!=2 && d<31)
						return true;
					else
						return false;
				}
		}
		else
			return false;
	}
	int lapsoA( int d, int m, int a ){
		return (a-aaaa);
	}
	//--------------------Metodos auxiliares de lectura/escritura--------------------
	friend istream &operator >>(istream &cin, Fecha &val){
		int d, m, a;
		bool bandera = false;
		while(!bandera){
			cout << "Dia: ";
			d = Auxiliar::leerInt();
			cout << "Mes: ";
			m = Auxiliar::leerInt();
			cout << "Año: ";
			a = Auxiliar::leerInt();
			if( val.validar(d, m, a) ){
				val.setDia(d);
				val.setMes(m);
				val.setA(a);
				bandera = true;
			}else cout << "Datos incorrectos" << endl;
		}
		return cin;
	}
	friend ostream &operator <<(ostream &out, Fecha &val){
		out << val.getDia() << "/"
			<< val.getMes() << "/"
			<< val.getA();
		return out;
	}
};

#endif

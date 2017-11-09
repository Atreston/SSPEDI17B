#include <iostream>
#include "colaDobleDinamica.h"

using std::cout;
using std::endl;

int main( ){
	Cola<int> lista;
	lista.encolar(6);
	lista.encolar(3);
	lista.encolar(1);
	lista.encolar(9);
	for( int i = 0; i < lista.getLongitud(); i++)
		cout << lista.desencolar() << endl;
	
	return 0;
}

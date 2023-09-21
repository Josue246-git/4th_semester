//Calcular el rango (diferencia entre el valor mayor y el menor) de un ABB ingresado
//Josue Rodriguez 7272

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"
#include "TDA_lista.h"

int main(){					

	ArbolBinario a;		
	//
	void leerAB(ArbolBinario *b);		
	void imprimirAB(ArbolBinario a);	
	void verDatosAB(ArbolBinario a);	
	void verHojasAB(ArbolBinario a);	
	void recorrerAB(ArbolBinario a);	
	void Menor_val_nodo(NodoBinario* r, Tipo* men );
	void Mayor_val_nodo(NodoBinario* r, Tipo* may );

	//

    cout<<endl<<"LEER ARBOL BINARIO "<<endl;
	leerAB(&a);							//llamado a funcion de ingreso AB
	verDatosAB(a);						//llamado a impresion datos generales AB

    cout<<endl<<endl<<"IMPRIMIR ARBOL BINARIO "<<endl;
	imprimirAB(a);						
	verHojasAB(a);						
	recorrerAB(a);				

    Tipo men = (a.getRaiz())->getDato();
    Tipo may = (a.getRaiz())->getDato();

    Menor_val_nodo(a.getRaiz(), &men);
    Mayor_val_nodo(a.getRaiz(), &may);

    cout<<endl<<endl<<"VALOR MENOR DE TODO EL AB es: "<<men<<endl;
    cout<<endl<<"VALOR MAYOR DE TODO EL AB es: "<<may<<endl;

    cout<<endl<<"El rango de los valores de los nodo de AB es: "<< may - men<<endl;

	cout<<endl;
}


void leerAB(ArbolBinario *b){
	b->leer();				
}

void imprimirAB(ArbolBinario a){
	cout << endl << "\t\t\tIMPRESION SIMPLE DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABSimple(a.getRaiz());	//llama metodo impresion simple de AB
	
	cout << endl << "\t\t\tIMPRESION JERARQUICA DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);	//llama a metodo impresion con formato jerarquico de AB
}

void verDatosAB(ArbolBinario a){		
	cout << endl << "\t\t\tIMPRESION DE DATOS GENERALES DE ARBOL BINARIO" << endl << endl;
	cout << endl << "El arbol " << (a.esVacio() ? "SI" : "NO") << " esta vacio";
	cout << endl << "El arbol posee " << a.contarNodos(a.getRaiz()) << " nodos";
	cout << endl << "La altura del arbol es " << a.calcularAltura(a.getRaiz());
	cout << endl << "El nodo raiz es: " << a.getRaiz()->getDato();
}

void verHojasAB(ArbolBinario a){		
    cout << endl << "\t\t\tIMPRESION DE NODOS HOJA DE ARBOL BINARIO" << endl << endl;
	a.verHojas(a.getRaiz());			
}

void recorrerAB(ArbolBinario a){		

	cout << endl << "\t\t\tRECORRIDOS DE ARBOL BINARIO" << endl << endl;
	cout << endl << "RECORRIDO EN PREORDEN" << endl;
	a.recorrerEnPreorden();		//llama al metodo correspondiente
	cout << endl << "RECORRIDO EN INORDEN" << endl;
	a.recorrerEnInorden();		//llama al metodo correspondiente
	cout << endl << "RECORRIDO EN POSORDEN" << endl;
	a.recorrerEnPostorden();		//llama al metodo correspondiente
}


void Menor_val_nodo(NodoBinario* r, Tipo* men ){
    if (r == NULL)  return ;
    
	Menor_val_nodo (r->getIzq(),men);

    if(r->getDato() < *men) *men = r->getDato();  

	Menor_val_nodo (r->getDer(),men);
}

void Mayor_val_nodo(NodoBinario* r, Tipo* may ){
    if (r == NULL)  return ;
    
	Mayor_val_nodo (r->getIzq(),may);

    if(r->getDato() > *may) *may = r->getDato();  

	Mayor_val_nodo (r->getDer(),may);
}

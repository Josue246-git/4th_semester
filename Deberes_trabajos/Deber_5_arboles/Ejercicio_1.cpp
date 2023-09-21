//Generar una lista con los nodos externos de un árbol previamente ingresado
//Josue Rodriguez 7272

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"
#include "TDA_lista.h"

int main(){					

	ArbolBinario a;		
    Lista l;	
	//
	void leerAB(ArbolBinario *b);		
	void imprimirAB(ArbolBinario a);	
	void verDatosAB(ArbolBinario a);	
	void verHojasAB(ArbolBinario a);	
	void recorrerAB(ArbolBinario a);	
	void Generar_lista_hojas(NodoBinario *r, Lista* lis);												
	void imprimirLista(Nodo* act);

	//
    cout<<endl<<"LEER ARBOL BINARIO "<<endl;
	leerAB(&a);							//llamado a funcion de ingreso AB
	verDatosAB(a);						//llamado a impresion datos generales AB

    cout<<endl<<"IMPRIMIR ARBOL BINARIO "<<endl;
	imprimirAB(a);						
	verHojasAB(a);						
	recorrerAB(a);				

    cout<<endl<<endl<<"\t\tGenerar lista con los nodos hijos o externos "<<endl;
    Generar_lista_hojas(a.getRaiz(), &l);
    imprimirLista(l.getPrimero());

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

void Generar_lista_hojas(NodoBinario *r, Lista* lis){												
	if (r != NULL){													
		if ((r -> getIzq() == NULL) && (r -> getDer() == NULL)) {	
			lis->insertarAlFinal(r->getDato());			
		} else {													
			Generar_lista_hojas(r -> getIzq(), lis);								
			Generar_lista_hojas(r -> getDer(), lis);								
		}
	}
	return;
}

void imprimirLista(Nodo* act){
    if(act != NULL){
        cout <<  "> " << act -> getDato() << endl;
        act = act -> getPunt();
        imprimirLista(act);
    }
}

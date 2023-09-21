//Permitir el ingreso de N valores por parte del usuario, y proceder a generar todos los 
//ABB posibles construidos a partir de los mismos.
//Josue Rodriguez 7272

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"
#include "TDA_lista.h"
#define FIN 9999     


int main(){					

	ArbolBinario a;	
	Lista l1;
	//
	void imprimirAB(ArbolBinario a);	
	void verDatosAB(ArbolBinario a);	
	void Generar_ArbolesBB_lis(Lista laux, Nodo* l1, ArbolBinario abbs[], int i=0);
	void ingresarLista(Lista* l);
	void imprimirLista(Nodo* act);
	int calcular_nodos(Nodo* act, int i =1);
	//

	cout<<endl<<"Ingrese los elementos a hacer el porceso "<<endl;
	ingresarLista(&l1);
	cout<<endl<<" Los elementos a hacer el porceso son: "<<endl;
	imprimirLista(l1.getPrimero());

	int tam = calcular_nodos(l1.getPrimero());

	ArbolBinario* abbs;
    abbs = new ArbolBinario[tam]; 

	Generar_ArbolesBB_lis(l1,l1.getPrimero(), abbs);
    
	cout<<endl;
}

void verDatosAB(ArbolBinario a){		
	cout << endl << "\t\t\tIMPRESION DE DATOS GENERALES DE ARBOL BINARIO" << endl << endl;
	cout << endl << "El arbol " << (a.esVacio() ? "SI" : "NO") << " esta vacio";
	cout << endl << "El arbol posee " << a.contarNodos(a.getRaiz()) << " nodos";
	cout << endl << "La altura del arbol es " << a.calcularAltura(a.getRaiz());
	cout << endl << "El nodo raiz es: " << a.getRaiz()->getDato();
}


void ingresarLista(Lista* l){
    Tipo aux;           //variable de lectura
    
    cout << endl << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    if(aux != FIN){
        //l->insertarAlInicio(aux);        //se ingresa elemento a la lista
        l->insertarAlFinal(aux);
        ingresarLista(l);
    }
}

void imprimirLista(Nodo* act){
    if(act != NULL){
        cout <<  "> " << act -> getDato() << endl;
        act = act -> getPunt();
        imprimirLista(act);
    }
}

void imprimirABB(ArbolBinario a){
	cout << endl << "\t\t\tIMPRESION SIMPLE DEL ARBOL BINARIO DE BUSQUEDA" << endl << endl;
	a.imprimirABSimple(a.getRaiz());	//llama metodo impresion simple de AB
	
	cout << endl << "\t\t\tIMPRESION JERARQUICA DEL ARBOL BINARIO DE BUSQUEDA " << endl << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);	//llama a metodo impresion con formato jerarquico de AB
}

int calcular_nodos(Nodo* act, int i =1){			//de la lista de datos 
	if(act== NULL) return i;
	else calcular_nodos(act->getPunt(), i+1);
}

void Generar_ABB(Nodo* act, ArbolBinario* abb, int i){
	if(i>0){
		abb->insertarNodo(act->getDato());
		Generar_ABB(act->getPunt(), abb, i-1);
	}
}

void Generar_ArbolesBB_lis(Lista laux, Nodo* l1, ArbolBinario abbs[], int i=0){
	//
	void Generar_ABB(Nodo* act, ArbolBinario* abb, int i);
	//
	if(l1 != NULL){
		cout<<endl<<" Arbol ABB "<<i+1<<endl;

		Generar_ABB(laux.getPrimero(), &abbs[i], i+1) ;
		imprimirABB(abbs[i]);

		Generar_ArbolesBB_lis(laux, l1->getPunt(), abbs, i+1);
	}
}
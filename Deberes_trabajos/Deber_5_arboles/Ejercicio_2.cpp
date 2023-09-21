//Determinar el valor mayor de cada nivel de un AB
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
	void levelOrderTraversal(NodoBinario* root, int level = 1);
	//

    cout<<endl<<"LEER ARBOL BINARIO "<<endl;
	leerAB(&a);							//llamado a funcion de ingreso AB
	verDatosAB(a);						//llamado a impresion datos generales AB

    cout<<endl<<endl<<"IMPRIMIR ARBOL BINARIO "<<endl;
	imprimirAB(a);						
	verHojasAB(a);						
	recorrerAB(a);				

    cout<<endl<<endl<<"VALOR MAYOR DE CADA NIVEL DEL ARBOL BINARIO"<<endl;
  	levelOrderTraversal(a.getRaiz());

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


Tipo Valor_may_lista(Nodo* act, Tipo may ){
	
	if(act != NULL){
		if(act->getDato() > may){
			may = act->getDato();
		}
		Valor_may_lista(act->getPunt(), may);
	}
	else return may;
}

bool printLevel(NodoBinario* raiz, int level, Lista* l){ // Función para imprimir todos los nodos de un nivel dado de izquierda a derecha
	if (raiz == NULL) return false;
 
    if (level == 1){
        cout << raiz->getDato() << " ";
		l->insertarAlFinal(raiz->getDato());
        return true;				// devuelve verdadero si al menos un nodo está presente en un nivel dado
    }
 
    bool left = printLevel(raiz->getIzq(), level - 1, l);
    bool right = printLevel(raiz->getDer(), level - 1, l);
 
    return (left || right);
}
 
// Función para imprimir el recorrido del orden de nivel de un árbol binario dado
void levelOrderTraversal(NodoBinario* root, int level = 1){
	Lista l;                            //se utiliza una lista para guardar los nodos de un nivel 
	//
	bool printLevel(NodoBinario* raiz, int level, Lista* l);
	Tipo Valor_may_lista(Nodo* act, Tipo may );
	//
    if (printLevel(root, level, &l)) {
		Nodo* act = l.getPrimero();
		cout<<"\t\t-> NIVEL "<<level-1<<" , el dato mayor es: "<<Valor_may_lista(act,act->getDato())<<endl;
		levelOrderTraversal(root, level+1);
    }
}

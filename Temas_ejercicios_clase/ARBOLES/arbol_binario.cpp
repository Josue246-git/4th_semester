// ArbolBinario2.cpp
// implementa un AB basico

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"
#include "TDA_lista.h"


Tipo Valor_may_lista(Nodo* act, Tipo may ){
	
	if(act != NULL){
		if(act->getDato() > may){
			may = act->getDato();
		}
		Valor_may_lista(act->getPunt(), may);
	}
	else return may;
}

// Función para imprimir todos los nodos de un nivel dado de izquierda a derecha
bool printLevel(NodoBinario* raiz, int level, Lista* l){
    
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
	Lista l;

    if (printLevel(root, level, &l)) {
		Nodo* act = l.getPrimero();
		cout<<"\t\t-> NIVEL "<<level-1<<" , el dato mayor es: "<<Valor_may_lista(act,act->getDato())<<endl;
		levelOrderTraversal(root, level+1);
    }
}

int main(){					

	ArbolBinario a;			
	//
	void leerAB(ArbolBinario *b);		
	void imprimirAB(ArbolBinario a);	
	void verDatosAB(ArbolBinario a);	
	void verHojasAB(ArbolBinario a);	
	void recorrerAB(ArbolBinario a);	
	int Sum_no_hojas(NodoBinario* r, NodoBinario* raiz);
	//

	leerAB(&a);							//llamado a funcion de ingreso AB
	verDatosAB(a);						//llamado a impresion datos generales AB

	imprimirAB(a);						//llamado a funcion que imprime un AB

	verHojasAB(a);						//llamado a impresion de nodos hoja del AB
	recorrerAB(a);						//llamado a la funcion que implementa diversos recorridos de AB

	NodoBinario* raiz = a.getRaiz(); 

	cout<<endl<<"La suma de los ramales es: "<<Sum_no_hojas(raiz, raiz) - raiz->getDato()<<endl;
	cout << endl;

	cout<<endl<<"\t\t\tIMPRESION DE LOS NODOS POR NIVELES"<<endl;

  	levelOrderTraversal(a.getRaiz());

	cout<<endl;
}


void imprimirEsp(int c){						//funcion para imprimir espacios
	for (int i = 1; i <= c; i++){	//ciclo impresion espacios
		cout << "   ";
    }
}


NodoBinario* leerNodo(int margen){ 				//funcion para ingresar AB por nodos

	Tipo aux;									//var de lectura
	Tipo fin = 9999;						//marca de fin de lectura
	NodoBinario* p;							//puntero a nuevo nodo
	//
	void imprimirEsp(int c);					//funcion para imprimir espacios
	//

	cout << endl;
	imprimirEsp(margen);					
	cout << "Valor para el Nodo. Ingrese [" << fin << "] para terminar: "; cin >> aux;	
	
	if (aux != fin){						//no ingresa marcador de fin lectura
	   p = new NodoBinario(aux);			//construye nuevo nodo solo con dato

	   imprimirEsp(margen);						
	   cout << "--- SUBARBOL IZQUIERDO ---";
	   p -> setIzq(leerNodo(margen+1)) ;			//puntero izq recibe direccion nuevo nodo ingresado
	   
	   imprimirEsp(margen);	
	   cout << "--- SUBARBOL DERECHO ---";
	   p -> setDer(leerNodo(margen+1)) ;			//puntero der recive direccion nuevo nodo ingresado
	   
	   return p;									//devuelve direccion nuevo nodo creado
	} 
	else {										//ingreso marcador final de lectura
		return NULL;							//no se creo el nodo
	}
}

void leerAB(ArbolBinario *b){
	b -> setRaiz(leerNodo(0));				//actualiza raiz del arbol nuevo con apuntador devuelto
}


void imprimirAB(ArbolBinario a){
	cout << endl << "\t\t\tIMPRESION SIMPLE DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABSimple(a.getRaiz());	//llama metodo impresion simple de AB
	
	cout << endl << "\t\t\tIMPRESION JERARQUICA DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);	//llama a metodo impresion con formato jerarquico de AB
}

void verDatosAB(ArbolBinario a){		//visualizar datos generales de un arbol

	cout << endl << "\t\t\tIMPRESION DE DATOS GENERALES DE ARBOL BINARIO" << endl << endl;
	cout << endl << "El arbol " << (a.esVacio() ? "SI" : "NO") << " esta vacio";
	cout << endl << "El arbol posee " << a.contarNodos(a.getRaiz()) << " nodos";
	cout << endl << "La altura del arbol es " << a.calcularAltura(a.getRaiz());
	cout << endl << "El nodo raiz es: " << a.getRaiz()->getDato();
}

void verHojasAB(ArbolBinario a){		//visualizar los nodos hoja del Ab

cout << endl << "\t\t\tIMPRESION DE NODOS HOJA DE ARBOL BINARIO" << endl << endl;
	a.verHojas(a.getRaiz());			//llama a metodo que visualiza nodos hoja del AB
}

void recorrerAB(ArbolBinario a){		//funcion que implementa los diversos recorridos de un AB

	cout << endl << "\t\t\tRECORRIDOS DE ARBOL BINARIO" << endl << endl;
	cout << endl << "RECORRIDO EN PREORDEN" << endl;
	a.recorrerEnPreorden();		//llama al metodo correspondiente
	cout << endl << "RECORRIDO EN INORDEN" << endl;
	a.recorrerEnInorden();		//llama al metodo correspondiente
	cout << endl << "RECORRIDO EN POSORDEN" << endl;
	a.recorrerEnPostorden();		//llama al metodo correspondiente
}

int Sum_no_hojas(NodoBinario* r, NodoBinario* raiz){

	if(r != NULL){
		if ((r -> getIzq() != NULL) || (r -> getDer() != NULL)){

			return r->getDato() + Sum_no_hojas(r->getIzq(), raiz) + Sum_no_hojas(r->getDer(), raiz);
			
		}	
	}
	return 0;
}


 
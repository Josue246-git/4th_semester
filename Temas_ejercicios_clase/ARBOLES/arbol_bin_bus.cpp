//Implementacion de un ABB 

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"
#include "TDA_lista.h"
#define fin 9999

int main(){					

	ArbolBinario a;			
	//
	void leerABB(ArbolBinario *b);		
	void imprimirABB(ArbolBinario a);	
    bool buscar_en_ABB(ArbolBinario a);
	//

	leerABB(&a);							//llamado a funcion de ingreso AB

	imprimirABB(a);						//llamado a funcion que imprime un AB

    cout<<endl<<"/t/tBUSCAR EN EL ARTBOL BINARIO"<<endl;
    cout<<endl<<"El valor "<<(buscar_en_ABB(a)?" SI ": " NO ")<<" esta en el arbol "<<endl ;

	cout<<endl;
}


void leerABB(ArbolBinario *b){

    Tipo aux; 
    cout<<endl<<" Ingrese un valor a incluir en el ABB, finalice con [ "<<fin<<" ]: "; cin>>aux;
    if(aux != fin){
        b->insertarNodo(aux);
        leerABB(b);
    }
    return;	
}


void imprimirABB(ArbolBinario a){
	cout << endl << "\t\t\tIMPRESION SIMPLE DEL ARBOL BINARIO DE BUSQUEDA" << endl << endl;
	a.imprimirABSimple(a.getRaiz());	//llama metodo impresion simple de AB
	
	cout << endl << "\t\t\tIMPRESION JERARQUICA DEL ARBOL BINARIO DE BUSQUEDA " << endl << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);	//llama a metodo impresion con formato jerarquico de AB
}

bool buscar_en_ABB(ArbolBinario a){
    Tipo aux;
    cout<<endl<<"Ingrese un dato a buscar en el ABB: ";cin>>aux;
    if(a.buscarNodo(aux)== NULL) return false;
    else return true;
}




//IMPLEMENTAR LA PARTE PARA ELIMINAR UN NODO DE UN ARBOL, LA CLAVE ESTA EN EL REEMPLAZO


//Calcular el ABB resultante de la unión de 2 ABB originales, previamente ingresados
//Josue Rodriguez 7272

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"
#include "TDA_lista.h"
#define fin 9999


int main(){					

	ArbolBinario a1,a2,ares;
    Lista l1,l2,lres;		
	//
	void leerABB(ArbolBinario *b);		
	void imprimirABB(ArbolBinario a);	
    void Generar_lis_nodos(NodoBinario* r, Lista* li);
    void Generar_lista_union(Nodo* l1, Nodo* l2, Lista* lres);
    void Generar_ABB_res(ArbolBinario*ares, Nodo* l);
	//

    cout<<endl<<"LEER ABB 1 "<<endl;
	leerABB(&a1);							//llamado a funcion de ingreso AB				//llamado a impresion datos generales AB

    cout<<endl<<endl<<"IMPRIMIR ABB"<<endl;
	imprimirABB(a1);					


    cout<<endl<<"LEER ABB 2 "<<endl;
	leerABB(&a2);							//llamado a funcion de ingreso AB				//llamado a impresion datos generales AB

    cout<<endl<<endl<<"IMPRIMIR ABB"<<endl;
	imprimirABB(a2);		
		
    Generar_lis_nodos(a1.getRaiz(), &l1);
    Generar_lis_nodos(a2.getRaiz(), &l2);

    cout<<endl<<endl<<"\t\t\tUNION DE LOS DOS ABB INGRESADOS"<<endl;

    Generar_lista_union(l1.getPrimero(),l2.getPrimero(),&lres);

    Generar_ABB_res(&ares, lres.getPrimero());
    imprimirABB(ares);

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

void Generar_lis_nodos(NodoBinario* r, Lista* li){
    if (r == NULL)  return ;
    
	Generar_lis_nodos (r->getIzq(),li);

    li->insertarAlFinal(r->getDato()); 

	Generar_lis_nodos (r->getDer(),li);
}

bool Esta_en_lista(Nodo* lres, Tipo val){      
    if(lres == NULL){
        return false;
    }
    else {
        if(lres->getDato() == val){
            return true;
        }
    }
    return Esta_en_lista(lres->getPunt(), val);
}

void Generar_lista_union(Nodo* l1, Nodo* l2, Lista* lres){
    //
    bool Esta_en_lista(Nodo* lres, Tipo val);
    //

    if(l1 != NULL){
        lres->insertarAlFinal(l1->getDato());
        l1= l1->getPunt();
    }
    else if(l2 != NULL){
        Tipo val = l2->getDato();
        if(!Esta_en_lista(lres->getPrimero(),val)){
            lres->insertarAlFinal(val);
        }   
        l2= l2->getPunt();
    }
    else return;
    Generar_lista_union(l1,l2,lres);
}

void Generar_ABB_res(ArbolBinario*ares, Nodo* l){

    if(l != NULL){
        ares->insertarNodo(l->getDato());
        Generar_ABB_res(ares, l->getPunt());
    }
}

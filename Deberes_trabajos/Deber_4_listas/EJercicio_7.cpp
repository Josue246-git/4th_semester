//Determinar si los elementos de una lista están ordenados (en caso de estarlo, indicar 
//el tipo de orden encontrado: ascendente o descendentemente)
//NOMBRE: JOSUE RODRIGUEZ 7272

#include <iostream>
using namespace std;
#include "TDA_lista.h"

#define FIN 9999     



int main(){

    Lista l1;                     
    //
    void ingresarLista(Lista* l);        
    void imprimirLista(Nodo* act);
    void Ordenado_asc_desc(Nodo* act, Lista *aux, Lista *aux2);
    bool Comparar_elem_listas(Nodo* act, Nodo* aux, bool ban= true);    
    
    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());
    
    cout << endl << "LISTA MODIFICADA: " <<endl;
    
    Lista asc, desc;

    Ordenado_asc_desc(l1.getPrimero(), &asc, &desc);

    cout<<"La lista l1 "<<(Comparar_elem_listas(l1.getPrimero(), asc.getPrimero())? " SI ":" NO " )<<" es accnedente"<<endl;
    cout<<"La lista l1 "<<(Comparar_elem_listas(l1.getPrimero(), desc.getPrimero())? " SI ":" NO " )<<" es descendente "<<endl;


    cout << endl;
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


void Ordenado_asc_desc(Nodo* act, Lista *aux, Lista *aux2){
    
    if(act != NULL){
        aux->insertarEnOrdenAsc(act->getDato());
        aux2->insertarEnOrdenDesc(act->getDato());
        Ordenado_asc_desc(act->getPunt(), aux, aux2);
    }   
}

bool Comparar_elem_listas(Nodo* act, Nodo* aux, bool ban= true){

    if(act != NULL){
        if(act->getDato() != aux->getDato()){
            ban=false;
        }
    }
    else return ban;
    Comparar_elem_listas(act->getPunt(), aux->getPunt(), ban);
}   

//Ordenar los valores de una lista de números en base a la cantidad de dígitos que posee
//NOMBRE: JOSUE RODRIGUEZ 7272

#include <iostream>
using namespace std;
#include "TDA_lista.h"

#define FIN 9999     



int main(){

    Lista l1, l_dig, auxL, auxD;                        
    //
    void ingresarLista(Lista* l);        
    void imprimirLista(Nodo* act);
    int Contar_dig(int num, int conta =0  );
    void lista_dig(Nodo* act, Lista *dig);
    void Ordenar_lista(Nodo* l1, Nodo* dig, Lista* auxL, Lista* auxD );
 
    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());
    
    cout << endl << "LISTA MODIFICADA: " <<endl;
    
    lista_dig(l1.getPrimero(), &l_dig);

    Ordenar_lista(l1.getPrimero(), l_dig.getPrimero(), &auxL, &auxD);
    l1.vaciarLista();
    l1= auxL;
    imprimirLista(l1.getPrimero());

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

int Contar_dig(int num, int conta =0  ){

    if(num != 0) {
        Contar_dig(num/10, conta+1);
    }
    else return conta;
}

void lista_dig(Nodo* act, Lista *dig){
    if(act != NULL){

        dig->insertarAlFinal(Contar_dig(act->getDato()));

        lista_dig(act->getPunt(), dig);
    }   
}

void Ordenar_lista(Nodo* l1, Nodo* dig, Lista* auxL, Lista* auxD ){
    
    if(dig != NULL){
        auxD->insertarEnOrdenAsc(dig->getDato());
        auxL->insertarEnOrdenAsc(l1->getDato());
        Ordenar_lista(l1->getPunt(), dig->getPunt(), auxL, auxD);
    }
}



//Ingresar una lista y modificar sus valores, sumando a cada uno la cantidad de dígitos que posee
//NOMBRE: JOSUE RODRIGUEZ 7272

#include <iostream>
using namespace std;
#include "TDA_lista.h"

#define FIN 9999     


int main(){

    Lista l1, pares, impares;                        
    //
    void ingresarLista(Lista* l);        
    void imprimirLista(Nodo* act);
    void Modificar_lista(Nodo* act, Lista *l1);

    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());
    
    cout << endl << "LISTA MODIFICADA: " <<endl;
    Nodo* prim = l1.getPrimero();
    l1.vaciarLista();

    Modificar_lista(prim, &l1);
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

void Modificar_lista(Nodo* act, Lista *l1){
    //
    int Contar_dig(int num, int conta =0 );
    //

    if(act != NULL){
        l1->insertarAlFinal(act->getDato() + Contar_dig(act->getDato()));
        Modificar_lista(act->getPunt(), l1);
    }
}
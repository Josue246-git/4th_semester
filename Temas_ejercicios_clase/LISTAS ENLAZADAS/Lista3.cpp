//Cononcer elnumero de nodos de la lista

#include <iostream>
using namespace std;
#include "TDA_lista.h"
#include "TDA_pila.h"
#define FIN 9999       //marcador final de lectura

int main(){
    Lista l;                           //crea el objeto de tipo  lista
    //
    void ingresarLista(Lista* l);        //permite el ingreso de valores a la lista
    void imprimirLista(Nodo* act);
    int contarNodo(Nodo* act);
    void Invertir_nodo(Lista &l);                   //invierte el orden de los nodos 
    void Asignar_val_inver(Nodo* act, Pila *p );
    void Invertir_nodo(Lista *l, Pila p1);
    //

    cout << endl << "INGRESAR ELEMENTOS A LA LISTA" <<endl;
    ingresarLista(&l);

    cout << endl << "LOS ELENTOS DE LA LISTA SON: " <<endl;
    imprimirLista(l.getPrimero());

    cout << endl << "EL NUMERO DE ELEMENTOS SON:  " <<endl;
    cout<<contarNodo(l.getPrimero())<<endl;

    cout << endl << "La lista invertida es: :  " <<endl;
    Pila p1;
    
    Asignar_val_inver(l.getPrimero(), &p1);
    l.vaciarLista();
    Invertir_nodo(&l, p1);

    imprimirLista(l.getPrimero());
    cout << endl;
}

void ingresarLista(Lista* l){
    Tipo aux;           //variable de lectura
    
    cout << endl << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    if(aux != FIN){
        //l->insertarAlInicio(aux);        //se ingresa elemento al incio de la lista, actua como una pila
        l->insertarAlFinal(aux);                //cuando se inserta al final acuta como una cola 
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

int contarNodo(Nodo* act){
    if(act != NULL){
        return 1 + contarNodo(act->getPunt());
    }
    return 0;                       //devuelvto por el ultimo llamado al a func recursiva 
}

void Asignar_val_inver(Nodo* act, Pila *p ){
    if(act != NULL){
        p->push(act->getDato());
        Asignar_val_inver(act->getPunt(), p);
    }
}

void Invertir_nodo(Lista *l, Pila p1){
    if(!p1.Pila_vacia()){
        l->insertarAlFinal(p1.pop());
        Invertir_nodo(l, p1);
    }
}                   






//Eliminar el penúltimo nodo de una lista ingresada
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
    int contarNodo(Nodo* act);
    Nodo* val_penu_nodo(Nodo* act, int nodos, Nodo* pen);
    void Eliminar_Nodo(Lista *l, Nodo* pen, Nodo* act);
    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());

    cout<<endl<<"LISTA MODIFICADA: "<<endl;
    int nodos = contarNodo(l1.getPrimero());

    Nodo* pen;
    pen= val_penu_nodo(l1.getPrimero(), nodos-1, pen);

    cout<<endl<<pen->getDato()<<endl;
    
    Nodo* prim= l1.getPrimero();

    l1.vaciarLista();
    Eliminar_Nodo(&l1, pen, prim);

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

int contarNodo(Nodo* act){
    if(act != NULL){
        return 1 + contarNodo(act->getPunt());
    }
    return 0;                       //devuelvto por el ultimo llamado al a func recursiva 
}

Nodo* val_penu_nodo(Nodo* act, int nodos, Nodo* pen){
    
    if(nodos == 0){
        return pen;
    }
    else{
        // cout<<endl<<nodos<<endl;
        Nodo* sig = act->getPunt();
        Nodo* sig2 = sig->getPunt();

        if(sig2 == NULL){
            pen = act;
        }
        val_penu_nodo(act->getPunt(), nodos-1, pen);
    }

}

void Eliminar_Nodo(Lista *l, Nodo* pen, Nodo* act){
    if(act != NULL){
        if(act != pen){
            l->insertarAlFinal(act->getDato());
        }

        Eliminar_Nodo(l, pen, act->getPunt());
    }
}
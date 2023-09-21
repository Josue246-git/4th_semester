//Encontrar el rango de una lista de valores ingresados
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
    int Bucle_men(Nodo* act, int menor);
    int Bucle_may(Nodo* act, int may);
    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());
    Nodo* prim = l1.getPrimero();


    cout<<endl<<"VALOR MAYOR: "<<Bucle_may(prim, prim->getDato())<<endl;
    cout<<endl<<" VALOR MENOR: " <<Bucle_men(prim, prim->getDato())<<endl;

    cout << endl<< "RANGO DE LA LISTA: " <<Bucle_may(prim, prim->getDato()) - Bucle_men(prim, prim->getDato()) <<endl;



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


int Bucle_men(Nodo* act, int menor){

    if(act!= NULL){
        if(act->getDato() < menor){
            menor = act->getDato();
        }  

        Bucle_men(act->getPunt(), menor );
    }
    else return menor;
}

int Bucle_may(Nodo* act, int may){

    if(act!= NULL){
        if(act->getDato() > may){
            may = act->getDato();
        }  

        Bucle_may(act->getPunt(), may );
    }
    else return may;
}



// Calcular la suma de los nodos pares y la suma de los nodos impares de una lista ingresada
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
    void Valores_pares(Nodo* act, Lista *res);
    void Valores_impares(Nodo* act, Lista *res);
    int  Sum_ele(Nodo* act, int sum = 0);
    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());
    
    cout << endl << "LOS ELEMENTOS DE LA LISTA IMPAR SON: " <<endl;
    Valores_impares(l1.getPrimero(), &impares);
    imprimirLista(impares.getPrimero());

    cout<<endl<<"La suma de sus elementos es: "<<Sum_ele(impares.getPrimero())<<endl;

    cout << endl << "LOS ELEMENTOS DE LA LISTA PARES SON: " <<endl;
    Valores_pares(l1.getPrimero(), &pares);
    imprimirLista(pares.getPrimero());

    cout<<endl<<"La suma de sus elementos es: "<<Sum_ele(pares.getPrimero())<<endl;


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

void Valores_pares(Nodo* act, Lista *res){

    if(act != NULL ){
        if(act->getDato() %2 == 0){
            res->insertarAlFinal(act->getDato());
        }
        Valores_pares(act->getPunt(), res);
    }
}

void Valores_impares(Nodo* act, Lista *res){
    if(act != NULL ){
        if(act->getDato() %2 != 0){
            res->insertarAlFinal(act->getDato());
        }
        Valores_impares(act->getPunt(), res);
    }
}

int  Sum_ele(Nodo* act, int sum = 0){
    if(act != NULL){
        sum=sum+act->getDato();
    }
    else return sum;
    Sum_ele(act->getPunt(), sum);
    
}
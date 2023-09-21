//Intercambiar los elementos de posiciones pares con los de las impares de una lista ingresada
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
    int contarNodo(Nodo* act);
    void Valores_pares(Nodo* act, Lista *res, int tam, int conta = 1);
    void Valores_impares(Nodo* act, Lista *res, int tam, int conta = 1);
    void Insertar_pos_inter(Lista* l, Nodo* par, Nodo* impar, int nodos);
    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());

    cout << endl << "LOS ELEMENTOS DE LA LISTA MODIFICADO SON: " <<endl;

    int num_nodos = contarNodo(l1.getPrimero());

    Valores_pares(l1.getPrimero(), &pares, num_nodos),
    Valores_impares(l1.getPrimero(), &impares, num_nodos);



    if(num_nodos%2 != 0){
        num_nodos = num_nodos-1;
        Nodo* ult = impares.ultimo();
        l1.vaciarLista();
        Insertar_pos_inter(&l1, pares.getPrimero(), impares.getPrimero(), num_nodos);
        l1.insertarAlFinal(ult->getDato());
    }
    else{
        l1.vaciarLista();
        Insertar_pos_inter(&l1, pares.getPrimero(), impares.getPrimero(), num_nodos);
    }

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

void Valores_pares(Nodo* act, Lista *res, int tam, int conta = 1){

    if(conta <= tam ){
        if(conta %2 == 0){
            res->insertarAlFinal(act->getDato());
        }
        Valores_pares(act->getPunt(), res, tam, conta+1);
    }
}

void Valores_impares(Nodo* act, Lista *res, int tam, int conta = 1){

    if(conta <= tam ){
        if(conta %2 != 0){
            res->insertarAlFinal(act->getDato());
        }
        Valores_impares(act->getPunt(), res, tam, conta+1);
    }
}

void Insertar_pos_inter(Lista* l, Nodo* par, Nodo* impar, int nodos){
    
    if(nodos != 0){

        if(par != NULL){
            l->insertarAlFinal(par->getDato());
            nodos = nodos-1;
        }
        if(impar != NULL){
            l->insertarAlFinal(impar->getDato());
            nodos = nodos-1;
        }

        Insertar_pos_inter(l, par->getPunt(), impar->getPunt(), nodos);
    }
}





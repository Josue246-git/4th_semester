//Determinar la moda (el valor que aparece con mayor frecuencia) entre los elementos de una lista
//NOMBRE: JOSUE RODRIGUEZ 7272

#include <iostream>
using namespace std;
#include "TDA_lista.h"

#define FIN 9999     


int main(){

    Lista l1, laux;                        
    //
    void ingresarLista(Lista* l);        
    void imprimirLista(Nodo* act);
    void Lista_sin_rep(Nodo* act, Lista *aux);
    void Contar_num_vec(Lista l, Nodo* aux, int *may ,int *val, int con = 1 );

    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());
    
    Lista_sin_rep(l1.getPrimero(), &laux);

    cout<<endl<<"LA MODA DE LA LISTA ES:"<<endl;
    int may_con, val=0;

    Contar_num_vec(l1, laux.getPrimero(), &may_con, &val);
    cout<<"La moda es: "<<val<<", "<<may_con<<" veces "<<endl;
    
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


void Esta_ele_lista(Nodo* act, Nodo* nuevo, bool *ban){

    if(act != NULL ) {
        if(act->getDato() == nuevo->getDato()){
            *ban= true;
        }

        Esta_ele_lista(act->getPunt(), nuevo, ban);
    }
}

void InsertarSinRep(int v, Lista *l){
    //
    void Esta_ele_lista(Nodo* act, Nodo* nuevo, bool *ban);
    //
    
    Nodo* nuevo;                            //apuntador a nuevo nodo a crear
    Nodo* act;   
    bool ban = false;

    nuevo = new Nodo(v);

    if(l->esVacia()){
        l->setPrimero(nuevo);
    }else{
        act = l->getPrimero();   

        Esta_ele_lista(act, nuevo, &ban);

        if(ban == false){
            l->insertarAlInicio(nuevo->getDato());
        }
    }
}

void Lista_sin_rep(Nodo* act, Lista *aux){
    //
    void InsertarSinRep(int v, Lista *l);

    //

    if(act != NULL){
        InsertarSinRep(act->getDato(), aux);

        Lista_sin_rep(act->getPunt(), aux);
    }
}

int num_rep(Nodo* act, int val, int conta =0){

    if(act != NULL){
        if(act->getDato() == val){
            conta= conta+1;
        }
    }
    else return conta;
    num_rep(act->getPunt(), val, conta);
}

void Contar_num_vec(Lista l, Nodo* aux, int *may ,int *val, int con = 1 ){
    //
    int num_rep(Nodo* act, int val, int conta =0);

    //
    
    if(aux != NULL){
        int conta = num_rep(l.getPrimero(), aux->getDato());
        if(con == 1 ) {
            *may = conta;
            *val= aux->getDato();
        }
        if(*may< conta){
            *may = conta;
            *val = aux->getDato();
        }
        Contar_num_vec(l, aux->getPunt(), may, val, con+1);
    }
}

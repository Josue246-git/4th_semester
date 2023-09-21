//GESTION BASICA DE UNA LISTA CIRCULAR
//JOSUE RODRIGUEZ 7272

#include <iostream>
using namespace std;
#include "Lista_circular.h"

#define FIN 9999      


int main(){

    ListaCircular lcir;                           
    //
    void ingresarLista(ListaCircular* l);        
    void imprimirLista(Nodo* act, Nodo* prim);

    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA CIRCULAR 1" <<endl;
    ingresarLista(&lcir);
    Nodo* prim = lcir.getPrimero();

    cout << endl << "LOS ELENTOS DE LA LISTA DEL PRIMERO AL ULTIMO SON: " <<endl;
    imprimirLista(prim, prim);

    Nodo* ult = lcir.getUltimo();
    cout<<endl<<"El val del ultimo nodo es: "<<ult->getDato()<<endl;
    ult = ult->getPunt();
    cout<<endl<<"El val del siguiente es: "<<ult->getDato()<<endl;

}


void ingresarLista(ListaCircular* l){

    Tipo aux;           
    
    cout << endl << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    if(aux != FIN){
        l->insertarAlFinal(aux);
        ingresarLista(l);
    }
}


void imprimirLista(Nodo* act, Nodo* prim){

    if(act != NULL ){
        do{
            cout <<  "> " << act -> getDato() << endl;
            act = act -> getPunt();
        } while (act!= prim);
    }
    else cout<<endl<<"La lista esta vacia"<<endl;
}


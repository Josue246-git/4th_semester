//GESTION BASICA DE UNA LISTA DOBLE
//JOSUE RODRIGUEZ 7272

#include <iostream>
using namespace std;
#include "Lista_doble.h"

#define FIN 9999      


int main(){

    ListaDoble ldob;                           
    //
    void ingresarLista(ListaDoble* l);        
    void imprimirListaPU(Nodo* act);
    void imprimirListaUP(Nodo* act);

    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA CIRCULAR 1" <<endl;
    ingresarLista(&ldob);

    cout << endl << "LOS ELENTOS DE LA LISTA DEL PRIMERO AL ULTIMO SON: " <<endl;
    imprimirListaPU(ldob.getPrimero());                  //Imprime la lista del primero al ultimo

    cout << endl << "LOS ELENTOS DE LA LISTA DEL ULTIMO AL PRIMERO SON: " <<endl;
    imprimirListaUP(ldob.getUltimo());                  //Imprime la lista del ultimo al primero

}

void ingresarLista(ListaDoble* l){

    Tipo aux;           
    
    cout << endl << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    if(aux != FIN){
        l->insertarAlFinal(aux);
        ingresarLista(l);
    }
}

void imprimirListaPU(Nodo* act){
    if(act != NULL){
        cout <<  "> " << act -> getDato() << endl;
        act = act -> getPunt();
        imprimirListaPU(act);
    }
}

void imprimirListaUP(Nodo* act){

    if(act != NULL){
        cout <<  "> " << act -> getDato() << endl;
        act = act -> getAnte();
        imprimirListaUP(act);
    }
}

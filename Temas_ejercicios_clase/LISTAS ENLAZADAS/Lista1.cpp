//Gestin lista simplemente enlazada
//A la final una lista funciona como una pila 
#include <iostream>

using namespace std;
#include "TDA_lista.h"

#define FIN 9999

int main(){
    Lista lis;
    //
    void Ingresar_lista(Lista *lis);
    void Imprimir_lista(Lista lis);
    //

    cout<<endl<<"El apuntador primero apunta a: "<< lis.getPrimero()<<endl;
    cout<<endl<<"La lista : "<<( lis.esVacia() ? " SI ": " NO" )<<" esta vacia "<<endl;

    Ingresar_lista(&lis);

    Imprimir_lista(lis);

    cout<<endl;
    return 0;
}

void Ingresar_lista(Lista *lis){
    Tipo aux;                       //var de lectura

    cout<<endl<<"Ingrese un valor a aniadir en la lista, finalice con [ "<<FIN<<" ] "; cin>>aux;
    if(aux != FIN){
        lis->insertarAlFinal(aux);
        Ingresar_lista(lis);
    }
}

void Imprimir_lista(Lista lis){
    Nodo *act;
    act = lis.getPrimero();

    while(act != NULL){
        cout << endl << "> " << act->getDato() << endl;
        act = act->getPunt();
    }
}

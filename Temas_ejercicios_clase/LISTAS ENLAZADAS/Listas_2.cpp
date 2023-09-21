//Implementa una lista simplemente en lazada
//JOSUE RODRIGUEZ 7272

using namespace std;

#include <iostream>
#include "TDA_lista.h"
#define FIN 0       //marcador final de lectura

int main(){

    Lista l;                //crea el objeto de tipo  lista
	//
    void ingresarLista(Lista* l);        //permite el ingreso de valores a la lista
    void imprimirLista(Nodo* act);
    void BusarEnLista(Lista l);
    void EliminarNodo(Lista l);			//metodo qye permite elminar el nod oque ocntiene el vlor v
    //

    cout << endl << "El apuntador primero apunta a: " << l.getPrimero();
    cout << endl << "La lista " << (l.esVacia()? "SI ": "NO ") << "esta vacia";

    ingresarLista(&l);           //llamado a la funcion 
    Nodo* act = l.getPrimero();
    imprimirLista(act);
    
    Nodo* ult = l.ultimo();
	cout<<endl<<"El ulimo nodo contiene el valor : "<<ult->getDato()<<endl;
	
	BusarEnLista(l);
	EliminarNodo(l);
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

// void imprimirLista(Lista l1){
//     Nodo *act;
//     act = l1.getPrimero();

//     while(act != NULL){
//         cout << endl << "> " << act->getDato() << endl;
//         act = act->getPunt();
//     }
// }

void BusarEnLista(Lista l){
	Tipo vB;			//variable del valora buscar 
	Nodo* enc;
	
	cout<<endl<<"Ingrese el vaor a buscar"<<endl;
	cin>>vB;
	
	enc = l.buscarElemento(vB);
	
	cout<<endl<<"El valor "<<vB<< (enc == NULL ? " NO": " SI")<<" se encuentra en la lista "<<endl;
}

void EliminarNodo(Lista l){
	Tipo ve;
	
	cout<<endl<<"Ingrese el valor a eliminar: "; cin>>ve;
	
	if(l.eliminarNodo(ve)){
		cout<<"Elmento eliminado "<<endl;
        Nodo* act = l.getPrimero();
		imprimirLista(act);
	}
	else cout<<endl<<"Error al eliminar el elemnto ...... Nueva lista: "<<ve<<endl;	
}




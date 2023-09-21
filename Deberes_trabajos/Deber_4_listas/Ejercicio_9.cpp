//Implementar el algoritmo de búsqueda binaria en una lista de valores previamente ingresada
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
    bool Busqueda_binaria(int value, Lista l);


    //
    
    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());
    
    int n;
    cout << endl << "Ingrese un elemento a buscar en la lista: ";cin >>n;

    cout<<"El elemento "<<n<<(Busqueda_binaria(n, l1)? " SI ":" NO " )<<" esta en la lista"<<endl;


    cout << endl;
}

void ingresarLista(Lista* l){
    Tipo aux;           //variable de lectura
    
    cout << endl << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    if(aux != FIN){
        //l->insertarAlInicio(aux);        //se ingresa elemento a la lista
        // l->insertarAlFinal(aux);
        l->insertarEnOrdenAsc(aux);
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


int Obtener_val_nodo(Nodo* act, int n, int conta=1, int val=0){
    if(act!= NULL){
        if(conta == n){
            val= act->getDato();
        }
    }
    else return val;
    Obtener_val_nodo(act->getPunt(), n, conta+1, val);
}


bool Busqueda_bin_Recursive(int value, Nodo* current, int left, int right) {
    //
    int Obtener_val_nodo(Nodo* act, int n, int conta=1, int val=0);

    //
    if (left > right) {
        return false; // El elemento no fue encontrado
    }
    else{
        int mid = left + (right - left) / 2;
        int midValue = Obtener_val_nodo(current, mid);

        if (midValue == value) {
            return true; // El elemento fue encontrado
        } else if (midValue < value) {
            return Busqueda_bin_Recursive(value, current->getPunt(), mid + 1, right);
        } else {
            return Busqueda_bin_Recursive(value, current->getPunt(), left, mid - 1);
        }
    }

}

bool Busqueda_binaria(int value, Lista l) {
    //
    bool Busqueda_bin_Recursive(int value, Nodo* current, int left, int right);
    int contarNodo(Nodo* act);

    //
    int left = 0;
    int right = contarNodo(l.getPrimero()) - 1;

    return Busqueda_bin_Recursive(value, l.getPrimero(), left, right);
}


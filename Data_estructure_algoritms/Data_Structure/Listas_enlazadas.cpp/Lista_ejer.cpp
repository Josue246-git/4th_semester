#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{ 
    int dato;
    struct Nodo *siguiente;
};

//Agreagar sin orden 
void Insertar_nodo_lista(Nodo *&lista, int n ){

    Nodo *nuevo_nodo= new Nodo();
    nuevo_nodo -> dato = n;

    Nodo *aux = lista ;
    Nodo *anterior = NULL;
    
    if(lista == NULL){
        lista= nuevo_nodo;
        nuevo_nodo->siguiente= NULL ;
    }
    else{
        while (aux != NULL){
            anterior = aux;
            aux = aux->siguiente;
        }
        anterior->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = aux;
    }

}

void Mostrar_elementos(Nodo *lista){

    Nodo * actual = new Nodo;
    actual = lista;

    while(actual != NULL){
        cout<<actual->dato<<" -> ";
        actual = actual-> siguiente;
    }
}

void Mostrar_menor_mayor_elemento(Nodo *lista){

    int mayor = 0, menor = 99999;
    
    while(lista != NULL){
        if(lista->dato > mayor){
            mayor = lista->dato;
        }
        if(lista->dato < menor){
            menor = lista->dato;
        }
        lista= lista->siguiente;
    }

    cout<<"\nEl mayor numero es: "<<mayor<<endl;
    cout<<"El menor elemento es: "<<menor<<endl;
}


int main(){ 
    int num_elementos,n;
    Nodo * lista= NULL;

    cout<<"Ingrese el numero de elementos que desea ingresar. ";cin>>num_elementos;

    for (int i = 0; i < num_elementos; i++){   
        cout<<"Ingrese el "<<i+1<<" elemento a la lista: ";cin>>n;
        Insertar_nodo_lista(lista, n);
    }
    cout<<"\n"<<endl;
    Mostrar_elementos(lista);
    Mostrar_menor_mayor_elemento(lista);

    return 0;
}



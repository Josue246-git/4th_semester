//FIFO
#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

bool cola_vacia(Nodo *frente){
    return(frente == NULL)? true : false;
}


void agregar_a_Cola(Nodo *&frente, Nodo *&fin, int n){

    Nodo *nuevo_nodo = new Nodo(); 
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = NULL;

    if(cola_vacia(frente)) frente = nuevo_nodo;
    else fin-> siguiente = nuevo_nodo; 

    fin = nuevo_nodo;
};

void quitar_de_cola(Nodo *& frente, Nodo *& fin, int &n){
    
    n = frente -> dato;
    Nodo *aux = frente;


    if(frente == fin ) {
        frente = NULL;
        fin = NULL;
    }
    else{
        frente = frente-> siguiente;
    }
    delete aux;
}

int main(){ 

    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato;
    cout<<"Digita un dato: "; cin>>dato;
    agregar_a_Cola(frente, fin, dato);

    cout<<"Digita otro  dato: "; cin>>dato;
    agregar_a_Cola(frente, fin, dato);

    cout<<"Digita otro dato: "; cin>>dato;
    agregar_a_Cola(frente, fin, dato);


    while(frente!= NULL ){
        quitar_de_cola(frente, fin , dato);
        if( frente != NULL ) cout<<dato<<" , ";
        else cout<<dato<<" . ";
    }
    
    return 0;
}



#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

void agregar_nodo_a_Pila(Nodo *& pila, int n){
    //Primer paso: Crear espacio en memoria para un nuevo nodo
    Nodo *nuevo_nodo = new Nodo();
    //Segundo paso: Llenar el dato 
    nuevo_nodo-> dato = n;
    //Tercer paso: Cargar el puntero 
    nuevo_nodo-> siguiente = pila;
    //Cuarto: Asignar el nuevo nodo a pila
    pila = nuevo_nodo;
}

void quitarPila(Nodo *& pila, int &n){
    Nodo *aux = pila;  
    n = aux -> dato;
    pila = aux -> siguiente;
    delete aux; 
}

int main(){
    int dato, n1, n2;
    Nodo *pila= NULL;
    
    cout<<"Digite un numero: "; cin >>n1;
    cout<<"Digite otro numero: "; cin >>n2;
    agregar_nodo_a_Pila(pila, n1);
    agregar_nodo_a_Pila(pila, n2);

    while(pila != NULL){
        quitarPila(pila, dato);
        if( pila != NULL ) cout<<dato<<" , ";
        else cout<<dato<<" . ";
    };  
    
    return 0;
}
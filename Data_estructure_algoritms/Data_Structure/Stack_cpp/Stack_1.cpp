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

    cout<<"Elemento"<<nuevo_nodo -> dato<<" agregado correctamente"<<endl;
}

void quitarPila(Nodo *& pila, int &n){
    Nodo *aux = pila;  
    n = aux -> dato;
    pila = aux -> siguiente;
    delete aux; 
}

int main(){
    int dato, n_nodos, n;
    Nodo *pila= NULL;
    
    cout<<"Digite el numero de nodos del stack: "; cin >>n_nodos;

    for(int i=0; i< n_nodos; i++){
        cout<<"Digite el numero: "; cin >>n;
        agregar_nodo_a_Pila(pila, n);
    };

    while(pila != NULL){
        quitarPila(pila, dato);
        if( pila != NULL ) cout<<dato<<" , ";
        else cout<<dato<<" . ";
    };  
    
    return 0;
}
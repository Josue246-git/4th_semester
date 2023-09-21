//5. Implementar el ordenamiento por inserción en una pila
//Nombre: jOSUE rODRGUEZ

#include <iostream>

typedef int Tipo; 
#define EXT 20
#define fin 9999
#include "TDA_pila.h"

using namespace std;



int main(){
    Pila p;
    //
    void leerPila(Pila *p );        
    void imprimirPila(Pila p);
    void ordenarPila(Pila *p);

    //

    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);

    cout<<endl<<"\t\t\t\t Ordenamiento descendente por inserción en una pila  "<<endl;
    
    ordenarPila(&p);
    imprimirPila(p);
    

    cout<<endl;
    return 0;
}

void leerPila(Pila *p ){          
    Tipo vl;  
    cout<<"Ingrese un valor a apilar, finalice con "<<fin<<": "; cin >> vl;

    if(vl != fin ){
        if(!p->Pila_llena()){
            p->push(vl);
            leerPila(p);
        }
        else cout<<"EROR....... PILA LLENA"<<endl;

    }
}

void imprimirPila(Pila p){
    if(!p.Pila_vacia()){
        cout<<endl<<" > "<<p.pop()<<endl;
        imprimirPila(p);
    }   
}    

void insertarEnOrden(Pila *pila, int elemento) {
    if (pila->Pila_vacia() || elemento > pila->Cima_pila()) {
        pila->push(elemento);
    } else {
        int temp = pila->Cima_pila();
        pila->pop();
        insertarEnOrden(pila, elemento);
        pila->push(temp);
    }
}

void ordenarPila(Pila *p) {
    if (!p->Pila_vacia()) {
        int temp = p->Cima_pila();
        p->pop();
        ordenarPila(p);
        insertarEnOrden(*&p, temp);
    }
}

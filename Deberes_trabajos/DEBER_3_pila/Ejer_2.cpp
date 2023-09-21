// 2. Calcular la suma de los elementos de una pila

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
    Tipo Suma_ele_pila(Pila p );
    //
    
    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);

    cout<<endl<<"\t\t\t\t CALCULAR LA SUMA DE LOS ELEMENTOS DE UNA PILA   "<<endl;
    cout<<endl<<"La suma de la pila es: "<<Suma_ele_pila(p)<<endl;

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

Tipo Suma_ele_pila(Pila p ){
    
    Tipo suma = 0;
    while(!p.Pila_vacia()){
        suma += p.pop();
    }
    return suma;
}


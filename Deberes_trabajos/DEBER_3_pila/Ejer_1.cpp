// 1. Encontrar el máximo y mínimo elemento de una pila

//Nombre: jOSUE rODRGUEZ

#include <iostream>

typedef int Tipo; 
#define EXT 20
#define fin 9999
#include "TDA_pila.h"

using namespace std;




int main(){
    Pila p;
    //PROTOTIPOS
        void leerPila(Pila *p );         
        void imprimirPila(Pila p);
        Tipo Max_val_pila(Pila p, Tipo may );
        Tipo Min_val_pila(Pila p, Tipo min );
    //
    
    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);

    cout<<endl<<"\t\t\t\t COMPROBAR EL MAX Y EL MIN VALOR DE LA PILA  "<<endl;
    Tipo cima = p.pop();
    cout<<"El max valor de la pila es:  "<<Max_val_pila(p, cima )<<endl;

    cout<<"El min valor de la pila es:  "<<Min_val_pila(p, cima)<<endl;

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

Tipo Max_val_pila(Pila p, Tipo may ){

    if(p.Pila_vacia()) return may;
    
    else {
        Tipo sig = p.pop();
        if(sig > may) may = sig;
        Max_val_pila(p,may);
    }
}

Tipo Min_val_pila(Pila p, Tipo min ){
    if(p.Pila_vacia()) return min;
    
    else {
        Tipo sig = p.pop();
        if(sig < min) min = sig;
        Min_val_pila(p,min);
    }
}

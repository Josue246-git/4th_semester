//9. Permitir el ingreso de una Pila de valores, y desplazar de sus valores N posiciones (considere valores positivos y negativos).

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
    void invertirPila(Pila p, Pila *p2);
    void Desplazar_elem(Pila *p, int n, Pila p2);
    //

    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);
    int n;

    do{
        cout<<"Ingrese el num de pos a desplazar los elementos, (si es neg -> abajo, si es pos ->arriba ) "; cin>>n;
    }
    while(abs(n) + p.get_tope() >= EXT);

    Pila p2;
    invertirPila(p, &p2); 

    Desplazar_elem(&p, n, p2);
    imprimirPila(p);

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

void invertirPila(Pila p, Pila *p2){
    
    int tope = p.get_tope()+1;
    for (int i = 0; i < tope; i++){
        p2->push(p.pop());
    }

}

void Desplazar_elem(Pila *p, int n, Pila p2){
    if(n >=  0 ){           //Si son positivos

        p->limpiar_pila();
        int tope_p2 = p2.get_tope()+1; 

        for (int i = 0; i < (n + tope_p2); i++){
            if(i < n) p->push(0);
            else p->push(p2.pop());
        }
    }
    else{
        for (int i = 0; i < abs(n); i++){
            p->push(0);
        }
    }
}
//10. Permitir el ingreso de una pila de valores, proceder a intercalar sus valores de inicio y final (primero, último, segundo, penúltimo, tercero, antepenúltimo, etc.)

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
    void Intercalar_pila(Pila *p);
    //

    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);

    cout<<"\t\t\tINTERCALAR PILA "<<endl;
    Intercalar_pila(&p);
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

void Intercalar_pila(Pila *p){
    Pila p2 = *p;
    int pos_cima = p2.get_tope()+1;
    p->limpiar_pila();

    for (int i = 0; i < pos_cima ; i++){            //Controla el numero de intercalaciones 
        p->push(p2.pop());    
    }
}

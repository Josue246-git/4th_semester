//PINGRESAR ORDENADAMENTE LOS VALORES EN UNA COLA 

//Nombre: jOSUE rODRGUEZ

#include <iostream>
#define EXT 20
#define fin 9999
#include "TDA_cola.h"
using namespace std;

int main(){
    Cola c, c2;
    //
        void Leer_cola(Cola *c);
        void Imprimir_cola(Cola c);
    //
    Tipo val = 0;

    cout<<"\t\t\tIngreso los datos de la primera la cola "<<endl;
    Leer_cola(&c);
    cout<<" \t\t\tImpresion de cola: "<<endl;
    Imprimir_cola( c);

    cout<<"\t\t\tIngreso los datos de la segunda la cola "<<endl;
    Leer_cola(&c2);
    cout<<" \t\t\tImpresion de cola 2: "<<endl;
    Imprimir_cola(c2);

    //
    
    cout<<endl;
}

void Leer_cola(Cola *c){
    Tipo vl;  
    void Ingresar_ordenar_cola(Cola *c, Tipo actual, Tipo vl);
    cout<<"Ingrese un valor a poner en la cola, finalice con "<<fin<<": "; cin >> vl;

    if(vl != fin ){
        if(!c->Cola_llena()){
            if(c->Tamanio_cola()+1 == 1) c->Insertar(vl);
            else Ingresar_ordenar_cola(c,c->Frente_cola(), vl);
            Leer_cola(c);
        }
        else cout<<endl<<"\t\t\t\tLa cola ya esta llena "<<endl;
    }
}

void Imprimir_cola(Cola c){
    if(!c.Cola_vacia()){
        cout<<endl<<" > "<<c.Quitar()<<endl;
        Imprimir_cola(c);
    }
}

void Ingresar_ordenar_cola(Cola *c, Tipo actual, Tipo vl){
    Cola copia_C = *c;
    Cola aux; 

    if(actual < vl){
        while (copia_C.Tamanio_cola()-2){

            aux.Insertar();
        }
        
        aux.Insertar();
    }
}
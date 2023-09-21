                                            //COLA CIRCULAR GESTION BASICA 
//Nombre: jOSUE rODRGUEZ

#include <iostream>
#define EXT 20
#define fin 9999
#include "TDA_cola_circular.h"
using namespace std;

int main(){

    ColaCircular c;
    //
        void Leer_cola(Cola *c);
        void Imprimir_cola(Cola c);

    //
    cout<<"Ingreso e impresion de cola "<<endl;
    Leer_cola(&c);

    cout<<" Impresion de cola: "<<endl;
    Imprimir_cola( c);

    cout<<endl;
}

void Leer_cola(Cola *c){
    Tipo vl;  
    cout<<"Ingrese un valor a poner en la cola, finalice con "<<fin<<": "; cin >> vl;

    if(vl != fin ){
        if(!c->colaLlena()){
            c->insertar(vl);
            Leer_cola(c);
        }
        else cout<<endl<<"\t\t\t\tLa cola ya esta llena "<<endl;
    }
}

void Imprimir_cola(Cola c){
    if(!c.colaVacia()){
        cout<<endl<<" > "<<c.quitar()<<endl;
        Imprimir_cola(c);
    }
}



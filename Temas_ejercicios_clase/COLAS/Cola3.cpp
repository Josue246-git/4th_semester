//Progrma para vber si cola A esta en cola B y viceversa 

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
        bool Esta_en_cola(Cola c, Tipo val);
        bool Comprobar_colaA_enB(Cola c, Cola c2);
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

    //VER SI UNA COLA A ESTA COMPUESTA EN B Y VICEVERSA  

    cout<<endl<<" LA cola A"<<(Comprobar_colaA_enB(c,c2) && Comprobar_colaA_enB(c2,c)? " SI ": " NO ")<<" esta en la cola B y viceversa"<<endl;
    cout<<endl;
}

void Leer_cola(Cola *c){
    Tipo vl;  
    cout<<"Ingrese un valor a poner en la cola, finalice con "<<fin<<": "; cin >> vl;

    if(vl != fin ){
        if(!c->Cola_llena()){
            c->Insertar(vl);
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

bool Esta_en_cola(Cola c, Tipo val){
    if(c.Cola_vacia()){
        return false;
    }
    else{
        if(c.Quitar()== val){
            return true;
        }
    }
    return Esta_en_cola(c, val);
}

bool Comprobar_colaA_enB(Cola c, Cola c2){

    while(!c.Cola_vacia()){
        if(!Esta_en_cola(c2, c.Quitar())) return false;             //HAY UN AVPOR DE C QUE NO ESTA EN C2
    };
    return true;
}

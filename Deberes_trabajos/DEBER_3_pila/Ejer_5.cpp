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
    Pila Insercion_Pila(Pila *p);

    //

    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);

    cout<<endl<<"\t\t\t\t Ordenamiento descendente por inserción en una pila  "<<endl;
    
    Pila p2 =Insercion_Pila(&p);

    p=p2;

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



Pila Insercion_Pila(Pila *p){

    Pila aux;
    while (!p->Pila_vacia()) {
        int tmp = p->Cima_pila();
        p->pop();

        while (!aux.Pila_vacia() && aux.Cima_pila() > tmp) {            //cambiar de > a < si se desea de forma ascendente
            p->push(aux.Cima_pila());
            aux.pop();
        }
        aux.push(tmp);
    }
    return aux;
}

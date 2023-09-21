// 4. Ingresar una pila de elementos entre los cuales se admite únicamente hasta N valores repetidos (Si se alcanza dicho valor, se aceptarán solamente valores únicos.

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
    bool ver_pila_rep_nveces(Pila p,int n, Tipo vl);
    bool ver_pila_rep_nveces(Pila p,int n, Tipo vl);
    void leerPila(Pila *p, int n);
    void imprimirPila(Pila p);

    //

    int n;
    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    cout<<"Inigrese el numero de veces en el que quiere que se repita los elelemntos, (debe eser mayor a 1): ";cin>>n;
    
    leerPila(&p, n);
    imprimirPila(p);


    cout<<endl;
    return 0;
}

bool ver_pila_rep_nveces(Pila p,int n, Tipo vl){            //VERIFICA si el num que se quiere ingresar ya esta repetido n veces en la pila actual 
    int n_veces = 0;

    while(!p.Pila_vacia()){
        if( vl == p.pop()){
            n_veces++;
        }
    }

    if(n_veces == n) {
        return true;
    }
    else return false;
}

void leerPila(Pila *p, int n){    
    Tipo vl;  
    cout<<"Ingrese un valor a apilar, finalice con "<<fin<<": "; cin >> vl;
    
    if(vl != fin ){
        if(!p->Pila_llena()){
            if(p->get_tope() <= 0 ) p->push(vl);                //primeros dos elemeto si acepta

            else {
                if(!ver_pila_rep_nveces(*p,n,vl)) p->push(vl);
                else cout<<endl<<"\t\tFavor de ingresar de aqui en adelante valores unicos no rep. que ya no sea "<<vl<<endl;
            }
            leerPila(p,n);
        }
        else cout<<"ERROR....... PILA LLENA"<<endl;
    }
}

void imprimirPila(Pila p){
    if(!p.Pila_vacia()){
        cout<<endl<<" > "<<p.pop()<<endl;
        imprimirPila(p);
    }   
}    
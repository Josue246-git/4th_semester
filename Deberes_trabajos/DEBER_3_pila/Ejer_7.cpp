//7. Insertar N elementos en las posiciones centrales de una pila

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
    void Insertar_elementos_medio(Pila *p, Pila p3);
    Tipo Retornar_elem(Pila p, int pos );
    //
    
    int dir = 0;
    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);


    if((p.get_tope()+1) % 2 == 0) cout<<endl<<" Pos centrales de la pila -> "<<p.get_tope()/2 +1<<" con valor: "<<Retornar_elem(p,p.get_tope()/2+1) <<" y "<<p.get_tope()/2 <<" con valor: "<<Retornar_elem(p,p.get_tope()/2)<<endl;
    else cout<<endl<<" Pos central de la pila -> "<<p.get_tope()/2<<" con valor: "<<Retornar_elem(p,p.get_tope()/2)<<endl;

    cout<<endl<<"\t\t\t\t Insertar N elementos en la pos central de la pila  "<<endl;

    Pila p3;

    cout<<endl<<"Ingresar los valores que se desea insertar: "<<endl;
    leerPila(&p3);

    cout<<endl<<"Pila a insertar eS: "<<endl;
    imprimirPila(p3);
    
    Insertar_elementos_medio(&p, p3);

    cout<<endl<<"LA PILA FINAL ES: "<<endl;
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

void Insertar_elementos_medio(Pila *p, Pila p3){

    Pila p2; 
    int num_ele = p->get_tope()+1;

    for (int i = num_ele; i > num_ele/2+1 ; i--){
        p2.push(p->pop());
    }
    for (int i = 0; i <= p3.get_tope()+2; i++){
        // cout<<endl<<" "<<i<<" "<<endl;
        p->push(p3.pop());
    }
    for (int i = 0; i <= p2.get_tope()+1; i++){
        p->push(p2.pop());
    }
}

Tipo Retornar_elem(Pila p, int pos ){           //Retorna el elemento de una posicion de pila dado
    while(!p.Pila_vacia()){
        Tipo val = p.pop();
        if(p.get_tope()+1 == pos){
            return val;
        }
    }
}
    
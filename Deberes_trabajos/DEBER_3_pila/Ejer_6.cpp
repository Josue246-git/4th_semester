//6. Calcular el promedio de los elementos que ocupan las posiciones centrales de una pila

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
    float Calcular_pos_centrales(Pila p);


    //
    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);
    
    cout<<"La suma entre los elementos de las pos centrlaes de la pila es: "<<Calcular_pos_centrales(p)<<endl;

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

float Calcular_pos_centrales(Pila p){
    
    float conta, sum = 0;
    int num_ele = p.get_tope()+1;

    if(num_ele % 2 != 0){           //N_elemtentos de pila IMPARES

        cout<<endl<<"(Pila con n_elemntos IMPARES)"<<endl;
        while (p.get_tope()+1 >= num_ele/2+1 ){
            sum = p.pop();
        }
        return sum;
    }
    else{                       //N_elementso de la pila PARES

        cout<<endl<<"(Pila con n_elemntos PARES)"<<endl;
        cout<<" DE los valores centrales: ";
        for (int i = num_ele; i > 0; i--){
            int num = p.pop();
            if(i == num_ele/2+1 || i == num_ele/2){
                sum+= num;
                conta++;

                cout<<num<<"  ";
            }
        }
    }
    cout<<endl;
    
    return (sum/conta);   
}
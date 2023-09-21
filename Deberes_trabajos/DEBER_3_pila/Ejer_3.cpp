// 3. Intercambiar, por parejas, los elementos de una pila previamente ingresada (primero con segundo, tercero con cuarto, etc.).

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
    int pos_cambiar(int pos);
    void Intercacmbiar_pos_elem(Pila *p, int pos1, int pos2 );
    //

    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);

    cout<<endl<<"\t\t\t\tIngresar las posiciones a cambiar "<<endl;
    int pos1 = pos_cambiar(p.get_tope());

    cout<<endl<<"La pos 1 es: "<<pos1<<endl;

    int pos2 = pos_cambiar(p.get_tope());
    cout<<endl<<"La pos 2 es: "<<pos2<<endl;

   
    if(pos1 < pos2){            //Para que pos1 sia simepre mayor a pos2
        int aux = pos1;
        pos1 = pos2;
        pos2 = aux;
    }

    Intercacmbiar_pos_elem(&p, pos1, pos2 );
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

int pos_cambiar(int pos){           //Comprueba que sea menor al numero de pos. de la pila original 
    int val = 0;
    do{
        cout<<"Ingresa el valor, considerar que se cuenta desde cero "; cin>> val;
    }
    while(val > pos || val < 0);

    return val;
}

void Intercacmbiar_pos_elem(Pila *p, int pos1, int pos2 ){

    Pila p3 ;
    Tipo val1, val2 = 0;

    int i = p->get_tope();

    while( !p->Pila_vacia()){
        if(p->get_tope() == pos1) {
            val1 = p->pop();
            cout<<endl<<"\t\t\t\tPOSICIONES "<<pos1<<" val( "<<val1<<" ) ";
        }
        else if( p->get_tope() == pos2) {
            val2 = p->pop();
            cout<<" y "<<pos2<<" val( "<<val2<<" )"<<endl;
        }
        else p3.push(p->pop());
    }
    int j=0;
     
    // cout<<endl<<val1<<" "<<val2<<endl;
    // cout<<"IMPRIMIR PREVIA "<<endl;

    while (j <= i){
        if(j  == pos2) p->push(val1);
        
        else if( j == pos1) p->push(val2);
        
        else p->push(p3.pop());
        j++;
    }
}
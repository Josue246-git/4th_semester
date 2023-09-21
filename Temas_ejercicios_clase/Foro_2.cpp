//Prograsma que permita ver si un umero es palindormo o no
//NOTA: EVITAR EL USO DE VECTORES 

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
        void imprimirPila(Pila p);
        void Sacar_dig(int num,Pila * p);
        bool Comprobar_pali( int num, Pila p);
        
    //
    
    int num=0;
    cout<<endl<<"Ingresa un numero a comprobar entero: ";cin>>num;
    Sacar_dig(num, & p);                            //Para guradarlo en la pila 

    cout<<endl<<"LA PILA ES:"<<endl;
    imprimirPila(p);

    cout<<endl<<"\t\t\t\t"<<num<< " ES PALINDROMO ?"<<endl;

    cout<<endl<<"EL numero "<<num<<(Comprobar_pali(num, p) ? " SI":" NO" )<<" es palindromo "<<endl;
    cout<<endl;
    return 0;
}


void Sacar_dig(int num, Pila * p){

    if (num / 10 != 0) {
        Sacar_dig(num / 10, p); // Llamada recursiva con el cociente
    }
    int digito = num % 10; // Obtener el dígito actual
    p->push(digito);
}

void imprimirPila(Pila p){

    if(!p.Pila_vacia()){
        cout<<endl<<" > "<<p.pop()<<endl;
        imprimirPila(p);
    }   
}    

bool Comprobar_pali( int num, Pila p){

    if (num / 10 != 0) {
        return Comprobar_pali(num / 10, p);         // Llamada recursiva con el cociente
    }
    int digito = num % 10;                  // Obtener el dígito actual
    
    if(digito != p.pop()){
        return false;
    }
    else return true;
}




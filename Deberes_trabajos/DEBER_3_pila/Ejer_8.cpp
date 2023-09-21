//8. Ingresar una frase y proceda a invertir el orden de las palabras, por medio del empleo de pilas

//Nombre: jOSUE rODRGUEZ
//NOTA: AL ARCHIVO TDA_pila.h, se lo debe pasar su Tipo a char para que el programa funcione

#include <iostream>
#include <string.h>

typedef char Tipo; 
#define EXT 20
#define fin 9999
#include "TDA_pila.h"

using namespace std;

int main(){
    Pila p;

    //
    void leerPila(Pila *p );
    void imprimirPila(Pila p);
    void Poner_frase_pila(char f[], Pila *p);
    //

    cout<<endl<<"Ingresar la frase a invertir por pila "<<endl;
    char f[EXT];    
    cin.getline(f, EXT, '.');
    cout<<"La frase es: "<<f<<endl;

    Poner_frase_pila(f, &p);

    cout<<endl<<"\t\t\t\tLa frase invertida es: "<<endl;

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
        cout<<p.pop();
        imprimirPila(p);
    }   
}    

void Poner_frase_pila(char f[], Pila *p){
    int num_pala = strlen(f);
    for (int i = 0; i < num_pala; i++){
        p->push(f[i]);
    }
}
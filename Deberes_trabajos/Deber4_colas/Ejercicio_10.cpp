//Permitir el ingreso de varios números enteros, y generar una cola ordenada con los divisores primos de cada 
//uno de ellos
//Nombre: JOSUE RODRIGUEZ (7272)

#include <iostream>
#define EXT 20
#define FIN 9999
#include "TDA_cola_circular.h"
using namespace std;


int main(){

    Cola c;

    //
    void leer_cola(Cola *c);
    void ing_enteros(int n);
    //

    int n;
    cout<<endl<<"Ingrese el cant. de numeros enteros que se desee sacar sus primos: "; cin>>n;
    ing_enteros(n);

    cout<<endl;
}

void leer_cola(Cola *c){
    Tipo vl;  
    cout<<"Ingrese un valor a poner en la cola, finalice con "<<FIN<<": "; cin >> vl;

    if(vl != FIN ){
        if(!c->colaLlena()){
            c->insertar(vl);
            leer_cola(c);
        }
        else cout<<endl<<"\t\t\t\tLa cola ya esta llena "<<endl;
    }
}

void imprimir_cola(Cola c1){
    if(!c1.colaVacia()){
        cout << endl << ">  " << c1.quitar();
        imprimir_cola(c1);
    }
}

void Generar_cola_div(int num, ColaCircular *c, int aum=1){
     
    if(aum <= num){ 
        if(num % aum == 0){
            if(!c->colaLlena()){
                c->insertar(aum);
            }
            else cout<<endl<<"\t\t\t\tLa cola ya esta llena "<<endl;
        }
        Generar_cola_div(num, c, aum+1);
    }
}

void ing_enteros(int n){
    if(n>0){
        int num;
        ColaCircular c;
        cout<<endl<<endl<<"Ingrese un numero entero para sacar sus divisores :"; cin>>num;
        cout<<endl<<"Los divisores de "<<num<<" son: ";
        Generar_cola_div(num, &c);
        imprimir_cola(c);
        ing_enteros(n-1);
    }
}




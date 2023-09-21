                                            //PILA GESTION BASICA 
//Nombre: jOSUE rODRGUEZ

#include <iostream>
#include <vector>

#include "TDA_pila.h"
typedef int Tipo; 
#define EXT 20

using namespace std;

int main(){
    Pila p, q;
    //
        void leerPila(Pila *p );              //ingresa datos en la pila, por referiencia ya que el objeto p se modificara 
        void imprimirPila(Pila p);
        bool Comparar_pilas(Pila p, Pila q);
        void Invertir_pila(Pila *p);
    //
    
    //ingreso y visualizacion de datoS: 

    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);

    // cout<<endl<<endl<<"Ingresar e imprimir los valores en la pila 2"<<endl;
    // leerPila(&q);
    // imprimirPila(q);

    // cout<<endl<<"Las dos pilas ingresadas: "<<(Comparar_pilas(p,q) ? "SI": "NO")<< " son iguales"<<endl;

    cout<<"\t\t\t\tINVERTIR PILA"<<endl;
    Invertir_pila(&p);
    imprimirPila(p);

    cout<<endl;
    return 0;
}

void leerPila(Pila *p ){
    Tipo fin = 9999;            //Valor referente para el fin de lectura 
    Tipo aux;  

    do{
        cout<<"Ingrese un valor a apilar, finalice con "<<fin<<": "; cin >> aux;

        if(aux != fin){                     //no es igual al fin de lectura
            if(!p->Pila_llena()){            //aun no esta llena la pila 
                p->push(aux);
            }
            else {
                cout<<endl<<"Pila esta llena"<<endl;
                aux = fin;
            }
        }
    }
    while (aux != fin);
}

void imprimirPila(Pila p){

    Tipo aux;           //Variable de lectura 
    
    while(!p.Pila_vacia()){
        aux = p.pop();
        cout<<" > "<<aux;

    } 
}

bool Comparar_pilas(Pila p, Pila q){                //El pop no se modifica porque se pasan por valor yno por referencia 
    if(p.tamanio_pila() != q.tamanio_pila()){
        return false;
    }
    else{
        while(!p.Pila_vacia()){
            if(p.pop() != q.pop()){
                return false;
            }
        }
        return true;
    } 
}


void Invertir_pila(Pila *p){

    Tipo vect[EXT];
    int aux = p->get_tope();
    

    for ( int i = 0; i < aux+1; i++){
        vect[i] = p->pop();
    }

    for (int i = 0; i < aux+1 ; i++){
        p->push(vect[i]);
    }
}





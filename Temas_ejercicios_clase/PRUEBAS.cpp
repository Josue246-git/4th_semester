//Lo mismo que pilas 1 pero ahora que se compare cocn n pilas 

#include <iostream>

#include "TDA_pila.h"
typedef int Tipo; 
#define EXT 20


using namespace std;

int main(){
    
    //
        void leerPila(Pila *p );              
        void imprimirPila(Pila p);
        bool Comparar_pilas(Pila p, Pila q);
        bool Todas_pilas_iguales(int n_pilas, Pila pilas[]);


    //
    int n_pilas;

    Pila pilas[EXT];

    cout<<"ingrese la cantidad de pilas que se desea comparar "; cin>>n_pilas;

    //Ingreso objetod pila en el vector 
    for (int n = 0; n < n_pilas; n++){

        Pila p; 
        cout<<endl<<"Ingresar e imprimir los valores en la pila "<<endl;
        leerPila(&p);
        imprimirPila(p);
        pilas[n] = p;

        // cout<<endl<<pilas[i].Cima_pila()<<endl;

        p.limpiar_pila();

        // cout<<endl<<pilas[i].Cima_pila()<<endl;
        // cout<<endl<<n_pilas<<endl;
    }

    cout<<endl<<"\t\t\t\tCOMPARACION ENTRE TODAS LAS "<<n_pilas<<" PILAS INGRESADAS"<<endl;
    cout<<endl<<endl<<"Todas las pilas ingresadas: "<<(Todas_pilas_iguales(n_pilas, pilas) ? "SI": "NO")<< " son iguales"<<endl;


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


bool Todas_pilas_iguales(int n_pilas, Pila pilas[]){
    
    for (int i = 0; i < n_pilas; i++){

        if(i != n_pilas-1){

            cout<<endl<<"Comparacion entre pila "<<i+1<<" y "<<i+2;  

            if(Comparar_pilas(pilas[i], pilas[i+1])== false ){

                cout<<" (Las pilas NO cumplen) "<<endl;  
                return false;
            }
            else cout<<endl<<" (Las pilas SI cumplen) "<<endl;  
        }
    }
    return true;
}


            
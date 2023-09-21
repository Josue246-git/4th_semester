// Ingresar ordenadamente los valores en una cola
//Nombre: JOSUE RODRGUEZ (7272)

//DONE

#include <iostream>
#define EXT 20
#define FIN 9999
#include "TDA_cola_circular.h"
using namespace std;


int main(){

    Cola c;

    
    void leer_cola_ordenada(Cola *c);
    void modificar_cola(Cola *c, Cola men, Cola may, int vl);
    void insertar_val_Dados(Cola *c, Cola men);
    void imprimir_cola(Cola c);
    

    cout<<endl<<"\t\t\tIngrese elementos a la cola "<<endl;
    leer_cola_ordenada(&c);

    cout<<endl<<"\t\t\tLos elementos de la cola son: "<<endl;
    imprimir_cola(c);

    cout << endl;
}

void imprimir_cola(Cola c){
    if(!c.colaVacia()){
        cout << endl << ">  " << c.quitar();
        imprimir_cola(c);
    }
}

void insertar_val_Dados(Cola *c, Cola men){         //fucnion que pasa los valores de una cola a otra 
    
    if(!men.colaVacia()){
        c->insertar(men.quitar());
        insertar_val_Dados(c, men);
    }
}

void modificar_cola(Cola *c, Cola men, Cola may, int vl){          //modifica la cola ordenadnola 

    if(c->frenteCola() >= vl) {          //Primer caso al inicio de todo
        may = *c;
        c->borrarCola();

        insertar_val_Dados(*&c, men);
        c->insertar(vl);
        insertar_val_Dados(*&c, may);
        return;
    }
    else if(c->frenteCola()<vl){
        men.insertar(c->quitar());
    }
    else return;
    modificar_cola(c, men, may, vl);
}

void leer_cola_ordenada(Cola *c){
    Tipo vl;  
    cout<<endl<<"Ingrese un valor a poner en la cola, finalice con "<<FIN<<": "; cin >> vl;

    if(vl != FIN ){ 
        if(!c->colaLlena()){
            if(c->tamanioCola()== 0 || c->finalCola()<=vl) {
                c->insertar(vl);          //primer elemento o insertar al final
                imprimir_cola(*c);
            }else{
                Cola men, may;
                modificar_cola(*&c, men, may, vl);
                imprimir_cola(*c);
            }
            leer_cola_ordenada(c);
        }
        else cout<<endl<<"\t\t\t\tLa cola ya esta llena "<<endl;
    }
}


 



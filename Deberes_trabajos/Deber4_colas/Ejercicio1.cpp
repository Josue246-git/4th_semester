// Eliminar los valores repetidos en una cola previamente ingresada
//ITS DONE
//Nombre: JOSUE RODRGUEZ (7272)

#include <iostream>
#define EXT 20
#define FIN 9999
#include "TDA_cola_circular.h"
using namespace std;

int main(){

    ColaCircular c;

    //
    void leer_cola(ColaCircular *c);
    void imprimir_cola(ColaCircular c1);
    void Eliminar_val_rep(ColaCircular c, ColaCircular *c_a);
    //

    cout<<endl<<"\t\t\tIngrese elementos a la cola "<<endl;
    leer_cola(&c);

    cout<<endl<<"\t\t\tLos elementos de la cola son: "<<endl;
    imprimir_cola(c);

    cout<<endl<<"\t\t\tELIMINAR VALORES REPETIDOS DE LA COLA "<<endl;
    ColaCircular c_a;
    Tipo val = c.quitar();
    c_a.insertar(val);

    Eliminar_val_rep(c, &c_a);

    imprimir_cola(c_a);


    cout << endl;
}

void leer_cola(ColaCircular *c){
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

void imprimir_cola(ColaCircular c1){
    if(!c1.colaVacia()){
        cout << endl << ">  " << c1.quitar();
        imprimir_cola(c1);
    }
}

bool Esta_en_cola(Cola c, Tipo val){
    if(c.colaVacia()){
        return false;
    }
    else{
        if(c.quitar()== val){
            return true;
        }
    }
    return Esta_en_cola(c, val);
}

void Eliminar_val_rep(ColaCircular c, ColaCircular *c_a){
    if(!c.colaVacia()){
        Tipo val = c.quitar();

        if(!Esta_en_cola(*c_a,val)) {
            c_a->insertar(val);
        } 
        
        Eliminar_val_rep(c, c_a);
    }
}


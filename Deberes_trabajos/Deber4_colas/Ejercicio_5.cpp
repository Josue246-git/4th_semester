//Encontrar la unión entre varias TDA colas ingresadas
//Nombre: JOSUE RODRGUEZ (7272)

#include <iostream>
#define EXT 20
#define FIN 9999
#include "TDA_cola_circular.h"
using namespace std;

int main(){

    ColaCircular c_colas;
    //
    void leer_cola(ColaCircular *c);
    void imprimir_cola(ColaCircular c1);
    bool Esta_en_cola(Cola c, Tipo val);
    void union_dos_colas(ColaCircular c1, ColaCircular c2, ColaCircular *c_res);
    void Ingresar_colas(int n , ColaCircular *c_colas, int con=1);
    //
    
    int n=0;
    cout<<"Ingresar el numero de colas a realizar sus uniones: ";cin>>n;

    Ingresar_colas(n, &c_colas);
    cout<<endl<<"\t\t\tUNION DE COLAS "<<endl;
    imprimir_cola(c_colas);
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

void union_dos_colas(ColaCircular c1, ColaCircular c2, ColaCircular *c_res){

    if(!c1.colaVacia()){
        c_res->insertar(c1.quitar());
    }
    else if(!c2.colaVacia()){
        Tipo val = c2.quitar();
        if(!Esta_en_cola(*c_res, val)){
            c_res->insertar(val);
        }
    }
    else return;
    union_dos_colas(c1,c2,c_res);
}

void Ingresar_colas(int n , ColaCircular *c_colas, int con=1){

    if(con <= n){
        ColaCircular aux, aux2;
        cout<<endl<<"Ingrese la cola "<<con<<endl;
        leer_cola(&aux);

        if(con == 1) *c_colas=aux;
        else{
            aux2= *c_colas;
            c_colas->borrarCola();
            union_dos_colas(aux2, aux, *&c_colas);
            cout<<endl;
        }

        Ingresar_colas(n, c_colas, con+1);
    }
}
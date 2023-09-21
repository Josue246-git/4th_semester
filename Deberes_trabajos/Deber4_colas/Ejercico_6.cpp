//Generar una pila ordenada descendentemente con los valores comunes a varias colas ingresadas
//Nombre: JOSUE RODRGUEZ (7272)

#include <iostream>
#define EXT 20
#define FIN 9999
#include "TDA_cola_circular.h"
#include "TDA_pila.h"
using namespace std;


int main(){

    ColaCircular inter_colas;
    //
    void leer_cola(ColaCircular *c);
    void imprimir_cola(ColaCircular c1);

    void inter_dos_colas(ColaCircular c1, ColaCircular c2, ColaCircular *c_res);    //devuelve una cola con la intereseccion de dos colas
    void Ingresar_colas(int n , ColaCircular *inter_colas, int con=1);  //gestiona el ingreso de n colas
    void Ingresar_pila(Pila *p, ColaCircular cola);     //ingresa los elemntos de la cola resultante a una pila 
    void insertarEnOrden(Pila *pila, int elemento);     //ordena los elemento sde la pila 
    void ordenarPila(Pila *p);
    
    void imprimirPila(Pila p);
    //

    int n=0;
    cout<<"Ingresar el numero de colas a realizar el procesp: ";cin>>n;
    
    
    Ingresar_colas(n, &inter_colas);
    cout<<endl<<"\t\t\tINTERSECCION DE COLAS "<<endl;
    imprimir_cola(inter_colas);

    cout<<endl<<"\t\t\t PILA DESCENDENTE "<<endl;
    Pila p;
    Ingresar_pila(&p, inter_colas);
    ordenarPila(&p);
    
    cout<<endl<<"La pila resultante es: "<<endl;
    imprimirPila(p);

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

void imprimirPila(Pila p){

    if(!p.Pila_vacia()){
        cout<<endl<<" > "<<p.pop()<<endl;
        imprimirPila(p);
    }   
}    

bool Esta_en_cola(Cola c, Tipo val){                //funcion que verfica si un elemento esta en la cola 

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

void inter_dos_colas(ColaCircular c1, ColaCircular c2, ColaCircular *c_res){
    
    if(!c1.colaVacia()){
        Tipo val= c1.quitar();
        if(Esta_en_cola(c2, val)){
            c_res->insertar(val);
        }
    }
    
    else return;
    inter_dos_colas(c1,c2,c_res);
}

void Ingresar_colas(int n , ColaCircular *inter_colas, int con=1){

    if(con <= n){
        ColaCircular aux, aux2;
        cout<<endl<<"Ingrese la cola "<<con<<endl;
        leer_cola(&aux);

        if(con == 1) *inter_colas=aux;
        else{
            aux2= *inter_colas;
            inter_colas->borrarCola();

            inter_dos_colas(aux2, aux, *&inter_colas);          //interseccion de dos colas 
            cout<<endl;
        }

        Ingresar_colas(n, inter_colas, con+1);
    }
}


void Ingresar_pila(Pila *p, ColaCircular cola){

    if(!(cola.colaVacia())){
        p->push(cola.quitar());
        Ingresar_pila(p,cola);
    }
}

void insertarEnOrden(Pila *pila, int elemento) {
    if (pila->Pila_vacia() || elemento > pila->Cima_pila()) {
        pila->push(elemento);
    } else {
        int temp = pila->Cima_pila();
        pila->pop();
        insertarEnOrden(pila, elemento);
        pila->push(temp);
    }
}

void ordenarPila(Pila *p) {
    if (!p->Pila_vacia()) {
        int temp = p->Cima_pila();
        p->pop();
        ordenarPila(p);
        insertarEnOrden(*&p, temp);
    }
}


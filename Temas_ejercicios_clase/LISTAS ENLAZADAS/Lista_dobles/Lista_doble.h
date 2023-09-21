//Definicion del TDA lista simplemente enlazada
#ifndef _LISTA_H
#define _LISTA_H
using namespace std;
#include "Nodo.h"

class ListaDoble{
private:
    Nodo* primero;              //atributo que almacena la direecion del primer nodo de la lista
    Nodo* ult;

public:
    ListaDoble();                    //metodo constructor
    void setPrimero(Nodo* v);   //metodo que actualiza el estado el atributo primero 
    Nodo* getPrimero();         //devuelve el estado del atributo
    
    Nodo* getUltimo();             //metodo que devuelve la direccion del ultimo nodo de la lista
    void setUltimo(Nodo* v);

    bool esVacia();             //metodo que comprueba si la lista es vacia
    void vaciarLista();         //elimina todos los nodos de la lista
    void insertarAlInicio(Tipo v); 
    void insertarAlFinal(Tipo v);

};

ListaDoble::ListaDoble(){
    setPrimero(NULL);           //inicializa el comiendo de la lista
}

void ListaDoble::setPrimero(Nodo* v){
    primero = v;                //actualiza el estado del atributo primero
}

Nodo* ListaDoble::getPrimero(){
    return primero;             //retorna el estado del atributo
} 


void ListaDoble::setUltimo(Nodo* v){
    ult = v;
}

Nodo* ListaDoble::getUltimo(){
    return ult;                                 //devuelve direccion de memoria del nodo apuntado
}


bool ListaDoble::esVacia(){
    return (getPrimero() == NULL);
}

void ListaDoble::vaciarLista(){
    setPrimero(NULL);
}


void ListaDoble::insertarAlFinal(Tipo v){
    Nodo* nuevo;                            
    nuevo = new Nodo(v);                    

    if(esVacia()){                        
        setPrimero(nuevo);
        Nodo* prim = getPrimero();
        prim->setPunt(NULL);
        prim->setAnte(NULL);
        setUltimo(prim);
    }
    else{
        Nodo* ult = getUltimo();
        ult->setPunt(nuevo);
        nuevo->setPunt(NULL);
        nuevo->setAnte(getUltimo());
        setUltimo(nuevo);
    }  
}




#endif


//Definicion del TDA lista simplemente enlazada
#ifndef _LISTA_H
#define _LISTA_H
using namespace std;
#include "Nodo.h"

class ListaCircular{
private:
    Nodo* primero;              //atributo que almacena la direecion del primer nodo de la lista
    Nodo* ult;

public:
    ListaCircular();                    //metodo constructor
    void setPrimero(Nodo* v);   //metodo que actualiza el estado el atributo primero 
    Nodo* getPrimero();         //devuelve el estado del atributo
    
    Nodo* getUltimo();             //metodo que devuelve la direccion del ultimo nodo de la lista
    void setUltimo(Nodo* v);

    bool esVacia();             //metodo que comprueba si la lista es vacia
    void vaciarLista();         //elimina todos los nodos de la lista
    void insertarAlInicio(Tipo v); 
    void insertarAlFinal(Tipo v);

};

ListaCircular::ListaCircular(){
    setPrimero(NULL);           //inicializa el comiendo de la lista
}

void ListaCircular::setPrimero(Nodo* v){
    primero = v;                //actualiza el estado del atributo primero
}

Nodo* ListaCircular::getPrimero(){
    return primero;             //retorna el estado del atributo
} 


void ListaCircular::setUltimo(Nodo* v){
    ult = v;
}

Nodo* ListaCircular::getUltimo(){
    return ult;                                 //devuelve direccion de memoria del nodo apuntado
}


bool ListaCircular::esVacia(){
    return (getPrimero() == NULL);
}

void ListaCircular::vaciarLista(){
    setPrimero(NULL);
}


void ListaCircular::insertarAlFinal(Tipo v){
    Nodo* nuevo;                            //apuntador a nuevo nodo a crear
//cout << endl << "Direccion 1 de ult: " << ult;
    nuevo = new Nodo(v);                    //crea un nuevo nodo conociendo el valor que va a contener el nuevo valor en el nodo
    
//cout << endl << "Direccion 2 de ult: " << ult;    

    if(esVacia()){                        
        setPrimero(nuevo);
        Nodo* prim = getPrimero();
        prim->setPunt(prim);
        setUltimo(prim);

    }
    else{
        ult->setPunt(nuevo);
        nuevo->setPunt(getPrimero());
        setUltimo(nuevo);
    }  
}




#endif


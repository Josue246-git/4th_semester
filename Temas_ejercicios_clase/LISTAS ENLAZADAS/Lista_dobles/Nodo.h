//Definiccion de la calse que origna cada elemento de una lista simple 
#ifndef _NODO_H
#define _NODO_H
#include <cstddef>

typedef int Tipo;

class Nodo{                 //Definicion de la clase
private:
    Tipo dato;              //Atributo para contener el valor a almacenar
    Nodo* punt;            //Atributo para apuntar al siguiente nodo
    Nodo* ante;             //Atributo para puntar al nodo anterior

public:                     //Metodos puclicos
    Nodo();                 //constructor
    Nodo(Tipo v);
    Nodo(Tipo v, Nodo* p);
    void setDato(Tipo v);   //metodo para actualizar el estado de v
    Tipo getDato();
    void setPunt(Nodo* v);
    Nodo* getPunt();
    void setAnte(Nodo* v);
    Nodo* getAnte();

};

Nodo::Nodo(){
    setPunt(NULL);
}
Nodo::Nodo(Tipo v){
    setDato(v);
    setAnte(NULL);
    setPunt(NULL);
}  
Nodo::Nodo(Tipo v, Nodo* p){
    setDato(v);
    setPunt(p);
}

void Nodo::setDato(Tipo v){
    dato = v;
}
Tipo Nodo::getDato(){
    return dato;
}

void Nodo::setPunt(Nodo* v){
    punt = v;
}
Nodo* Nodo::getPunt(){
    return punt;  
}

void Nodo::setAnte(Nodo* v){
    ante = v;
}
Nodo* Nodo::getAnte(){
    return ante;  
}

#endif
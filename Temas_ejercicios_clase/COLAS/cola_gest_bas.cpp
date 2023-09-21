                                            //COLA GESTION BASICA 
//Nombre: jOSUE rODRGUEZ

#include <iostream>
#define EXT 20
#include "TDA_cola.h"

using namespace std;

int main(){

    Cola c;

    cout<<endl<<"El tda cola contiene el valor: "<<c.get_final()<<endl;
    cout<<endl<<"El tda cola contiene el valor: "<<c.get_frente()<<endl;
    
    cout<<endl<<"El TDA cola "<<(c.Cola_vacia() ? "Si" : "No")<<" esta vacia"<<endl;
    cout<<endl<<"El TDA cola "<<(c.Cola_llena() ? "Si" : "No")<<" esta llena"<<endl;
    cout<<endl<<"El TDA cola continene: "<<c.Tamanio_cola()<<" ELEMENTOS "<<endl;

    c.Insertar(100);
    c.Insertar(200);

    cout<<endl<<"El TDA cola "<<(c.Cola_vacia() ? "Si" : "No")<<" esta vacia"<<endl;
    cout<<endl<<"El TDA cola "<<(c.Cola_llena() ? "Si" : "No")<<" esta llena"<<endl;

    cout<<endl<<"El TDA cola continene: "<<c.Tamanio_cola()<<" ELEMENTOS "<<endl;

    cout<<endl<<" El valor contenido enla pos frente es: "<<c.Frente_cola()<<endl;
    c.Quitar();

    cout<<endl<<"El TDA cola "<<(c.Cola_vacia() ? "Si" : "No")<<" esta vacia"<<endl;
    cout<<endl<<"El TDA cola "<<(c.Cola_llena() ? "Si" : "No")<<" esta llena"<<endl;

    cout<<endl<<"El TDA cola continene: "<<c.Tamanio_cola()<<" ELEMENTOS "<<endl;

    c.Quitar();

    cout<<endl<<"El TDA cola "<<(c.Cola_vacia() ? "Si" : "No")<<" esta vacia"<<endl;
    cout<<endl<<"El TDA cola "<<(c.Cola_llena() ? "Si" : "No")<<" esta llena"<<endl;

    cout<<endl<<"El TDA cola continene: "<<c.Tamanio_cola()<<" ELEMENTOS "<<endl;


    cout<<endl;
}



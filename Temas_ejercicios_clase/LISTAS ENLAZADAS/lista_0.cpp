//Gestion basica de Nodo 

#include <iostream>

using namespace std;

#include "Nodo.h"

int main(){
    
    Nodo n;                          //
    Nodo n1 (105);                    //Conociendo el valor almacenado 
    Nodo n2 (103, &n1) ;              //Conociendo el vcaor y una direccion siguiente 
    
    n.set_dato(54);

    cout<<"El valor del nodo uno es: "<<n.get_dato()<<endl;
    cout<<"El valor que apunto es: : "<<n.get_punt()<<endl;             //porque el sigiuente es NULL o cero

    cout<<"El valor del nodo dos es: "<<n1.get_dato()<<endl;
    cout<<"El valor que apunto es: : "<<n1.get_punt()<<endl;             //porque el sigiuente es NULL o cero

    cout<<"El valor del nodo tres es: "<<n2.get_dato()<<endl;
    cout<<"El valor que apunto es: : "<<n2.get_punt()<<endl;             //porque el sigiuente es NULL o cero

    n1.set_punt(&n);

    Nodo* aux = &n2;              //Para recorrer la list, solo con nodos, va a apuntar al comienzo de la lista

    //RECORRIDO DE LOS NODOS 
    cout<<endl<<" valor de n2: "<<aux->get_dato()<<endl;
    aux = n2.get_punt(); 
    cout<<endl<<" valor de n1: "<<aux->get_dato()<<endl;
    aux = n1.get_punt();
    cout<<endl<<" valor de n: "<<aux->get_dato()<<endl;
    //RECORRIDO DE NODOS CON CICLO 
    
    // while (aux == NULL){
        
    //     cout<<endl<<" valor "<<aux->get_dato()<<endl;
    //     aux = n2.get_punt();

    // }
    

    cout<<endl;
    return 0;
}
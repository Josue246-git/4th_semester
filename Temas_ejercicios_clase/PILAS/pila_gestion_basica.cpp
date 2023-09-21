                                            //PILA GESTION BASICA 
//Nombre: jOSUE rODRGUEZ

#include <iostream>
#include "TDA_pila.h"

using namespace std;

int main(){
    

    Pila p;                                                   //Declarracion de lun objeto de tipo pila 

    cout<<endl<<"El valor del atributo top es: "<<p.get_tope()<<endl;
    cout<<endl<<"La pila "<< (p.Pila_llena() ? "SI": "NO")<<" llena" <<endl;
    cout<<endl<<"La pila "<< (p.Pila_vacia() ? "SI": "NO") <<" vacia "<<endl;
    
    p.push(15);

    cout<<endl<<"La pila "<< (p.Pila_llena() ? "SI": "NO")<<" llena" <<endl;
    cout<<endl<<"La pila "<< (p.Pila_vacia() ? "SI": "NO") <<" vacia "<<endl;
    
    cout<<"El valot del top es: "<<p.pop();

    cout<<endl<<"La pila "<< (p.Pila_llena() ? "SI": "NO")<<" llena" <<endl;
    cout<<endl<<"La pila "<< (p.Pila_vacia() ? "SI": "NO") <<" vacia "<<endl;
    
    cout<<"El valot del top es: "<<p.pop();

    cout<<endl<<"La pila "<< (p.Pila_llena() ? "SI": "NO")<<" llena" <<endl;
    cout<<endl<<"La pila "<< (p.Pila_vacia() ? "SI": "NO") <<" vacia "<<endl;
    return 0;


}



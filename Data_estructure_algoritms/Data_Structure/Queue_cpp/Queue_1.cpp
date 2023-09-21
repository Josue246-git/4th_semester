//FIFO
//Lo mismo pero añadiendo una menu con las funcionalidades de añadir, quitar y mostrar

#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

bool cola_vacia(Nodo *frente){
    return(frente == NULL)? true : false;
}


void agregar_a_Cola(Nodo *&frente, Nodo *&fin, int n){

    Nodo *nuevo_nodo = new Nodo(); 
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = NULL;

    if(cola_vacia(frente)) frente = nuevo_nodo;
    else fin-> siguiente = nuevo_nodo; 

    fin = nuevo_nodo;

    cout<<"Elemento "<< n <<" anadido"<<endl;
};

void quitar_de_cola(Nodo *&frente, Nodo *&fin, int &n){
    
    n = frente -> dato;
    Nodo *aux = frente;

    if(frente == fin ) {
        frente = NULL;
        fin = NULL;
    }
    else{
        frente = frente-> siguiente;
    }
    delete aux;
}

void ver_elementos_cola(Nodo *frente){

    if(frente == NULL) cout <<"La cola esta vacia"<<endl;
    else{
        while(frente != NULL ){
            if( frente != NULL ) cout<<frente->dato<<" , ";
            else cout<<frente->dato<<" . ";
            frente = frente -> siguiente;
        }
    }
}


void menu(){
        cout<<"\t MENU"<<endl;
        cout<<"1. Para agregar elementos"<<endl;
        cout<<"2. Para eliminar elementos"<<endl;
        cout<<"3. Para ver elementos"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Ingresa un numero correspondiente "<<endl;
}


int main(){ 

    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato=0;
    int opc=0, conta =0;

    do{
        do{
            system("cls");
            menu();
            cin >> opc;
        }while(opc>4 || opc <=0);
        
        switch (opc){
            case 1:
                cout<<"\t\t\t INGRESAR ELEMENTOS A LA COLA"<<endl;
                cout<<"Ingrese un elemento de la cola: "; cin>>dato;
                agregar_a_Cola(frente, fin, dato);
                break;

            case 2:
                cout<<"\t\t\t ELIMINAR ELEMENTOS A LA COLA"<<endl;
                quitar_de_cola(frente, fin , dato);
                cout<<dato<<" Eliminado"<<endl;
                break;

            case 3:
                cout<<"\t\t\t VER ELEMENTOS DE LA COLA"<<endl;
                ver_elementos_cola(frente);
                system("pause");
                break;
        }
    }while(opc!= 4 );
   
    return 0;
}


 
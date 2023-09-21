//
//NOMBRE: JOSUE RODRIGUEZ 7272

#include <iostream>
using namespace std;
#include "TDA_lista.h"


#define FIN 9999 


int main(){

    Lista l1;                           
    //
    void ingresarLista(Lista* l);        
    void imprimirLista(Nodo* act);
    int contarNodo(Nodo* act);
    int control_n(int tam);
    void Dividir_lista(Nodo* l1, int n, int tam, Lista *aux1, Lista *aux2, int con=1);
    void Ordenar_lista(Lista *l1, Nodo* aux1, Nodo* aux2, int n, int tam , int con= 1);

    //

    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());


    int tam = contarNodo(l1.getPrimero());
    int n = control_n(tam);

    Lista aux1, aux2;

    Dividir_lista(l1.getPrimero(), n, tam, &aux1, &aux2);               //divide la lista en los menores al numero y mayores 
    // cout<<endl;
    // imprimirLista(aux1.getPrimero());

    // cout<<endl;
    // imprimirLista(aux2.getPrimero());

    cout<<endl<<"La lista resultante es:"<<endl;
    l1.vaciarLista();

    Ordenar_lista(&l1, aux1.getPrimero(), aux2.getPrimero(), n, tam);
    imprimirLista(l1.getPrimero());


    cout << endl;
}


void imprimirLista(Nodo* act){
    if(act != NULL){
        cout <<  "> " << act -> getDato() << endl;
        act = act -> getPunt();
        imprimirLista(act);
    }
}

void ingresarLista(Lista* l){
    Tipo aux;           //variable de lectura
    
    cout << endl << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    if(aux != FIN){
        //l->insertarAlInicio(aux);        //se ingresa elemento a la lista
        l->insertarAlFinal(aux);
        // l->insertarEnOrdenDesc(aux);
        ingresarLista(l);
    }
}


int contarNodo(Nodo* act){
    if(act != NULL){
        return 1 + contarNodo(act->getPunt());
    }
    return 0;                       //devuelvto por el ultimo llamado al a func recursiva 
}

int control_n(int tam){

    int n;
    cout<<endl<<"INNGRESE LA POS EN DONDE SE REQUIERA HACER EL PROCESO, debe ser menor a  "<<tam<<"(que es el numero de nodos): "; cin>>n;
    if(n<= 0 || n >tam) control_n(tam);
    else return n;
}

void Dividir_lista(Nodo* l1, int n, int tam, Lista *aux1, Lista *aux2, int con=1){

    if(con <= tam){
        if(con<= (tam-n)){
            aux1->insertarAlFinal(l1->getDato());
        }
        else{
            aux2->insertarAlFinal(l1->getDato());
        }

        Dividir_lista(l1->getPunt(), n, tam, aux1, aux2, con+1);
    }

}


void Ordenar_lista(Lista *l1, Nodo* aux1, Nodo* aux2, int n, int tam , int con= 1){

    if(con <= tam){
        // cout<<endl<<con<<endl;
        if(con<=n){
            l1->insertarAlFinal(aux2->getDato());
            aux2 = aux2->getPunt();
        }
        else{
            l1->insertarAlFinal(aux1->getDato());
            aux1= aux1->getPunt();
        }

        Ordenar_lista(l1, aux1, aux2 ,n, tam , con+1);
    }
}







//

#include <iostream>
using namespace std;
#include "TDA_lista.h"
#include "TDA_pila.h"
#define FIN 9999      

int contarNodo(Nodo* act){
    if(act != NULL){
        return 1 + contarNodo(act->getPunt());
    }
    return 0;                       //devuelvto por el ultimo llamado al a func recursiva 
}

void ingresarLista(Lista* l){
    Tipo aux;           //variable de lectura
    
    cout << endl << "Ingrese un valor a la lista. Finalice con [" << FIN << "]: ";
    cin >> aux;

    if(aux != FIN){
        //l->insertarAlInicio(aux);        //se ingresa elemento a la lista
        l->insertarAlFinal(aux);
        ingresarLista(l);
    }
}

void imprimirLista(Nodo* act){
    if(act != NULL){
        cout <<  "> " << act -> getDato() << endl;
        act = act -> getPunt();
        imprimirLista(act);
    }
}


void Ordenar_tres_asc(Lista l, int tam, int inicio, Nodo* l_prim, Lista *aux, int con=1 ){

    if(con<= tam){
        if(con >= inicio &&  con <= inicio+2){
            aux->insertarEnOrdenAsc(l_prim->getDato());
        }

        l_prim= l_prim->getPunt();
        Ordenar_tres_asc(l, tam, inicio, l_prim,aux, con+1);
    }   
}

void Ordenar_tres_desc(Lista l, int tam, int inicio, Nodo* l_prim, Lista *aux, int con=1 ){
    cout<<endl<<"inicio desc "<<inicio<<endl;
    if(con<= tam){
        if(con >= inicio &&  con <= inicio+2){
            aux->insertarEnOrdenDesc(l_prim->getDato());
        }
        l_prim= l_prim->getPunt();
        Ordenar_tres_desc(l, tam, inicio, l_prim, aux, con+1);
    }   
}

void Ingresar_val_ordenados(Lista *l, int tam, int inicio, Nodo* l_prim, Nodo* aux, Nodo* l2, int con=1){
    
    if(con<= tam){
        if(con >= inicio &&  con <= inicio+2){
            l->insertarAlFinal(aux->getDato());
            aux= aux->getPunt();
        }
        else l->insertarAlFinal(l2->getDato());
        l2= l2->getPunt();
        Ingresar_val_ordenados(l, tam, inicio, l_prim, aux, l2 , con+1);
    }   
}

void Ordenar_lista_general(Lista *l, int tam, int con=1, int ban = 0){
    Lista aux, aux2;
    if(con < tam ){
        if(con%3 == 0 || con == 1){
            
            if(ban==0){
                if(con == 1) Ordenar_tres_asc(*l, tam, con, l->getPrimero(), &aux);
                else Ordenar_tres_asc(*l, tam, con+1, l->getPrimero(), &aux);   //sacar los tres elementos y ordenarlos 
                
                cout<<endl;
                imprimirLista(aux.getPrimero());
                cout<<endl;

                aux2 = *l;
                l->vaciarLista();
                Ingresar_val_ordenados(&*l, tam, con, l->getPrimero(), aux.getPrimero(), aux2.getPrimero());  //ingreso a la lista orignal los nuevos
                
                cout<<endl;
                imprimirLista(l->getPrimero());
                cout<<endl;

                ban=1;
            }
            else if(ban==1){
                Ordenar_tres_desc(*l,tam, con+1, l->getPrimero(), &aux);
                cout<<endl;
                imprimirLista(aux.getPrimero());
                cout<<endl;

                aux2 = *l;
                l->vaciarLista();
                Ingresar_val_ordenados(&*l, tam, con+1, l->getPrimero(), aux.getPrimero(), aux2.getPrimero());
                
                cout<<endl;
                imprimirLista(l->getPrimero());
                cout<<endl;
                ban=0;
            }
        }
        if(tam%3 != 0 ){

        }

        Ordenar_lista_general(l, tam, con+1, ban);
    }
}


int main(){

    Lista l1, l2, l3;                           
    //
    void ingresarLista(Lista* l);        
    void imprimirLista(Nodo* act);
    
    //

    cout << endl << "INGRESAR ELEMENTOS A LA LISTA 1" <<endl;
    ingresarLista(&l1);

    cout << endl << "LOS ELEMENTOS DE LA LISTA 1 SON: " <<endl;
    imprimirLista(l1.getPrimero());

    cout<<endl<<"LA lista ordenada asc y dsc es: "<<endl;
    int tam = contarNodo(l1.getPrimero()); 

    Ordenar_lista_general(&l1, tam);

    imprimirLista(l1.getPrimero());

    cout << endl;
}



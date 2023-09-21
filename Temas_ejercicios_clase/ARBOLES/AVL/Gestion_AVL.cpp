//Implementacion de un ABB 

using namespace std;
#include <iostream>
#include "TDA_AVL.h"
#define fin 9999


int main(){					

	AVLTree avl;
    //
    void leerAVL(AVLTree *avl);
    bool buscar_en_AVL(AVLTree avl);
    //

    cout << "INGRESAR LOS NODOS DEL AVL:" << endl;
    leerAVL(&avl);

    cout << "Elementos en orden ascendente:" << endl;
    avl.imprimir_avl();


    int nodoEliminar;
    cout << "Ingrese el valor del nodo a eliminar: ";
    cin >> nodoEliminar;
    avl.eliminar(nodoEliminar);


    cout << "Elementos en orden ascendente después de eliminar el nodo " << nodoEliminar << ":" << endl;
    avl.imprimir_avl();


    cout << "BUSCAR ELEMENTO EN EL AVL:" << endl;

    cout<<endl<<"El valor "<<(buscar_en_AVL(avl)?" SI ": " NO ")<<" esta en el arbol "<<endl ;

    return 0;
    cout<<endl;
}


void leerAVL(AVLTree *avl){

    Tipo aux; 
    cout<<endl<<" Ingrese un valor a incluir en el AVL, finalice con [ "<<fin<<" ]: "; cin>>aux;
    if(aux != fin){
        avl->insertar(aux);
        leerAVL(avl);
    }
    return;	
}


bool buscar_en_AVL(AVLTree avl){
    Tipo aux;
    cout<<endl<<"Ingrese un dato a buscar en el ABB: ";cin>>aux;
    if(avl.buscarNodo(aux) == NULL) return false;
    else return true;
}


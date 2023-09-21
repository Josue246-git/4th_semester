#include <iostream>
#include <math.h>

typedef int Tipo; 
using namespace std;


void recorrido_heap_niveles(int* heap){
    int nivel;
    cout<<"Ingrese el nivel que desa ver "; cin>>nivel;


    for (int i =pow(2, nivel)-1 ; i < nivel+; i++){
        cout<<heap[i]<<" ";
    }

}

void recorrrido_preorden(int* heap, int i, int n ){

    if ((i >= n)) return;
    

    int val_raiz = heap[i];
    int izq = 2 * i + 1;
    int der = 2 * i + 2;

    cout << val_raiz << " "; // Imprimir el valor del nodo actual en preorden

    recorrrido_preorden(heap, izq, n); // Recorrido en preorden del subárbol izquierdo
    recorrrido_preorden(heap, der, n); 
}


int main(){

    int heap[8];

    for (int i = 0; i < 8; i++){
        cout<<"Ingrese el valor del heap en la posicion "<<i<<" "; cin>>heap[i];
    }
    
    // recorrido_heap_niveles(heap);

    recorrrido_preorden(heap, 0, 8);

    return 0;
}




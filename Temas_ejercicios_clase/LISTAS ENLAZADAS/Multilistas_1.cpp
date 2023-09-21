//implemente un porrama que perimta el ilngrewso de vartios numeros y 


#include <iostream>
using namespace std;
#include "TDA_lista.h"

#define FIN 9999
#define EXT 9    // extension maxima de los vectores      

int main(){

    //
    void Ingresar_nums(int nums[], int *n1, int aux= 0);       
    void ImprimirNumeros(int nums[], int n1, Lista lis[], int i=0 );
    void GenerarListas(int nums[] , Lista lis[], int n1, int i=0);
    //

    int nums[EXT];              //definicnio de vector ede numeros
    Lista listas[EXT];            //definicnion de vector e de listas de digitos 
    int n=0;                          // la cantidad de nuemros a ahcer el proceso
    Ingresar_nums(nums, &n);

    cout<<endl<<"El tamaño de vector de numeros es: "<<n<<endl;
    cout<<endl<<"VALORES PROCESADOS"<<endl;
    GenerarListas(nums, listas, n);
    ImprimirNumeros(nums, n, listas);

    cout << endl;
}



void Ingresar_nums(int nums[], int *n1, int aux = 0){

    if((aux != FIN) && (*n1 < EXT )){

        cout<<endl<<"Ingrese un numero entero, finalizae con "<<FIN<<" : "; cin>>aux;

        if((aux != FIN) && (*n1 < EXT )){       
            nums[*n1] = aux;
            (*n1)++;    
        }        
        Ingresar_nums(nums, n1, aux);
    }

}       

void Imprimir_digitos(Nodo* act){

    if(act != NULL){
        cout<<endl<<"\t > "<<act->getDato();
        act= act->getPunt();
        Imprimir_digitos(act);
    }
}

void ImprimirNumeros(int nums[], int n1, Lista lis[], int i= 0){

    if(i < n1){

        cout<<endl<<" > "<<nums[i]<<endl;
        Nodo* act;             
        act = lis[i].getPrimero();

        Imprimir_digitos(act);

        ImprimirNumeros(nums, n1, lis, i+1);
    }
}


void Esta_ele_lista(Nodo* act, Nodo* nuevo, bool *ban){

    if(act != NULL ) {
        if(act->getDato() == nuevo->getDato()){
            *ban= true;
        }

        Esta_ele_lista(act->getPunt(), nuevo, ban);
    }
}

void InsertarSinRep(int v, Lista *l){
    Nodo* nuevo;                            //apuntador a nuevo nodo a crear
    Nodo* act;   
    bool ban = false;

    nuevo = new Nodo(v);

    if(l->esVacia()){
        l->setPrimero(nuevo);
    }else{
        act = l->getPrimero();   

        Esta_ele_lista(act, nuevo, &ban);

        if(ban == false){
            l->insertarAlInicio(nuevo->getDato());
        }
    }
}

void Insertar_dig_listas(int aux, Lista *lis){
    
    if(aux!=0){
        lis->insertarAlFinal(aux);
        aux= aux/10;
        Insertar_dig_listas(aux, lis);
    }
}

void GenerarListas(int nums[] , Lista lis[], int n1, int i = 0){
    int aux;                

    if(i< n1){
        aux = nums[i];
        Insertar_dig_listas(aux, &lis[i]);
        GenerarListas(nums, lis, n1, i+1);
    }
}


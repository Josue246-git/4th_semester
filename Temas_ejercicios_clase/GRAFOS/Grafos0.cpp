//Implementar gestion basicas de vertices

using namespace std;
#include <iostream>
#include "Vertice.h"
#include "Global_functions.h"
#define fin 9999


int main(){
    //
    void leer_vertices(Vertice vv[], int tam, int i=0);
    void Imprimir_vertices(Vertice vv[], int tam, int i=0);
    void Buscar_ver_valor(Vertice vv[], int tam);
    void Buscar_ver_num(Vertice vv[], int tam);
    //
    int n;
    Vertice* vec_ver;	                //apuntador a objetos de tipo vertice, o vector de vertices 				

    cout<<endl<<"CANTIDAD DE VERTICES A PROCESAR"<<endl; 
    n = Leer_N();

    vec_ver = new Vertice[n];                   //creacion de objetos de tipo vertice, se hace esto para mejorar la optizacion del vector, en vez de ponerle un tamaño a mi gusto
    
    cout<<endl<<"INGRESE LOS VERTICES "<<endl; 
    leer_vertices(vec_ver, n);

    cout<<endl<<"IMPRIMIR LOS VERTICES "<<endl; 
    Imprimir_vertices(vec_ver, n);

    cout<<endl<<"BUSQUEDA EN EL VECTOR"<<endl; 
    Buscar_ver_valor(vec_ver,n);

	cout<<endl;
}


void leer_vertices(Vertice vv[], int tam, int i=0){
    Tipo aux ; 
    if(i < tam){
        cout<<endl<<"ingrese un valor al vertice "<<i<<" :";cin>>aux;
        vv[i].setDato(aux);
        vv[i].setNum(i);
        leer_vertices(vv, tam, i+1);
    }
}

void Imprimir_vertices(Vertice vv[], int tam, int i=0){
    if(i < tam){
        cout<<endl<<"Valor almacenado en el vertice: "<<vv[i].getNum()<<" es: "<<vv[i].getDato()<<endl;
        Imprimir_vertices(vv, tam, i+1);
    }
}

void Buscar_ver_valor(Vertice vv[], int tam){
    int n;
    Tipo aux;
    bool ban ;

    cout<<endl<<"Cantidad de busqueda por dato:"; n=Leer_N();

    for (int i = 0; i < n; i++){
        cout<<endl<<"Ingrese el valor da buscar: ";cin>>aux;
        ban=false;
        for (int j = 0; j < tam; j++){
            if(vv[j].esIgualDato(aux)){
                ban=true;
            }
        }
        cout<<endl<<"El valor "<<aux<<(ban ? " SI": " NO")<<" existe en el vector "<<endl;
    }
}

void Buscar_ver_num(Vertice vv[], int tam){

}
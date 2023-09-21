//programa que perimita ingresar n cadenas 

using namespace std;

#include <iostream>
#include <string.h>
#include "utilidades.h"

#define DATOS 1000
#define EXT 30
#define FIN '.'  


//void Ingresar_datos(char datos[][EXT], int n){

//    for (int i = 0; i < n; i++){
//        cout<<"INGRESE el dato: "<<i<<" debe tener max. "<<EXT<<" caracteres: ";
//        cin.getline(datos[i],EXT, '.');
//    }

//}

void Ingresar_datos(char datos[][EXT], int *n){
    char aux[EXT]; 

    do{
        cout<<"INGRESE el dato: "<<*n<<" debe tener max. "<<EXT<<" caracteres, ingrese (.) si desea detminar: ";
        cin.getline(aux,EXT, '.');
        cin.ignore();

        if(strlen(aux) >0 ){
            strcpy(datos[*n],aux);
            (*n)++;
        }
    } 
    while((strlen(aux) > 0));
}


int transformarClave(char datos[]){
    int ac = 0;

    for (int i = 0; i < strlen(datos); i++){
        ac += int(datos[i]);
    }
    return ac;  
}

int dispersion_modular(int v){
    return (v % DATOS);
}


void imprimir_claves(char datos[][EXT], int n1){

    int nClave=0;
    cout<<endl<<"Claves ingreadas"<<endl;

    for (int i = 0; i < n1; i++){
        cout<<endl<<">"<<datos[i];

        nClave = transformarClave(datos[i]);

        cout<<endl<<"\t CLAVE NUMERICA: "<<nClave;
        cout<<endl<<"\t CLAVE DISPERSION: "<<dispersion_modular(nClave);
    }
     
}



void imprimir_datos(char datos[][EXT], int n){
    for (int i = 0; i < n; i++){
        cout<<"Dato: "<<i<<" "<<datos[i]<<endl;
    }
}

int dispersion_plegamiento(int v){
    int ac = 0;

    do{
        ac += v % 1000;
        v = v / 1000;
    } while (v != 0);

    return (ac%1000);
}

int main(){

	//Prototypes

	//
    int n=0;
    // cout<<"Ingrese el numero de datos a poner en el hasing "; 
    // n = leerN(1,EXT);

    char datos[DATOS][EXT];  

    Ingresar_datos(datos, &n);
    //imprimir_datos(datos, n);

    imprimir_claves(datos, n);
    cout<<endl;
}

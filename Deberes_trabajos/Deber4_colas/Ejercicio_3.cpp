// Permitir el ingreso de una cadena de caracteres y ordenar los caracteres de cada palabra encontrada
//Nombre: JOSUE RODRGUEZ (7272)
//NOTA: CAMBIAR EN TDA_cola.h de tipo int a tipo char

#include <iostream>
#include <string.h>
#define EXT 20
#define FIN 9999
#include "TDA_cola_circular.h"
using namespace std;

#include "Global_functions.h"



int main(){

    Cola c;
    //
    void leer_cola(ColaCircular *c);
    void imprimir_cola(Cola c1);
    void insertar_val_Dados(Cola *c, Cola men);
    void modificar_cola(Cola *c, Cola men, Cola may, int vl);
    void Encontrar_palabra(char cadena[],Cola pal, int i = 0);
    //

    char cadena[EXT];
    cout<<endl<<"Ingresar la cadena de caracteres a hacer el eproceso: "<<endl;
    cin.getline(cadena, EXT, '.');
    
    Pasar_frase_min(cadena);                                //pasa la frase a minusculas 

    Encontrar_palabra(cadena, c);

    cout << endl;
}



void leer_cola(ColaCircular *c){
    Tipo vl;  
    cout<<"Ingrese un valor a poner en la cola, finalice con "<<FIN<<": "; cin >> vl;

    if(vl != FIN ){
        if(!c->colaLlena()){
            c->insertar(vl);
            leer_cola(c);
        }
        else cout<<endl<<"\t\t\t\tLa cola ya esta llena "<<endl;
    }
}


void imprimir_cola(Cola c1){
    if(!c1.colaVacia()){
        cout << endl << ">  " << c1.quitar();
        imprimir_cola(c1);
    }
}

void insertar_val_Dados(Cola *c, Cola men){         //fucnion que pasa los valores de una cola a otra 
    
    if(!men.colaVacia()){
        c->insertar(men.quitar());
        insertar_val_Dados(c, men);
    }
}

void modificar_cola(Cola *c, Cola men, Cola may, int vl){

    if(c->frenteCola() >= vl) {          //Primer caso al inicio de todo
        may = *c;
        c->borrarCola();

        insertar_val_Dados(*&c, men);
        c->insertar(vl);
        insertar_val_Dados(*&c, may);
        return;
    }
    else if(c->frenteCola()<vl){
        men.insertar(c->quitar());
    }
    else return;
    modificar_cola(c, men, may, vl);
}

void Encontrar_palabra(char cadena[],Cola pal, int i = 0){

    if(i <= strlen(cadena)){

        if(((cadena[i]>='a') && cadena[i] <= 'z')){
            
            if(pal.tamanioCola()== 0 || pal.finalCola() <=cadena[i]) {
                pal.insertar(cadena[i]);

            }else{
                Cola men, may;
                modificar_cola(&pal, men, may, cadena[i]);
            }
        }
        else if((cadena[i-1]>='a') && (cadena[i-1] <= 'z')){            
            cout<<endl<<"La cola es: "<<endl;
            imprimir_cola(pal);
            pal.borrarCola();
        }
        Encontrar_palabra(cadena, pal, i+1);
    }
}
//TODO CON RECURSIVIDAD

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#include <string.h>

#define EXT 30

using namespace std;
#include "Global_functions.h"

int main(){

	//Prototypes

    void Comprobar_frase_palin(char f[], char f2[][EXT], int num_pal, int i = 0);
    void Pasar_a_palabras_recur(char frase[], char palabras[][EXT], int *num_pal, int i = 0, int j=0, int k=0);
	//

    char f[EXT];    
    char f2[(EXT/2)][EXT];
    int num_pala=0;

    cout<<"INGRESE una frase"<<endl;

    cin.getline(f, 30, '.');

    Pasar_frase_min(f);
    cout<<"La frase es: "<<f<<endl;


    cout<<endl<<"\t\t VERIFICAR SI LAS PALABRAS DE LA FRASE SON PALINDROMOS "<<endl;
    
    Pasar_a_palabras_recur(f, f2, &num_pala);


    Comprobar_frase_palin(f, f2, num_pala+1);
    
}

void Pasar_a_palabras_recur(char frase[], char palabras[][EXT], int *num_pal, int i = 0, int j=0, int k=0){

    if((frase[i] >= 'A') && (frase[i] <= 'Z') || ((frase[i]>='a') && frase[i] <= 'z')){
        palabras[j][k] = frase[i];
        k++;
    }
    else if((frase[i-1] >= 'A') && (frase[i-1] <= 'Z') || ((frase[i-1]>='a') && frase[i-1] <= 'z')){
        palabras[j][k] = '\0';  //el back eslah 0 es un fin de cadena
        j++;
        k=0;
    }

    if(i == (strlen(frase)-1)){
        palabras[j][k] = '\0';  
        *num_pal = j;
        return;
    }

    Pasar_a_palabras_recur(frase, palabras, num_pal, i+1, j,k);
}


void Comprobar_frase_palin(char f[], char f2[][EXT], int num_pal, int i = 0){
    //
    bool Comprobar_pal_palin(char palabra[], int j, int i=0);
    //

    if(num_pal != 0){
        cout<<endl<<" "<< f2[i]<<", ES PALINDROMO?"<<endl;
        cout<<" Esta cadena "<< (Comprobar_pal_palin(f2[i], strlen(f2[i])-1) ? "SI" : "NO" )<<" es un palindromo "<<endl;
        Comprobar_frase_palin(f, f2, num_pal-1, i+1);
    }  
}


bool Comprobar_pal_palin(char palabra[], int j, int i=0){

    if(i >= j){
        return true;
    }
    if(palabra[i] != palabra[j]){
        return false;
    }

    Comprobar_pal_palin( palabra,j-1, i+1);
}



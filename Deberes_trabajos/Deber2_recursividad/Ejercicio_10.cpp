// 10. Determinar las letras más repetidas encontradas en una cadena ingresada (evitar repeticiones)

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#include <cmath>
#include <string.h>

#define EXT 30

using namespace std;
#include "Global_functions.h"

int main(){

	//Prototypes
    void a_min(char f[], int size);
    void Calular_rep_letras(char f[], int num_rep[], int size = 0);
    int Num_max_rep(char f[], int num_rep[], int size = 0, int max =0);
    void Letra_mas_rep(int num_rep[],int max, int i =0);
	// 

    char cadena[EXT]; 

    cout<<"INGRESE una frase con "<<endl;
    cin.getline(cadena, EXT, '.');

    a_min(cadena, strlen(cadena));                  //A minuculas la frase 
    cout<<endl<<"La cadena ingresada es: "<<cadena<<endl;

    cout<<endl<<"\t\t\tLOS TERMINOS QUE SE REPITEN EN LA CADENA SON: "<<endl;

    int rep[26]={0};


    Calular_rep_letras(cadena, rep, strlen(cadena));

    int max = Num_max_rep(cadena,  rep);

    Letra_mas_rep(rep, max);

}

void a_min(char f[], int size){
    
    if(size >= 0){
        f[size] = tolower(f[size]);
        a_min(f, --size);
    }
}

void Calular_rep_letras(char f[], int num_rep[], int size ){

    if(f[size] >= 'a' && f[size]<='z') {
        num_rep[f[size] - 'a'] = num_rep[f[size] - 'a'] +1 ;
    }

    if(size == 0) return ;

    Calular_rep_letras(f, num_rep,--size);
}

int Num_max_rep(char f[], int num_rep[], int size = 0, int max =0){
    
    if(size == 26){
        return max;
    }

    if(num_rep[size] > max){
        max = num_rep[size];
    }

    Num_max_rep(f, num_rep, ++size, max);
}

void Letra_mas_rep(int num_rep[],int max, int i =0){

    if(i < 26 ){

        if(num_rep[i] == max) {
            cout<<endl<< static_cast<char>('a' + i) <<" "<< num_rep[i] << " veces" <<endl;
            i=25;
        }
    }

    Letra_mas_rep(num_rep, max, ++i);

}


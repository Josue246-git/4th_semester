
// 1. Calcular el Factorial de cada número ingresado

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#include <string.h>

#define EXT 30

using namespace std;
#include "Global_functions.h"

int main(){

	//Prototypes

    void Ingresar_num(int cant_num); 
    int Factorial_recur(int num, int res);
	//

    int cant_num=0;

    cout<<" Ingresa el numero de valores a sacar su respectivo factorail "; cant_num = Leer_N();
    Ingresar_num(cant_num);

}

void Ingresar_num(int cant_num){
    //
    int Factorial_recur(int num, int res=1);
    //
    int num=0; 
    
    if(cant_num > 0){
        cout<<" INGRESAR UN NUMERO PARA SACAR SU FACTORIAL "; num = Leer_N();
        cout<<" \t\t\t CALCULAR EL FACTORIAL DE: "<< num <<endl;
        cout<<" Es: "<<Factorial_recur(num)<<endl;
        Ingresar_num(--cant_num);
    }
    
}

int Factorial_recur(int num, int res=1){

    if(num == 1 || num == 0 ){
        return res;
    }
    else{
        return Factorial_recur(num-1, res *= num);
    }
}

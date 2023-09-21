// 7. Imprimir solamente el N-ésimo dígito fraccionario de cada numero real (posee parte entera y 
//parte fraccionaria) ingresado.

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

#define EXT 30

using namespace std;
#include "Global_functions.h"

int main(){

	//Prototypes
    void Ingresar_decimales(int num_val);
	// 

    int  num_val= 0;

    cout<<"Ingrese el numero de datos a realizar el proceso "; num_val = Leer_N();

    Ingresar_decimales(num_val);
}



void Ingresar_decimales(int num_val){

    //Prototipos
    int Encontrar_dig(double num, int dig_dec, int valor=10);
    int Encontrar_dig_recur(double num, int dig_dec, int i=0, int parte_int=0);
    //
    
    double num = 0;
    int dig_dec, num_dig, parte_int = 0;

    if(num_val > 0){
        cout<<"Ingrese un numero decimal(MAX CON 15 DIGITOS, que es la numero max de digitos dec. de double )"; num = Leer_N_decimal();
        cout<<"Ingrese el n-esimo digito decimal a cononcer "; dig_dec = Leer_N();

        parte_int = num;
        
        num_dig= Encontrar_dig_recur( num-parte_int, dig_dec);

        cout<<endl<<"El digito del la posicion decimal "<<dig_dec<<" es:"<<num_dig<<endl;
        Ingresar_decimales(--num_val);
    }
}

int Encontrar_dig(double num, int dig_dec, int conta=0){

    int parte_int =0;

    for (int i = 1; i < 16; i++)
    {
        num = num* 10;
        parte_int = num;

        if(i == dig_dec ) return parte_int;

        num = num-parte_int;
    }
}

int Encontrar_dig_recur(double num, int dig_dec, int i=0, int parte_int=0){
    
    if(i == dig_dec ) return parte_int;

    if(i<16){

        num = num* 10;
        parte_int = num;
        num = num-parte_int;
        
        if(num*10 == 0.0){
            parte_int=parte_int+1;
        }

        Encontrar_dig_recur(num,dig_dec,++i, parte_int);

    }

}




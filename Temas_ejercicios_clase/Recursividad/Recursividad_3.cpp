//Programa que perimite individuaslizar los digitos de cada numero 

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#include <string.h>

#define NR 10 			
using namespace std;

#include "Global_functions.h"

int main(){

	//Prototypes    
    void IngresarNumeros(int num, int *el_may);
	//

    int num =0;
    int vect[NR];
    int el_may = 0;

    cout<<"INGRESA EL NUMERO DE VALORES A INDIVIDUALIZAR"<<endl;
    num = Leer_N();

    IngresarNumeros(num, &el_may);

    cout<<endl<<"El digito mayor de los mayores es: "<<el_may<<endl;
}


void IngresarNumeros(int num, int *el_may){
   
    //
    void Individualizar_dig(int num, int *may );
    //
    int n, dig_may = 0;

    if(num>0){
        cout<<endl<<"Ingrese un valor entero "<<endl;
        cin>>n;

        if(n == 0) cout<<endl<<" > ";
        else Individualizar_dig( abs(n), &dig_may);

        cout<<endl<<"El digito mayor es: "<<dig_may<<endl;

        if( dig_may > *el_may) *el_may = dig_may;
        
        IngresarNumeros(num-1, el_may);
    }
}

void Individualizar_dig(int num, int *may){
    int dig; 

    if(num != 0){
        
        dig = num %10;
        Individualizar_dig( num/10 , may);
        cout<<endl<<" > "<<dig;

        if(dig > *may ) *may = dig;
    }
}




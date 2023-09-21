
//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#include <string.h>

using namespace std;
#include "Global_functions.h"


int main(){
	//Prototypes

    void Ingresar_num(int num ); 
	//

	int num=0;

	cout<<"Ingrese el numero de datos a ingresar "; num = Leer_N();

	Ingresar_num(num);

}

void Ingresar_num(int num ){
	//Prototypes
    int Calcular_potencia(int a, int b, int res);
	//
    int base,exp, potencia=0;

    if(num>0){
        cout<<endl<<"Ingrese el valor de la base "<<endl; base= Leer_N();
		cout<<endl<<"Ingrese el valor del exponente "<<endl;  exp= Leer_N();

		if(exp == 0){
			potencia = 1;
			cout<<endl<<"La potencia entre la base: "<<base<<" y el exp: "<<exp<<" es: "<<potencia<<endl<<endl;
		}	
		else{
			potencia = Calcular_potencia(base,exp, base);
			cout<<endl<<"La potencia entre la base: "<<base<<" y el exp: "<<exp<<" es: "<<potencia<<endl<<endl;
		}

		Ingresar_num(--num);
    }
}

int Calcular_potencia(int base, int exp, int res ){

	//Prototypes
	int Calcular_sum(int num, int num_vec, int cons);
	//

	if( exp == 1) return res;

	res = Calcular_sum(res, base-1, res);

	Calcular_potencia(base, --exp, res );
}


int Calcular_sum(int num, int num_vec, int cons){

	if(num_vec == 0 ) return num;

	num = num+cons;

	Calcular_sum(num, --num_vec, cons);
}


// 6. Generalice la solución al problema anterior (5)

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
    void Calcular_coor_enteras(double x, double y, int radio, int conta);
	// 
    int radio=0;

    cout<<"Ingrese el radio de la circunfercia "; radio = Leer_N();

    cout<<"\t\t\tPUNTOS DE COORDENADAS ENTERAS DE LA CIRCUNFERENCIA X^2 + Y^2 = 25"<<endl;

    Calcular_coor_enteras(0, 0, radio, radio);
}

void Calcular_coor_enteras(double x, double y, int radio, int conta){
    int entero=0;

    if(conta >= 0  ){

        y = sqrt(pow(radio,2)-pow(x,2));                        
        entero = y;
        if(y == entero) {
            cout<<"Con x = "<<x<<endl;
            cout<<"Cordenada entera: ( "<<x<<" , "<<y<<" ) "<<endl;
            cout<<"Cordenada entera: ( "<<x<<" , -"<<y<<" ) "<<endl;
            cout<<"Con y = "<<x<<endl;
            cout<<"Cordenada entera: ( "<<y<<" , "<<x<<" ) "<<endl;
            cout<<"Cordenada entera: ( -"<<y<<" , "<<x<<" ) "<<endl<<endl;
        }

        Calcular_coor_enteras(++x, 0, radio , --conta);
    }
}









// 4. Generar los N valores múltiplos de X. Calcular el promedio de aquellos valores generados que estén dentro del rango comprendido entre A y B; si no están en ese rango, los valores solo deberán imprimirse.
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
    int area_Circulos(int n1, int n2 );
    int Pregunta_orden(int preg);
    void Ordenar_num(int *n1, int *n2, int *n3);
    void Calcular_mul(int num, int n_mul, int vect[], int i, int res);
    float Generar_prom(int inicio, int fin, int vect[], int i, int sum, int n_mul, int conta);

	// 

    int n_val, x, inicio,fin=0;   

    cout<<"Ingrese el num a sacar su valor: "; x=Leer_N();
    cout<<"Ingrese el num de multiplos que se desea sacar a su valor: "; n_val=Leer_N();

    int vect[n_val]; 

    Calcular_mul(x, n_val, vect, 1, x);

    cout<<"\t\tLos multiplos de "<<x<<" son: "<<endl;
    Imprimir_Arreglo(n_val, vect);

    cout<<endl<<"\t\tGenerar promedio de un rango definido  "<<endl;
    cout<<"Ingrese el rango a sacar el promedio "<<endl;
    inicio= Leer_N();
    fin = Leer_N();

    float prom = Generar_prom(inicio, fin, vect, 0, 0,n_val,0);
    cout<<"El prom de los num entre ["<<inicio<<" , "<<fin<<"] es: "<<prom<<endl;

}


void Calcular_mul(int num, int n_mul, int vect[], int i, int res ){

    if(n_mul != 0 ){
        vect[i-1] = res;
        Calcular_mul(num, --n_mul, vect, ++i, num * (i+1));
    }

}


float Generar_prom(int inicio, int fin, int vect[], int i, int sum, int n_mul, int conta){
    
    if( i == n_mul ){
        return (sum/conta);
    }

    if(vect[i] >= inicio && vect[i]<= fin){

        sum += vect[i];
        conta++;
    }
    else{
        cout<<"Los multiplos que NO cumplen son "<<i+1<<" con valor de: "<<vect[i]<<endl;
    }
    Generar_prom(inicio, fin, vect, ++i, sum, n_mul, conta);
}


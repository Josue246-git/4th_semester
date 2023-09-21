
// 2. Generar el área de los círculos cuyo radio está comprendido entre los valores A y B

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#include <cmath>
#include <string.h>

#define EXT 30

using namespace std;

int main(){

	//Prototypes
    int area_Circulos(int n1, int n2 );
	//

    int num1, num2 = 0;

    cout<<" INGRESAR LOS DOS NUMEROS DEL RANGO DE RADIOS EN LOS QUE SE DESEA CALCULAR EL AREA DE LOS CIRCULOS  "<<endl;
    cin>> num1;
    cin>>num2;

    area_Circulos(num1, num2 );

    return 0;
}

int area_Circulos(int n1, int n2 ){

    if(n1 > n2 ) return 0;
    
    else{
        cout<<endl<<"El area del circulo con el radio "<<n1<<" es: "<<M_PI *n1*n1<<endl;
        area_Circulos(n1+1, n2);
    }
    
}



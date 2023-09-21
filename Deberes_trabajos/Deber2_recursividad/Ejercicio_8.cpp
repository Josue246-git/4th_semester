//8. Imprimir la tabla con las raíces cuadradas de los valores comprendidos entre 6.0 y 7.5
//con incrementos de 0.001

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
    void Generar_tabla(float inicio, float fin, float i);
	// 

    float inicio= 6.0;
    float fin = 7.5;
    float increm = 0.001;


    cout<<endl<<"\t\t\t TABLA COMPRENDIDA ENTRE [ "<<inicio<<" , "<<fin<<" ] con incremento de: "<<increm<<endl;
    cout<<endl<<"NUMERO "<<"\t\t RAIZ DEL NUMERO "<<endl;

    Generar_tabla(inicio, fin, increm);

}

void Generar_tabla(float inicio, float fin, float i){
    
    if(inicio <= fin){

        cout<<inicio<< "\t\t" << sqrt(inicio)<<endl;
        Generar_tabla(inicio+i, fin, i);
    }
}





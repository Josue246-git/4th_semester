//8. GENERALIZE EL PROGRAMA anterior(8)

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

    float inicio, fin, increm =0;

    cout<<"Ingresar el numero de inicio del intervalo: "; inicio=Leer_N_decimal();
    cout<<"Ingresar el numero de fin del intervalo: "; fin=Leer_N_decimal();
    cout<<"Ingresar el incremento de inicio a fin : "; cin>>increm;

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





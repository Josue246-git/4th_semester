
//3. Ingresar tres números, y proceder a ordenarlos (ascendente o descendentemente, de acuerdo a lo requerido por el usuario)

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
    int Pregunta_orden(int preg=0);
    void Ordenar_num(int n1, int n2, int n3, int preg);

	// 

    int n1,n2,n3 = 0;
    cout<<"ingresar los tres numeros a ordenar "<<endl;

    cout<<endl<<"Primero: "; n1 = Leer_N();
    cout<<endl<<"Segundo: "; n2 = Leer_N();
    cout<<endl<<"Tercero: "; n3 = Leer_N();

    cout<<"Los numeros son: "<<n1<<", "<<n2<<", "<<n3<<endl;

    int preg = Pregunta_orden();

    if(preg == 1) cout<<"\t\t\t Ordenar de forma Ascendete"<<endl;
    else cout<<"\t\t\t Ordenar de forma Descendete"<<endl;

    Ordenar_num(n1, n2, n3, preg);


    return 0;
}

int Pregunta_orden(int preg=0){

    cout<<endl<<"De que forma desea ordenar los valores "<<endl;
    cout<<"Ascendente: digite 1"<<endl;
    cout<<"Descendente: digite 2"<<endl;
    cin>>preg;

    if(preg < 1 || preg > 2){
        cout<<endl<<"Porfavor ingresa un numero valido "<<endl;
        Pregunta_orden(preg);
    }

    return preg;
}

void Ordenar_num(int n1, int n2, int n3, int preg){
    if(preg == 1){
        if(n1<n2 && n2>n3) Ordenar_num(n1, n3, n2, preg);
        else if(n2<n1 && n1<n3) Ordenar_num(n2, n1, n3, preg);
        else if(n2<n3 && n3<n1) Ordenar_num(n2, n3, n1, preg);
        else if(n3<n1 && n1<n2) Ordenar_num(n3, n1, n2, preg);
        else if(n3<n2 && n2<n1) Ordenar_num(n3, n2, n1, preg);
        else if(n1<n2 && n2<n3){
            cout<<"Los numeros ordenados son: "<<n1<<", "<<n2<<", "<<n3<<endl;
        }
    }
    else{
        if(n1>n2 && n2<n3) Ordenar_num(n1, n3, n2, preg);
        else if(n2>n1 && n1>n3) Ordenar_num(n2, n1, n3, preg);
        else if(n2>n3 && n3>n1) Ordenar_num(n2, n3, n1, preg);
        else if(n3>n1 && n1>n2) Ordenar_num(n3, n1, n2, preg);
        else if(n3>n2 && n2>n1) Ordenar_num(n3, n2, n1, preg);
        else if(n1>n2 && n2>n3){
            cout<<"Los numeros ordenados son: "<<n1<<", "<<n2<<", "<<n3<<endl;
        }
    }
    
}





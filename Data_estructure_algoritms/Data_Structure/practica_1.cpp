#include<iostream>
#include<stdlib.h>
#include<cmath>

using namespace std;

int numero_datos(){
    int n=0;
    do{
        cout<<"Ingrese el numero de datos a contar sus digitos ";cin>>n;
    }
    while ( (n < 0) );  
    
    return n;
}

float ingresar_num(){
    float num=0;
    cout<<"Ingrese un numero a sacar sus digitos "; cin>>num;
    cout<<endl;
    return num;
}   

int Ejecucion_contar_n_digitos( float num){
    int parte_entera = num;
    int conta = 0;

    while (parte_entera != 0){

        parte_entera /= 10;
        conta++;
    }

    double decimalPart = num - static_cast<int>(num);
    const double epsilon = 1e-10; // precisión de punto flotante

    while (abs(decimalPart - round(decimalPart)) > epsilon) {
        decimalPart *= 10;
        conta++;
    }

    return(conta);
}

void imprimir_cantidad_digitos(int n_digitos){
    cout<<n_digitos<<endl;
}


int main(){
    int num_datos = numero_datos();

    for (int i = 0; i < num_datos; i++)
    {
        float num = ingresar_num();

        cout<<"Con el digito "<<num<<", la cantidad de datos son:"<<endl;

        int n_digitos = Ejecucion_contar_n_digitos(num);

        imprimir_cantidad_digitos(n_digitos);
    }
    
    
    return 0;
}
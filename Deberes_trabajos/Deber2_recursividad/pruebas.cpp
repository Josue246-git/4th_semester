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
    void Ingresar_datos(int num_val);
    int  MCD(int n1, int n2,  int div, int mcd = 0);
    int Suma_divs(int num , int divisor, int res = 0);

	// 

    int  num_val= 0;
    int n1,n2, n=0;

    // cout<<"Ingrese el numero de datos a realizar el proceso "; num_val = Leer_N();
    // Ingresar_datos(num_val);

    // cout<<"Ingresar dos numeros para sabar su MCD"<<endl;
    // n1 = Leer_N();
    // n2 = Leer_N();
    // if(n1 > n2){
    //     int aux = n1;
    //     n1 = n2;
    //     n2 = aux; 
    // }
    // cout<<n1<<" "<<n2<<endl;
    // int mcd = MCD(n1, n2, n1);
    // cout<<"El MCD de "<<n1<<" "<<n2<<" es: "<<mcd<<endl;

    cout<<"Ingresar un num "; n = Leer_N();

    if(Suma_divs(n, n-1) == n ) cout <<" El numero "<<n<<" es perfecto"<<endl;
    if(Suma_divs(n, n-1) > n ) cout <<" El numero "<<n<<" es abundante"<<endl;
    if(Suma_divs(n, n-1) < n ) cout <<" El numero "<<n<<" es deficiente"<<endl;

    
}

void Ingresar_datos(int num_val){
    //
        int Factorial(int num);
        int Factorial_sumas(int num, int res = 0);
        void decimal_binario(int num,  int vect[], int binario = 0, int i = 0 );
    //
    int n =0;

    if(num_val > 0 ){

        // cout<<"Ingrese un valor a sacar su factorial "; cin>>n;

        // // int fact = Factorial(n);
        // int fact = Factorial_sumas(n , n);

        // cout<<"El factoiral de "<<n <<" es: "<<fact<<endl;


        cout<<"Ingrese un decimal a sacar su binario "; cin>>n;

        // int fact = Factorial(n);
        
        cout<<"El binario de "<<n <<" es: "<<endl;
        int vect[n]; 
        decimal_binario(n,vect);


        Ingresar_datos(--num_val);
    }
}


int Factorial(int num){
    
    if(num == 0|| num == 1){
        return 1;
    }
    //return num * Factorial(--num);          //No va a funcionar, pues c++ va primero con el valor decrementado y despues con el original, que ya estaria decremntado y se lo perderia 
    return num * Factorial(num-1);
}

int Factorial_sumas(int num, int res ){  // num = decrementador, res = respuesta de cada nivel o paso 
    //
    int sumas_suc(int num, int vec, int res_sum);
    //

    if(num == 1 ) return res;
    
    res = sumas_suc(res, num - 2, res);

    Factorial_sumas(num-1, res );
}

int sumas_suc(int num, int vec, int res_sum){
    if(vec == 0){
        return res_sum; 
    }
    res_sum= res_sum+num;

    sumas_suc(num, --vec, res_sum);
}


// void decimal_binario(int num,  int vect[], int binario = 0, int i = 0 ){

//     if(num == 1){
//         vect[i] = 1;
//         Imprimir_Arregl_reves(i, vect);
//         return;
//     }

//     binario = num % 2 ;
//     vect[i]= binario,
//     num = num/2;

//     decimal_binario(num , vect, binario, i+1);
// }

void decimal_binario(int num,  int vect[], int binario = 0, int i = 0){

    if(num != 1){
        
        binario = num % 2 ;
        vect[i]= binario,
        num = num/2;
        decimal_binario(num , vect, binario, i+1);
        cout<<endl<<num<<endl;
    }
    else if(num == 1){
        vect[i] = 1;
        Imprimir_Arregl_reves(i, vect);
    }   
}


int  MCD(int n1, int n2,int div, int mcd = 0){

    if(mcd != 0 || div == 1){
        return mcd;
    }

    if(mcd == 0){
        if((n1 % div == 0)&&(n2 % div == 0)){
            mcd = div;
        }
    }

    MCD(n1, n2, div-1, mcd);
}

//Num perfecto: que la suma de sus divisores sea igual al num, 
// Num abundante: que la suma de sus divisores es superior al num,
                                
int Suma_divs(int num , int divisor, int res = 0){

    if(divisor == 0 ){
        return res; 
    }

    if(num % divisor == 0){
        res = res + divisor;
    }

    Suma_divs(num, divisor-1, res);
}




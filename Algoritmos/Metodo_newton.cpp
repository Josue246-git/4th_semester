#include <iostream>
#include <cmath>
using namespace std;

//PRIMERA FUNCION

// float Fn(float x){
//     return (pow(2,x) + x - 2);
// }

// float derivada_Fn(float x){
//     return(pow(2,x) + log(2) + 1);
// }

//SEGUNDA FUNCION
// float Fn(float x){
//     return (pow(3,x) + x - 3);
// }

// float derivada_Fn(float x){
//     return(pow(3,x) + log(3) + 1);
// }

//TERCERA FUNCION 

float Fn(float x){
    return (pow(0.25, x)-pow(x,2)+4*x-3);
}

float derivada_Fn(float x){
    return(pow(0.25, x)-log(0.25)-2*x+4);
}



int main() {

    int i=0;
    float x1= 0, x0 = 0,d =0;

    cout<<"Algoritmo para calcular raices de una ecuacion (METODO NEWTON-RAPHSON)"<<endl;
    cout<<endl<<"Ingrese el valor inicial ";cin>>x0;

    cout<<endl<<"CON UN PRIMER x0 "<<x0<<endl;
    do{
        cout<<endl<<"iteracion "<<i<<", res: "<<x0<<endl;
        x1 = x0 - Fn(x0)/derivada_Fn(x0);

        d = abs(x1-x0);

        x0=x1;
        i++;
    } 
    while ((d > 0.001) && i< 20);


    cout<<endl<<"Numero de interaciones es: "<<i<<endl;

    if(i == 20) cout<<"No se encontro una raiz de la funcion "<<endl;
    else {
        cout<<"La respuesta es: "<<x1<<endl;
        x0 = 3;
        x1=0;
        d=0;
        cout<<endl<<"CON UN SEGUNDO x0 "<<x0<<endl;
        i=0;

        do{
            cout<<endl<<"iteracion "<<i<<", res: "<<x0<<endl;
            x1 = x0 - Fn(x0)/derivada_Fn(x0);

            d = abs(x1-x0);

            x0=x1;
            i++;
        }
        while ((d > 0.001) && i< 20);

        cout<<endl<<"Numero de interaciones es: "<<i<<endl;
    
        if(i==20) cout<<"No se encontro una raiz de la funcion "<<endl;
        else cout<<"La respuesta es: "<<x1<<endl;
    }
    cout<<endl;
}





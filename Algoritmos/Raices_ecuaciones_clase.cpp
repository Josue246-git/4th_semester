#include <iostream>
#include <math.h>
using namespace std;


// float funcion_x(float x){
//     return (pow(0.5, x) -(x/3) + 1);
// }

float funcion_x(float x){
    return (pow(x,2)-2 );
}


int main() {

    int aux = 0, i=0;
    float h,a,b, x1, x2, signo = 0;

    cout<<endl<<"Ingrese el paso de busqueda (h) a realizar: ";cin>>h;
    cout<<endl<<"Ingrese el min del intervalo:  ";cin>>a;
    cout<<endl<<"Ingrese el max del intervalo: ";cin>>b;

    cout<<endl<<"\t\t\t CALCULO DE RAICES DE ECUACIONES en el intervalo ["<<a<<" , "<<b<<" ]"<<endl;

    x1=a;
    x2=a+h;

    do{
        i++;
        signo = funcion_x(x2) * funcion_x(x1);
        if(signo >0){
            x1 = x2;
            x2 = x1+h;
        }
        else{
            cout<<endl<<"El numero de iteraciones es: "<<i<<endl;
            cout<<endl<<"Aproximadamente la solucion es: "<<(x1+x2)/2<<endl;
            cout<<"COn un error maximo: "<<h/2<<endl;
            aux=1;
        }
    }
    while ((aux == 0) && (x2 <= b));


    if(aux == 0) cout<<endl<<" no se tiene un resultado en dichos interevalos"<<endl;
    
    cout<<endl;
}
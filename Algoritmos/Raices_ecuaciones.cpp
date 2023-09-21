#include <iostream>
#include <math.h>
using namespace std;


float funcion_x(float x){
    return (pow(0.5, x) -(x/3) + 1);
}

int main() {

    int sig1 = 1, sig2 = 1;
    float h,a,b,res=0;

    cout<<endl<<"Ingrese el paso de busqueda (h) a realizar: ";cin>>h;
    cout<<endl<<"Ingrese el min del intervalo:  ";cin>>a;
    cout<<endl<<"Ingrese el max del intervalo: ";cin>>b;

    cout<<endl<<"\t\t\t CALCULO DE RAICES DE ECUACIONES en el intervalo ["<<a<<" , "<<b<<" ]"<<endl;

    if(funcion_x(a)< 0) sig1=-1;


    for (float i = a; i <= b; i=i+h){

        cout<<endl<<i<<" "<<funcion_x(i)<<endl;

        if(funcion_x(i)< 0) sig2 = -1;
        
        if(sig1 != sig2 ){
            res = i;
            break;
        }
        
    }

    if(res == 0){
        cout<<endl<<"No existe raiz en el intervalo dado"<<endl;
    }


    cout<<endl<<"La respuesta esta entre ["<<res-h<<" , "<<res<<" ]"<<endl;
    float p_medio = (res-h+res)/2;
    cout<<"Aprox en el punto medio: "<<p_medio<<endl;
    cout<<"Con un error maximo del: "<<h/2<<endl;
    
    cout<<endl;
}
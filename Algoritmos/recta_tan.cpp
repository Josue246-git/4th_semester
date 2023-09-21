#include <iostream>
#include <math.h>
using namespace std;


// float f(float x){
//     return (log(x));
// }

float f(float x){
    return (pow(3,x)+pow(x,2)-1);
}

float f_derivada(float x){
    return ( (f(x+0.0001)-f(x))/0.0001);
}


 
int main() {

    cout<<endl<<"\t\t\tCALCULAR LA RECTA TANGENTE Y NORMAL DADO UN VALOR X0"<<endl;

    float x0, y0, m, b,m2;

    cout<<endl<<"Ingrese el valor de x0: "; cin>>x0;

    cout<<endl<<"Calcular y0: "<<endl;
    y0 = f(x0);
    cout<<"y0 = "<<y0<<endl;

    m = f_derivada(x0);

    cout<<endl<<"La funcion de la recta tangente es:"<<endl;

    b= -(m*x0)+y0;

    if(b >= 0) cout<<"y = "<<m<<"x + "<<b<<endl;
    else cout<<"y = "<<m<<"x "<<b<<endl;

    m2= -1/m;
    cout<<endl<<"La funcion de la recta normal es:"<<endl;

    b= -(m2*x0)+y0;

    if(b >= 0) cout<<"y = "<<m2<<"x + "<<b<<endl;
    else cout<<"y = "<<m2<<"x "<<b<<endl;
    
    cout<<endl;
}
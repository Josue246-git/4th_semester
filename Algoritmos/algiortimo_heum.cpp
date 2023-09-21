#include <iostream>
#include <cmath>

using namespace std;

float f(float t, float y){
    return (1-2*t)*y;
}

void heun(float t0, float y0, float h, int n, float b) {
    float t1 = t0;
    float y1 = y0;

    cout<<"i       ti       yi"<<endl;

    int i = 0;

    do{
        cout<<i<<"      "<<t0<<"        "<<y0<<endl;

        float k1 = f(t0, y0);
        float k2 = f(t0 + h, y0 + h*k1);
        y0 = y0 + h * (k1 + k2)/2;
        t0 = t0 + h;

        i++;

    } while ((i < n) || (t0<= b) );
    
}


int main() {

    int n;
    float t0, y0, h, a, b, res;

    cout<<endl<<"\t\t\tALGORTIMO DE HEUM "<<endl;


    cout<<"Ingresar la condicion incicial :";cin>>y0;
    cout<<"Ingresar el numero de iteraciones :";cin>>n;
    cout<<"INgrese el dominio: "<<endl;
    cin>>a;
    cin>>b;

    h=(b-a)/n;

    cout<<endl<<"El h : "<<h<<endl;
    t0=a;
    heun(t0, y0, h, n, b);
    
}

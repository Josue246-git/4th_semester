#include <iostream>
#include <cmath>

using namespace std;



int main() {

    int i=0;
    float x0,y0, xn1, yn1, xn, yn, d;


    cout<<endl<<"Ingrese los puntos x0, y0: "<<endl;
    cin>>x0;
    cin>>y0;

    xn = x0; yn = y0; 
    cout<<endl<<"\t\t\tALGORTIMO DE MANDELBROT "<<endl;

    do{
        xn1 = xn*xn - yn*yn + x0;
        yn1 = 2*xn*yn + y0;

        d= sqrt(pow(xn1-x0, 2)+pow(yn1-y0,2 ));

        if(d > 2){
            cout<<endl<<i<<"      "<<xn<<"        "<<yn<<endl;
            cout<<"FALSO, El punto ("<<x0<<", "<<y0<<") NO CONVERGE "<<endl;
            break;
        }

        xn = xn1;
        yn = yn1;

        i++;

        if(i == 90){
            cout<<endl<<i<<"      "<<xn<<"        "<<yn<<endl;
            cout<<"VERDADERO, El punto ("<<x0<<", "<<y0<<") SI CONVERGE "<<endl;
        }    

    } while (i <= 90);


    cout<<endl;
    
}


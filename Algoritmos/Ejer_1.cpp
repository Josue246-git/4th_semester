
//SIN POW 


#include <iostream>
#include <math.h>
using namespace std;

int Potencia(int base, int exp){
    if(exp == 0){
        return 1;
    }
    return base* Potencia(base, exp-1);
}

int CalcularPol(int n , int coef[],int x){
    int res=0;
    for (int i = 0; i < n+1; i++){
        res +=  coef[i]*Potencia(x,i);
    }
    return res;
}

int main() {
    cout<<"\t\t\t CALCULO DE POLINOMIO SIN POW"<<endl;
    
    int n,x, res; 
    cout<<endl<<"Ingrese el orden del polinomio: "; cin>>n;
    int coef[n+1];
    
    for (int i = 0; i < n+1; i++){
        cout<<endl<<"Ingrese el coeficiente "<<i+1<<" :"; cin>>coef[i];
    }

    cout<<endl<<"Ingrese el valor de x a reempalazar "; cin>>x;

    res = CalcularPol(n, coef,x);

    cout<<endl<<"El resultado del pol es: "<<res<<endl;

}
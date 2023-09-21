#include <iostream>
#include <cmath>
using namespace std;

float fn(float x){
return pow(3,x) + x - 3;
}

float dfn(float x){
return pow(3,x) + log(3) + 1;
}

int main(){

float x0;

cout << "Ingrese el valor inicial" << endl;
cin >> x0;

float x1,d;
int n = 0;

do{
    x1 = x0 - fn(x0)/dfn(x0);
    cout << "x" << n + 1 << " = " << x1 << endl;
    d = abs(x1-x0);
    x0 = x1;
    n++;
    
}while(d > 0.001);

cout << "La raiz es: " << x1 << endl;
cout << "Numero de iteraciones: " << n << endl;

return 0;
}
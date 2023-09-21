
#include <iostream>
using namespace std;

int MCD(int a, int b){                      //Funcion que calcula el MCD con el algoritmo de euclides
    if(b==0) return a;
    return MCD(b, a%b);
} 


int main() {

    int a,b;
    
    do{ 
        cout<<endl<<"Ingrese el primer numero a sacar el MCD: ";cin>>a;
        cout<<endl<<"Ingrese el segundo numero sacar el MCD: ";cin>>a;
    }
    while(a<b);


}
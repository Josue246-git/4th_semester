
#include <iostream>
using namespace std;

int main() {

    double x= 1,z = 0;
    int i=0; 

    do{
        x = x/ 2;
        z= x+1;
        i++;
    }
    while( z > 1 );

    cout<<endl<<"x: "<<x<<endl;
    cout<<endl<<"El numero de iteraciones que se hizo es:"<<i<<endl;
}
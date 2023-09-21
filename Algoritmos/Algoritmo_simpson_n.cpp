#include <iostream>
#include <cmath>
using namespace std;


double truncateToDecimal(double number, int decimalPlaces) {   //funcion para truncar un numero a solo un decimal o a n
    double multiplier = std::pow(10, decimalPlaces);
    double truncatedNumber = std::trunc(number * multiplier) / multiplier;
    return truncatedNumber;
}


double f(double x){                 //funcion 
	return pow(3,x);							//Define la función f(x)1
}

// double f(float x){
// 	return 2/(sqrt(1+pow(x,3)));							//Define la función f(x)2
// }



double simpson(double a, double b){                 //algroitmo de simlpson, formula

	double c=(a+b)/2;										//Define el tamaño del intervalo

	double I=(b-a)/6*(f(a)+4*f(c)+f(b));						//Calcula la integral	

	return I;
}


int main() {
    double a, b; // Límites de integración

    cout<< "Ingrese el límite inferior de integración (a): ";
    cin>> a;
    a = truncateToDecimal(a,1);

    cout << "Ingrese el límite superior de integración (b): ";
    cin >> b;
    b= truncateToDecimal(b,1);
    
    // cout<<a<<" "<<b<<endl;

    double sum = 0;
    int n=0;
    double aux=a;

    while (aux<=b){                     //calcula el numero n de pasos con 0.1
        aux=aux+0.1;
        n++;
    }

    // cout<<endl<<n<<endl;
    
    if(n %2 != 0) n=n-1;                //comprtueba que no sea impar
    if(n>100) n=100;                    //Se limita a 100

    for (int i = 0; i < n; i++){
        
        b=a+0.1;
        sum = sum + simpson(a,b);
        a=b;
    }
    
    cout<<endl<<"La respuesta de la integral es: "<<sum<<endl;
    return 0;
}

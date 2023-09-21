#include<iostream>
#include<cmath>
using namespace std;

float f(float x){
	return 3/(sqrt(1+pow(x,5)));							//Define la función f(x)1
}

// float f(float x){
// 	return 2/(sqrt(1+pow(x,3)));							//Define la función f(x)2
// }



float simpson(float a, float b){

	float c=(a+b)/2;										//Define el tamaño del intervalo

	float I=(b-a)/6*(f(a)+4*f(c)+f(b));						//Calcula la integral	

	return I;
}

int main(){

	float a,b;

	cout<<endl<<"ALGORITMO DE SIMPSON "<<endl;
	cout<<endl<<"Ingrese el intervalo de integracion a: "; cin>>a;
	cout<<"Ingrese el intervalo de integracion b: "; cin>>b;

	cout<<endl<<"La solucion de la integral es aproximadamente: "<<simpson(a,b)<<endl;
	
	
	return 0;
}
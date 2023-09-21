//TDA COLA que me diga que cada valor ingersado es capicuaa mediante el empleo de COLA CIRCULAR


#include <iostream>
#define EXT 20
#define fin 9999
#include "TDA_cola_circular.h"
using namespace std;

int main(){

    ColaCircular c1;

    void leerColaR(ColaCircular *c1);
    void imprimirColaR(ColaCircular c1);
    


    leerColaR(&c1);
    cout << endl << "Elementos de la cola: ";
    cout << endl << "=======================";
    imprimirColaR(c1);

    cout << endl;
}

bool esCapicua(Tipo numero, int numOrg, int numInvertido = 0){    

    if (numero > 0) {
        int digito = numero % 10;
        numInvertido = numInvertido * 10 + digito;
        numero = numero / 10;
    }
    else  return numOrg == numInvertido;
    esCapicua(numero, numOrg,  numInvertido);

}

void leerColaR(ColaCircular *c1){
    //
    bool esCapicua(Tipo numero, int numOrg, int numInvertido = 0);  
    //
    
    Tipo x;
    cout << endl << "Valor a insertar. Finalice con "<<fin<<": ";
    cin >> x;
    if(x != fin){
        if(!c1->colaLlena()){
            cout << endl << "El numero ingresado "<<(esCapicua(x, x)?"Si ":"No ")<<"es capicua";
            c1 -> insertar(x);
            leerColaR(c1);
        }
        else{
            cout << endl << "C1:'Ya me llene :('";
        }
    }
}   

void imprimirColaR(ColaCircular c1){
    if(!c1.colaVacia()){
        //no hay que cambiar el orden en colas, explota BOOM!
        cout << endl << ">  " << c1.quitar();
        imprimirColaR(c1);
    }
}


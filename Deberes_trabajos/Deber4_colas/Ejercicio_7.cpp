//Ingresar una cola de valores, y si hubieran valores consecutivos adyacentes en esta, 
//separarlos con un valor correspondiente al promedio calculado entre los dos elementos contiguos al 
//espacio en que se insertará el nuevo valor
//NOMNRE: JOSUE RODRIGUEZ 7272

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "TDA_cola.h"
using namespace std;

bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(numero); i++) {
        if (numero % i == 0) {
            return false;
        }
    }

    return true;
}

vector<int> obtenerDivisoresPrimos(int numero) {
    vector<int> divisores;

    for (int i = 2; i <= numero; i++) {
        if (esPrimo(i) && (numero % i == 0)) {
            divisores.push_back(i);
        }
    }

    return divisores;
}

int main() {
    Cola cola;

    int cantidadNumeros;
    cout << "Ingrese la cantidad de números: ";
    cin >> cantidadNumeros;

    for (int i = 0; i < cantidadNumeros; i++) {
        int numero;
        cout << "Ingrese el número " << i + 1 << ": ";
        cin >> numero;

        vector<int> divisoresPrimos = obtenerDivisoresPrimos(numero);
        for (int divisor : divisoresPrimos) {
            cola.insertar(divisor);
        }
    }

    ofstream archivo("divisores_primos.txt");
    if (archivo.is_open()) {
        while (!cola.colaVacia()) {
            archivo << cola.frenteCola() << endl;
            cola.quitar();
        }
        archivo.close();
        cout << "Se han guardado los divisores primos en el archivo 'divisores_primos.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }

    return 0;
}
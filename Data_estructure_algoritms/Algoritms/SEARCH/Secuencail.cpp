// Secuencial search 
//No importa que el array este ordenada
#include <iostream>
using namespace std;


void secuencial_search(int array[], int size, int dato) {

    int i=0;
    bool band = false;
    //Simplemente buscar el elemento secuencialmente
    while((band == false) && (i < size)){
        if(array[i] == dato){
            band = true;
        }
        i++;
    }

    if(band == true) cout<<"Dato: "<<dato<<" encontrado!!, en la posicion: "<< i-1 <<endl;
    else cout<<"Dato no encontrado !!"<<endl;
}

// Driver code
int main() {
    int dato =0;
    int data[] = {9, 5, 1, 4, 3};
    int size =  sizeof(data)/sizeof(data[0]);
    cout <<"Ingresar el dato a buscar en el array: ";cin>>dato;

    secuencial_search(data, size, dato);
 
}
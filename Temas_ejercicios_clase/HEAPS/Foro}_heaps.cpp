// Autor: Josue Rodriguez 7272

using namespace std;

#include <iostream>
#include "monticulo.h"
#include "utilidades.h"


int main(){											//programa principal
	int n;
	//
	void leerMonticulo(Monticulo * m1, int n1);		//prototipo de la funcion que lee un monticulo de datos
	void imprimirMonticulo(Monticulo m1);	//prototipo de la funcion que imprime un monticulo
	void imprimirMinimo(Monticulo m1);				//prototipo de la funcion que imprime el valor minimo del monticulo
    void Heap_sort(Monticulo m , Clave aux[]);
    void Encontrar_k_menores_mayores(int k, Clave aux[]);
    //

	cout << endl << "CANTIDAD DE ELEMENTOS DEL MONTICULO";
	n = leerN(1,20);								//cantidad de elementos
	Monticulo m(n);									//creacion de monticulo

	leerMonticulo(&m, n);							//llamada a ingreso de monticulo
	imprimirMonticulo(m);						//llamada a impresion de monticulo

	imprimirMinimo(m);


    cout<<endl<<"ORDENAMIENTO HEAP SORT "<<endl;
    Clave aux[n];                                   //se utiliza un vector auxiliar para guardar los valores del mon. ordenado

    Heap_sort(m, aux);

    for (int i = 0; i < m.getNumDatosAct(); i++){
        cout << endl << ">   " << aux[i];
    }    

    cout<<endl<<"Selección de los k elementos más grandes o más pequeños"<<endl;

    cout<<"Ingrese el valor k(numero de valores mayores o menores del monticulo )";
    int k = leerN(1,m.getNumDatosAct()); 
    Encontrar_k_menores_mayores(k, aux);


	cout << endl;
}

void leerMonticulo(Monticulo* m1, int n1){		//funcion que lee n datos y los inserta en un monticulo
	Clave aux;

	cout << endl << "INGRESO DE ELEMENTOS DEL MONTICULO";
	for (int i=0; i < n1; i++){					//ciclo
		cout << endl << "Ingrese un valor: ";
		cin >> aux;
		m1->Insertar(aux);						//insercion de elemento en monticulo
	}
}

void imprimirMonticulo(Monticulo m1){	//funcion que imprime un monticulo
	Clave aux;									

	cout << endl << "IMPRESION DE ELEMENTOS DEL MONTICULO";
	for (int i = 0; i < m1.getNumDatosAct(); i++){
		aux = m1.getValor(i);						//calcula valor extraido del monticulo
		cout << endl << ">   " << aux;
	}
}

void imprimirMinimo(Monticulo m1){				//funcion que imprime el valor minimo del monticulo
	cout << endl << "El valor minimo incluido en el Monticulo es : " << m1.BuscarMinimo();
}


void Heap_sort(Monticulo m , Clave aux[]){
    m.getNumDatosAct();
    int num_datos = m.getNumDatosAct();

    for(int i = 0; i < num_datos; i++){
        aux[i] = m.EliminarMinimo();
    }
}

void Encontrar_k_menores_mayores(int k, Clave aux[]){

    cout<<endl<<"LOS ELEMENTOS MENORES SON: "<<endl;

    for (int i = 0; i < k; i++){
        cout<<"elemento "<<i+1<<": "<<aux[i]<<" "<<endl;
    }
    cout<<endl;

    cout<<endl<<"LOS ELEMENTOS MAYORES SON: "<<endl;

    for (int  i = k-1; i >= 0; i--){
        cout<<"elemento "<<k-i<<": "<<aux[i]<<" "<<endl;
    }
    cout<<endl;
}

//Generar un listado ordenado descendentemente con los valores que contienen una cantidad impar de dígitos, 
//tomados de entre varios números enteros ingresados por el usuario (aplíquese el algoritmo de ordenamiento 
//por inserción)

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>

#define EXT 10 			
using namespace std;

int main(){
	// system("color 4d");

	int vect[EXT];
    int vect_impar[EXT];
	int n=0;
    int n2=0;

	//Prototypes
	int LeerN_elementos(int limit_inf, int limit_sup); //Prototipo de la fucnion, se recomienda porque se trabaja con var. locales 
	void Leer_vect(int n, int *vect);
	void Imprimir_Arreglo(int n, int *vect);// El vector siempre se pasa por referecia, por lo que no es necesario 

    void Sacar_impares_vec(int n, int *vect, int *vect_impar, int *n2);
    void insertionSort(int array[], int size); 
	//
    
	cout<<endl<<"\t\t\t TAMANIO DEL VECTOR"<<endl;
	n = LeerN_elementos(1, EXT);
 
	cout<<endl<<"\t\t\t LEER VECTOR "<<endl;
	Leer_vect(n, vect);

	Imprimir_Arreglo(n, vect);

    cout<<endl<<"\t\t\t SACAR LOS VALORES IMPARES DEL VECTOR  "<<endl;
	Sacar_impares_vec(n, vect, vect_impar, &n2);
    
    Imprimir_Arreglo(n2, vect_impar);

    cout<<endl<<"\t\t\t ORDENAIMEINTO DESCENDENTE DEL VECTOR IMPAR, POR INSERCION  "<<endl;
	insertionSort(vect_impar, n2);
    
    Imprimir_Arreglo(n2, vect_impar);

	return 0;
}


int LeerN_elementos(int limit_inf, int limit_sup){
	int n=0;

	do{
		cout <<"Ingrese un valor entero comprendido entre "<<limit_inf <<" hasta "<<limit_sup<<": "; cin>>n;
	}
	while((n > limit_sup) || (n < limit_inf) );
	return n;
}

void Leer_vect(int n, int *vect){

	cout<<endl<<"INGRESE LOS VALORES DEL ARREGLO "<<endl;
	
	for(int i = 0; i < n; i++){
		cout<<"Ingrese el valor en la poscion "<<i<<": "; 
		cin>> *vect++;
    }							
}

void Imprimir_Arreglo(int n, int *vect){

	cout<<endl<<"\t\t\t El vector es:  "<<endl;
	
	for(int i = 0; i < n; i++){
		cout<<"Del valor ["<<i<<"]: "<<*vect<<endl;
		vect++;
	}

}

void Sacar_impares_vec(int n, int *vect, int *vect_impar, int *n2){

    for (int i = 0; i < n; i++){
       if((vect[i] % 2) != 0  ) {
            vect_impar[*n2] = vect[i];
            *n2= *n2+1;
       }
    }
}

void insertionSort(int array[], int size) {
    
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    while (key > array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}
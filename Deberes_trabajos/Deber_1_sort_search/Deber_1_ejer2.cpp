//Ingresar varios números enteros, y determinar el (los) valor(es) más repetido(s) que constan entre ellos
//(aplique el algoritmo de búsqueda binaria y ordenamiento por selección, en caso de requerirlo)

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>

#define EXT 10 			
using namespace std;

int main(){
	// system("color 4d");

	int vect[EXT];
    int vect_rep_may[EXT];
	int n=0;

	//Prototypes
	int LeerN_elementos(int limit_inf, int limit_sup); 
	void Leer_vect(int n, int *vect, int vec_rep[]);
	void Imprimir_Arreglo(int n, int *vect);
	int binarySearch(int array[], int x, int low, int high);
	void selectionSort(int array[], int size);
	void Determinar_valores_rep(int array[], int size, int vect_rep_mey[]);

	//
    
	cout<<endl<<"\t\t\t TAMANIO DEL VECTOR"<<endl;
	n = LeerN_elementos(1, EXT);
 
	cout<<endl<<"\t\t\t LEER VECTOR "<<endl;
	Leer_vect(n, vect,vect_rep_may);
	Imprimir_Arreglo(n, vect);

	cout<<endl<<"\t\t\t ORDENAR VECTOR POR SELECCION ASCENDENTEMENTE "<<endl;
	selectionSort(vect, n);
	Imprimir_Arreglo(n, vect);


	cout<<endl<<"\t\t\t DETERMINAR LOS VALORES REPETIDOS DEL VECTOR "<<endl;
	Determinar_valores_rep(vect, n, vect_rep_may);



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

void Leer_vect(int n, int *vect, int vec_rep[]){

	cout<<endl<<"INGRESE LOS VALORES DEL ARREGLO "<<endl;
	
	for(int i = 0; i < n; i++){
		cout<<"Ingrese el valor en la poscion "<<i<<": "; 
		cin>> *vect++;
		vec_rep[i]=0;
    }							
}

void Imprimir_Arreglo(int n, int *vect){

	cout<<endl<<"\t\t\t El vector es:  "<<endl;
	
	for(int i = 0; i < n; i++){
		cout<<"Del valor ["<<i<<"]: "<<*vect<<endl;
		vect++;
	}

}

int binarySearch(int array[], int x, int low, int high) {
	// Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x) return mid;

    if (array[mid] < x) low = mid + 1;
    else high = mid - 1;
  }

  return -1;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {

	void swap(int *a, int *b); 
  for (int step = 0; step < size - 1; step++) {
    
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
}

void Determinar_valores_rep(int array[], int size,  int vect_rep_may[]){
	int valor_rep = 0;
	int max_index = 0;
	int conta =0;

	for (int i = 0; i < size; i++){

		valor_rep++;
		if(array[i] != array[i+1]){
			cout<<"El valor de "<< array[i]<<" se repite: "<<valor_rep<<" veces"<<endl;
			vect_rep_may[conta] = valor_rep;				//Guardo las rep de cada num del vec
			conta++;
			valor_rep=0;
		}
	}

	//Saco la mayor repeticion 
	int max_number = vect_rep_may[0];
	
	for (int i = 1; i < size; i++) {
        if (vect_rep_may[i] > max_number) {
            max_number = vect_rep_may[i];
        }
    }

	valor_rep=0;

	//Cuales elementos del arreglo ordenado tiene la misma rep.
	for (int i = 0; i < size; i++){

		valor_rep++;
		if(array[i] != array[i+1]){

			if(valor_rep == max_number){
				cout<<"El(los) valores mas repetido(s) son: "<<array[i]<<", "<<max_number<<" veces"<<endl;
			}
			valor_rep=0;
		}
	}

}
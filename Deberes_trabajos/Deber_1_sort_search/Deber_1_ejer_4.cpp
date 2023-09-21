// Permitir el ingreso de dos arreglos de valores enteros, y calcular la unión de los mismos 
// (aplique método de búsqueda lineal y ordenamiento por selección en caso de requerirlos)

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#include <string>

#define EXT 10 			
using namespace std;

int main(){
	// system("color 4d");

	int vect_1[EXT];
    int vect_2[EXT];
    int vec_res[EXT*2];
	int n1=0;
    int n2=0;
	int n3=0;

	//Prototypes
	int LeerN_elementos(int limit_inf, int limit_sup); 
	void Leer_vect(int n, int *vect);
	void Imprimir_Arreglo(int n, int *vect);
    void Union_2_vectores(int n1, int n2, int vect_1[], int *vect_2, int vec_res[], int *n3);
	int Buscar_elemen(int n, int vect[], int elemen);
	void selectionSort(int array[], int size);
	void Vector_no_repetido(int *n, int vect[]);

	//
    
	cout<<endl<<"\t\t\t TAMANIO DEL VECTOR 1"<<endl;
	n1 = LeerN_elementos(1, EXT);
 
	cout<<endl<<"\t\t\t LEER VECTOR 1"<<endl;
	Leer_vect(n1, vect_1);
	Imprimir_Arreglo(n1, vect_1);
	selectionSort(vect_1, n1);

    cout<<endl<<"\t\t\t TAMANIO DEL VECTOR 2"<<endl;
	n2 = LeerN_elementos(1, EXT);

    cout<<endl<<"\t\t\t LEER VECTOR 2"<<endl;
	Leer_vect(n2, vect_2);
	Imprimir_Arreglo(n2, vect_2);
	selectionSort(vect_2, n2);

    cout<<endl<<"\t\t\t UNION DE LOS DOS VECTORES ANTERIORES"<<endl;

	Vector_no_repetido(&n1, vect_1);

	Vector_no_repetido(&n2, vect_2);

	Union_2_vectores(n1, n2, vect_1, vect_2, vec_res, &n3);
	Imprimir_Arreglo(n3, vec_res);

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

int Buscar_elemen(int n, int vect[], int elemen){

	for (int i = 0; i < n; i++){
		if(vect[i] == elemen) return i;
	}
	return -1;
}

void Vector_no_repetido(int *n, int vect[]){

	int elem_rep[EXT];
	for (int i = 0; i < *n; i++){
		elem_rep[i]= vect[i];
	}
	int conta=0;

	for (int i = 0; i < *n; i++){

		if(elem_rep[i] != elem_rep[i+1]){
			vect[conta]= elem_rep[i];
			conta++;
		}
	}

	*n=conta;	
}

void Union_2_vectores(int n1, int n2, int vect_1[], int *vect_2, int vec_res[], int *n3){
    
	int conta=0;
	int pos_rep = 0;
	*n3 = n1;

	for (int i = 0; i < n1+n2; i++){

		if(i<n1) vec_res[i] = vect_1[i];
		
		if(i >= n1){
			pos_rep= Buscar_elemen(n2, vect_1, vect_2[conta]);

			if(pos_rep == -1){
				vec_res[*n3] = vect_2[conta];
				*n3+=1;
			}
			conta++;
		}		
    }

}

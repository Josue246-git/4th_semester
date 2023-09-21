//Generar los factores primos de cada uno de varios números ingresados por el usuario (aplique el algoritmo 
//de búsqueda binaria y ordenamiento por el método de la burbuja, en caso de requerirlo)

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#include <string>

#define EXT 10 			
using namespace std;

int main(){
	// system("color 4d");

	int vect[EXT];
	int n=0;
    int n2=0;

	//Prototypes
	int LeerN_elementos(int limit_inf, int limit_sup); 
	void Leer_vect(int n, int *vect);
	void Imprimir_Arreglo(int n, int *vect);
	void selectionSort(int array[], int size);
	void Determinar_valores_rep(int array[], int size);
	void Generar_factores_num(int num);
	int binarySearch(int array[], int x, int low, int high);
	void Factores_num_ingresado(int n, int vect[]);
	//
    
	cout<<endl<<"\t\t\t TAMANIO DEL VECTOR"<<endl;
	n = LeerN_elementos(1, EXT);
 
	cout<<endl<<"\t\t\t LEER VECTOR "<<endl;
	Leer_vect(n, vect);
	Imprimir_Arreglo(n, vect);

	cout<<endl<<"\t\t\t ORDENAR VECTOR POR SELECCION ASCENDENTEMENTE "<<endl;
	selectionSort(vect, n);
	Imprimir_Arreglo(n, vect);

    cout<<endl<<"\t\t\t GENERAR FACTORES DE CADA VALOR DEL ARRAY "<<endl;	
	for(int i = 0; i < n; i++){
        Generar_factores_num(vect[i]);
	}
	
	cout<<endl<<endl<<"\t\t\t GENERAR FACTORES PRIMOS DE UN VALOR DEL ARRAY"<<endl;
	Factores_num_ingresado(n, vect);

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

void Generar_factores_num(int num){

    cout<<endl<<" Los factores primos de "<<num<<" son: ";
    int factor = 2;

    if((num == 1) || (num == 0)) cout<<" "<<num<<", ";

    while (num > 1){
        if(num % factor == 0){
			
            cout<<" "<<factor<<", ";
            num /= factor;
        }
        else factor++;
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

void Factores_num_ingresado(int n,int vect[]){
	string res;
	int ele_ingresado =0;
	int pos_ele=0;

	do{
		cout<<endl<<"Ingrese el elemento a sacar el factor primo: "; cin >>ele_ingresado;
		pos_ele= binarySearch(vect, ele_ingresado, 0, n-1);

		if(pos_ele != -1) Generar_factores_num(vect[pos_ele]);
		else cout<<"No se ha encontrado el numero ingresado "<<endl;

		cout<<endl<<"Desea continuar con otro numero (SI|NO) "; cin >>res;
	
	}while ((res == "si"));

}
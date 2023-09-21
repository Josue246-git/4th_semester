// Permitir el ingreso de varios números enteros, y proceder a ordenarlos descendentemente en base a la cantidad de 
// dígitos pares que poseen (aplique ordenamiento por inserción en caso de requerirlo)

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>

#define EXT 10 			//Definicon de la extension del arreglo, es una cosnt simbolica Y SIEMPRE CON MAYUSCULAS 
using namespace std;

int main(){
	// system("color 4d");

	int vect[EXT];
    int vect_par[EXT];
	int n=0;
    int n2=0;

	//Prototypes
	int LeerN_elementos(int limit_inf, int limit_sup); //Prototipo de la fucnion, se recomienda porque se trabaja con var. locales 
	void Leer_vect(int n, int *vect);
	void Imprimir_Arreglo(int n, int *vect);// El vector siempre se pasa por referecia, por lo que no es necesario 

    void Sacar_pares_vec(int n, int *vect, int *vect_par, int *n2);
    void insertionSort(int array[], int size); 
	//
    
	cout<<endl<<"\t\t\t TAMANIO DEL VECTOR"<<endl;
	n = LeerN_elementos(1, EXT);
 
	cout<<endl<<"\t\t\t LEER VECTOR "<<endl;
	Leer_vect(n, vect);
	Imprimir_Arreglo(n, vect);


    cout<<endl<<"\t\t\t SACAR LOS VALORES PARES DEL VECTOR  "<<endl;
	Sacar_pares_vec(n, vect, vect_par, &n2);
    Imprimir_Arreglo(n2, vect_par);

    cout<<endl<<"\t\t\t ORDENAIMEINTO DESCENDENTE DEL VECTOR PAR, POR INSERCION  "<<endl;
	insertionSort(vect_par, n2);
    
    Imprimir_Arreglo(n2, vect_par);

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

void Sacar_pares_vec(int n, int *vect, int *vect_par, int *n2){

    for (int i = 0; i < n; i++){
       if((vect[i] % 2) == 0  ) {
            vect_par[*n2] = vect[i];
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
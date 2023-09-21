//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#define EXT 10 			//Definicon de la extension del arreglo, es una cosnt simbolica Y SIEMPRE CON MAYUSCULAS 
using namespace std;

int main(){
	// system("color 4d");

	int vect[EXT];
	int n=0;

	//Prototypes
	int LeerN_elementos(int limit_inf, int limit_sup); //Prototipo de la fucnion, se recomienda porque se trabaja con var. locales 
	void Leer_vect(int n, int *vect);
	void Imprimir_Arreglo(int n, int *vect);// El vector siempre se pasa por referecia, por lo que no es necesario 
	void Insercion(int *n, int *vect);
	void Eliminar_elemento_pos(int *n,int *vect);
	void Eliminar_elemento_valor(int *n,int *vect);
	void bubbleSort(int array[], int size);
	int binarySearch(int array[], int x, int low, int high);

	//

	cout<<endl<<"\t\t\t TAMANIO DEL VECTOR"<<endl;
	n = LeerN_elementos(1, EXT);
 
	cout<<endl<<"\t\t\t LEER VECTOR "<<endl;
	Leer_vect(n, vect);

	Imprimir_Arreglo(n, vect);

	// cout<<endl<<"\t\t\t INSERTAR UN VALOR EN EL VECTOR YA DADO "<<endl;

	// if(n < 10) Insercion(&n, vect); // Para insertar valores en un vector ya dado
	
	// else cout<<"No puede insertarse ya que el vector esta lleno con "<<n<<" elementos"<<endl;


	// Imprimir_Arreglo(n, vect);

	// cout<<endl<<"\t\t\t ELIMINAR UN ELEMENTO DADO SU POS. "<<endl;
	// Eliminar_elemento_pos(&n, vect);

	// Imprimir_Arreglo(n, vect);

	// cout<<endl<<"\t\t\t ELIMINAR UN ELEMENTO DADO EL VALOR "<<endl;
	// Eliminar_elemento_valor(&n, vect);

	// Imprimir_Arreglo(n, vect);

	cout<<endl<<"\t\t\t ORDEN ASCENDENTE DEL VECTROR"<<endl;
	bubbleSort(vect, n-1);

	Imprimir_Arreglo(n, vect);

	cout<<endl<<"\t\t\t BUSQUEDA BINARIA "<<endl;

	int valor_buscar;
	cout<<endl<<"Ingrese el dato a buscar: ";cin>>valor_buscar;

	int pos_valor= binarySearch(vect,valor_buscar, 0, n-1 );

	// cout<<" El valor "<<valor_buscar<<((pos_valor == -1) ? " No " : " SI")<<" Se encuanetra en el vector "<<endl;  //Con operacoin TERNARIA   

	if(pos_valor == -1) cout<<endl<<"No existe el valor en el vector "<<endl;
	else cout<<endl<<"Dato "<<valor_buscar<<" encontrado"<<" en la pos. "<<pos_valor<<endl;

	// system("pause");
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
		cin>> *vect++;							//TAMBIEN SE PUEDE HACAER DE ESTA FORMA PERO CON EL PARENTESIS SE CONTROLA LA JERARQUIA *(vect++)
	}
}

void Imprimir_Arreglo(int n, int *vect){

	cout<<endl<<"\t\t\t El vector es:  "<<endl;
	
	for(int i = 0; i < n; i++){
		cout<<"Del valor ["<<i<<"]: "<<*vect<<endl;
		vect++;
	}

}

void Insercion(int *n, int *vect){
	int new_eleme=0;
	int new_pos =0;

	cout<<endl<<"Ingrese el elemento a insertatr en el vector: "; cin>>new_eleme;
	cout<<endl<<"Ingrese la posicion a insertatr en el vector "<<endl; 
	new_pos = LeerN_elementos(0, *n-1);

	for (int i = *n; i >= new_pos ; i--){ 
		vect[i] = vect[i-1];
	}

	vect[new_pos] = new_eleme;
	*n= *n+1;
}

void Eliminar_elemento_pos(int *n,int *vect){

	int new_pos =0;

	cout<<"Ingrese la posicion a eliminar en el vector "<<endl;
	new_pos = LeerN_elementos(0, *n-1);

	for (int i = new_pos; i <= *n-1 ; i++){

		vect[i] = vect[i+1];
	}
	*n= *n-1;
}

int Buscar_elemen(int n, int vect[], int elemen){

	for (int i = 0; i < n; i++){
		if(vect[i] == elemen) return i;
	}
	return -1;
}

void Eliminar_elemento_valor(int *n,int *vect){    // Si me dan el vallor y no la posicion 
	
	int Buscar_elemen(int n, int vect[], int elemen);
	
	int new_elem =0;
	int new_pos = 0;

	cout<<"Ingrese el elemento a eliminar en el vector: "; cin>>new_elem;
	new_pos = Buscar_elemen( *n, vect, new_elem);

	if(new_pos != -1){

		for (int i = new_pos; i <= *n-1 ; i++){ 
			vect[i] = vect[i+1];
		}

		*n= *n-1;
	}	
}

//Ordenar ascendnte  acendente 
void bubbleSort(int array[], int size) {
    int temp =0;

  for (int step = 0; step < size; ++step) {
    temp = 0;

    // loop to compare array elements
    for (int i = 0; i < size - step; ++i) {

      if (array[i] > array[i + 1]) {
        // swapping elements if elements
        // are not in the intended order
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
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


//*P: Valor apuntado por p
//p++ se incrementa los indices o la posicinoes del vector



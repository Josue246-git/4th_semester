
int Leer_N(){
    int num;

    cout<<"\t(ingresa un valor entero pos.)  "<<endl;
    cin>> num ; 

    if(num < 1){
        num = Leer_N();
    }

    return num;
}

double Leer_N_decimal(){
    double num;

    cout<<"\t(ingresa un valor decimal pos.)  "<<endl;
    cin>> num ; 

    if(num < 1){
        num = Leer_N();
    }

    return num;
}

void Imprimir_Arreglo(int n, int *vect){

	cout<<endl<<"\t\t\t El vector es:  "<<endl;
	
	for(int i = 0; i < n; i++){
		cout<<"Del valor ["<<i+1<<"]: "<<*vect<<endl;
		vect++;
	}
}

void Imprimir_Arregl_reves(int n, int vect[]){

	cout<<endl<<"\t\t\t El vector es:  "<<endl;
	
	for(int i = n; i >= 0 ; i--){
		cout<<"Del valor ["<<i<<"]: "<<vect[i]<<endl;
	}

}

void Pasar_frase_min(char f[]){
    
    for(int i = 0; i < strlen(f); i++) {
        f[i] = tolower(f[i]);
    }
}



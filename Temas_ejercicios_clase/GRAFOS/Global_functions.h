int leerN(){
    int num;

    cout<<"\t(ingresa un valor entero pos.)  "<<endl;
    cin>> num ; 

    if(num <= 0){
        num = leerN();
    }

    return num;
}


int leerN(int li, int ls){		//funcion que ingresa cantidad de valores a procesar
	int x; 			//var de lectura
	
	cout << endl << "Ingrese un valor positivo: ";
	cin >> x;
	
	if ((x < li) || (x > ls)){			//valor no admitido
		x = leerN();	//volver a ingresar un valor 
	}
	return x;		//devolver el valor leido
}

//void Pasar_frase_min(char f[]){
    
//    for(int i = 0; i < strlen(f); i++) {
//        f[i] = tolower(f[i]);
//    }
//}

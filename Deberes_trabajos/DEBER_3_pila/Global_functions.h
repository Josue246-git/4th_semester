int Leer_N(){
    int num;

    cout<<"\t(ingresa un valor entero pos.)  "<<endl;
    cin>> num ; 

    if(num < 0){
        num = Leer_N();
    }

    return num;
}



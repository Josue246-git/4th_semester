
typedef int Tipo;    
//typedef char Tipo;                  //Por el ejercicio 8 descomentar

#define EXT 20

class Pila{
    
    private: 
        Tipo vec[EXT];              //AArregado de los adatos de la pila
        int tope;                   //Dato que me da el tope de la pila 

    public:
        Pila();                 //CONSTRUCTOR 
        
        void set_vec(Tipo val, int pos) ;               //Actualiza el valor de los parametros val y pos
        void set_tope(int val) ;

        Tipo get_vec(int pos);
        int get_tope();

        bool Pila_vacia();                          //V cunado esta vacia o F si no lo esta
        bool Pila_llena();

        void push(Tipo val);
        Tipo pop();

        void limpiar_pila();                //Limpira la pila 

        int tamanio_pila();                 //Calcula rl tamaño de la pila 
        Tipo Cima_pila();

}; 



Pila::Pila(){
    set_tope(-1);                       //La pila se inicializa su tope con valor menos uno,no es cero porque ya tendriam,os un elemento 
}

void Pila::set_vec(Tipo val, int pos){          
    vec[pos] = val;
}

void Pila::set_tope(int val){
    tope = val;
}

Tipo Pila::get_vec(int pos){
    return vec[pos];
}

int Pila::get_tope(){
    return tope;
}


bool Pila::Pila_vacia(){
    return (get_tope() == -1);
}                          

bool Pila::Pila_llena(){
    return(get_tope() == EXT-1);
}


void Pila:: push(Tipo val){             //Cuanod se pushea el valor se sobrescribe 
    if(!Pila_llena()){                      //Aun hay espacio en la pila
        set_tope(get_tope()+1);
        set_vec(val, get_tope());
    }

}

Tipo Pila:: pop(){

    Tipo aux;                           //Almacena el valor de la pos que ocupa el tope
    if(!Pila_vacia()){                     
        aux = get_vec(get_tope());          //Almacena temporalmente el valor a devolver 
        set_tope(get_tope()-1);
        return aux;
    }
}


void Pila:: limpiar_pila(){             //Los daotos anteriores se sobreescriben con los nuevos 
    set_tope(-1);
}

int Pila :: tamanio_pila(){
    return get_tope()+1;
}                 

Tipo Pila:: Cima_pila(){                //Devualeve el valor del tope pila sin eliminarllo como lo hace el pop
    Tipo aux;  
                             
    if(!Pila_vacia()){                     
        aux = get_vec(get_tope());          
        return aux;
    }
}
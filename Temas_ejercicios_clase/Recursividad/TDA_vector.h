//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
//TEMA: Crear un TDA de tipo vector, definiendo una clase

typedef int Tipo;                  //Crear un tipo de base par el array 
#define EXT 30

class vector{

    private: 
        Tipo vect[EXT];              //Declaracion del ateributo vector, con el tipo de dato definido en typedef 
        int num_elem;                   //Numero de elementos ocupados en el vector 

    public: 
        //Prototipos
        vector();                               //Constructor 
        void setVect(Tipo val , int pos);       // se pud escrrbir con camel csae o con union de palabras min y may sin _
                                                //metodo que actualiza el valor del vector
        void setnumElem(int val);               //actualiza el num de elemento s

        Tipo getVect(int pos );                    //Metodo que devuelve el estado del atributo get en la posicion pos
        int getNumElem();                          //Metodo que devuelve el estado del atributo n. de elementos

        ~vector();                           
};

vector :: vector(){

}

void vector :: setVect(Tipo val , int pos){
    vect[pos] = val;
}      
                                        
void vector :: setnumElem(int val){
    num_elem = val;
}               

Tipo vector :: getVect(int pos ){
    return vect[pos];
}

int vector :: getNumElem(){
    return num_elem;
}

vector :: ~vector(){

}   





//NOTA: cuando se usa estructuras deniamicas si se le pone el destructor en la clase, sino no 

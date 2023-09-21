//Gabriel Jimenez 7182 
//Josue Rodriguez 7272
//SE HACE uso de una multilista en donde se ingresa n numeros, de los cuales se saca sus digitos en un vector de listas
// de cada uno de estos se verifica si es capicua o no con el uso de PILAS y se agrega su respectivo promedio de sus valores 
// en una COLA, al finalizar se imprime todos los valores de la COLA con los promedios de cada uno de los numeros

#include <iostream>
using namespace std;
#include "TDA_lista.h"
#include "TDA_cola_circular.h"
#include "TDA_pila.h"

#define FIN 9999
#define EXT 9


int main() {
    //
    void Ingresar_nums(int nums[], int *n1, int aux = 0);
    void GenerarListas(int nums[] , Lista lis[], int n1, int i = 0);
    void ImprimirNumeros(int nums[], int n1, Lista lis[], ColaCircular *c, int i= 0);
    void imprimirColaR(ColaCircular c1);
    //

    int nums[EXT];
    Lista listas[EXT];
    int n = 0;
    Pila p1;
    ColaCircular c1;


    Ingresar_nums(nums, &n);

    cout<<endl<<"El tamaño de vector de numeros es: "<<n<<endl;
    cout << endl << "El vector de numeros es:" << endl;
    GenerarListas(nums, listas, n);

    ImprimirNumeros(nums, n, listas, &c1);

    cout<<endl<<"LA COLA CON LOS PROMEDIOS DE LOS NUMEROS ANTERIORES SON: "<<endl;
    imprimirColaR(c1);

    cout << endl;

    return 0;
}

void Ingresar_nums(int nums[], int *n1, int aux = 0){
    if((aux != FIN) && (*n1 < EXT )){

        cout<<endl<<"Ingrese un numero entero, finalizae con "<<FIN<<" : "; cin>>aux;

        if((aux != FIN) && (*n1 < EXT )){       
            nums[*n1] = aux;
            (*n1)++;    
        }        
        Ingresar_nums(nums, n1, aux);
    }
}       

void Insertar_dig_listas(int aux, Lista *lis){
    
    if(aux!=0){
        lis->insertarAlInicio(aux%10);
        Insertar_dig_listas(aux/10, lis);
    }
}

void Transoformar_lis_pila(Nodo* act, Pila *p){

    if(act != NULL){
        p->push(act->getDato());
        Transoformar_lis_pila(act->getPunt(), p);
    }
}

bool esCapicua(Pila p, Nodo* act, bool ban = false){    

    if(act == NULL){
        return ban;
    }
    else{
        if(p.pop() != act->getDato()){
            ban= true;
        }
    }
    esCapicua(p, act->getPunt(), ban);
}

void GenerarListas(int nums[] , Lista lis[], int n1, int i = 0){
    //
    void Insertar_dig_listas(int aux, Lista *lis);
    void Transoformar_lis_pila(Nodo* act, Pila *p);
    bool esCapicua(Pila p, Nodo* act, bool ban = false);   
    //

    int aux;                
    Pila p1;
    if(i< n1){
        aux = nums[i];
        Insertar_dig_listas(aux, &lis[i]);
        Transoformar_lis_pila(lis[i].getPrimero(), &p1);
        cout <<" El numero: "<<nums[i]<< (esCapicua(p1, lis[i].getPrimero())? " NO " : " SI " )<<" es un palindromo "<<endl;
        GenerarListas(nums, lis, n1, i+1);
    }
}

float Calcular_prom(Nodo* act, int conta = 0, int sum = 0){
    
    if(act!= NULL){
        conta=conta+1;
        sum=sum+act->getDato();
    }
    else return (sum/conta);
    Calcular_prom(act->getPunt(), conta, sum);
}

void Imprimir_digitos(Nodo* act){

    if(act != NULL){
        cout<<endl<<"\t > "<<act->getDato();
        act= act->getPunt();
        Imprimir_digitos(act);
    }
}

void ImprimirNumeros(int nums[], int n1, Lista lis[], ColaCircular *c, int i= 0){
    //
    float Calcular_prom(Nodo* act, int conta = 0, int sum = 0);
    void Imprimir_digitos(Nodo* act);

    //

    if(i < n1){
        cout<<endl<<" > "<<nums[i]<<endl;
        Nodo* act;             
        act = lis[i].getPrimero();
        Imprimir_digitos(act);
        float prom = Calcular_prom(act);
        cout << "\t Promedio de los elementos es: " << prom << endl;
        c->insertar(prom);

        ImprimirNumeros(nums, n1, lis, c, i+1);
    }
}

void imprimirColaR(ColaCircular c1){
    if(!c1.colaVacia()){
        //no hay que cambiar el orden en colas, explota BOOM!
        cout << endl << ">  " << c1.quitar();
        imprimirColaR(c1);
    }
}

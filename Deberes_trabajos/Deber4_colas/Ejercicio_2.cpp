// Intercambiar las posiciones pares con las impares dentro de un TDA Cola ingresado previamente
//Nombre: JOSUE RODRGUEZ (7272)


#include <iostream>
#define EXT 20
#define FIN 9999
#include "TDA_cola_circular.h"
using namespace std;


int main(){

    ColaCircular c;

    //
    void leer_cola(ColaCircular *c);
    void imprimir_cola(ColaCircular c1);
    void sacar_pares_impares(ColaCircular c, ColaCircular *par, ColaCircular *impar, int tam, int conta = 1);
    void intercalar(ColaCircular par, ColaCircular impar, ColaCircular *c, int tam, Tipo ult, int conta=1);
    //

    cout<<endl<<"\t\t\tIngrese elementos a la cola "<<endl;
    leer_cola(&c);

    cout<<endl<<"\t\t\tLos elementos de la cola son: "<<endl;
    imprimir_cola(c);

    cout<<endl<<"\t\t\tLa nueva cola intercalada de pares e impares es: "<<endl;
    ColaCircular par, impar;

    int tam = c.tamanioCola();
    Tipo ult;
    if(tam%2 != 0) {
        tam = c.tamanioCola()-1;
        ult = c.finalCola();
    }
    else ult = 0;

    sacar_pares_impares(c, &par,&impar,tam);            //Saca en dos colas los pares e impares
    
    cout<<endl<<"Elementos pares a intercambiar : "<<endl;
    imprimir_cola(par);

    cout<<endl<<"Elementos impares a intercambiar: "<<endl;
    imprimir_cola(impar);
    cout<<endl;

    c.borrarCola();

    cout<<endl<<"COLA RESULTANTE: "<<endl;
    intercalar(par, impar, &c, par.tamanioCola(), ult);
    imprimir_cola(c);
    
    cout<<endl;
}

void leer_cola(ColaCircular *c){
    Tipo vl;  
    cout<<"Ingrese un valor a poner en la cola, finalice con "<<FIN<<": "; cin >> vl;

    if(vl != FIN ){
        if(!c->colaLlena()){
            c->insertar(vl);
            leer_cola(c);
        }
        else cout<<endl<<"\t\t\t\tLa cola ya esta llena "<<endl;
    }
}

void imprimir_cola(ColaCircular c1){
    if(!c1.colaVacia()){
        cout << endl << ">  " << c1.quitar();
        imprimir_cola(c1);
    }
}


void sacar_pares_impares(ColaCircular c, ColaCircular *par, ColaCircular *impar, int tam, int conta = 1){

    if(conta <= tam){
        if(conta%2 != 0) impar->insertar(c.quitar());
        else par->insertar(c.quitar());
        sacar_pares_impares(c, par, impar, tam, conta+1);
    }   
}

void intercalar(ColaCircular par, ColaCircular impar, ColaCircular *c, int tam, Tipo ult, int conta=1){
    if(conta<= tam+1){
        if(ult != 0 && conta == tam) c->insertar(ult);
        else if (conta <= tam){
            c->insertar(par.quitar());
            c->insertar(impar.quitar());
        }
        intercalar(par, impar, c, tam, ult, conta+1);
    }
}

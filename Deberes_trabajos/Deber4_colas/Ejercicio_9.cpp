//Calcular la diferencia existente entre el N-ésimo elemento de una cola, y los valores precedentes a este
//Nombre: JOSUE RODRGUEZ (7272)

#include <iostream>
#define EXT 20
#define FIN 9999
#include "TDA_cola_circular.h"
using namespace std;


int main(){

    Cola c;

    //
    void leer_cola(Cola *c);
    void imprimir_cola(Cola c1);
    Tipo Esta_en_cola(Cola c,  int n , int cont=1);
    Tipo Dif_antece_n(Cola c, int n, Tipo ele, int cont = 1, Tipo sum=0);
    //

    cout<<endl<<"\t\t\tIngrese elementos a la cola "<<endl;
    leer_cola(&c);

    cout<<endl<<"\t\t\tLos elementos de la cola son: "<<endl;
    imprimir_cola(c);

    int n;
    cout<<endl<<"Ingrese el n-simo termino para hacer el proceso: "; cin>>n;

    cout<<endl<<"\t\t\tDIFERENCIA QUE EXISTE ENTRE  "<<n<<" y sus antecesores "<<endl;
    Tipo ele = Esta_en_cola(c,n);
    
    cout<<endl<<"La difrenencia es: "<<Dif_antece_n(c, n, ele)<<endl;


    cout<<endl;
}

void leer_cola(Cola *c){
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

void imprimir_cola(Cola c1){
    if(!c1.colaVacia()){
        cout << endl << ">  " << c1.quitar();
        imprimir_cola(c1);
    }
}

Tipo Esta_en_cola(Cola c,  int n , int cont=1){
    if(!(c.colaVacia())){
        Tipo val= c.quitar();
        if(cont == n) return val;
        Esta_en_cola(c,n, cont+1);
    }
}

Tipo Dif_antece_n(Cola c, int n, Tipo ele, int cont = 1, Tipo sum=0){
    
    if( !(c.colaVacia())){
        Tipo val = c.quitar();
        if(cont < n){
            sum= sum + val;

        }
        else if(cont == n) {
            cout<<ele <<" - "<<sum<<"(suma de los elementos antecesores)"<<endl;
            return ele-sum;
        }
        Dif_antece_n(c,n,ele,cont+1,sum);
    }
}

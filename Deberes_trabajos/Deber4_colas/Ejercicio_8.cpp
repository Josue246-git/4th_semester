//Calcular la desviación típica existente entre los valores pertenecientes a una cola de valores ingresados
//Nombre: JOSUE RODRGUEZ (7272)

#include <iostream>
#define EXT 20
#define FIN 9999
#include "TDA_cola_circular.h"
#include "math.h"
using namespace std;


int main(){

    ColaCircular c;

    //
    void leer_cola(ColaCircular *c);
    void imprimir_cola(ColaCircular c1);
    double cal_media(ColaCircular c, double tam, double sum=0);
    double cal_des_tip_cola(ColaCircular c, double media, int tam, double sum=0);
    //

    cout<<endl<<"\t\t\tIngrese elementos a la cola "<<endl;
    leer_cola(&c);

    cout<<endl<<"\t\t\tLos elementos de la cola son: "<<endl;
    imprimir_cola(c);

    cout<<endl<<"\t\t\tLA DESVIACION A TIPICA DE LOS ELEMENTOS DE LA COLA ES: "<<endl;
    double tam = c.tamanioCola();

    double media = cal_media(c, tam);
    cout<<endl<<"media: "<<media<<endl;

    cout<<endl<<cal_des_tip_cola(c, media, tam)<<endl;

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

double cal_media(ColaCircular c, double tam, double sum=0){
    if(c.colaVacia()){
        return sum/tam;
    }
    else {
        sum=sum+c.quitar();
        cal_media(c,tam, sum);   
    }
}

double cal_des_tip_cola(ColaCircular c, double media, int tam, double sum=0){

    if(!c.colaVacia()){
        sum = sum + pow(c.quitar()-media,2);
    }
    else {
        return sqrt(sum/tam);
    }
    cal_des_tip_cola(c, media, tam, sum);
}


//Prograsma que permita el ingreso dede una pila de valores y proceda a mul sus elementos por un nuevo valor ingresado 
//NOTA: EVITAR EL USO DE VECTORES 

//Nombre: jOSUE rODRGUEZ

#include <iostream>

typedef int Tipo; 
#define EXT 20
#define fin 9999
#include "TDA_pila.h"

using namespace std;


int main(){
    Pila p;
    //
        void leerPila(Pila *p );              //ingresa datos en la pila, por referiencia ya que el objeto p se modificara 
        void imprimirPila(Pila p);
        bool Comparar_pilas(Pila p, Pila q);
        void Mul_elementos_pila(Pila *p, Tipo n, Pila *q);
        bool Comprobra_ordenamiento_des(Pila p, Tipo cima , bool val= true);
        bool Comprobra_ordenamiento_asc(Pila p, Tipo cima , bool val= true);


    //
    
    //ingreso y visualizacion de datoS: 

    cout<<endl<<"Ingresar e imprimir los valores en la pila 1"<<endl;
    leerPila(&p);
    imprimirPila(p);

    // Tipo n;
    // cout<<endl<<"mULTIPLICAR POR UN NUM INGRESADO LA PILA "<<endl;
    // cout<<"Ingrese el num a mul los elementos: ";cin>>n;
    
    // Pila q;         //Pila auxiliar para gurdar los valores de p aumentados

    // Mul_elementos_pila(&p, n, &q);
    // imprimirPila(p);

    cout<<endl<<"COMPROBAR SI ESTA ORDENADO ASCENDENTE O DESCENDENTEMENTE  "<<endl;
    Tipo cima = p.pop();
    cout<<endl<<"La pila ingresada: "<<(Comprobra_ordenamiento_des(p, cima) ? "SI": "NO")<< " es descendente  "<<endl;
    cout<<endl<<"La pila ingresada: "<<(Comprobra_ordenamiento_asc(p, cima ) ? "SI": "NO")<< " es ascnedente  "<<endl;

    cout<<endl;
    return 0;
}

void leerPila(Pila *p ){          
    Tipo vl;  
    cout<<"Ingrese un valor a apilar, finalice con "<<fin<<": "; cin >> vl;

    if(vl != fin ){
        if(!p->Pila_llena()){
            p->push(vl);
            leerPila(p);
        }
        else cout<<"EROR....... PILA LLENA"<<endl;

    }
}

void imprimirPila(Pila p){

    if(!p.Pila_vacia()){
        cout<<endl<<" > "<<p.pop()<<endl;
        imprimirPila(p);
    }   
}    

void Mul_elementos_pila(Pila *p, Tipo n, Pila *q){

    if(!p->Pila_vacia()){
        
        q->push(p->pop()*n);
        cout<<endl<<"Valor apilado en q: "<<q->Cima_pila()<<endl;
        Mul_elementos_pila(p, n,q);
        p->push(q->pop());
    }
}

        
bool Comprobra_ordenamiento_des(Pila p, Tipo cima , bool val= true){

    if(p.Pila_vacia()){
        return val;
    }
    else{
        Tipo sig = p.pop();
        // cout<<endl<<" n pila: "<<cima<<endl;
        // cout<<endl<<" sig: "<<sig<<endl;
        if(sig > cima) val = false;
        // cout<<endl<< val <<endl;
        cima = sig;
 
        Comprobra_ordenamiento_des(p,cima,val);
    }
}

bool Comprobra_ordenamiento_asc(Pila p, Tipo cima , bool val= true){

    if(p.Pila_vacia()){
        return val;
    }
    else{
        Tipo sig = p.pop();
        if(sig < cima) val = false;
        cima = sig;
        Comprobra_ordenamiento_asc(p,cima,val);
    }
}




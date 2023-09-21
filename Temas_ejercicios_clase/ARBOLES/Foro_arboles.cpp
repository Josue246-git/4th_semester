
//Programa para buscar un elemento y una vez encontrado dicho elemento buscar los divisores de dicho valor en el mismo ABB
//y los elimina tambien del arbol ABB

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"
#define fin 9999

int main(){					

	ArbolBinario a;			
	//
	void leerABB(ArbolBinario *b);		
	void imprimirABB(ArbolBinario a);	
    bool buscar_en_ABB(ArbolBinario a, Tipo aux);
    void Generar_divs(ArbolBinario *a, Tipo aux, Tipo div=1);
	//

    cout<<endl<<"\t\tINGRESO DE NODOS AL ABB"<<endl;
	leerABB(&a);							//llamado a funcion de ingreso AB

    cout<<endl<<"\t\tIMPRIMIR ABB"<<endl;
	imprimirABB(a);						//llamado a funcion que imprime un AB

    cout<<endl<<"\t\tBUSCAR EN EL ABB"<<endl;
    Tipo aux;
    cout<<endl<<"Ingrese un dato a buscar en el ABB: ";cin>>aux;
    cout<<endl<<"El valor "<<aux<<(buscar_en_ABB(a,aux)?" SI ": " NO ")<<" esta en el arbol "<<endl ;

    if(buscar_en_ABB(a, aux)){
        cout<<endl<<"\t\tBUSCAR EN EL ABB, los valores divisores de: "<<aux<<endl;
        Generar_divs(&a,aux);
        imprimirABB(a);
    }
   
	cout<<endl;
}


void leerABB(ArbolBinario *b){

    Tipo aux; 
    cout<<endl<<" Ingrese un valor a incluir en el ABB, finalice con [ "<<fin<<" ]: "; cin>>aux;
    if(aux != fin){
        b->insertarNodo(aux);
        leerABB(b);
    }
    return;	
}


void imprimirABB(ArbolBinario a){
	cout << endl << "IMPRESION SIMPLE DEL ARBOL BINARIO DE BUSQUEDA" << endl;
	a.imprimirABSimple(a.getRaiz());	//llama metodo impresion simple de AB
	
	cout << endl << "IMPRESION JERARQUICA DEL ARBOL BINARIO DE BUSQUEDA " << endl << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);	//llama a metodo impresion con formato jerarquico de AB
}


bool buscar_en_ABB(ArbolBinario a, Tipo aux ){
    if(a.buscarNodo(aux)== NULL) return false;
    else return true;
}

void Generar_divs(ArbolBinario *a, Tipo aux, Tipo div=1){
    if(div <= aux){
        if(aux % div == 0){
            if(buscar_en_ABB(*a,div)) {
                cout<<endl<<"El divisor "<<div<<" SI esta en el arbol "<<endl ;
                a->eliminarNodo(div);
                cout<<endl<<"\t valor eliminado"<<endl;
            }
            else cout<<endl<<"El divisor "<<div<<" NO esta en el ABB."<<endl;
        }
        Generar_divs(a, aux, div+1);
    }
}





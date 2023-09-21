//Permitir el ingreso de varios AB y determinar cuáles, entre ellos 
//son SIMILARES (iguales estructuras, contenidos de los nodos distintas), EQUIVALENTES 
//(similares, y los nodos contienen los mismos valores) y DISTINTOS (con estructuras distintas)
//Josue Rodriguez 7272

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"
#include "TDA_lista.h"


int main(){					

	ArbolBinario a;		
	//
    void Ingresar_varios_AB(int n, ArbolBinario ABs[], int i=0);
    void Verificar_ABs(int n, ArbolBinario ABs[], int i=0);
	//
    int n;
    ArbolBinario* Abinarios;
    cout<<endl<<"Ingresar el numero de AB a realizar los procesos ";cin>>n;
    Abinarios = new ArbolBinario[n]; 
    Ingresar_varios_AB(n, Abinarios);

    cout<<endl<<"VERIFICAR ARBOLES BIN. SI SON: "<<endl;
    Verificar_ABs(n,Abinarios);

	cout<<endl;
}

void leerAB(ArbolBinario *b){
	b->leer();				
}

void imprimirAB(ArbolBinario a){
	cout << endl << "\t\t\tIMPRESION SIMPLE DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABSimple(a.getRaiz());	//llama metodo impresion simple de AB
	
	cout << endl << "\t\t\tIMPRESION JERARQUICA DEL ARBOL BINARIO" << endl << endl;
	a.imprimirABJerarquia(a.getRaiz(), 0);	//llama a metodo impresion con formato jerarquico de AB
}

void verDatosAB(ArbolBinario a){		
	cout << endl << "\t\t\tIMPRESION DE DATOS GENERALES DE ARBOL BINARIO" << endl << endl;
	cout << endl << "El arbol " << (a.esVacio() ? "SI" : "NO") << " esta vacio";
	cout << endl << "El arbol posee " << a.contarNodos(a.getRaiz()) << " nodos";
	cout << endl << "La altura del arbol es " << a.calcularAltura(a.getRaiz());
	cout << endl << "El nodo raiz es: " << a.getRaiz()->getDato();
}

void Ingresar_varios_AB(int n, ArbolBinario ABs[], int i=0){
    //
    void leerAB(ArbolBinario *b);
    void imprimirAB(ArbolBinario a);
    void verDatosAB(ArbolBinario a);		
    //

    if( i < n ){
        cout<<endl<<"LEER ARBOL BINARIO "<<i+1<<endl;
        leerAB(&ABs[i]);							
        verDatosAB(ABs[i]);						
        cout<<endl<<endl<<"IMPRIMIR ARBOL BINARIO "<<i+1<<endl;
        imprimirAB(ABs[i]);	
        Ingresar_varios_AB(n,ABs, i+1);
    }
}

bool ABs_similares(NodoBinario* r1, NodoBinario* r2){
      // Si ambos árboles son nulos, son similares
    if (r1 == nullptr && r2 == nullptr) {
        return true;
    }
    // Si solo uno de los árboles es nulo, no son similares
    if (r1 == nullptr || r2 == nullptr) {
        return false;
    }
    // Verificar si los valores de los nodos son iguales y los subárboles son similares
    return(ABs_similares(r1->getIzq(), r2->getIzq()) &&
           ABs_similares(r1->getDer(), r2->getDer()));
}

bool ABs_equivalentes(NodoBinario* r1, NodoBinario* r2){
    if (r1 == nullptr && r2 == nullptr) {
        return true;
    }
    // Si solo uno de los árboles es nulo, no son similares
    if (r1 == nullptr || r2 == nullptr) {
        return false;
    }
    // Verificar si los valores de los nodos son iguales y los subárboles son similares
    return( (r1->getDato() == r2->getDato()) && ABs_equivalentes(r1->getIzq(), r2->getIzq()) &&
           ABs_equivalentes(r1->getDer(), r2->getDer()));
}

void Veri_demas_ABs(int n, int j, ArbolBinario a, ArbolBinario ABs[]){
    //
    bool ABs_similares(NodoBinario* r1, NodoBinario* r2);
    bool ABs_equivalentes(NodoBinario* r1, NodoBinario* r2);
    //
    if(j<n){
        cout<<"\t\tCON EL AB "<<j+1<<endl;
        cout<<endl<<(ABs_similares(a.getRaiz(),ABs[j].getRaiz())?" SI ": " NO ")<<" son similares (igual estructura, contenido de los nodos distintos) "<<endl ;
        cout<<(ABs_equivalentes(a.getRaiz(),ABs[j].getRaiz())?" SI ": " NO ")<<" son equivalentes (igual estructura y valores de nodos)"<<endl ;
        cout<<(ABs_similares(a.getRaiz(),ABs[j].getRaiz())?" NO ": " SI ")<<" son distintos (iguales estructuras)"<<endl ;

        Veri_demas_ABs(n,j+1,a,ABs);
    }
}

void Verificar_ABs(int n, ArbolBinario ABs[], int i=0){
    //
    void Veri_demas_ABs(int n, int j, ArbolBinario a, ArbolBinario ABs[]);
    //
    if(i<n){
        if(i < n-1) cout<<endl<<"EL AB "<<i+1<<endl;
        Veri_demas_ABs(n,i+1,ABs[i], ABs);

        Verificar_ABs(n,ABs,i+1);
    }
}   

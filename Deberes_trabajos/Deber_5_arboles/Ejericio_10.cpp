//Permitir el ingreso de varios AB y determinar cuáles, entre ellos son LLENOS (no hay nodos 
//que tengan un solo nodo descendiente), COMPLETOS (hasta el nivel n-1 todos los nodos son llenos, 
//y en el nivel n todos los nodos hoja ocupan las posiciones mas a la izquierda) y DEGENERADOS (solo existe un 
//nodo hoja, y todos los demás nodos solo tienen un nodo descendiente)

//Josue Rodriguez 7272

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"

int main(){					

	ArbolBinario a;		
	//
    void Ingresar_varios_AB(int n, ArbolBinario ABs[], int i=0);
	//
    int n;
    ArbolBinario* Abinarios;
    cout<<endl<<"Ingresar el numero de AB a realizar los procesos ";cin>>n;
    Abinarios = new ArbolBinario[n]; 

    cout<<endl<<"VERIFICAR ARBOLES BIN. SI SON: "<<endl;
    Ingresar_varios_AB(n, Abinarios);

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

// Realiza un recorrido en orden en el árbol binario y completa la array `A[]`
void inorder(NodoBinario* root, bool A[], int i){
    if (root == nullptr) return;
    inorder(root->getIzq(), A, 2*i + 1);
    A[i] = true;
    // recurre con índice `2i+2` para el nodo derecho
    inorder(root->getDer(), A, 2*i + 2);
}
 
// Función para verificar si un árbol binario dado es un árbol binario completo o no
bool isComplete(NodoBinario* root, int n){
    void inorder(NodoBinario* root, bool A[], int i);
    // regresa si el árbol está vacío
    if (root == NULL) return true;
    // construye una array booleana auxiliar de tamaño `n`
    bool vect[n];
    // llenar la array `A[]`
    inorder(root, vect, 0);
    // verifica si todas las posiciones en la array están llenas o no
    for (int i = 0; i < n; i++){
        if (!vect[i]) return false;
    }
    return true;
}

bool ABs_degenerado(NodoBinario* r){
    // Si el árbol está vacío o es un nodo hoja, es degenerado
    if (r == NULL || (r->getIzq() == NULL && r->getDer() == NULL)) {
        return true;
    }

    // Si el árbol no es degenerado, entonces uno de los hijos debe ser nulo
    if (r->getIzq() && r->getDer()) {
        return false;
    }

    // Verificar recursivamente los hijos
    if (r->getIzq()) {
        return ABs_degenerado(r->getIzq());
    } else {
        return ABs_degenerado(r->getDer());
    }
}

void Verificar_ABs(ArbolBinario AB, int i){
    cout<<endl<<"EL AB "<<i<<" es:"<<endl;
	cout<<(AB.arbolLleno(AB.getRaiz())?" SI ": " NO ")<<" es un AB LLENO "<<endl ;
	cout<<(isComplete(AB.getRaiz(), AB.contarNodos(AB.getRaiz()))?" SI ": " NO ")<<" es un AB COMPLETO"<<endl ;
    cout<<(ABs_degenerado(AB.getRaiz())?" SI ": " NO ")<<" es un AB DEGENERADO "<<endl<<endl;
}   

void Ingresar_varios_AB(int n, ArbolBinario ABs[], int i=0){
    if( i < n ){
        cout<<endl<<"LEER ARBOL BINARIO "<<i+1<<endl;
        leerAB(&ABs[i]);							
        verDatosAB(ABs[i]);						
        cout<<endl<<endl<<"IMPRIMIR ARBOL BINARIO "<<i+1<<endl;
        imprimirAB(ABs[i]);	
		Verificar_ABs(ABs[i],i+1);
        Ingresar_varios_AB(n,ABs, i+1);
    }
}

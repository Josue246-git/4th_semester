//Determinar el valor numéricamente menor más cercano a la hoja más alejada de la raíz de un AB ingresado
//Josue Rodriguez 7272

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"
#include "TDA_lista.h"
#include <climits>



int main(){					

	ArbolBinario a;	
	Lista l1;	
	//
	void leerAB(ArbolBinario *b);		
	void imprimirAB(ArbolBinario a);	
	void verDatosAB(ArbolBinario a);	
	void verHojasAB(ArbolBinario a);	
	void recorrerAB(ArbolBinario a);	
    int Resolucion_proceso(NodoBinario* r);

	//

    cout<<endl<<"LEER ARBOL BINARIO "<<endl;
	leerAB(&a);							//llamado a funcion de ingreso AB
	verDatosAB(a);						//llamado a impresion datos generales AB

    cout<<endl<<endl<<"IMPRIMIR ARBOL BINARIO "<<endl;
	imprimirAB(a);						
	verHojasAB(a);						
	recorrerAB(a);				

    cout<<endl<<endl<<"VALOR MAYOR DE CADA NIVEL DEL ARBOL BINARIO"<<endl;
	Tipo min = Resolucion_proceso(a.getRaiz());                 //funcion que retorna el valor min buscado
	cout<<endl<<"El valor numericamente menor mas cercano a la hoja mas alejada es: "<<min<<endl;
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

void verHojasAB(ArbolBinario a){		
    cout << endl << "\t\t\tIMPRESION DE NODOS HOJA DE ARBOL BINARIO" << endl << endl;
	a.verHojas(a.getRaiz());			
}

void recorrerAB(ArbolBinario a){		

	cout << endl << "\t\t\tRECORRIDOS DE ARBOL BINARIO" << endl << endl;
	cout << endl << "RECORRIDO EN PREORDEN" << endl;
	a.recorrerEnPreorden();		//llama al metodo correspondiente
	cout << endl << "RECORRIDO EN INORDEN" << endl;
	a.recorrerEnInorden();		//llama al metodo correspondiente
	cout << endl << "RECORRIDO EN POSORDEN" << endl;
	a.recorrerEnPostorden();		//llama al metodo correspondiente
}


// Función para encontrar el valor numéricamente menor en el camino desde la raíz hasta una hoja
void Encontra_min_camino_rh(NodoBinario* root, int minValue, int& result) {
    if (root == NULL) {
        return;
    }
    // Actualizar el valor numéricamente menor si se encuentra un valor más pequeño
    minValue = std::min(minValue, root->getDato());

    // Si es una hoja, actualizar el resultado si se encuentra un camino más largo
    if (root->getIzq() == nullptr && root->getDer() == NULL) {
        result = std::min(result, minValue);
    }

    // Recorrer recursivamente por las ramas izquierda y derecha
    Encontra_min_camino_rh(root->getIzq(), minValue, result);
    Encontra_min_camino_rh(root->getDer(), minValue, result);
}

// Función para encontrar la hoja más alejada de la raíz en el árbol
NodoBinario* hoja_mas_alejada(NodoBinario* root, int level, int& maxLevel) {
    if (root == NULL) {
        return NULL;
    }
    // Si es una hoja, verificar si es la hoja más alejada
    if (root->getIzq() == NULL && root->getDer() == NULL) {
        if (level > maxLevel) {
            maxLevel = level;
            return root;
        }
    }

    // Recorrer recursivamente por las ramas izquierda y derecha
    NodoBinario* leftLeaf = hoja_mas_alejada(root->getIzq(), level + 1, maxLevel);
    NodoBinario* rightLeaf = hoja_mas_alejada(root->getDer(), level + 1, maxLevel);

    // Retornar la hoja más alejada entre las ramas izquierda y derecha
    if (leftLeaf != NULL && rightLeaf != NULL) {
        return (level > maxLevel) ? leftLeaf : rightLeaf;
    } else if (leftLeaf != NULL ) {
        return leftLeaf;
    } else {
        return rightLeaf;
    }
}

// Función para encontrar el valor numéricamente menor más cercano a la hoja más alejada de la raíz
int Resolucion_proceso(NodoBinario* r) {
    //
    void Encontra_min_camino_rh(NodoBinario* root, int minValue, int& result);
    NodoBinario* hoja_mas_alejada(NodoBinario* root, int level, int& maxLevel);
    //
    int maxLevel = 0;
    NodoBinario* deepestLeaf = hoja_mas_alejada(r, 0, maxLevel);
	cout<<endl<<"Del camino hacia la hoja: "<<deepestLeaf->getDato()<<endl;
    int result = INT_MAX;
    Encontra_min_camino_rh(r, INT_MAX, result);
    return result;
}


//Imprimir todos los caminos que van desde la raíz a cada una de las hojas de un AB ingresado
//Josue Rodriguez 7272

using namespace std;
#include <iostream>
#include "TDA_arbol_binario.h"
#include "TDA_lista.h"
#include "TDA_cola.h"

int main(){					

	ArbolBinario a;	
    Cola c1;	
	//
	void leerAB(ArbolBinario *b);		
	void imprimirAB(ArbolBinario a);	
	void verDatosAB(ArbolBinario a);	
	void verHojasAB(ArbolBinario a);	
	void recorrerAB(ArbolBinario a);	
	void imprimirCamino_hojas_raiz(NodoBinario* r, Cola cam);
	//

    cout<<endl<<"LEER ARBOL BINARIO "<<endl;
	leerAB(&a);							//llamado a funcion de ingreso AB
	verDatosAB(a);						//llamado a impresion datos generales AB

    cout<<endl<<endl<<"IMPRIMIR ARBOL BINARIO "<<endl;
	imprimirAB(a);						
	verHojasAB(a);						
	recorrerAB(a);				

    cout<<endl<<endl<<"IMPRIMIR CAMINOS DE RAIZ A CADA UNA DE LAS HOJAS "<<endl;
    imprimirCamino_hojas_raiz(a.getRaiz(), c1 );


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


void Imprimir_camino(Cola c1, int tam){	//imprime los datos de la cola con la ruta o camino 

    if(!c1.colaVacia()){
        cout<<c1.quitar();
        if(tam > 1 ) cout<<"->";
        Imprimir_camino(c1, tam-1);
    }
}

void imprimirCamino_hojas_raiz(NodoBinario* r, Cola cam){
	//
	void Imprimir_camino(Cola c1, int tam);
	//
    if(r == NULL) return ;
    cam.insertar(r->getDato());

    if((r->getDer() == NULL) &&(r->getIzq() == NULL)){
        cout<<"Para la hoja: "<<r->getDato()<<endl;
        Imprimir_camino(cam,cam.tamanioCola());
        cout<<endl;
    }   

    imprimirCamino_hojas_raiz(r->getIzq(), cam);
    imprimirCamino_hojas_raiz(r->getDer(), cam);

    cam.quitar();
}

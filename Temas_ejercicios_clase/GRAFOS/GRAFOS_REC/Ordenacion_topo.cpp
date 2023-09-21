// grafo2.cpp
// GESTIONA UN GRAFO CON MATRIZ DE ADYACENCIA

using namespace std;
#include <iostream>
#include "GrafoLista.h"
#include "RecorreGrafo.h"
#include "CaminoMinimo.h"
#include "utilidades.h"


void dfsTopologicalSort(int nodo, GrafoLista g, bool visitado[], Pila* pila) {
    visitado[nodo] = true;

    // Realizar DFS en los nodos adyacentes no visitados
    for (int i = 0; i < g.getNumVerts(); ++i) {
        if (g.adyacente(nodo, i) && !visitado[i]) {
            dfsTopologicalSort(i, g, visitado, pila);
        }
    }

    // Agregar el nodo al tope de la pila
    pila->push(nodo);
}

void ordenamiento_topologico(int ordenamiento[], GrafoLista g) {
    int n = g.getNumVerts();
    bool visitado[n];
    for (int i = 0; i < n; i++) visitado[i] = false;
    Pila pila;
    
    // Realizar DFS para todos los nodos no visitados
    for (int i = 0; i < n; ++i) {
        if (!visitado[i]) {
            dfsTopologicalSort(i, g, visitado, &pila);
        }
    }

    // Construir el orden topológico a partir de la pila
    int j = 0;
    while (!pila.Pila_vacia()) {
        ordenamiento[j] = pila.get_tope();
        pila.pop();
        j++;
    }
}


int main(){
	GrafoLista g;						//declara un grafo para manipular las clases
	int n;								//cantidad de vertices a crear
	//
	GrafoLista ingresarVertices(int n1);
	void ingresarArcos(GrafoLista *g);			//añade arcos => grafos no valorados
	void ingresarArcosValor(GrafoLista *g);		//añade arcos => grafos valorados
	void imprimirGrafo(GrafoLista g);			//prototipo de la funcion que presenta los vertices del grafo
	//

	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO";
	n = leerN(1,20);					//lectura de cantidad de vertices del grafo
	cin.ignore();                       //para los strings para que no acepte el enter
	
	g = ingresarVertices(n);				//llamado a funcion de ingreso de los datos referentes al grafo
	ingresarArcos(&g);					//llamado a la funcion que ingresa los arcos del grafo
	//ingresarArcosValor(&g);				//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafo(g);					//llamado a la funcion que imprime la matriz de adyacencia
	
	int nv = g.getNumVerts();
	int ordenamiento[nv];
    for (int i = 0; i < n; i++) ordenamiento[i] = 0;

    ordenamiento_topologico(ordenamiento, g);

	cout<<endl <<"ORDENAMIENTO TOPOLOGICO "<<endl;
    for (int nodo : ordenamiento) {
        cout << nodo << " ";
    }
	cout << endl;
}

GrafoLista ingresarVertices(int n1){				//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux; 
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcos(GrafoLista *g){				//funcion que ingresa los datos de los arcos de un grafo
	int nv = g -> getNumVerts();
	int na;
	TipoG aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Valor del Vertice Destino: ";
			cin >> aux; 
			g -> setArco(x.getDato(), aux);
		}
	}
}

void ingresarArcosValor(GrafoLista *g){			//funcion que ingresa los datos de los arcos de un grafo incluido peso
	int nv = g -> getNumVerts();
	int na;
	int peso;						//peso del arco
	TipoG aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g -> getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Identificador del Vertice Destino: ";
			cin >> aux; 
			cout << endl << "PESO DEL ARCO";
			peso = leerN(0, 100);
			cin.ignore();
			g -> setArco(x.getDato(), aux, peso);
		}
	}
}

void imprimirGrafo(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	int na;
	TipoG aux;
	cout << endl << "===============================================";
	cout << endl << "M A T R I Z     D E    A D Y A C E N C I A";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
	
		for (int j = 0; (j < nv); j++){
			if (g.adyacente(i,j)){
				Vertice x = g.getVertice(j);
				cout << endl << "\t\t--->" << x.getDato();
			}
		}
	}
	cout << endl << "===============================================";
	cout << endl;
}

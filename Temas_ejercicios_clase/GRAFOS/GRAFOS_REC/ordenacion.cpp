// grafo2.cpp
// GESTIONA UN GRAFO CON MATRIZ DE ADYACENCIA

using namespace std;
#include <iostream>
#include <vector>
#include "GrafoMatriz.h"
#include "RecorreGrafo.h"
#include "CaminoMinimo.h"
#include "utilidades.h"



void ordenamientoTopologico(int** matrizAdyacencia, int n, GrafoMatriz g) {

    int gradosEntrada[n];
    vector<int> ordenamiento;

    for (int i = 0; i < n; i++){
        gradosEntrada[i] = 0;
    }
    
    Cola cola;

    // Paso 1: Calcular grados de entrada
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            gradosEntrada[j] += matrizAdyacencia[i][j];
        }
    }

    // Paso 2: Encolar vértices con grado de entrada cero
    for (int i = 0; i < n; i++) {
        if (gradosEntrada[i] == 0) {
            cola.insertar(i);
        }
    }

    // Paso 4: Procesar la cola
    while (!cola.colaVacia()) {
        int vertice = cola.frenteCola();
        cola.quitar();
        ordenamiento.push_back(vertice);

        for (int k = 0; k < n; k++) {
            if (matrizAdyacencia[vertice][k] == 1) {
                gradosEntrada[k]--;
                if (gradosEntrada[k] == 0) {
                    cola.insertar(k);
                }
            }
        }
    }

    // Paso 5: Verificar si se completó el ordenamiento topológico
    if (ordenamiento.size() != n) {
         cout << "El grafo contiene un ciclo. No se puede realizar el ordenamiento topológico." << endl;
    } else {
        cout << "Ordenamiento topológico:"<<endl;
        for (int j = 0; j < n; j++) {
            cout << " " << ordenamiento[j];
        }
        cout << endl;
		for (int j = 0; j < n; j++) {
            cout << " " << g.getVertice(ordenamiento[j]).getDato() ;
        }
        cout << endl;
    }
}


int main(){
	GrafoMatriz g;						//declara un grafo para manipular las clases
	int n;								//cantidad de vertices a crear
	//
	GrafoMatriz ingresarVertices(int n1);
	void ingresarArcos(GrafoMatriz *g);			//añade arcos => grafos no valorados
	void ingresarArcosValor(GrafoMatriz *g);		//añade arcos => grafos valorados
	void imprimirGrafo(GrafoMatriz g);			//prototipo de la funcion que presenta los vertices del grafo
	//

	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO";
	n = leerN(1,20);					//lectura de cantidad de vertices del grafo
	cin.ignore();                       //para los strings para que no acepte el enter
	
	g = ingresarVertices(n);				//llamado a funcion de ingreso de los datos referentes al grafo
	ingresarArcos(&g);					//llamado a la funcion que ingresa los arcos del grafo
	//ingresarArcosValor(&g);				//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafo(g);					//llamado a la funcion que imprime la matriz de adyacencia
	
    int **m_ad = g.getMatrizAdayacencia();
    int nv = g.getNumVerts();

    for (int i = 0; i < nv; i++){
        for (int j = 0; j < nv; j++){
            if(m_ad[i][j] == 0xffff) m_ad[i][j] = 0;
        }
    }
    
    ordenamientoTopologico(m_ad, nv, g);

	cout << endl;
}

GrafoMatriz ingresarVertices(int n1){				//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoMatriz a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el Valor del vertice No. " << (i+1) << ": ";
		cin >> aux; 
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcos(GrafoMatriz *g){				//funcion que ingresa los datos de los arcos de un grafo
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

void ingresarArcosValor(GrafoMatriz *g){			//funcion que ingresa los datos de los arcos de un grafo incluido peso
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

void imprimirGrafo(GrafoMatriz g){				//funcion que presenta los datos del grafo
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

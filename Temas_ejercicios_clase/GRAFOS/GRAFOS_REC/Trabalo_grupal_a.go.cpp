
using namespace std;
#include <iostream>
#include "utilidades.h"
#include "RecorreGrafo.h"
#include "CaminoMinimo.h"


GrafoMatriz ingresarVertices(int n1){			//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoMatriz a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el nombre del vertice No. " << (i+1) << ": ";
		std::getline(cin, aux);
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcosValor(GrafoMatriz *g){		//funcion que ingresa los datos de los arcos de un grafo incluido peso
	int nv = g->getNumVerts();
	int na;
	int peso;									//peso del arco
	TipoG aux;

	for (int i = 0; (i < nv); i++){
		Vertice x = g->getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE ARCOS DE SALIDA DEL VERTICE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Identificador del Vertice Destino: ";
			std::getline(cin, aux);
			cout << "PESO DEL ARCO";
			peso = leerN(0, 100);
			cin.ignore();
			g->setArco(x.getDato(), aux, peso);
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


void calcularCaminoMinimo(GrafoMatriz g){		//funcion que calcula el camino minimo
	TipoG aux1;
	int * v1;									//vector de distancias minimas
	int orig;									//numero de vertice origen
	
	cout << endl << "================================================";
	cout << endl << "APLICACION ALGORITMO DIJKSTRA: CAMINOS MINIMOS CON ORIGEN EN VERTICE " << aux1;
	cout << endl << "================================================";
	cout << endl << "Identificador del Vertice de Origen: ";
	std::getline(cin, aux1);
	
	CaminoMinimo c(g, g.getNumVertice(aux1));	//instancia la clase camino minimo para posibilitar su uso
	
	c.Dijkstra(g, g.getNumVertice(aux1));		//llama al metodo que aplica alg. Dijkstra				
	v1 = c.OdistanciaMinima();					//recibe el vector de distancias minimas desde ese origen

	cout << endl << "COSTOS MINIMOS DESDE EL VERTICE " << aux1;
	for (int i = 0; i < g.getNumVerts(); i++){
		cout << endl << "==> Hasta Vertice [" << g.getVertice(i).getDato() << "]: ";
		if (v1[i] == 0xFFFF){
			cout << "INALCANZABLE";
		} else {
			cout << v1[i];
		}
	}
	cout << endl << "================================================";
}


int main(){

	GrafoMatriz g;								//declara un grafo para manipular las clases
	int n;										//cantidad de vertices a crear

    cout << endl << "===============================================";
	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);					//llamado a funcion de ingreso de los datos referentes al grafo
	
	ingresarArcosValor(&g);						//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafo(g);							//llamado a la funcion que imprime la matriz de adyacencia
	
    //IMPLEMENTACION DEL ALGORITMO DIJKSTRA
	calcularCaminoMinimo(g);					//llamado a la funcion que calcula el camino minimo
	
	cout << endl;

}


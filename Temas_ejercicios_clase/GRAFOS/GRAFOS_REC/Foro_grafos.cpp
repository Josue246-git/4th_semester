// Grafo5.cpp
// Implementa recorrido de grafos

using namespace std;
#include <iostream>
#include "utilidades.h"
#include "RecorreGrafo.h"
#include "CaminoMinimo.h"

int main(){

	GrafoMatriz g;								//declara un grafo para manipular las clases
	int n;										//cantidad de vertices a crear
	
	GrafoMatriz ingresarVertices(int n1);
	void ingresarArcos(GrafoMatriz *g);			//añade arcos => grafos no valorados
	void ingresarArcosValor(GrafoMatriz *g);	//añade arcos => grafos valorados
	void imprimirGrafo(GrafoMatriz g);			//prototipo de la funcion que presenta los vertices del grafo
	// int ** matrizCaminos(GrafoMatriz g);		//prototipo de la funcion que implementa el algoritmo de Warshall
	void ingresar_paradas(GrafoMatriz g );


	cout << endl << "CANTIDAD DE PARADAS DE LA CIUDAD: ";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);					//llamado a funcion de ingreso de los datos referentes al grafo
	ingresarArcosValor(&g);						//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafo(g);							//llamado a la funcion que imprime la matriz de adyacencia
	
	//matrizCaminos(g);							//llamado a la funcion que genera la matriz de caminos
	
	ingresar_paradas(g);
						//llamado a la funcion que calcula el camino minimo
	
	cout << endl;

}

GrafoMatriz ingresarVertices(int n1){			//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoMatriz a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el nombre de la parada No. " << (i+1) << ": ";
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
	cout << endl << "\t\t\tCONEXIONES ENTRE PARADAS: ";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "parada No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
	
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

void ingresar_paradas(GrafoMatriz g ){
	
	void calcularCaminoMinimo(GrafoMatriz g);

	calcularCaminoMinimo(g);
	cout<<endl<<"Desea ver la ruta mas corta con otra parada ?"<<endl;
	cout<<"1. Si"<<endl;
	cout<<"2. No"<<endl;
	int op;
	cin>>op;
	if(op == 1){
		ingresar_paradas(g);
	}else{
		return;
	}
}

void calcularCaminoMinimo(GrafoMatriz g){		//funcion que calcula el camino minimo
	TipoG aux1;
	int * v1;									//vector de distancias minimas
	int orig;									//numero de vertice origen
	
	cout << endl << "================================================";
	cout << endl << "APLICACION ALGORITMO DIJKSTRA: CAMINOS MAS CORTOS ENTRE TODAS LAS PARADAS ";
	
	cout << endl << "Identificador del Vertice de Origen: ";
	cin>>aux1;
	
	CaminoMinimo c(g, g.getNumVertice(aux1));	//instancia la clase camino minimo para posibilitar su uso
	
	c.Dijkstra(g, g.getNumVertice(aux1));		//llama al metodo que aplica alg. Dijkstra				
	v1 = c.OdistanciaMinima();					//recibe el vector de distancias minimas desde ese origen

	cout << endl << "COSTOS MINIMOS DESDE LA PARADA " << aux1;

	for (int i = 0; i < g.getNumVerts(); i++){
		cout << endl << "==> Hasta LA PARADA [" << g.getVertice(i).getDato() << "]: ";
		if (v1[i] == 0xFFFF){
			cout << "INALCANZABLE";
		} else {
			cout << v1[i];
		}
	}
	cout << endl << "================================================";
}




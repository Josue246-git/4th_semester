//Determinar los vértices que se encuentran a exactamente N arcos de distancia del 
//vértice V (n y V deben ser ingresados por el usuario).

//JOSUE RODRIGUEZ 7272

using namespace std;
#include <iostream>
#include "utilidades.h"
#include "RecorreGrafo.h"
#include "CaminoMinimo.h"



int main(){

	GrafoLista g;								//declara un grafo para manipular las clases
	int n;										//cantidad de vertices a crear
	//
	GrafoLista ingresarVertices(int n1);
	void ingresarArcos(GrafoLista *g);			//añade arcos => grafos no valorados
	void ingresarArcosValor(GrafoLista *g);	//añade arcos => grafos valorados
	void imprimirGrafo(GrafoLista g);			//prototipo de la funcion que presenta los vertices del grafo
	void imprimirLista(GrafoLista g);
	void verticesExactDistance(GrafoLista grafo, int n, int v);
	//


	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);					
	ingresarArcos(&g);						
	//ingresarArcosValor(&g);						
	imprimirGrafo(g);							
	int num, ver ; 

	cout<<"Ingrese el numero de arcos a realizar el proceso, "<<" debe ser un valor entre ["<<1<<" , "<<g.getMaxVerts()<<" ]"<<endl;
	num = leerN(1,g.getMaxVerts());

	cout<<"Ingrese el numero del vertice a localizar, "<<" debe ser un valor entre ["<<0<<" , "<<g.getNumVerts()-1<<" ]"<<endl;
	ver = leerN(0,g.getNumVerts()-1);

	cout<<endl<<"Llegar a: "<<(g.getVertice(ver)).getDato()<<" con "<<num<<" arcos de distancia"<<endl;

	verticesExactDistance(g, num, ver);

	cout << endl;

}

GrafoLista ingresarVertices(int n1){			//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el nombre del vertice No. " << (i+1) << ": ";
		std::getline(cin, aux);
		a.nuevoVertice(aux);
	}
	return a;
}

void ingresarArcos(GrafoLista *g){				//funcion que ingresa los datos de los arcos de un grafo
	int nv = g->getNumVerts();
	int na;
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
			g->setArco(x.getDato(), aux);
		}
	}
}

void ingresarArcosValor(GrafoLista *g){		//funcion que ingresa los datos de los arcos de un grafo incluido peso
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

void imprimirLista(GrafoLista g){				//funcion que presenta los datos del grafo
	int nv = g.getNumVerts();
	NodoG* actual;								//apunta al nodo actual de la lista

	cout << endl << "ELEMENTOS CONTENIDOS EN LA LISTA";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";

		ListaG vlista = g.listaAdyacencia(i);
		actual = vlista.getPrimero();			//copiar la direccion del primer nodo de la lista

		while (actual != NULL){					//repetir el ciclo mientras haya nodos en la lista
			cout << endl << "> " << actual->getDato() << " > " << actual->getPeso();	//visualiza el contenido del nodo actual de la lista
			actual = actual->getPunt();			//apuntador actual avanza al siguiente nodo
		}
	}
}

//Impleta el algoritmo de recorrido en profundidad para poder localizarl los vertices con n arcos de distancia
void dfsExactDistance(GrafoLista grafo, int nodo, int distancia, bool visitado[]) {
    if (distancia == 0) {
        cout << (grafo.getVertice(nodo)).getDato() << " ";
        return;
    }

    visitado[nodo] = true;

    for (int i = 0; i < grafo.getNumVerts(); ++i) {
        if (grafo.adyacente(nodo, i) && !visitado[i]) {
            dfsExactDistance(grafo, i, distancia - 1, visitado);
        }
    }
}

void verticesExactDistance(GrafoLista grafo, int n, int v) {
	//
	void dfsExactDistance(GrafoLista grafo, int nodo, int distancia, bool visitado[]);
	//
    int numVertices = grafo.getMaxVerts();
    bool visitado[numVertices];
	for (int i = 0; i < numVertices; i++) visitado[i] = false;
	
    cout << "Vértices a exactamente " << n << " arcos de distancia del vértice " << v << ": ";

    dfsExactDistance(grafo, v, n, visitado);

    cout << endl;
}

//Ejercicio 4 grafos 

//JOSUE RODRIGUEZ 7272

using namespace std;
#include <iostream>
#include "utilidades.h"
#include "RecorreGrafo.h"
#include "CaminoMinimo.h"
#include "unordered_set"



int main(){

	GrafoLista g;								//declara un grafo para manipular las clases
	int n;										//cantidad de vertices a crear
	//
	GrafoLista ingresarVertices(int n1);
	void ingresarArcos(GrafoLista *g);			//añade arcos => grafos no valorados
	void ingresarArcosValor(GrafoLista *g);	//añade arcos => grafos valorados
	void imprimirGrafo(GrafoLista g);			//prototipo de la funcion que presenta los vertices del grafo
	void imprimirLista(GrafoLista g);
	void recorrerGrafo(GrafoLista g);  
	//

    cout<<endl<<"\t\t\tGRAFO QUE MODELA EL RECORRIDO DE UN MUSEO "<<endl;

	cout << endl << "CANTIDAD DE SALAS DEL MUSEO : ";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);					
	ingresarArcos(&g);						
	//ingresarArcosValor(&g);						
	imprimirGrafo(g);	
    						
	recorrerGrafo(g);

	cout << endl;
}

GrafoLista ingresarVertices(int n1){			//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el nombre de la especie No. " << (i+1) << ": ";
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
		cout << endl << "CANTIDAD DE DEPREDADORES DE LA ESPECIE";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Identificador de la especie Destino: ";
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
		cout << endl << "ESPECIE No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
	
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
		cout << endl << "Especie No. " << x.getNum()+1 << " - " << x.getDato() << " - ";

		ListaG vlista = g.listaAdyacencia(i);
		actual = vlista.getPrimero();			//copiar la direccion del primer nodo de la lista

		while (actual != NULL){					//repetir el ciclo mientras haya nodos en la lista
			cout << endl << "> " << actual->getDato() << " > " << actual->getPeso();	//visualiza el contenido del nodo actual de la lista
			actual = actual->getPunt();			//apuntador actual avanza al siguiente nodo
		}
	}
}


//Se impleemnta un recorrido en profundidad de un GRAFO para poder obtener las salas adyacentes y un posible recorrido
int* recorrerProfLa(GrafoLista g, int v, int* ult_sala) {     
    int w;    
	Pila pila;
	int* m;

	if (v < 0 || v > g.getNumVerts()) return NULL; 					//Vertice de origen no existe
	
	m = new int[g.getNumVerts()];

	for (int i = 0; i < g.getNumVerts(); i++) {
		m[i] = 0xffff;
	}

	m[v] = 0; 														// vértice origen queda marcado
	pila.push(v);
	while (!pila.Pila_vacia()) {
		int cw;
		cw = pila.pop();
		w = cw;
		cout << "SALA [" << w << "] => " << g.getVertice(w).getDato() << " => visitado" << endl;
        *ult_sala = w;
		// inserta en la pila los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++) {
			if (g.getArco(w,u) && m[u] == 0xffff) { 					// se marca vértice u con número de arcos hasta el
				m[u] = m[w] +1;
				pila.push(u);
			}
		}
	}
	pila.limpiar_pila();
	return m;
	
}

void recorrerGrafo(GrafoLista g){				//funcion que implementa recorrido de un grafo
	//
	int* recorrerProfLa(GrafoLista g, int v, int* ult_sala);
	//
	TipoG aux;
	
	cout << endl << "Identificador de la sala para inicializar el recorrido: ";
	std::getline(cin, aux);
    int ult_sala=0;
	cout << endl << "RECORRIDO EL MUSEO POR VERTICES ADYACENTES, PARITIENDO DE LA SALA: "<<aux<<"\n" << endl;
    int* recorrido = recorrerProfLa(g, g.getNumVertice(aux), &ult_sala);
    
	cout << endl << "RECORRIDO EL MUSEO, REGRESANDO POR VERTICENTES ADYACENTES DESDE LA SALA FINAL: "<<g.getVertice(ult_sala).getDato()<<"\n" << endl;
    recorrerProfLa(g, recorrido[ult_sala],&ult_sala);

	cout << endl << "===============================================";
}

//Determinar el vértice que posee el mayor grado de entrada y el vértice que 
//posee el mayor grado de salida dentro de un grafo ingresado por el usuario.

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
	void Encontrar_may_entrada(int vec[], int nv);
	void Encontrar_may_salida(int vec[], int nv);
	void Calcular_grado_entrada(GrafoLista g, int gEnt[], int nv);
	void Calcular_grado_salida(GrafoLista g, int gSal[], int nv);
	//


	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);					
	ingresarArcos(&g);						
	//ingresarArcosValor(&g);						
	imprimirGrafo(g);							
	
	cout<<"CONOCER EL VERTICE CON MAYOR GRADO DE ENTRADA Y DE SALIDA: "<<endl;
	int nv = g.getNumVerts();
	int gEnt[nv] ;                   //vector de grados de entrada por cada vertice 
	for (int n = 0; n < nv; n++){
		gEnt[n] = 0;
	}
	
	Calcular_grado_entrada(g,gEnt, nv);
	Encontrar_may_entrada(gEnt, nv);

	imprimirLista(g);
	int gSal[nv] ;                   //vector de grados de entrada por cada vertice 
	for (int n = 0; n < nv; n++){
		gSal[n] = 0;
	}
	Calcular_grado_salida(g,gSal, nv);
	Encontrar_may_salida(gSal, nv);
	
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

void Encontrar_may_entrada(int vec[], int nv){
	int mayor = 0;
	int pos = 0;
	for (int i = 0; i < nv; i++){
		if (vec[i] > mayor){
			mayor = vec[i];
			pos = i;
		}
	}
	cout << endl << "El vertice con mayor grado de entrada es: " << pos+1 << " con grado: " << mayor;
}

void Encontrar_may_salida(int vec[], int nv){
	int mayor = 0;
	int pos = 0;
	for (int i = 0; i < nv; i++){
		if (vec[i] > mayor){
			mayor = vec[i];
			pos = i;
		}
	}
	cout << endl << "El vertice con mayor grado de salida es: " << pos+1 << " con grado: " << mayor;
}

void Calcular_grado_entrada(GrafoLista g, int gEnt[], int nv){
	Tipo aux;
    NodoG* actual;
	cout << endl << "===============================================";
	cout << endl << "Grados de entrada: ";

	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);
		cout << endl << "Vertice No. " << x.getNum()+1 << " - " << x.getDato() << " - ";

        for (int j = 0; j < nv; j++){
            ListaG vlista = g.listaAdyacencia(j);
            if(vlista.buscarValorEnLista(x.getDato())!= NULL){
                gEnt[i] = gEnt[i]+1;
            }
        }
        cout<<endl<<"Grado entrada: "<<gEnt[i];
	}
	cout << endl << "===============================================";
	cout << endl;
}

void Calcular_grado_salida(GrafoLista g, int gSal[], int nv){
	NodoG* actual;								//apunta al nodo actual de la lista
	
	for (int i = 0; (i < nv); i++){
		Vertice x = g.getVertice(i);

		ListaG vlista = g.listaAdyacencia(i);
		actual = vlista.getPrimero();			//copiar la direccion del primer nodo de la lista
		while (actual != NULL){					//repetir el ciclo mientras haya nodos en la lista
			gSal[i] = gSal[i]+1;
			actual = actual->getPunt();			//apuntador actual avanza al siguiente nodo
		}
	}
}

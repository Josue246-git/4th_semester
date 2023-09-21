//Ejercicio 3 grafos 

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
	bool verificaTeoria6Grados(GrafoLista grafo);
	//

    cout<<endl<<"\t\t\tGRAFO QUE MODELA LA TEORIA DE LOS 6 GRADOS DE SEPARACION"<<endl;

	cout << endl << "CANTIDAD DE PERSONAS A TRATAR: ";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);					
	ingresarArcos(&g);						
	//ingresarArcosValor(&g);						
	imprimirGrafo(g);	
    						
	if (verificaTeoria6Grados(g))  cout << "Se cumple la teoría de los 6 grados de separación." << endl;
    else  cout << "No se cumple la teoría de los 6 grados de separación." << endl;

	cout << endl;
}

GrafoLista ingresarVertices(int n1){			//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoLista a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el nombre de la persona No. " << (i+1) << ": ";
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
		cout << endl << "Pesona No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
		cout << endl << "CANTIDAD DE PERSONAS CONOCIDAS ";
		na = leerN(0, 10);
		cin.ignore();
		
		for (int j = 0; (j < na); j++){
			cout << endl << "Identificador de la Pesona conocida: ";
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
		cout << endl << "PERSONA No. " << x.getNum()+1 << " - " << x.getDato() << " - ";
	
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
		cout << endl << "Persona No. " << x.getNum()+1 << " - " << x.getDato() << " - ";

		ListaG vlista = g.listaAdyacencia(i);
		actual = vlista.getPrimero();			//copiar la direccion del primer nodo de la lista

		while (actual != NULL){					//repetir el ciclo mientras haya nodos en la lista
			cout << endl << "> " << actual->getDato() << " > " << actual->getPeso();	//visualiza el contenido del nodo actual de la lista
			actual = actual->getPunt();			//apuntador actual avanza al siguiente nodo
		}
	}
}

//Se hace uso de un recorrido en ancchura modificado, para comprobar el grado de separacion maximo entre cada par de vertices 
bool verificaTeoria6Grados(GrafoLista grafo) {
    int numPersonas = grafo.getNumVerts();

    for (int i = 0; i < numPersonas; ++i) {
        bool visitado[numPersonas];
        for (int i = 0; i < numPersonas; i++) visitado[i]=false;
        
        Cola cola;
        int gradoSeparacion = 0;

        visitado[i] = true;
        cola.insertar(i);
        cout<<"Para la persona: "<<i<<endl;
        while (!cola.colaVacia()) {
            int tamCola = cola.tamanioCola();

            while (tamCola > 0) {
                int persona = cola.frenteCola();
                int cw = cola.quitar();
                cout << "Vertice [" << cw << "] => " << grafo.getVertice(cw).getDato() << " => visitado" << endl;
                for (int j = 0; j < numPersonas; ++j) {
                    if (grafo.adyacente(persona,j ) && !visitado[j]) {
                        visitado[j] = true;
                        cola.insertar(j);
                    }
                }
                tamCola--;
            }

            gradoSeparacion++;

            if (gradoSeparacion > 6) {
                return false;
            }
        }
    }

    return true;
}
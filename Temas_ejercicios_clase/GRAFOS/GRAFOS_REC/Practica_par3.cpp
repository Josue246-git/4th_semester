// 7272 JOSUE RODRIGUEZ
//practica 3

using namespace std;
#include <iostream>
#include "utilidades.h"
#include "RecorreGrafo.h"
#include "CaminoMinimo.h"


int main(){

	GrafoMatriz g;								//declara un grafo para manipular las clases
	int n;										//cantidad de vertices a crear
	//
	GrafoMatriz ingresarVertices(int n1);
	void ingresarArcos(GrafoMatriz *g);			//añade arcos => grafos no valorados
	void ingresarArcosValor(GrafoMatriz *g);	//añade arcos => grafos valorados
    void recorrerGrafo(GrafoMatriz g );
	void imprimirGrafo(GrafoMatriz g);			//prototipo de la funcion que presenta los vertices del grafo
	//

	cout << endl << "CANTIDAD DE VERTICES DEL GRAFO";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);					//llamado a funcion de ingreso de los datos referentes al grafo
	ingresarArcos(&g);						//llamado a la funcion que ingresa los arcos del grafo
	//ingresarArcosValor(&g);						//llamado a la funcion que ingresa los arcos valorados del grafo
	imprimirGrafo(g);							//llamado a la funcion que imprime la matriz de adyacencia

    recorrerGrafo(g );						

	cout << endl;
}

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

void ingresarArcos(GrafoMatriz *g){				//funcion que ingresa los datos de los arcos de un grafo
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

void recorrerGrafo(GrafoMatriz g){				//funcion que implementa recorrido de un grafo

	TipoG aux;
    //
	int* recorrerAnchura(GrafoMatriz g, int v, Cola* c1);
	int* recorrerProf(GrafoMatriz g, int v, Cola* c2);
	void Imprimir_cola(Cola c, GrafoMatriz g);
	bool Cola_ordendad_Asc(Cola q, GrafoMatriz g);
	bool Cola_ordendad_desc(Cola q, GrafoMatriz g);
	//

    Cola c1;
    Cola c2;
    
	
	cout << endl << "Identificador del Vertice de Origen: ";
	std::getline(cin, aux);
	
	cout << endl << "===============================================";
	cout << endl << "RECORRIDO DEL GRAFO EN ANCHURA\n" << endl;
	recorrerAnchura(g, g.getNumVertice(aux), &c1);

	
	cout << endl << "===============================================";
	cout << endl << "RECORRIDO DEL GRAFO EN PROFUNDIDAD\n" << endl;
	recorrerProf(g, g.getNumVertice(aux), &c2);

	cout << endl << "===============================================";
    cout<<endl<<"Lista de vertices del recorrido en anchura"<<endl;
	Imprimir_cola(c1, g);

    cout<<endl<<"Lista de vertices del recorrido en profundidad"<<endl;
	Imprimir_cola(c2, g);


    cout<<endl<<"COMPROBAR SI LOS VERTICES ESTAN ORDENADOS ASC O DESC EN EL REC ANCHURA "<<endl<<endl;
    cout<<" La lista de vertices "<<(Cola_ordendad_Asc(c1, g)? "SI ":"NO ")<<" esta ordenada ASCENDENTEMENTE"<<endl;
    cout<<" La lista de vertices "<<(Cola_ordendad_desc(c1, g)? "SI ":"NO ")<<" esta ordenada DESCENDENTEMENTE"<<endl;


    cout<<endl<<"COMPROBAR SI LOS VERTICES ESTAN ORDENADOS ASC O DESC EN EL REC PROFUNDIDAD "<<endl<<endl;
    cout<<" La lista de vertices "<<(Cola_ordendad_Asc(c2, g)? "SI ":"NO ")<<" esta ordenada ASCENDENTEMENTE"<<endl;
    cout<<" La lista de vertices "<<(Cola_ordendad_desc(c2, g)? "SI ":"NO ")<<" esta ordenada DESCENDENTEMENTE"<<endl;

}

int* recorrerAnchura(GrafoMatriz g, int v, Cola* c1){	//recorre grafo en anchura recibiendo numero de vertice inicial
	int w;
	Cola cola;
	int* m;

	if (v < 0 || v > g.getNumVerts()) {
		return m;			//Vértice no existe
	}
	m = new int[g.getNumVerts()];
								// inicializa los vértices como no marcados
	for (int i = 0; i < g.getNumVerts(); i++) {	//inicializa las claves de cada vertice
		m[i] = 0xffff;
	}
	m[v] = 0; // vértice origen queda marcado

	cola.insertar(v);

	while (!cola.colaVacia()) {				//mientras haya elementos en la cola
		int cw;
		cw = cola.quitar();					//extrae un vertice de la cola
		w = cw;
		cout << "Vertice [" << w << "] => " << g.getVertice(w).getDato() << " => visitado" << endl;
		c1->insertar(w);
		// inserta en la cola los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++){
			if (g.getArco(w,u) && m[u] == 0xffff) { 	// se marca vértice u con número de arcos hasta el
				m[u] = m[w] +1;	
				cola.insertar(u);
			}
		}
	}
	return m;
}

int* recorrerProf(GrafoMatriz g, int v, Cola* c2) {  		//recorre grafo en profundidad recibiendo numero de vertice inicial
	int w;
	Pila pila;
	int* m;

	if (v < 0 || v > g.getNumVerts()) {
		return m; 													//Vertice de origen no existe
	}
	m = new int[g.getNumVerts()];
	// inicializa los vértices como no marcados
	for (int i = 0; i < g.getNumVerts(); i++) {
		m[i] = 0xffff;
	}
	m[v] = 0; // vértice origen queda marcado
	pila.push(v);
	while (!pila.Pila_vacia()) {
		int cw;
		cw = pila.pop();
		w = cw;
		cout << "Vertice [" << w << "] => " << g.getVertice(w).getDato() << " => visitado" << endl;
		c2->insertar(w);
		// inserta en la pila los adyacentes de w no marcados
		for (int u = 0; u < g.getNumVerts(); u++) {
			if (g.getArco(w,u) != 0xffff  && m[u] == 0xffff) { // se marca vértice u con número de arcos hasta el
				m[u] = m[w] +1;
				pila.push(u);
			}
		}
	}
	return m;
}

void Imprimir_cola(Cola c, GrafoMatriz g){
    if(!c.colaVacia()){
        cout<<endl<<" > "<<g.getVertice(c.quitar()).getDato()<<endl;
        Imprimir_cola(c, g);
    }
}

bool Cola_ordendad_Asc(Cola q, GrafoMatriz g) {
    if (q.colaVacia() || q.tamanioCola() == 1) {
        return true; // Si la cola está vacía o tiene un solo elemento, está ordenada ascendentemente.
    }

	TipoG prev = g.getVertice(q.quitar()).getDato();

    while (!q.colaVacia()) {
        TipoG act = g.getVertice(q.quitar()).getDato();

        if (prev > act) return false; // Si encontramos un elemento que rompe el orden ascendente, la cola no está ordenada.

        prev = act;
    }

    return true; // Si llegamos aquí, la cola está ordenada desc.
}

bool Cola_ordendad_desc(Cola q, GrafoMatriz g) {
    if (q.colaVacia() || q.tamanioCola() == 1) {
        return true; // Si la cola está vacía o tiene un solo elemento, está ordenada desc.
    }

	TipoG prev = g.getVertice(q.quitar()).getDato();

    while (!q.colaVacia()) {
        TipoG act = g.getVertice(q.quitar()).getDato();

        if (prev < act) return false; // Si encontramos un elemento que rompe el orden desc, la cola no está ordenada.

        prev = act;
    }

    return true; // Si llegamos aquí, la cola está ordenada desc.
}



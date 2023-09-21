//Ejercicio 3 grafos 

//JOSUE RODRIGUEZ 7272

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
	void imprimirGrafo(GrafoMatriz g);			//prototipo de la funcion que presenta los vertices del grafo
	void imprimirLista(GrafoMatriz g);
	int com_depredador_sustituto(GrafoMatriz g, int especie);
	int com_prezas_amenazas(GrafoMatriz g, int especie);
	//

    cout<<endl<<"\t\t\tGRAFO QUE MODELA UN ECOSISTEMA "<<endl;

	cout << endl << "CANTIDAD DE ESPECIES EN EL ECOSISTEMA: ";
	n = leerN(1,20);							//lectura de cantidad de vertices del grafo
	cin.ignore();
	
	g = ingresarVertices(n);					
	ingresarArcos(&g);						
	//ingresarArcosValor(&g);						
	imprimirGrafo(g);	
    						
	cout<<"\t\t\tCOMPROBACOIN DE QUE CADA ESPECIE CUMPLE QUE: "<<endl;
	for (int i = 0; i < g.getNumVerts(); i++){

		cout<<endl<<"\tPARA LA ESPECIE: "<<g.getVertice(i).getDato()<<endl;

		if(com_depredador_sustituto(g, i) == 1) cout<<"Sus depredadores SI tiene sustituto";
		else if(com_depredador_sustituto(g,i) == 2) cout<<"Sus depredadores NO tienen sustituto y desapareceran ";
		else cout<<endl<<"No tiene depredadores";

		cout<<endl;
		if(com_prezas_amenazas(g,i)==1) cout<<"Sus prezas SI siguen teniendo amenaza"<<endl;
		else if(com_prezas_amenazas(g,i)==2) cout<<"Sus prezas NO tienen amenazas y estas creceran descontroladamente "<<endl;
		else cout<<endl<<"No tiene prezas"<<endl;
	}
	

	cout << endl;
}

GrafoMatriz ingresarVertices(int n1){			//funcion que ingresa los datos de los vértices de un grafo
	TipoG aux;
	GrafoMatriz a(n1);

	for (int i = 0; (i < n1); i++){
		cout << endl << "Ingrese el nombre de la especie No. " << (i+1) << ": ";
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


int** transponerMatriz(int** matriz, int filas, int columnas) {
    int** matrizTranspuesta = new int*[columnas];
    for (int i = 0; i < columnas; ++i) {
        matrizTranspuesta[i] = new int[filas];
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matrizTranspuesta[j][i] = matriz[i][j];
        }
    }

    return matrizTranspuesta;
}

int com_depredador_sustituto(GrafoMatriz g, int especie){
	//
	int** transponerMatriz(int** matriz, int filas, int columnas);
	//

	int** m_ad = g.getMatrizAdayacencia();
	int nv = g.getNumVerts();
	int** m_in = transponerMatriz(m_ad, nv, nv);
	int conta = 0;
	bool aux = true;

	for (int i = 0; i < nv; i++){
		if(m_ad[especie][i] == 1){

			for (int j = 0; j < nv; j++){
				if(m_in[i][j] == 1){
					conta++;
				}
				if(conta != 1) aux = false;
			}
			if(aux == true) return 2;
			else return 1;
		}
		else return 0;
	}

}

int com_prezas_amenazas(GrafoMatriz g, int especie){
	//
	int** transponerMatriz(int** matriz, int filas, int columnas);
	//
	int** m_ad = g.getMatrizAdayacencia();
	int nv = g.getNumVerts();
	int** m_in = transponerMatriz(m_ad, nv, nv);
	int conta = 0;
	bool aux = true;

	for (int i = 0; i < nv; i++){
		if(m_in[especie][i] == 1){

			for (int j = 0; j < nv; j++){
				if(m_ad[i][j] == 1){
					conta++;
				}
				if(conta != 1) aux = false;
			}
			if(aux == true) return 2;
			else return 1;
		}
		else return 0;
	}
}

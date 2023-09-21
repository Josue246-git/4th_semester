#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void ordenamientoTopologico(vector<vector<int>>& matrizAdyacencia) {
    int n = matrizAdyacencia.size();
    vector<int> gradosEntrada(n, 0);
    vector<int> ordenamientoTopologico;
    queue<int> cola;

    // Paso 1: Calcular grados de entrada
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            gradosEntrada[j] += matrizAdyacencia[i][j];
        }
    }

    // Paso 2: Encolar vértices con grado de entrada cero
    for (int i = 0; i < n; i++) {
        if (gradosEntrada[i] == 0) {
            cola.push(i);
        }
    }

    // Paso 4: Procesar la cola
    while (!cola.empty()) {
        int vertice = cola.front();
        cola.pop();
        ordenamientoTopologico.push_back(vertice);

        for (int i = 0; i < n; i++) {
            if (matrizAdyacencia[vertice][i] == 1) {
                gradosEntrada[i]--;
                if (gradosEntrada[i] == 0) {
                    cola.push(i);
                }
            }
        }
    }

    // Paso 5: Verificar si se completó el ordenamiento topológico
    if (ordenamientoTopologico.size() != n) {
        cout << "El grafo contiene un ciclo. No se puede realizar el ordenamiento topológico." << endl;
    } else {
        cout << "Ordenamiento topológico:";
        for (int i = 0; i < n; i++) {
            cout << " " << ordenamientoTopologico[i];
        }
        cout << endl;
    }
}

int main() {
    // Ejemplo de uso
    vector<vector<int>> matrizAdyacencia = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    ordenamientoTopologico(matrizAdyacencia);

    return 0;
}

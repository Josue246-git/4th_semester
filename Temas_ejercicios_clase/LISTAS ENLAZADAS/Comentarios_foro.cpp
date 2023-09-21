


void imprimirLista(Lista& l) {
    cout << "\nNotas ingresadas:" << endl;
    Nodo* nodo = l.getPrimero();
    while (nodo != NULL) {
        cout << nodo->getDato() << endl;
        nodo = nodo->getPunt();
    }
}

float calcularPromedio(Lista& l) {
    float sumatoria = 0;
    int contador = 0;

    Nodo* nodo = l.getPrimero();
    while (nodo != NULL) {
        sumatoria += nodo->getDato();
        contador++;
        nodo = nodo->getPunt();
    }

    return sumatoria / contador;
}
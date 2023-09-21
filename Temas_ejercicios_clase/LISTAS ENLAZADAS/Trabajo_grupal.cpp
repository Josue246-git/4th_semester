//Gabriel Jimenez 7182 
//Josue Rodriguez 7272
//Promedio de una lista previamente ingresada
#include <iostream>
#include "Lista.h"

#define FIN 0
#define EXT 9

using namespace std;



int main() {
    int nums[EXT];
    Lista listas[EXT];
    int n = 0;
    Pila p1;

    void Ingresar_nums(int nums[], int *n1);       
    void ImprimirNumeros(int nums[], int n1, Lista lis[]);
    void GenerarListas(int nums[], Lista lis[], int n1);
    float CalcularPromedioRecursivo(Nodo* act, int suma, int contador,Pila mayor);
    float CalcularPromedio(Lista lis,Pila p1);
    void leerPilaR(Pila *p1);
    void amplificarPila(Pila *p1,Tipo a,Pila *aux);
    void imprimirPilaR(Pila p1);
    
    bool comprobarAscendente(Pila *p1,Pila *aux);
    bool comprobarDescendente(Pila *p1,Pila *aux);

    void ordenamientoInsercion(Pila p1);
    void ordenamientoPorInsercion(Pila& pila);

    Ingresar_nums(nums, &n);

    cout << endl << "El vector de numeros es:" << endl;
    GenerarListas(nums, listas, n);

    ImprimirNumeros(nums, n, listas);
    imprimirPilaR(p1);

    cout << endl;

    return 0;
}

void Ingresar_nums(int nums[], int *n1) {
    int aux;

    do {
        cout << endl << "Ingrese un numero entero, finalice con " << FIN << ": ";
        cin >> aux;

        if ((aux != FIN) && (*n1 < EXT)) {
            nums[*n1] = aux;
            (*n1)++;
        }
    } while ((aux != FIN) && (*n1 < EXT));
}

void ImprimirNumeros(int nums[], int n1, Lista lis[],Pila p1) {
    cout << endl << "VALORES PROCESADOS" << endl;

    for (int i = 0; i < n1; i++) {
        cout << endl << " > " << nums[i] << endl;
        Nodo* act = lis[i].getPrimero();

        while (act != nullptr) {
            cout << endl << "\t > " << act->getDato();
            act = act->getPunt();
        }

        cout << "\t Promedio: " << CalcularPromedio(lis[i],p1) << endl;
    }
}

void GenerarListas(int nums[], Lista lis[], int n1) {
    int aux;

    for (int i = 0; i < n1; i++) {
        aux = nums[i];

        do {
            lis[i].insertarAlInicio(aux % 10);
            aux = aux / 10;
        } while (aux != 0);
    }
}

float CalcularPromedioRecursivo(Nodo* act, int suma, int contador,Pila p1) {
    if (act == nullptr) {
        if (contador > 0) {
            p1.push(static_cast<float>(suma) / contador);
            return static_cast<float>(suma) / contador;
            
        } else {
            return 0.0;
        }
    }

    suma += act->getDato();
    contador++;
    
    return CalcularPromedioRecursivo(act->getPunt(), suma, contador,p1);
}

float CalcularPromedio(Lista lis,Pila p1) {
    return CalcularPromedioRecursivo(lis.getPrimero(), 0, 0,p1);
}

void insertarOrdenado(Pila& pila, Tipo elemento) {
    if (pila.pilaVacia() || elemento >= pila.cimaPila()) {
        pila.push(elemento);
    } else {
        Tipo temp = pila.pop();
        insertarOrdenado(pila, elemento);
        pila.push(temp);
    }
}

bool comprobarAscendente(Pila *p1,Pila *aux){
    if(!p1->pilaVacia()){
        aux->push(p1->pop()); 
        if((aux->cimaPila()<=p1->cimaPila())){
            return true;
        }
        return false;
        comprobarAscendente(p1,aux);
    }

}
bool comprobarDescendente(Pila *p1,Pila *aux){
    if(!p1->pilaVacia()){
        aux->push(p1->pop()); 
        if((aux->cimaPila()>=p1->cimaPila())){
            return true;
        }
        return false;
        comprobarDescendente(p1,aux);
    }

}
void leerPilaR(Pila *p1){
    Tipo vl;
    cout<<endl<<"Ingrese el valor a apilar. Finalice con: "<<FIN<<": ";
    cin>>vl;
    if (vl!=FIN){
        p1->push(vl);
        leerPilaR(p1);

    }
}
void imprimirPilaR(Pila p1){
    if(!p1.pilaVacia()){
        cout<<endl<<"> "<<p1.pop()<<endl;
        imprimirPilaR(p1);
    }
}
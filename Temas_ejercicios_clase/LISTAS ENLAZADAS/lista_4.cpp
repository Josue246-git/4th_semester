using namespace std;
#include<iostream>
#include"ListaString.h"
#defineFIN"fff" // marcador de final de lectura

void ingresarLista(Lista *l1);
void imprimirLista(Lista l1);
void buscarEnLista(Lista l1);
void eliminarDeLista(Lista *l1);
int contarNodos(Nodo *act);

int main()
{
    system("color 80");
    Lista l;

    cout << "Programa de administracion de nombres" << endl;
    cout << "-------------------------------------------------------" << endl;

    int opcion;
    do
    {
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Agregar un nombre" << endl;
        cout << "2. Imprimir la lista de nombres" << endl;
        cout << "3. Buscar un nombre" << endl;
        cout << "4. Eliminar un nombre" << endl;
        cout << "5. Contar el numero de nombres" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese su opcion: " << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            ingresarLista(&l);
            break;
        case 2:
            imprimirLista(l);
            break;
        case 3:
            buscarEnLista(l);
            break;
        case 4:
            eliminarDeLista(&l);
            break;
        case 5:
            cout << "La lista contiene " << contarNodos(l.getPrimero()) << " nombres" << endl;
            break;
        case 6:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }
    } while (opcion != 6);

    cout << endl;
    system("pause");
}

void ingresarLista(Lista *l1)
{
    string nombre;
    cout << "Ingrese un nombre para agregar a la lista. Finalice con [" << FIN << "] :" << endl;
    cin >> nombre;

    if (nombre != FIN)
    {
        l1->insertarAlFinal(nombre);
        ingresarLista(l1);
    }
}

void imprimirLista(Lista l1)
{
    cout << "Lista de nombres:" << endl;
    Nodo *act = l1.getPrimero();

    while (act != NULL)
    {
        cout << "> " << act->getDato() << endl;
        act = act->getPunt();
    }
}

void buscarEnLista(Lista l1)
{
    string nombre;
    cout << "Ingrese el nombre a buscar: ";
    cin >> nombre;

    Nodo *enc = l1.buscarElemento(nombre);

    if (enc != NULL)
    {
        cout << "El nombre " << nombre << " se encuentra en la lista" << endl;
    }
    else
    {
        cout << "El nombre " << nombre << " no se encuentra en la lista" << endl;
    }
}

void eliminarDeLista(Lista *l1)
{
    string nombre;
    cout << "Ingrese el nombre a eliminar: ";
    cin >> nombre;

    if (l1->eliminarNodo(nombre))
    {
        cout << "Nombre eliminado satisfactoriamente. Nueva lista generada:" << endl;
        imprimirLista(*l1);
    }
    else
    {
        cout << "Error al eliminar el nombre " << nombre << endl;
    }
}

int contarNodos(Nodo *act)
{
    if (act != NULL)
    {
        return 1 + contarNodos(act->getPunt());
    }
    return 0;
}
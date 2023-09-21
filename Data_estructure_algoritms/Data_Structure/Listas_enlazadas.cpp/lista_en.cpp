#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Nodo{ 
    int dato;
    struct Nodo *siguiente;
};

bool Lista_vacia(Nodo *& lista){
    return ((lista == NULL)? false : true);
}

void insertar_nodo_lista(Nodo *& lista, int n ){

    Nodo * nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = n;

    if (lista == NULL) {
        // La lista está vacía, el nuevo nodo se inserta al principio
        lista = nuevo_nodo;
        nuevo_nodo->siguiente = NULL;

    } else if (n <= lista->dato) {
        // El nuevo nodo se inserta al principio de la lista
        nuevo_nodo->siguiente = lista;
        lista = nuevo_nodo;

    } else {
        Nodo *aux1 = lista;
        Nodo *aux2 = NULL;

        while ((aux1 != NULL ) && (aux1-> dato <= n)){
            aux2 = aux1;
            aux1 = aux1->siguiente;
        }

        // El nuevo nodo se inserta en medio o al final de la lista
        aux2->siguiente = nuevo_nodo;
        nuevo_nodo->siguiente = aux1;
    }

    cout<<"Elemento "<<nuevo_nodo->dato<<" ingresado a la lista"<<endl;
}

void Mostrar_elementos(Nodo *&lista){

    Nodo * actual = new Nodo;
    actual = lista;

    while(actual != NULL){
        cout<<actual->dato<<" -> ";
        actual = actual-> siguiente;
    }
}

void Buscar_elementos(Nodo *&lista, int n){
    Nodo * actual = new Nodo;
    actual = lista;
    bool encontrado = false; 

    while((actual != NULL )&& (actual->dato <= n) ){
        cout<<actual->dato<<" -> ";
        if(actual-> dato == n){
            encontrado = true;
            actual = NULL;
        }
        else actual = actual-> siguiente;
    }

    if(encontrado == false){
        cout<<"No se ha encontrado el elemento "<<endl;
    }
}

void Eliminar_elemento_lista(Nodo *&lista, int n){

    if(lista != NULL){
        Nodo *aux_borrar= lista;
        Nodo *anterior = NULL;

        while((aux_borrar != NULL)&&(aux_borrar->dato != n)){
            anterior = aux_borrar;
            aux_borrar= aux_borrar->siguiente;
        }
        if(aux_borrar == NULL){
            cout<<"No se encontro dicho dato para ser borrado"<<endl;
        }
        else if(anterior == NULL){
            lista= lista->siguiente;
            delete aux_borrar;
        }
        else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}

void Eliminar_toda_lista(Nodo *&lista, int &n){

    while (lista != NULL){
        Nodo *aux = lista;
        n = aux -> dato;
        lista = aux -> siguiente;
        delete aux;
        cout<<n<<" -> "<<endl;
    }
}

void menu(){
        cout<<"\t MENU LISTA ENLAZADA"<<endl;
        cout<<"Ingresa un elemento "<<endl<<endl;
        cout<<"1. Para agregar elementos"<<endl;
        cout<<"2. Para ver elementos"<<endl;
        cout<<"3. Para buscar un elemento "<<endl;
        cout<<"4. Para eliminar un elemento "<<endl;
        cout<<"5. Para eliminar todo la damn lista "<<endl;
        cout<<"6. Salir"<<endl;
}

int main(){ 
    int n=0, opc;
    Nodo *lista = NULL;

    do{
        do{
            system("cls");
            menu();
            cin >> opc;
        }while(opc>6 || opc <=0);

        n=0;
        switch (opc){
            case 1:
                cout<<"\t\t\t INGRESAR ELEMENTOS A LA LISTA"<<endl;
                cout<<"Ingrese un elemento de la lista: "; cin>>n;
                insertar_nodo_lista(lista, n);
                system("pause");
                break;
            
            case 2:
                cout<<"\t\t\t VER ELEMENTOS DE LA LISTA"<<endl;
                if(Lista_vacia(lista)==false) Mostrar_elementos(lista);
                else cout<<"Debe haber elementos para poder ejecutar la funcionalidad"<<endl;
                system("pause");
                break;

            case 3:
                cout<<"\t\t\t BUSCAR UN ELEMENTOS DE LA COLA"<<endl;
                if(Lista_vacia(lista)==false){
                    cout<<"Ingrese un elemento a buscar en la lista: "; cin>>n;
                    Buscar_elementos(lista,n );
                }
                else cout<<"Debe haber elementos para poder ejecutar la funcionalidad"<<endl;
                system("pause");
                break;

            case 4:
                cout<<"\t\t\t ELIMINAR UN ELEMENTO DE LA LISTA"<<endl;
                if(Lista_vacia(lista)==false){
                    cout<<"Ingrese un elemento a eliminar en la lista: "; cin>>n;
                    Eliminar_elemento_lista(lista,n );
                    cout<<n<<" Eliminado"<<endl;
                }
                else cout<<"Debe haber elementos para poder ejecutar la funcionalidad"<<endl;
                system("pause");
                break;

            case 5:
                cout<<"\t\t\t ELIMINAR TODOS LOS ELEMENTOS DE LA LISTA"<<endl;
                if(Lista_vacia(lista)==false){
                    Eliminar_toda_lista(lista, n);
                    cout<<"Lista Eliminado"<<endl;
                }

                else cout<<"Debe haber elementos para poder ejecutar la funcionalidad"<<endl;
                system("pause");
                break;
        } 

    }while(opc!= 6 );

}



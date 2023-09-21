#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//ARBOL: ESTRUCTURA DE DATOS NO LIENAL, DINAMICAS 
struct Nodo{ 
    int dato;
    Nodo * der;
    Nodo * izq;
};

Nodo *crearNodo(int n ){
    Nodo *nuevo_nodo = new Nodo();
    
    nuevo_nodo->dato =n;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->der = NULL;
    return nuevo_nodo;
}

int cont=0;
void Insertar_nodo_arbol(Nodo *&arbol, int n){
    
    if(arbol == NULL){
        Nodo * nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    else{
        int raiz = arbol->dato;

        if(raiz > n) Insertar_nodo_arbol(arbol->izq, n);

        else Insertar_nodo_arbol(arbol->der, n);
    }
}


void Mostrar_Arbol(Nodo *arbol, int contador){

    if(arbol != NULL){
        Mostrar_Arbol(arbol->der, contador+1);

        for(int i=0; i<contador; i++){

            cout<<"   ";
        }
        cout<<arbol->dato<<endl;

        Mostrar_Arbol(arbol->izq, contador+1);
    }
}

//n= elemento que se quiere buscar
bool Buscar_nodo_arbol(Nodo *arbol, int n){
    if(arbol == NULL){
        return false;
    }
    else if(arbol->dato == n){
        return true;
    }
    else if(arbol->dato > n){
        return Buscar_nodo_arbol(arbol->izq, n);
    }
    else if(arbol->dato < n){
        return Buscar_nodo_arbol(arbol->der, n);
    }
}   

bool Arbol_vacio(Nodo *arbol){
    return ((arbol != NULL)? false : true);
}

void menu(){
        cout<<"\t MENU ARBOL"<<endl;
        cout<<"Ingresa una opcion "<<endl<<endl;
        cout<<"1. Para agregar dato al arbol"<<endl;
        cout<<"2. Para mostrar arbol"<<endl;
        cout<<"3. Buscar un nodo enel arbol  "<<endl;
        cout<<"4. Recorrer arbol  "<<endl;
        cout<<"5. Para eliminar todo la damn arbol "<<endl;
        cout<<"6. Salir"<<endl;
}

int main(){ 

 int n=0, opc, conta =0;

    Nodo *arbol = NULL;

    do{
        do{
            system("cls");
            menu();
            cin >> opc;
        }while(opc>6 || opc <=0);

        n=0;
        switch (opc){
            case 1:
                cout<<"\t\t\t INGRESAR ELEMENTOS AL ARBOL"<<endl;
                cout<<"Ingrese un elemento de la lista: "; cin>>n;
                
                Insertar_nodo_arbol(arbol, n);
                system("pause");
                break;

            case 2:
            
                cout<<"\t\t\t VER ELEMENTOS DEL ARBOL"<<endl;
                if(Arbol_vacio(arbol)== false) Mostrar_Arbol(arbol, conta);
                else cout<<"Arbol vacion, ingrese elementos"<<endl;
                system("pause");
                break;

            case 3:
                cout<<"\t\t\t BUSCAR UN ELEMENTOS EN EL ARBOL"<<endl;
                if(Arbol_vacio(arbol)==false){

                    cout<<"Ingrese un elemento a buscar en el arbol: "; cin>>n;
                    if(Buscar_nodo_arbol(arbol, n) == true) cout<<"Elemento "<< n<<" encontrado"<<endl;
                    else cout<<"No se ha encontrado"<<endl;
                }
                else cout<<"Debe haber elementos para poder ejecutar la funcionalidad"<<endl;
                system("pause");
                break;

            // case 4:
            //     cout<<"\t\t\t RECORRER ARBOLES"<<endl;
            //     if(Lista_vacia(lista)==false){
            //         cout<<"Ingrese un elemento a eliminar en la lista: "; cin>>n;
            //         Eliminar_elemento_lista(lista,n );
            //         cout<<n<<" Eliminado"<<endl;
            //     }
            //     else cout<<"Debe haber elementos para poder ejecutar la funcionalidad"<<endl;
            //     system("pause");
            //     break;

        //     case 5:
        //         cout<<"\t\t\t ELIMINAR TODOS LOS ELEMENTOS DE LA LISTA"<<endl;
        //         if(Lista_vacia(lista)==false){
        //             Eliminar_toda_lista(lista, n);
        //             cout<<"Lista Eliminado"<<endl;
        //         }

        //         else cout<<"Debe haber elementos para poder ejecutar la funcionalidad"<<endl;
        //         system("pause");
        //         break;
        } 

    }while(opc!= 6 );

    return 0;
}



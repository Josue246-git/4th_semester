
// Autor: JOsue Rodriguez 7272

#ifndef _ARBOL_AVL_H
#define _ARBOL_AVL_H

#include "Nodo_bin.h"                 //acceder a metodos de nodos

class AVLTree{                         // definicion de la clase

private:
  NodoBinario *raiz;              // apuntador al nodo raiz

  NodoBinario *buscar(NodoBinario *rSub, Tipo v) { // implementa búsqueda de un nodo en el AB
    if (rSub == NULL){              // no existen nodos
      return NULL; // no encontro: devuelve apuntador a NULL
    }
    else { // si hay nodos
      if (v == rSub->getDato()) {              // valor buscado esta en este nodo
        return rSub; // devuelve apuntador a este nodo
      }
      else{ // valor buscado no esta en este nodo
        if (v < rSub->getDato()){                                   // valor buscado es menor que valor del nodo
          return buscar(rSub->getIzq(), v); // repite busqueda en subarbol izquierdo
        }
        else{                                   // valor buscado no es menor que valor del nodo
          return buscar(rSub->getDer(), v); // repite busqueda en subarbol derecho
        }
      }
    }
  }


int obtenerAltura(NodoBinario *nodo){     //obtiene la altura de cada nodo pasado por parametro 
    if (nodo == NULL){
      return 0;
    }
    return nodo->getHeight();
  }

  int obtenerBalance(NodoBinario *nodo){        //obtiene el barance o el factor de equilibrio del nodo determinado 
    if (nodo == NULL)
    {
      return 0;
    }
    return obtenerAltura(nodo->getIzq()) - obtenerAltura(nodo->getDer());
  }

  int max(int a, int b){                  //funcion que retorna el maximo o el mayor de dos nueros ingresados 
    return (a > b) ? a : b;
  }

  // Rotate right
  NodoBinario *rotacionDerecha(NodoBinario *nodo) {         //realiza la operacion de rotar derecho, segun la teoria antes explicada
    NodoBinario *nuevaRaiz = nodo->getIzq();
    NodoBinario *temp = nuevaRaiz->getDer();

    nuevaRaiz->setDer(nodo);
    nodo->setIzq(temp);

    nodo->setHeight(max(obtenerAltura(nodo->getIzq()), obtenerAltura(nodo->getDer())) + 1);
    nuevaRaiz->setHeight(max(obtenerAltura(nuevaRaiz->getIzq()), obtenerAltura(nuevaRaiz->getDer())) + 1);

    return nuevaRaiz;
  }

  // Rotate left

  NodoBinario *rotacionIzquierda(NodoBinario *nodo)     ////realiza la operacion de rotar a la izq, segun la teoria antes explicada
  {
    NodoBinario *nuevaRaiz = nodo->getDer();
    NodoBinario *temp = nuevaRaiz->getIzq();

    nuevaRaiz->setIzq(nodo);
    nodo->setDer(temp);

    nodo->setHeight(max(obtenerAltura(nodo->getIzq()), obtenerAltura(nodo->getDer())) + 1);
    nuevaRaiz->setHeight(max(obtenerAltura(nuevaRaiz->getIzq()), obtenerAltura(nuevaRaiz->getDer())) + 1);

    return nuevaRaiz;
  }

  NodoBinario *insertarNodo(NodoBinario *nodo, int valor){        //Inserta un nuevo nodo con todos los casos previstos 
    if (nodo == NULL){
      return new NodoBinario(valor);
    }

    if (valor < nodo->getDato()){
      nodo->setIzq(insertarNodo(nodo->getIzq(), valor));
    }
    else if (valor > nodo->getDato()){
      nodo->setDer(insertarNodo(nodo->getDer(), valor));
    }
    else{
      return nodo; // Valor duplicado, no se permite
    }

    nodo->setHeight(1 + max(obtenerAltura(nodo->getIzq()), obtenerAltura(nodo->getDer())));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && valor < (nodo->getIzq())->getDato()){
      return rotacionDerecha(nodo);
    }

    if (balance < -1 && valor > (nodo->getDer())->getDato())
    {
      return rotacionIzquierda(nodo);
    }

    if (balance > 1 && valor > (nodo->getIzq())->getDato())
    {
      nodo->setIzq(rotacionIzquierda(nodo->getIzq()));
      return rotacionDerecha(nodo);
    }

    if (balance < -1 && valor < (nodo->getDer())->getDato())
    {
      nodo->setDer(rotacionDerecha(nodo->getDer()));
      return rotacionIzquierda(nodo);
    }

    return nodo;
  }

  NodoBinario *encontrarNodoMinimo(NodoBinario *nodo){        //encuentra el valor minimo en el subarvol izquierdo relativo 
    NodoBinario *actual = nodo;

    while (actual->getIzq() != NULL)
    {
      actual = actual->getIzq();
    }
    return actual;
  }

  NodoBinario *eliminarNodo(NodoBinario *nodo, int valor){      //elimina el nodo del AVL con todos los casos previstos 
    if (nodo == NULL){
      return nodo;
    }

    if (valor < nodo->getDato())
    {
      nodo->setIzq(eliminarNodo(nodo->getIzq(), valor));
    }
    else if (valor > nodo->getDato())
    {
      nodo->setDer(eliminarNodo(nodo->getDer(), valor));
    }
    else
    {
      if (nodo->getIzq() == NULL || nodo->getDer() == NULL)
      {
        NodoBinario *temp = nodo->getIzq() ? nodo->getIzq() : nodo->getDer();

        if (temp == NULL)
        {
          temp = nodo;
          nodo = NULL;
        }
        else
        {
          *nodo = *temp;
        }

        delete temp;
      }
      else
      {
        NodoBinario *temp = encontrarNodoMinimo(nodo->getDer());
        nodo->setDato(temp->getDato());
        nodo->setDer(eliminarNodo(nodo->getDer(), temp->getDato()));
      }
    }

    if (nodo == NULL)
    {
      return nodo;
    }

    nodo->setHeight(1 + max(obtenerAltura(nodo->getIzq()), obtenerAltura(nodo->getDer())));
    int balance = obtenerBalance(nodo);

    if (balance > 1 && obtenerBalance(nodo->getIzq()) >= 0)
    {
      return rotacionDerecha(nodo);
    }

    if (balance > 1 && obtenerBalance(nodo->getIzq()) < 0)
    {
      nodo->setIzq(rotacionIzquierda(nodo->getIzq()));
      return rotacionDerecha(nodo);
    }

    if (balance < -1 && obtenerBalance(nodo->getDer()) <= 0)
    {
      return rotacionIzquierda(nodo);
    }

    if (balance < -1 && obtenerBalance(nodo->getDer()) > 0)
    {
      nodo->setDer(rotacionDerecha(nodo->getDer()));
      return rotacionIzquierda(nodo);
    }

    return nodo;
  }

  void Imprimir_AVL(NodoBinario *root, string indent, bool last){       //Immprime el arbol completo con una serie de mecanismos de espaciado 
    if (root != nullptr)
    {
      cout << indent;
      if (last)
      {
        cout << "R----";
        indent += "   ";
      }
      else
      {
        cout << "L----";
        indent += "|  ";
      }
      cout << root->getDato() << endl;
      Imprimir_AVL(root->getIzq(), indent, false);
      Imprimir_AVL(root->getDer(), indent, true);
    }
  }

public:
  AVLTree(); // constructor
  void setRaiz(NodoBinario *v);
  NodoBinario *getRaiz();

  bool esVacio();
  void insertar(int valor);
  void eliminar(int valor);
  void imprimir_avl();
  NodoBinario *buscarNodo(Tipo v);
};

AVLTree::AVLTree()
{
  setRaiz(NULL);
}

void AVLTree::setRaiz(NodoBinario *v) { // metodo que actualiza el atributo
  raiz = v;
}

NodoBinario *AVLTree::getRaiz() { // metodo que devuelve el atributo
  return raiz;
}

bool AVLTree::esVacio() {                             // metodo que determina si el AB carece de nodos
  return (getRaiz() == NULL); // true si raiz == null
}

void AVLTree::insertar(int valor){
  setRaiz(insertarNodo(getRaiz(), valor));
}

void AVLTree::eliminar(int valor){

  setRaiz(eliminarNodo(getRaiz(), valor));
}

void AVLTree::imprimir_avl(){
  Imprimir_AVL(raiz, "", true);
  cout << endl;
}

NodoBinario *AVLTree::buscarNodo(Tipo v){                              // permite buscar y encontrar un nodo con valor v en un arbol binario
  return buscar(getRaiz(), v);    // llama a metodo interno de búsqueda
}

#endif

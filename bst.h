#include "pilotos.h"
#include <iostream>
using namespace std;

template <class T>
class Nodo {
    public:
        T* piloto;        // El piloto que se almacenará en este nodo
        Nodo* izquierda;      // Puntero al nodo izquierdo
        Nodo* derecha;        // Puntero al nodo derecho
        vector<Nodo*> hijos;

        Nodo(T *p) : piloto(p), izquierda(nullptr), derecha(nullptr) {}
};

template <class T>
class ArbolBinario {
private:
    Nodo<T>* raiz;

    Nodo<T>* add(Nodo<T>* nodo, T* piloto) {
        if (nodo == nullptr) {
            return new Nodo<T>(piloto); // Crear un nuevo nodo si el lugar está vacío

        }
        if(piloto->tiempo < nodo->piloto->tiempo) { // Comparar por tiempo
            nodo->izquierda = add(nodo->izquierda, piloto); // Insertar en el subárbol izquierdo
        } else {
            nodo->derecha = add(nodo->derecha, piloto); // Insertar en el subárbol derecho
        }
        return nodo;
    }

    void imprimirEnOrden(Nodo<T>* nodo, int &contador) {
        if(nodo == nullptr){
            return;
        }

        imprimirEnOrden(nodo->izquierda, contador); // Recorrer el subárbol izquierdo
        cout << contador << ". " << nodo->piloto->info();   // Imprimir el piloto en el nodo actual  
        contador++;    
        imprimirEnOrden(nodo->derecha, contador);    // Recorrer el subárbol derecho
        
    }
    void asignarPuntosInOrder(Nodo<T>* nodo, int &indice, const int* listaPuntos, int size) {
        if (nodo == nullptr || indice >= size) {
            return;
        }

        // Recorrer el subárbol izquierdo
        asignarPuntosInOrder(nodo->izquierda, indice, listaPuntos, size);

        // Asignar el valor de puntos del arreglo al nodo actual
        if(indice < 10){

        nodo->piloto->puntos = listaPuntos[indice];
        indice++;
        }else{
            nodo->piloto->puntos = 0;
        }

        // Recorrer el subárbol derecho
        asignarPuntosInOrder(nodo->derecha, indice, listaPuntos, size);
    }
   

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertarP(T* piloto) {
        raiz = add(raiz, piloto);
    }

    void imprimir() {
        int contador = 1;
        imprimirEnOrden(raiz, contador);
    }
    void asignarPuntos(const int* listaPuntos, int size) {
        int indice = 0;
        asignarPuntosInOrder(raiz, indice, listaPuntos, size);
    }


};

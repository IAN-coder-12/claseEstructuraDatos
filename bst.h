#include "pilotos.h"
#include <iostream>
using namespace std;

template <class T>
class Nodo {
    public:
        Piloto* piloto;        // El piloto que se almacenará en este nodo
        Nodo* izquierda;      // Puntero al nodo izquierdo
        Nodo* derecha;        // Puntero al nodo derecho

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
    // void obtenerPilotos(Nodo* nodo, vector<Piloto>& pilotos) {
    //     if (nodo != nullptr) {
    //         obtenerPilotos(nodo->izquierda, pilotos);
    //         pilotos.push_back(nodo->piloto); // Agregar piloto al vector
    //         obtenerPilotos(nodo->derecha, pilotos);
    //     }
    // }

public:
    ArbolBinario() : raiz(nullptr) {}

    void insertarP(T* piloto) {
        raiz = add(raiz, piloto);
    }

    void imprimir() {
        int contador = 1;
        imprimirEnOrden(raiz, contador);
    }
};
// template <class T>
// class Nodo{
//     Piloto piloto;        
//     Nodo* izquierda;      
//     Nodo* derecha;       

//     Nodo(Piloto p) : piloto(p), izquierda(nullptr), derecha(nullptr) {}
// };


// template <class T>
// class ArbolBinario {
// private:
//     Nodo <T> *raiz;

//     void insertar(Nodo*& nodo, Piloto piloto) {
//         if (nodo == nullptr) {
//             nodo = new Nodo(piloto); // Crear un nuevo nodo si el lugar está vacío
//         } else if (piloto.getTiempo() < nodo->piloto.getTiempo()) { // Comparar por tiempo
//             insertar(nodo->izquierda, piloto); // Insertar en el subárbol izquierdo
//         } else {
//             insertar(nodo->derecha, piloto); // Insertar en el subárbol derecho
//         }
//     }

//     void imprimirEnOrden(Nodo* nodo) {
//         if (nodo != nullptr) {
//             imprimirEnOrden(nodo->izquierda); // Recorrer el subárbol izquierdo
//             nodo->piloto.info();               // Imprimir el piloto en el nodo actual
//             imprimirEnOrden(nodo->derecha);    // Recorrer el subárbol derecho
//         }
//     }

// public:
//     ArbolBinario() : raiz(nullptr) {}
//     ~ArbolBinario();
//     void add(Piloto*);
//     bool empty() const;

// };

// template <class T>
// bool ArbolBinario<T>::empty() const {
// 	return (raiz == 0);
// }

// template <class T>
// void ArbolBinario<T>::add(Piloto *piloto) {   
//     //Si el árbol está vacío, se agrega en la raíz
// 	if(empty()){
// 		Nodo<T> *nuevo_nodo = new Nodo<T>(val);
// 		if(nuevo_nodo == NULL){
// 			throw OutOfMemory();
// 		}
// 		raiz = nuevo_nodo;
// 	}else{
// 	//Si el árbol no está vacío, se agrega de manera recursiva
// 	root -> add(piloto);
// 	}
// }

// template <class T>
// void inOrder() {
//     imprimirEnOrden(raiz);
// }

// // Destructor para liberar memoria
// template <class T>
// void destruir(T* nodo) {
//     if (nodo != nullptr) {
//         destruir(nodo->izquierda);
//         destruir(nodo->derecha);
//         delete nodo;
//     }
// }

// template <class T>
// ArbolBinario<T>::~ArbolBinario() {
// 	destruir(raiz);
// }

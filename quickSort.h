#include <algorithm> 
#include <vector>
#include "pilotos.h"
using namespace std;

// Función para intercambiar dos elementos
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Función de partición para el Quick Sort
template <typename T>
int partition(vector<T> &arr, int low, int high) {
    double pivot = arr[high].tiempo; // Seleccionamos el último elemento como pivote
    int i = low - 1;     // Índice del elemento más pequeño

    for (int j = low; j < high; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (arr[j].tiempo < pivot) { // Ahora usamos la sobrecarga del operador <
            i++;
            std::swap(arr[i], arr[j]); // Intercambiar los elementos
        }
    }
    // Intercambiar el pivote con el elemento en la posición i+1
    std::swap(arr[i + 1], arr[high]);
    return i + 1; // Devolver el índice de partición
}

// Función recursiva de Quick Sort
template <typename T>
void quickSort(vector<T> &arr, int low, int high) {
    if (low < high) {

        // Obtener el índice de partición
        int pi = partition(arr, low, high);

        // Ordenar los elementos antes y después de la partición
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
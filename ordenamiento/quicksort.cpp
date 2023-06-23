#include <iostream>
using namespace std;

// Función para intercambiar dos elementos en un arreglo
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Función para colocar el pivote en la posición correcta y dividir el arreglo
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Tomamos el último elemento como pivote
    int i = (low - 1);  // Índice del elemento más pequeño
    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor o igual que el pivote
        if (arr[j] <= pivot) {
            i++;  // Incrementamos el índice del elemento más pequeño
            swap(&arr[i], &arr[j]);  // Intercambiamos arr[i] y arr[j]
        }
    }
    swap(&arr[i + 1], &arr[high]);  // Colocamos el pivote en su posición correcta
    return (i + 1);
}

// Función principal que implementa QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Obtenemos el índice de partición, arr[p] está en su posición correcta
        int p = partition(arr, low, high);
        
        // Ordenamos los elementos antes y después de la partición
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}



int main() {
    int arr[] = {64, 10, 12, 5, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arreglo original:" << endl;
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Arreglo ordenado:" << endl;
    printArray(arr, n);

    return 0;
}

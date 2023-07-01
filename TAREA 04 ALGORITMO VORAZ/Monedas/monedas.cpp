#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> CambioMonedas(vector<int> denominaciones, int cantidad) {
    vector<int> resultado;
    sort(denominaciones.rbegin(), denominaciones.rend()); // Ordenar las denominaciones en orden descendente

    for (int i = 0; i < denominaciones.size(); i++) {
        while (cantidad >= denominaciones[i]) {
            resultado.push_back(denominaciones[i]);
            cantidad -= denominaciones[i];
        }
    }

    return resultado;
}

int main() {
    vector<int> denominaciones = {50, 20, 10, 5, 1}; // Denominaciones de monedas disponibles
    int cantidad = 123; // Cantidad de cambio a dar

    vector<int> resultado = CambioMonedas(denominaciones, cantidad);

    cout << "Cambio en monedas: ";
    for (int i = 0; i < resultado.size(); i++) {
        cout << resultado[i] << " ";
    }
    cout << endl;

    return 0;
}

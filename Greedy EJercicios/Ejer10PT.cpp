#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> obtenerCambioGreedy(vector<int>& monedas, int cantidad) {
    sort(monedas.begin(), monedas.end(), greater<int>()); // Ordenar monedas de forma descendente

    int numMonedas = monedas.size();
    vector<int> cambio(numMonedas, 0);

    for (int i = 0; i < numMonedas; i++) {
        cambio[i] = cantidad / monedas[i];
        cantidad %= monedas[i];
    }

    return cambio;
}

int main() {
    // Monedas disponibles (desordenadas)
    vector<int> monedas = {50, 1, 10, 2, 5, 100, 20};

    // Cantidad a cambiar
    int cantidad = 123;

    vector<int> cambio = obtenerCambioGreedy(monedas, cantidad);

    // Mostrar resultado
    cout << "Cambio mínimo de " << cantidad << " euros:" << endl;
    for (int i = 0; i < monedas.size(); i++) {
        if (cambio[i] > 0) {
            cout << cambio[i] << " monedas de " << monedas[i] << " euros" << endl;
        }
    }

    return 0;
}

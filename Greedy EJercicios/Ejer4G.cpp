#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cliente {
    int tiempoEspera;
    double satisfaccion;
};

bool compararTiempoEspera(const Cliente& c1, const Cliente& c2) {
    return c1.tiempoEspera > c2.tiempoEspera;
}

double maximizarPropinas(vector<Cliente>& clientes, int k) {
    sort(clientes.begin(), clientes.end(), compararTiempoEspera);

    int numClientes = clientes.size();
    int grupos = numClientes / k;
    int clientesRestantes = numClientes % k;

    double propinasTotales = 0.0;

    int inicio = 0;
    for (int i = 0; i < grupos; i++) {
        int fin = inicio + k;
        for (int j = inicio; j < fin; j++) {
            double propina = clientes[j].satisfaccion;
            propinasTotales += propina;
        }
        inicio = fin;
    }

    if (clientesRestantes > 0) {
        for (int i = inicio; i < numClientes; i++) {
            double propina = clientes[i].satisfaccion;
            propinasTotales += propina;
        }
    }

    return propinasTotales;
}

int main() {
    vector<Cliente> clientes = {
        {5, 0.2}, {3, 0.33}, {2, 0.5}, {7, 0.14}, {4, 0.25}, {6, 0.17}
    };

    int camareros = 2;

    double propinasMaximas = maximizarPropinas(clientes, camareros);

    cout << "Propinas máximas obtenidas: " << propinasMaximas << endl;

    return 0;
}

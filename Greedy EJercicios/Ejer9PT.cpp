#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Cliente {
    vector<double> caracteristicas;

    Cliente(const vector<double>& _caracteristicas) : caracteristicas(_caracteristicas) {}
};

double calcularDistancia(const vector<double>& v1, const vector<double>& v2) {
    int dimension = v1.size();
    double distancia = 0.0;

    for (int i = 0; i < dimension; i++) {
        distancia += pow(v1[i] - v2[i], 2);
    }

    return sqrt(distancia);
}

int encontrarGrupo(const vector<Cliente>& centroides, const Cliente& cliente) {
    int numGrupos = centroides.size();
    double minDistancia = numeric_limits<double>::max();
    int grupo = -1;

    for (int i = 0; i < numGrupos; i++) {
        double distancia = calcularDistancia(centroides[i].caracteristicas, cliente.caracteristicas);

        if (distancia < minDistancia) {
            minDistancia = distancia;
            grupo = i;
        }
    }

    return grupo;
}

vector<vector<Cliente>> agruparClientes(const vector<Cliente>& clientes, int numGrupos) {
    int numClientes = clientes.size();
    int dimension = clientes[0].caracteristicas.size();

    // Inicializar centroides aleatoriamente
    vector<Cliente> centroides(numGrupos);
    vector<int> asignaciones(numClientes);

    for (int i = 0; i < numGrupos; i++) {
        int indiceAleatorio = rand() % numClientes;
        centroides[i] = clientes[indiceAleatorio];
    }

    bool cambios = true;

    while (cambios) {
        cambios = false;

        // Asignar cada cliente al grupo más cercano
        for (int i = 0; i < numClientes; i++) {
            int grupoActual = asignaciones[i];
            int nuevoGrupo = encontrarGrupo(centroides, clientes[i]);

            if (grupoActual != nuevoGrupo) {
                asignaciones[i] = nuevoGrupo;
                cambios = true;
            }
        }

        // Recalcular centroides
        vector<int> conteo(numGrupos, 0);
        vector<vector<double>> sumas(numGrupos, vector<double>(dimension, 0.0));

        for (int i = 0; i < numClientes; i++) {
            int grupo = asignaciones[i];
            conteo[grupo]++;

            for (int j = 0; j < dimension; j++) {
                sumas[grupo][j] += clientes[i].caracteristicas[j];
            }
        }

        for (int i = 0; i < numGrupos; i++) {
            if (conteo[i] > 0) {
                for (int j = 0; j < dimension; j++) {
                    centroides[i].caracteristicas[j] = sumas[i][j] / conteo[i];
                }
            }
        }
    }

    // Agrupar clientes por grupos
    vector<vector<Cliente>> grupos(numGrupos);

    for (int i = 0; i < numClientes; i++) {
        int grupo = asignaciones[i];
        grupos[grupo].push_back(clientes[i]);
    }

    return grupos;
}

int main() {
    // Ejemplo de clientes con 3 características
    vector<Cliente> clientes = {
        {{1.0, 2.0, 3.0}},
        {{4.0, 5.0, 6.0}},
        {{7.0, 8.0, 9.0}},
        {{10.0, 11.0, 12.0}},
        {{13.0, 14.0, 15.0}},
        {{16.0, 17.0, 18.0}},
        {{19.0, 20.0, 21.0}},
        {{22.0, 23.0, 24.0}}
    };

    int numGrupos = 2;

    vector<vector<Cliente>> grupos = agruparClientes(clientes, numGrupos);

    // Mostrar resultados
    for (int i = 0; i < numGrupos; i++) {
        cout << "Grupo " << i + 1 << ":" << endl;

        for (const auto& cliente : grupos[i]) {
            cout << "(";
            for (const auto& caracteristica : cliente.caracteristicas) {
                cout << caracteristica << " ";
            }
            cout << ")" << endl;
        }

        cout << endl;
    }

    return 0;
}

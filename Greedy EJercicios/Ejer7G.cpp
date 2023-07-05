#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Nodo {
public:
    int id;

    Nodo(int _id) : id(_id) {}
};

class Arista {
public:
    Nodo* origen;
    Nodo* destino;

    Arista(Nodo* _origen, Nodo* _destino) : origen(_origen), destino(_destino) {}
};

class Grafo {
public:
    vector<Nodo*> nodos;
    vector<Arista*> aristas;

    ~Grafo() {
        for (Nodo* nodo : nodos) {
            delete nodo;
        }

        for (Arista* arista : aristas) {
            delete arista;
        }
    }
};

vector<int> encontrarParadasGasolinera(Grafo& grafo, int distanciaMaxima) {
    vector<int> paradas;

    Nodo* inicio = grafo.nodos[0]; // Nodo de inicio (punto de partida)
    Nodo* fin = grafo.nodos[grafo.nodos.size() - 1]; // Nodo de fin (destino)
    Nodo* actual = inicio; // Nodo actual durante el recorrido

    while (actual != fin) {
        Nodo* mejorGasolinera = nullptr;
        int maxDistancia = actual->id + distanciaMaxima;

        // Buscar la arista con el destino más lejano dentro del rango de distancia
        for (Arista* arista : grafo.aristas) {
            if (arista->origen == actual) {
                Nodo* vecino = arista->destino;
                if (vecino->id <= maxDistancia) {
                    if (!mejorGasolinera || vecino->id > mejorGasolinera->id) {
                        mejorGasolinera = vecino;
                    }
                }
            }
        }

        if (!mejorGasolinera) {
            // No se encontró una arista con destino dentro del rango
            break;
        }

        paradas.push_back(mejorGasolinera->id);
        actual = mejorGasolinera;
    }

    return paradas;
}

int main() {
    Grafo grafo;

    // Crear nodos y aristas
    for (int i = 0; i <= 1000; i += 100) {
        Nodo* nodo = new Nodo(i);
        grafo.nodos.push_back(nodo);

        if (i > 0) {
            Arista* arista = new Arista(grafo.nodos[i / 100 - 1], nodo);
            grafo.aristas.push_back(arista);
        }
    }

    int distanciaMaxima = 300; // Distancia máxima que el autobús puede recorrer sin repostar

    vector<int> paradas = encontrarParadasGasolinera(grafo, distanciaMaxima);

    cout << "Paradas en las gasolineras: ";
    for (int i = 0; i < paradas.size(); i++) {
        cout << paradas[i] << " ";
    }
    cout << endl;

    return 0;
}

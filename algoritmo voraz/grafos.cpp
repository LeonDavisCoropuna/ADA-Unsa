#include <iostream>
#include <vector>

// Estructura para representar una arista del grafo
struct Arista {
    int destino;
    int peso;
};

// Estructura para representar el grafo
class Grafo {
private:
    int numVertices;
    std::vector<std::vector<Arista>> listaAdyacencia;

public:
    Grafo(int vertices) {
        numVertices = vertices;
        listaAdyacencia.resize(numVertices);
    }

    // Agregar una arista al grafo
    void agregarArista(int origen, int destino, int peso) {
        Arista arista;
        arista.destino = destino;
        arista.peso = peso;
        listaAdyacencia[origen].push_back(arista);
    }

    // Obtener el número de vértices del grafo
    int obtenerNumVertices() {
        return numVertices;
    }

    // Obtener la lista de adyacencia del grafo
    std::vector<std::vector<Arista>>& obtenerListaAdyacencia() {
        return listaAdyacencia;
    }
};

int main() {
    // Crear un grafo con 5 vértices
    Grafo grafo(5);

    // Agregar aristas al grafo
    grafo.agregarArista(0, 1, 10);
    grafo.agregarArista(0, 2, 5);
    grafo.agregarArista(1, 2, 2);
    grafo.agregarArista(1, 3, 1);
    grafo.agregarArista(2, 1, 3);
    grafo.agregarArista(2, 3, 9);
    grafo.agregarArista(2, 4, 2);
    grafo.agregarArista(3, 4, 4);
    grafo.agregarArista(4, 0, 7);

    // Obtener el número de vértices
    int numVertices = grafo.obtenerNumVertices();
    std::cout << "Número de vértices: " << numVertices << std::endl;

    // Obtener la lista de adyacencia
    std::vector<std::vector<Arista>>& listaAdyacencia = grafo.obtenerListaAdyacencia();

    // Mostrar las aristas del grafo
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Aristas del vértice " << i << ": ";
        for (const Arista& arista : listaAdyacencia[i]) {
            std::cout << "(" << arista.destino << ", " << arista.peso << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}

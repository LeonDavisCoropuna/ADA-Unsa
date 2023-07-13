#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Nodo {
public:
    int id;
    unordered_set<Nodo*> vecinos;

    Nodo(int id) : id(id) {}

    void agregarVecino(Nodo* vecino) {
        vecinos.insert(vecino);
    }
};

class Grafo {
public:
    vector<Nodo*> nodos;

    ~Grafo() {
        for (Nodo* nodo : nodos) {
            delete nodo;
        }
    }

    Nodo* agregarNodo(int id) {
        Nodo* nuevoNodo = new Nodo(id);
        nodos.push_back(nuevoNodo);
        return nuevoNodo;
    }

    void agregarArista(Nodo* nodo1, Nodo* nodo2) {
        nodo1->agregarVecino(nodo2);
        nodo2->agregarVecino(nodo1);
    }

    void recubrimientoMinimal() {
        unordered_set<Nodo*> recubrimiento;

        // Ordenar las aristas en orden creciente de grado de los nodos
        vector<pair<int, Nodo*>> grados;
        for (Nodo* nodo : nodos) {
            grados.push_back({nodo->vecinos.size(), nodo});
        }
        sort(grados.begin(), grados.end());

        // Seleccionar aristas hasta cubrir todos los nodos
        for (auto& par : grados) {
            Nodo* nodo = par.second;

            // Si el nodo no está cubierto, agregarlo al recubrimiento
            if (recubrimiento.find(nodo) == recubrimiento.end()) {
                recubrimiento.insert(nodo);

                // Marcar los vecinos como cubiertos
                for (Nodo* vecino : nodo->vecinos) {
                    recubrimiento.insert(vecino);
                }
            }
        }

        // Imprimir el recubrimiento minimal
        cout << "Recubrimiento minimal: ";
        for (Nodo* nodo : recubrimiento) {
            cout << nodo->id << " ";
        }
        cout << endl;
    }
};

int main() {
    Grafo grafo;

    // Agregar nodos al grafo
    Nodo* nodo1 = grafo.agregarNodo(1);
    Nodo* nodo2 = grafo.agregarNodo(2);
    Nodo* nodo3 = grafo.agregarNodo(3);
    Nodo* nodo4 = grafo.agregarNodo(4);
    Nodo* nodo5 = grafo.agregarNodo(5);

    // Agregar aristas al grafo
    grafo.agregarArista(nodo1, nodo2);
    grafo.agregarArista(nodo1, nodo3);
    grafo.agregarArista(nodo2, nodo4);
    grafo.agregarArista(nodo3, nodo4);
    grafo.agregarArista(nodo3, nodo5);

    // Resolver el recubrimiento minimal
    grafo.recubrimientoMinimal();

    return 0;
}

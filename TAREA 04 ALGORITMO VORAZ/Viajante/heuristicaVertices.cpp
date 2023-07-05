#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Nodo {
public:
    int id;
    Nodo(int id) : id(id) {}
};

class Arista {
public:
    Nodo* origen;
    Nodo* destino;
    int peso;
    Arista(Nodo* origen, Nodo* destino, int peso) : origen(origen), destino(destino), peso(peso) {}
};

class Grafo {
public:
    vector<Nodo> nodos;
    vector<Arista> aristas;

    void insertarNodo(int id) {
        Nodo nodo(id);
        nodos.push_back(nodo);
    }

    void insertarArista(int idOrigen, int idDestino, int peso) {
        Nodo* origen = nullptr;
        Nodo* destino = nullptr;

        for (auto& nodo : nodos) {
            if (nodo.id == idOrigen) {
                origen = &nodo;
            } else if (nodo.id == idDestino) {
                destino = &nodo;
            }
        }

        if (origen && destino) {
            Arista arista(origen, destino, peso);
            aristas.push_back(arista);
        } else {
            cout << "Error: Nodo de origen o destino no encontrado." << endl;
        }
    }

    // Resto del código...

    // Función para encontrar el siguiente nodo no visitado más cercano
     Nodo* encontrarSiguienteNodo(Nodo* nodoActual, vector<bool>& visitado,int &total) {
        Nodo* siguienteNodo = nullptr;
        int distanciaMinima = numeric_limits<int>::max();

        for (const auto& arista : aristas) {
            if (arista.origen == nodoActual && !visitado[arista.destino->id] && arista.peso < distanciaMinima) {
                distanciaMinima = arista.peso;
                siguienteNodo = arista.destino;
            }
        }
        //cout<<"D. minima: "<<distanciaMinima<<endl;
        total += distanciaMinima;
        return siguienteNodo;
    }

    // Función para resolver el problema del agente viajero utilizando la heurística del vecino más cercano
    vector<Nodo*> heuristicaVertices(int n) {
        int numNodos = nodos.size();
        vector<bool> visitado(numNodos, false);
        vector<Nodo*> ruta;
        Nodo* nodoActual = &nodos[n-1]; // Comenzar desde el primer nodo
        int total = 0,idNodoInicio = nodoActual->id;
        ruta.push_back(nodoActual);
        visitado[nodoActual->id] = true;

        for (int i = 0; i < numNodos - 1; ++i) {
            Nodo* siguienteNodo = encontrarSiguienteNodo(nodoActual, visitado,total);
            ruta.push_back(siguienteNodo);
            visitado[siguienteNodo->id] = true;
            nodoActual = siguienteNodo;
        }
        visitado[idNodoInicio] = false;
        Nodo* siguienteNodo = encontrarSiguienteNodo(nodoActual, visitado,total);
        cout<<"Distancia total: "<<total<<endl;
        return ruta;
    }

    Arista* encontrarSiguienteArista(Nodo* nodoActual, vector<bool>& visitado) {
        Arista* siguienteArista = nullptr;
        int distanciaMinima = numeric_limits<int>::max();

        for (auto& arista : aristas) {
            if (arista.origen == nodoActual && !visitado[arista.destino->id] && arista.peso < distanciaMinima) {
                distanciaMinima = arista.peso;
                siguienteArista = &arista;
            }
        }

        return siguienteArista;
    }

    vector<Arista*> heuristicaAristas(int n) {
        int numNodos = nodos.size();
        vector<bool> visitado(numNodos, false);
        vector<Arista*> ciclo;
        Nodo* nodoActual = &nodos[n-1]; // Comenzar desde el primer nodo
        visitado[nodoActual->id] = true;
        int total = 0,idNodoInicio = nodoActual->id;

        for (int i = 0; i < numNodos - 1; ++i) {
            Arista* siguienteArista = encontrarSiguienteArista(nodoActual, visitado);
            ciclo.push_back(siguienteArista);
            visitado[siguienteArista->destino->id] = true;
            nodoActual = siguienteArista->destino;
        }

        // Agregar la arista final para completar el ciclo
        visitado[idNodoInicio] = false;

        Arista* aristaFinal = encontrarSiguienteArista(nodoActual, visitado);
        ciclo.push_back(aristaFinal);
        return ciclo;
    }

};

int main() {
    Grafo grafo;

    // Insertar nodos
    grafo.insertarNodo(1);
    grafo.insertarNodo(2);
    grafo.insertarNodo(3);
    grafo.insertarNodo(4);
    grafo.insertarNodo(5);

    // Insertar aristas
    grafo.insertarArista(1, 2, 10);
    grafo.insertarArista(1, 3, 55);

    grafo.insertarArista(2, 4, 25);
    grafo.insertarArista(4, 2, 25);

    grafo.insertarArista(1, 4, 25);
    grafo.insertarArista(1, 5, 45);
    grafo.insertarArista(2, 1, 10);
    grafo.insertarArista(2, 3, 20);
    grafo.insertarArista(2, 5, 40);
    grafo.insertarArista(3, 1, 55);
    grafo.insertarArista(3, 2, 20);
    grafo.insertarArista(3, 4, 15);
    grafo.insertarArista(3, 5, 30);

    grafo.insertarArista(4, 1, 25);
    grafo.insertarArista(4, 3, 15);
    grafo.insertarArista(4, 5, 50);
    grafo.insertarArista(5, 1, 45);
    grafo.insertarArista(5, 2, 40);
    grafo.insertarArista(5, 3, 30);
    grafo.insertarArista(5, 4, 50);

    vector<Nodo*> ruta = grafo.heuristicaVertices(5);

    //Mostrar la ruta resultante
    cout << "Ruta del agente viajero: ";
    for (Nodo* nodo : ruta) {
        cout << nodo->id << " ";
    }
    cout << endl;
    
    cout<<"Aristas: "<<endl;
    vector<Arista*> ciclo = grafo.heuristicaAristas(1);
    cout<<"(";
    for (Arista* arista : ciclo) {
        cout<<"("<<arista->origen->id<<" - "<<arista->destino->id<<")";
    }
    cout<<")";

    return 0;
}

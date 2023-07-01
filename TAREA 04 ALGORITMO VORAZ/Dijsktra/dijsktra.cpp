#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

template<typename T>
class Graph {
private:
    vector<T> nodes; // Vector para almacenar los nombres de los nodos
    vector<vector<int>> adjacencyMatrix; // Matriz de adyacencia

public:
    void addNode(const T& node) {
        nodes.push_back(node);

        int n = nodes.size();
        for (auto& row : adjacencyMatrix) {
            row.resize(n, INT_MAX);
        }

        adjacencyMatrix.resize(n, vector<int>(n, INT_MAX));
    }

    void addEdge(const T& from, const T& to, int weight) {
        int fromIndex = getNodeIndex(from);
        int toIndex = getNodeIndex(to);
        adjacencyMatrix[fromIndex][toIndex] = weight;
    }

    vector<int> Dijkstra(const T& source) {
        int n = nodes.size();
        vector<int> distances(n, INT_MAX);
        int sourceIndex = getNodeIndex(source);
        distances[sourceIndex] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, sourceIndex));

        while (!pq.empty()) {
            pair<int, int> current = pq.top();
            pq.pop();

            int nodeIndex = current.second;
            int nodeDistance = current.first;

            if (nodeDistance > distances[nodeIndex]) {
                continue;
            }

            for (int i = 0; i < n; i++) {
                int neighborDistance = adjacencyMatrix[nodeIndex][i];
                if (neighborDistance != INT_MAX) {
                    int totalDistance = nodeDistance + neighborDistance;

                    if (totalDistance < distances[i]) {
                        distances[i] = totalDistance;
                        pq.push(make_pair(totalDistance, i));
                    }
                }
            }
        }

        return distances;
    }

private:
    int getNodeIndex(const T& node) {
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i] == node) {
                return i;
            }
        }
        return -1; // Si el nodo no se encuentra en la lista
    }
};

int main() {
    Graph<string> graph;

    // Agregar nodos al grafo
    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addNode("D");
    graph.addNode("E");

    // Agregar aristas al grafo
    graph.addEdge("A", "B", 4);
    graph.addEdge("A", "C", 1);
    graph.addEdge("B", "D", 1);
    graph.addEdge("C", "B", 2);
    graph.addEdge("C", "D", 5);
    graph.addEdge("D", "E", 3);

    string source = "A";
    vector<int> distances = graph.Dijkstra(source);

    cout << "Distancias mínimas desde el nodo " << source << ":\n";
    for (int i = 0; i < distances.size(); i++) {
        cout << "Nodo " << distances[i] << ": " << distances[i] << endl;
    }

    return 0;
}

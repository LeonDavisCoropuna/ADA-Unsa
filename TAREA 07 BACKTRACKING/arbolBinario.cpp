#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int level;
    int value;
    int weight;
};

bool compareNodes(const Node& a, const Node& b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int max_value = 0;

void knapsack_binary_tree(vector<Node>& nodes, int capacity, int current_index, int current_value, int current_weight) {
    if (current_index >= nodes.size() || current_weight > capacity) {
        max_value = max(max_value, current_value);
        return;
    }

    // No tomar el nodo actual
    knapsack_binary_tree(nodes, capacity, current_index + 1, current_value, current_weight);

    // Tomar el nodo actual si cabe en la mochila
    if (current_weight + nodes[current_index].weight <= capacity) {
        knapsack_binary_tree(nodes, capacity, current_index + 1, current_value + nodes[current_index].value, current_weight + nodes[current_index].weight);
    }
}

int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    vector<Node> nodes;
    for (int i = 0; i < values.size(); ++i) {
        nodes.push_back({i, values[i], weights[i]});
    }
    sort(nodes.begin(), nodes.end(), compareNodes);

    max_value = 0;
    knapsack_binary_tree(nodes, capacity, 0, 0, 0);
    return max_value;
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 40;
    cout << "Valor máximo en la mochila (árbol binario): " << knapsack(values, weights, capacity) << endl;
    return 0;
}

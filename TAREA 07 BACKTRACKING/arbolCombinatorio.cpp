#include <iostream>
#include <vector>

using namespace std;

int max_value = 0;

void knapsack_combinatorial_tree(vector<int>& values, vector<int>& weights, int capacity, int current_index, int current_value, int current_weight) {
    if (current_index >= values.size() || current_weight > capacity) {
        max_value = max(max_value, current_value);
        return;
    }

    // No tomar el elemento actual
    knapsack_combinatorial_tree(values, weights, capacity, current_index + 1, current_value, current_weight);

    // Tomar el elemento actual si cabe en la mochila
    if (current_weight + weights[current_index] <= capacity) {
        knapsack_combinatorial_tree(values, weights, capacity, current_index + 1, current_value + values[current_index], current_weight + weights[current_index]);
    }
}

int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    max_value = 0;
    knapsack_combinatorial_tree(values, weights, capacity, 0, 0, 0);
    return max_value;
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;
    cout << "Valor máximo en la mochila (árbol combinatorio): " << knapsack(values, weights, capacity) << endl;
    return 0;
}

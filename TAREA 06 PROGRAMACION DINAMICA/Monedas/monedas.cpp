#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Función para resolver el problema del cambio de monedas usando programación dinámica
int cambioMonedas(vector<int>& monedas, int cantidad) {
    int n = monedas.size();
    vector<int> dp(cantidad + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= cantidad; i++) {
        for (int j = 0; j < n; j++) {
            if (monedas[j] <= i) {
                int subproblema = dp[i - monedas[j]];
                if (subproblema != INT_MAX && subproblema + 1 < dp[i]) {
                    dp[i] = subproblema + 1;
                }
            }
        }
    }

    return dp[cantidad] == INT_MAX ? -1 : dp[cantidad];
}

int main() {
    int cantidadObjetivo = 8; // Cantidad objetivo a obtener con las monedas
    vector<int> monedas = {1, 4, 6}; // Diferentes denominaciones de monedas

    int minMonedas = cambioMonedas(monedas, cantidadObjetivo);
    cout << "Cantidad minima de monedas necesarias: " << minMonedas << endl;

    return 0;
}

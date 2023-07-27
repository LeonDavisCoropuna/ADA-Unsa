#include <iostream>
#include <vector>

using namespace std;

// Estructura para representar un objeto con su valor y peso
struct Objeto {
    int valor;
    int peso;
};

// Función para resolver el problema de la mochila usando programación dinámica
int mochila(int capacidad, vector<Objeto>& objetos) {
    int n = objetos.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacidad + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacidad; w++) {
            // Si el peso del objeto es menor o igual a la capacidad de la mochila
            if (objetos[i - 1].peso <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - objetos[i - 1].peso] + objetos[i - 1].valor);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidad];
}

int main() {
    int capacidadMochila = 6; // Capacidad máxima de la mochila
    vector<Objeto> objetos = {
        {2, 1},  // {valor, peso}
        {3, 2},
        {4, 5}
    };

    int valorMaximo = mochila(capacidadMochila, objetos);
    cout << "El valor maximo que se puede obtener es: " << valorMaximo << endl;

    return 0;
}

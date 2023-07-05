#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contenedor {
    int toneladas;
};

bool compararMayortoneladas(const Contenedor& obj1, const Contenedor& obj2) {
    return obj1.toneladas > obj2.toneladas;
}

int Mochila01(vector<Contenedor>& Contenedors, int capacidad) {
    sort(Contenedors.begin(), Contenedors.end(), compararMayortoneladas);

    int numContenedors = Contenedors.size();
    vector<int> dp(capacidad + 1, 0);
    vector<int> numContenedores(capacidad + 1, 0);

    for (int i = 0; i < numContenedors; i++) {
        for (int j = capacidad; j >= Contenedors[i].toneladas; j--) {
            int beneficio = Contenedors[i].toneladas + dp[j - Contenedors[i].toneladas];
            int cantidad = 1 + numContenedores[j - Contenedors[i].toneladas];
            if (beneficio > dp[j]) {
                dp[j] = beneficio;
                numContenedores[j] = cantidad;
            }
        }
    }

    cout << "El número máximo de contenedores es: " << numContenedores[capacidad] << endl;
    return dp[capacidad];
}

int main() {
    vector<Contenedor> Contenedors = {
        {16},{31},{12},{26},{11}
    };
    int capacidadMochila = 50;
    int toneladasMaximo = Mochila01(Contenedors, capacidadMochila);
    cout << "El toneladas máximo obtenido en la mochila es: " << toneladasMaximo << endl;

    return 0;
}

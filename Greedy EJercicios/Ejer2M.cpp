#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Programa {
    int toneladas;
};

bool compararMayortoneladas(const Programa& obj1, const Programa& obj2) {
    return obj1.toneladas > obj2.toneladas;
}

int Disco(vector<Programa>& Programas, int capacidad) {
    sort(Programas.begin(), Programas.end(), compararMayortoneladas);

    int numProgramas = Programas.size();
    vector<int> dp(capacidad + 1, 0);
    vector<int> numProgramaes(capacidad + 1, 0);

    for (int i = 0; i < numProgramas; i++) {
        for (int j = capacidad; j >= Programas[i].toneladas; j--) {
            int beneficio = Programas[i].toneladas + dp[j - Programas[i].toneladas];
            int cantidad = 1 + numProgramaes[j - Programas[i].toneladas];
            if (beneficio > dp[j]) {
                dp[j] = beneficio;
                numProgramaes[j] = cantidad;
            }
        }
    }

    cout << "El número máximo de Programas es: " << numProgramaes[capacidad] << endl;
    return dp[capacidad];
}

int main() {
    vector<Programa> Programas = {
        {16},{31},{12},{26},{11}
    };
    int capacidadDisco = 50;
    int bytesMaximo = Disco(Programas, capacidadDisco);
    cout << "El maximo numero de bytes es : " << bytesMaximo << endl;

    return 0;
}

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

int Buque(vector<Contenedor>& Contenedors, int capacidad) {
    sort(Contenedors.begin(), Contenedors.end(), compararMayortoneladas);

    int numContenedors = Contenedors.size();
    vector<int> dp(capacidad + 1, 0);
    int aaa = 1;
    for (int i = 0; i < numContenedors; i++) {
        for (int j = capacidad; j >= Contenedors[i].toneladas; j--) {
            int beneficio = Contenedors[i].toneladas + dp[j - Contenedors[i].toneladas];
            if (beneficio > dp[j]) {
                dp[j] = beneficio;
            }
        }
    }
    return dp[capacidad];
}

int main() {
    vector<Contenedor> Contenedors = {
        {16},{31},{12},{11}
    };
    int capacidadMochila = 50;
    int toneladasMaximo = Buque(Contenedors, capacidadMochila);
    //31+16 = 47 el maximo es 47
    //16+12+11 = 39
    cout << "El toneladas máximo obtenido en el buque es: " << toneladasMaximo << endl;

    return 0;
}

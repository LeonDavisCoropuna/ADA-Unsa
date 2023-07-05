#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Clase {
    int inicio;
    int fin;
};

bool compararClases(const Clase& c1, const Clase& c2) {
    return c1.fin < c2.fin; // Ordenar las clases por hora de finalización en orden ascendente
}

int minimizarAulas(vector<Clase>& clases) {
    sort(clases.begin(), clases.end(), compararClases); // Ordenar las clases

    int numAulas = 0;
    int lastFin = -1;

    for (const auto& clase : clases) {
        if (clase.inicio > lastFin) {
            numAulas++; // Se necesita un aula adicional si la clase comienza después de la última finalizada
            lastFin = clase.fin;
        }
    }

    return numAulas;
}

int main() {
    // Clases con horarios preestablecidos
    vector<Clase> clases = {
        {8, 10},
        {9, 11},
        {10, 12},
        {13, 15},
        {14, 16},
        {15, 17},
        {16, 18}
    };

    int numAulas = minimizarAulas(clases);

    cout << "Número mínimo de aulas necesarias: " << numAulas << endl;

    return 0;
}

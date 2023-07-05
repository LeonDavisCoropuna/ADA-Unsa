#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Ciudad {
    int x;
    int y;

    Ciudad(int _x, int _y) : x(_x), y(_y) {}
};

struct Conexion {
    int ciudad1;
    int ciudad2;
    double distancia;

    Conexion(int c1, int c2, double dist) : ciudad1(c1), ciudad2(c2), distancia(dist) {}
};

bool compararConexiones(const Conexion& c1, const Conexion& c2) {
    return c1.distancia < c2.distancia;
}

int encontrarRaiz(vector<int>& unionFind, int ciudad) {
    if (unionFind[ciudad] == ciudad)
        return ciudad;

    return encontrarRaiz(unionFind, unionFind[ciudad]);
}

void unirCiudades(vector<int>& unionFind, int ciudad1, int ciudad2) {
    int raiz1 = encontrarRaiz(unionFind, ciudad1);
    int raiz2 = encontrarRaiz(unionFind, ciudad2);

    unionFind[raiz2] = raiz1;
}

vector<Conexion> interconectarCiudades(vector<Ciudad>& ciudades) {
    int numCiudades = ciudades.size();
    vector<Conexion> conexiones;

    // Calcular todas las distancias entre las ciudades
    for (int i = 0; i < numCiudades; i++) {
        for (int j = i + 1; j < numCiudades; j++) {
            double distancia = sqrt(pow(ciudades[i].x - ciudades[j].x, 2) + pow(ciudades[i].y - ciudades[j].y, 2));
            conexiones.push_back(Conexion(i, j, distancia));
        }
    }

    // Ordenar las conexiones por distancia de menor a mayor
    sort(conexiones.begin(), conexiones.end(), compararConexiones);

    vector<Conexion> redInterconexion;
    vector<int> unionFind(numCiudades);

    // Inicializar el conjunto de ciudades
    for (int i = 0; i < numCiudades; i++) {
        unionFind[i] = i;
    }

    // Construir la red de interconexión
    for (int i = 0; i < conexiones.size(); i++) {
        int ciudad1 = conexiones[i].ciudad1;
        int ciudad2 = conexiones[i].ciudad2;

        if (encontrarRaiz(unionFind, ciudad1) != encontrarRaiz(unionFind, ciudad2)) {
            unirCiudades(unionFind, ciudad1, ciudad2);
            redInterconexion.push_back(conexiones[i]);
        }
    }

    return redInterconexion;
}

int main() {
    vector<Ciudad> ciudades;

    // Agregar coordenadas de las ciudades
    ciudades.push_back(Ciudad(1, 1));
    ciudades.push_back(Ciudad(2, 3));
    ciudades.push_back(Ciudad(4, 5));
    ciudades.push_back(Ciudad(7, 2));
    ciudades.push_back(Ciudad(9, 6));

    vector<Conexion> redInterconexion = interconectarCiudades(ciudades);

    cout << "Conexiones de menor costo para interconectar las ciudades:" << endl;
    for (const auto& conexion : redInterconexion) {
        cout << "Ciudad " << conexion.ciudad1 << " <-> Ciudad " << conexion.ciudad2 << ", Distancia: " << conexion.distancia << endl;
    }

    return 0;
}

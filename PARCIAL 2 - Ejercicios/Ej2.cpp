#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
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
    int n;
    while(1){
        cin>>n;
        if(n == 0) break;
        int p1,p2;
        for(int i=0;i<n;i++){
            cin>>p1;
            cin>>p2;
            ciudades.push_back(Ciudad(p1,p2));
        }
        vector<Conexion> redInterconexion = interconectarCiudades(ciudades);
        if(redInterconexion[0].distancia > 10000){
            cout<<"INFINITY"<<endl;
        }
        else{
            float w = round(redInterconexion[0].distancia*10000.0)/10000.0;
            cout<<w<< endl;
        }
        redInterconexion.clear();
        ciudades.clear();
    }

    return 0;
}

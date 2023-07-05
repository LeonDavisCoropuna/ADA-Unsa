#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CacheLRU {
private:
    int capacity; // Capacidad máxima de la caché
    vector<int> cache; // Vector para almacenar los datos en la caché

public:
    CacheLRU(int capacity) : capacity(capacity) {}

    bool refer(int key) {
        // Buscar el dato en la caché
        auto it = find(cache.begin(), cache.end(), key);

        if (it != cache.end()) {
            // El dato está presente en la caché (hit)
            // Mover el dato al frente del vector (indicando que se utilizó recientemente)
            cache.erase(it);
            cache.insert(cache.begin(), key);
            return true;
        } else {
            // El dato no está en la caché (miss)
            if (cache.size() == capacity) {
                // Eliminar el dato menos recientemente utilizado (al final del vector)
                cache.pop_back();
            }
            // Insertar el nuevo dato al frente del vector
            cache.insert(cache.begin(), key);
            return false;
        }
    }
};

int main() {
    int cacheCapacity = 3; // Capacidad de la caché
    vector<int> requests = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3}; // Conjunto de solicitudes

    CacheLRU cache(cacheCapacity);

    int cacheMisses = 0; // Contador de fallos de caché

    // Procesar cada solicitud
    for (int request : requests) {
        if (!cache.refer(request)) {
            cacheMisses++;
        }
    }

    cout << "Número de fallos de caché: " << cacheMisses << endl;

    return 0;
}

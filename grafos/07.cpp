#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool esConexo(const vector<vector<int>>& grafo, int inicio) {
    vector<bool> visitado(grafo.size(), false); // Vector para marcar los vértices visitados
    queue<int> q; // Cola para BFS

    q.push(inicio);
    visitado[inicio] = true; // Marcar el vértice de inicio como visitado

    while (!q.empty()) {
        int nodo = q.front();
        q.pop();

        // Recorrer los vecinos
        for (int vecino : grafo[nodo]) {
            if (!visitado[vecino]) { // Si el vecino no ha sido visitado
                visitado[vecino] = true; // Marcarlo como visitado
                q.push(vecino); // Agregar a la cola
            }
        }
    }

    // Verificar si todos los vértices han sido visitados
    for (bool v : visitado) {
        if (!v) return false; // Si hay algún vértice no visitado, no es conexo
    }
    return true; // El grafo es conexo
}

int main() {
    // Ejemplo de un grafo conexo
    vector<vector<int>> grafo = {
        {1, 2},    // Nodo 0
        {0, 3},    // Nodo 1
        {0, 3},    // Nodo 2
        {1, 2}     // Nodo 3
    };

    if (esConexo(grafo, 0)) {
        cout << "El grafo es conexo." << endl;
    } else {
        cout << "El grafo no es conexo." << endl;
    }

    return 0;
}
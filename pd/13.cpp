#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int u, v;
    int weight;
};

bool detectarCicloNegativo(int V, int E, const vector<Edge>& edges) {
    // Inicializar distancias
    vector<int> dist(V, numeric_limits<int>::max());
    dist[0] = 0; // Asumimos que el nodo fuente es el nodo 0

    // Relajar todas las aristas V-1 veces
    for (int i = 1; i < V; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != numeric_limits<int>::max() && 
                dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    // Verificar ciclos negativos
    for (const auto& edge : edges) {
        if (dist[edge.u] != numeric_limits<int>::max() && 
            dist[edge.u] + edge.weight < dist[edge.v]) {
            return true; // Se encontró un ciclo negativo
        }
    }

    return false; // No se encontraron ciclos negativos
}

int main() {
    int V, E;
    cout << "Ingrese el número de nodos (V): ";
    cin >> V;
    cout << "Ingrese el número de aristas (E): ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Ingrese las aristas (u, v, peso):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    if (detectarCicloNegativo(V, E, edges)) {
        cout << "Se detectó un ciclo negativo en el grafo." << endl;
    } else {
        cout << "No se detectó ningún ciclo negativo en el grafo." << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

bool dfs(int nodo, vector<int>& estados, const vector<vector<int>>& grafo) {
    if (estados[nodo] == 1) // Si está en proceso, hay un ciclo
        return true;
    if (estados[nodo] == 2) // Si ya fue visitado completamente, no hacer nada
        return false;

    estados[nodo] = 1; // Marcar como visitado en proceso

    // Recorrer los vecinos
    for (int vecino : grafo[nodo]) {
        if (dfs(vecino, estados, grafo)) {
            return true; // Si encontramos un ciclo en la llamada recursiva
        }
    }

    estados[nodo] = 2; // Marcar como visitado completamente
    return false; // No se encontró ningún ciclo
}

bool esDAG(const vector<vector<int>>& grafo) {
    vector<int> estados(grafo.size(), 0); // Inicializar todos los nodos como no visitados

    // Probar cada nodo
    for (int i = 0; i < grafo.size(); i++) {
        if (estados[i] == 0) { // Si no ha sido visitado
            if (dfs(i, estados, grafo)) {
                return false; // Si hay un ciclo, no es un DAG
            }
        }
    }
    return true; // Si no se encontraron ciclos, es un DAG
}

int main() {
    // Ejemplo de un grafo dirigido
    vector<vector<int>> grafo = {
        {1},      // Nodo 0
        {2},      // Nodo 1
        {0},      // Nodo 2 (crea un ciclo)
        {}        // Nodo 3 (sin aristas)
    };

    if (esDAG(grafo)) {
        cout << "El grafo es un DAG." << endl;
    } else {
        cout << "El grafo tiene ciclos." << endl;
    }

    return 0;
}
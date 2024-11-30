/*
    Diseñe un algoritmo eficiente que compruebe si un grafo es bipartido o no. 

    NOTA: Un grafo es bipartido si su conjunto de vértices V puede dividirse en dos 
    conjuntos disjuntos X e Y de tal forma que todas las aristas del grafo van de un 
    vértice en X a un vértice en Y. 

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool esBipartito(const vector<vector<int>>& grafo, int inicio, vector<int>& colores) {
    queue<int> q;
    q.push(inicio);
    colores[inicio] = 0; // Asignar el primer color

    while (!q.empty()) {
        int nodo = q.front();
        q.pop();

        for (int vecino : grafo[nodo]) {
            if (colores[vecino] == -1) { // Si no está coloreado
                // Asignar color opuesto
                colores[vecino] = 1 - colores[nodo];
                q.push(vecino);
            } else if (colores[vecino] == colores[nodo]) {
                // Si el vecino tiene el mismo color
                return false;
            }
        }
    }
    return true;
}

bool esGrafoBipartito(const vector<vector<int>>& grafo) {
    vector<int> colores(grafo.size(), -1); // -1 indica que el vértice no está coloreado

    for (int i = 0; i < grafo.size(); i++) {
        if (colores[i] == -1) { // Si el nodo no ha sido visitado
            if (!esBipartito(grafo, i, colores)) {
                return false; // Si no se puede colorear, no es bipartito
            }
        }
    }
    return true; // Si se pudieran colorear todos los componentes
}

int main() {
    // Ejemplo de un grafo bipartito
    vector<vector<int>> grafo = {
        {1, 3},    // Nodo 0
        {0, 2},    // Nodo 1
        {1, 3},    // Nodo 2
        {0, 2}     // Nodo 3
    };

    if (esGrafoBipartito(grafo)) {
        cout << "El grafo es bipartito." << endl;
    } else {
        cout << "El grafo no es bipartito." << endl;
    }

    return 0;
}
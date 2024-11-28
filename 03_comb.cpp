#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 5; // Número de ciudades
int dist[N][N] = {
    {0, 3, 10, 11, 7},
    {3, 0, 8, 12, 9},
    {10, 8, 0, 9, 4},
    {11, 12, 9, 0, 5},
    {7, 9, 4, 5, 0}
};

int bestCost = INT_MAX; // Mejor costo encontrado
vector<int> bestPath; // Mejor camino encontrado

void tsp(int pos, vector<bool>& visited, int count, int cost, vector<int>& path) {
    // Si todas las ciudades han sido visitadas y volvemos al inicio
    if (count == N && dist[pos][0]) {
        if (cost + dist[pos][0] < bestCost) {
            bestCost = cost + dist[pos][0];
            bestPath = path;
            bestPath.push_back(0); // Volver al inicio
        }
        return;
    }

    // Explorar las ciudades
    for (int i = 0; i < N; i++) {
        if (!visited[i] && dist[pos][i]) {
            // Marcar la ciudad como visitada
            visited[i] = true;
            path.push_back(i);

            // Llamada recursiva al siguiente nivel
            tsp(i, visited, count + 1, cost + dist[pos][i], path);

            // Desmarcar la ciudad para retroceder
            visited[i] = false;
            path.pop_back();
        }
    }
}

int main() {
    vector<bool> visited(N, false);
    vector<int> path;
    
    visited[0] = true; // Comenzar desde la ciudad 0
    path.push_back(0);
    
    tsp(0, visited, 1, 0, path); // Llamar a la función TSP

    cout << "El costo mínimo es: " << bestCost << endl;
    cout << "El mejor camino es: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
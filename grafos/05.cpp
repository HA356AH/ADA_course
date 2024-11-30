#include <iostream>
#include <vector>

using namespace std;

const int N = 6; // Dimensiones de la matriz

// Matriz del laberinto
bool M[N][N] = {
    {0, 0, 0, 0, 0, 0}, // Fila 0
    {1, 1, 0, 1, 1, 0}, // Fila 1
    {0, 0, 0, 0, 0, 0}, // Fila 2
    {0, 1, 1, 1, 1, 0}, // Fila 3
    {0, 0, 0, 0, 0, 0}, // Fila 4
    {1, 1, 1, 1, 1, 0}  // Fila 5
};

vector<pair<int, int>> camino; // Para almacenar el camino encontrado

// Verifica si se ha alcanzado la salida
bool esSalida(int x, int y) {
    return (x == N - 1 && y == N - 1); // Salida en (5, 5)
}

// Verifica si la celda es válida para moverse
bool esValido(int x, int y, vector<vector<bool>>& visitado) {
    return (x >= 0 && x < N && y >= 0 && y < N && M[x][y] == 0 && !visitado[x][y]);
}

// Función de backtracking para encontrar el camino
bool backtrack(int x, int y, vector<vector<bool>>& visitado) {
    // Si se llega a la salida
    if (esSalida(x, y)) {
        camino.push_back({x, y});
        return true;
    }

    // Marcar la celda como visitada
    visitado[x][y] = true;
    camino.push_back({x, y});

    // Movimientos posibles: abajo, arriba, derecha, izquierda
    vector<pair<int, int>> movimientos = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (auto& mov : movimientos) {
        int nuevoX = x + mov.first;
        int nuevoY = y + mov.second;

        if (esValido(nuevoX, nuevoY, visitado)) {
            if (backtrack(nuevoX, nuevoY, visitado)) {
                return true; // Si se encontró la salida
            }
        }
    }

    // Desmarcar la celda y retroceder
    visitado[x][y] = false;
    camino.pop_back();
    return false; // No se encontró la salida
}

int main() {
    vector<vector<bool>> visitado(N, vector<bool>(N, false)); // Matriz de visitados

    if (backtrack(0, 0, visitado)) { // Comenzar desde (0, 0)
        cout << "Camino encontrado: ";
        for (auto& p : camino) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    } else {
        cout << "No se encontró camino a la salida." << endl;
    }

    return 0;
}
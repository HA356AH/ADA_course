#include <iostream>
#include <vector>

using namespace std;

// Definición de las dimensiones del laberinto
const int N = 5; // Filas
const int M = 5; // Columnas

// Laberinto (true = camino, false = muro)
bool maze[N][M] = {
    {true, true, false, true, true},
    {false, true, false, false, true},
    {true, true, true, false, true},
    {true, false, true, true, true},
    {true, true, false, false, true}
};

// Estructura para almacenar el camino
vector<pair<int, int>> path;

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < M && maze[x][y]);
}

// Función de backtracking para encontrar el camino
bool solveMaze(int x, int y) {
    // Si se ha llegado a la meta
    if (x == N - 1 && y == M - 1) {
        path.push_back({x, y});
        return true;
    }

    // Verifica si el movimiento es seguro
    if (isSafe(x, y)) {
        path.push_back({x, y});

        // Mueve hacia abajo
        if (solveMaze(x + 1, y)) return true;
        // Mueve hacia la derecha
        if (solveMaze(x, y + 1)) return true;
        // Mueve hacia arriba
        if (solveMaze(x - 1, y)) return true;
        // Mueve hacia la izquierda
        if (solveMaze(x, y - 1)) return true;

        // Si no se encontró un camino, retrocede
        path.pop_back();
    }
    return false;
}

int main() {
    if (solveMaze(0, 0)) {
        cout << "El camino encontrado es: " << endl;
        for (auto p : path) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    } else {
        cout << "No hay camino disponible." << endl;
    }
    return 0;
}
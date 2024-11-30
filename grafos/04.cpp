/*
    Resuelva el problema del viajante de comercio utilizando la técnica B&B para  5  ciudades utilizando la siguiente matriz de distancias (que es simétrica): 
*/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int n = 5; // Número de ciudades

// Matriz de distancias (simbólica)
int dist[n][n] = {
    {   0,  3,  10, 11, 7},
    {   3,  0,  8, 12, 9},
    {   10, 8,  0, 9, 4},
    {   11, 12, 9, 0, 5},
    {   7,  9,  4, 5, 0}
};

int minCost = INF; // Costo mínimo encontrado
vector<int> bestPath; // Mejor camino encontrado

// Función para calcular el costo de la ruta actual
void tsp(int currentCity, int count, int cost, vector<bool>& visited, vector<int>& path) {
    // Si hemos visitado todas las ciudades
    if (count == n && dist[currentCity][0] > 0) {
        // Considerar el costo de regresar a la ciudad de inicio
        int totalCost = cost + dist[currentCity][0];
        if (totalCost < minCost) {
            minCost = totalCost; // Actualizar costo mínimo
            bestPath = path; // Guardar mejor camino
            bestPath.push_back(0); // Regresar a la ciudad de inicio
        }
        return;
    }

    // Explorar las ciudades no visitadas
    for (int city = 0; city < n; ++city) {
        if (!visited[city] && dist[currentCity][city] > 0) { // Si no ha sido visitada
            visited[city] = true; // Marcar ciudad como visitada
            path.push_back(city); // Agregar ciudad al camino
            tsp(city, count + 1, cost + dist[currentCity][city], visited, path);
            visited[city] = false; // Desmarcar ciudad para otras combinaciones
            path.pop_back(); // Deshacer la ruta actual
        }
    }
}

int main() {
    vector<bool> visited(n, false); // Ciudades visitadas inicialmente a falso
    vector<int> path; // Ruta actual
    visited[0] = true; // Comenzar en la ciudad 0
    path.push_back(0); // Agregar ciudad de inicio

    tsp(0, 1, 0, visited, path); // Comenzar el TSP

    // Mostrar el costo mínimo encontrado y el mejor camino
    cout << "Costo mínimo del recorrido: " << minCost << endl;
    cout << "Mejor camino: ";
    for (int city : bestPath) {
        cout << city + 1 << " "; // Mostrar ciudades en formato 1-based
    }
    cout << endl;

    return 0;
}
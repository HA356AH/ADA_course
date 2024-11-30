#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Número máximo de nodos
const int MAXN = 20;
const int INF = INT_MAX;

// Matriz de costos
int dist[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

// Función para calcular el costo mínimo usando DP
int tsp(int mask, int pos, int n) {
    // Si todos los nodos han sido visitados, regresar al nodo inicial
    if (mask == (1 << n) - 1) {
        return dist[pos][0]; // Regresar al nodo inicial
    }

    // Si ya se ha calculado este estado, devolver el resultado
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    // Explorar todos los nodos
    for (int city = 0; city < n; city++) {
        // Si la ciudad no ha sido visitada
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, n);
            ans = min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans; // Memorizar el resultado
}

int main() {
    int n;

    cout << "Ingrese el número de nodos: ";
    cin >> n;

    cout << "Ingrese la matriz de distancias:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Inicializar la tabla de DP
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(1, 0, n); // Comenzar desde el nodo 0
    cout << "El costo mínimo para visitar todos los nodos es: " << result << endl;

    return 0;
}
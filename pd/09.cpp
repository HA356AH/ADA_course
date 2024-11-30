#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int INF = INT_MAX;

void encontrarCaminosMinimos(int k, const vector<vector<int>>& cost) {
    int n = cost.size();
    vector<int> dp(n, INF);
    vector<int> path(n, -1);

    // Inicializar para la última etapa
    for (int j = 0; j < n; j++) {
        if (cost[k-1][j] != INF) { // Si hay un camino desde la última etapa
            dp[j] = cost[k-1][j];
            path[j] = k-1; // Guardar la etapa anterior
        }
    }

    // Calcular costos mínimos desde la penúltima etapa hacia la primera
    for (int i = k - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (cost[i][j] != INF) {
                for (int l = 0; l < n; l++) {
                    if (dp[l] != INF) {
                        int nuevoCosto = cost[i][j] + dp[l];
                        if (nuevoCosto < dp[j]) {
                            dp[j] = nuevoCosto;
                            path[j] = i; // Guardar la etapa anterior
                        }
                    }
                }
            }
        }
    }

    // Mostrar el costo mínimo para cada vértice de destino
    for (int j = 0; j < n; j++) {
        if (dp[j] == INF) {
            cout << "No es posible llegar al vértice " << j << " desde el origen." << endl;
        } else {
            cout << "El costo mínimo para llegar al vértice " << j << " es: " << dp[j] << endl;
        }
    }
}

int main() {
    int k, n;

    cout << "Ingrese el número de etapas (k): ";
    cin >> k;
    
    cout << "Ingrese el número de vértices (n): ";
    cin >> n;

    vector<vector<int>> cost(k, vector<int>(n, INF));

    cout << "Ingrese la matriz de costos (use " << INF << " para indicar que no hay camino):\n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    encontrarCaminosMinimos(k, cost);

    return 0;
}
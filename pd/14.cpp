#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const double INF = std::numeric_limits<double>::infinity();

void detectarArbitraje(int n, const vector<vector<double>>& rate) {
    vector<double> dp(n, 0);
    dp[0] = 100; // Comenzamos con 100 unidades de la moneda de origen

    // Aplicar el algoritmo de Bellman-Ford
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (dp[u] > 0 && rate[u][v] > 0) {
                    dp[v] = max(dp[v], dp[u] * rate[u][v]);
                }
            }
        }
    }

    // Verificar si hay un ciclo de arbitraje
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (dp[u] > 0 && rate[u][v] > 0) {
                if (dp[v] < dp[u] * rate[u][v]) {
                    cout << "Arbitraje detectado. Se puede obtener más dinero." << endl;
                    return;
                }
            }
        }
    }

    cout << "No se detecta arbitraje." << endl;
}

int main() {
    int n;

    cout << "Ingrese el número de monedas: ";
    cin >> n;

    vector<vector<double>> rate(n, vector<double>(n, 0));

    cout << "Ingrese la matriz de tasas de cambio (0 si no hay conversión):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rate[i][j];
        }
    }

    detectarArbitraje(n, rate);

    return 0;
}
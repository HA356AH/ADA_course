#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int INF = INT_MAX;

void calcularCostoMinimo(int n, const vector<vector<int>>& cost, int partida, int llegada) {
    vector<int> dp(n, INF);
    dp[partida] = 0; // El costo de partir de la aldea de inicio es 0

    // Calcular el costo mínimo para cada aldea
    for (int j = partida + 1; j <= llegada; j++) {
        for (int i = partida; i < j; i++) {
            if (cost[i][j] != INF) { // Si hay un costo definido
                dp[j] = min(dp[j], dp[i] + cost[i][j]);
            }
        }
    }

    // Resultado final
    if (dp[llegada] == INF) {
        cout << "No es posible llegar a la aldea " << llegada << " desde la aldea " << partida << endl;
    } else {
        cout << "El costo mínimo para llegar desde la aldea " << partida << " a la aldea " << llegada << " es: " << dp[llegada] << endl;
    }
}

int main() {
    int n;

    cout << "Ingrese el número de aldeas: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n, INF));

    cout << "Ingrese la matriz de costos (use " << INF << " para indicar que no hay camino):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int partida, llegada;
    cout << "Ingrese el punto de partida: ";
    cin >> partida;
    cout << "Ingrese el punto de llegada: ";
    cin >> llegada;

    calcularCostoMinimo(n, cost, partida, llegada);

    return 0;
}
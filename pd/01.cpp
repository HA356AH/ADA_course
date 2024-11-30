#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para resolver el problema de la mochila 0/1
int knapsack(int W, const vector<int>& pesos, const vector<int>& beneficios, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Construir la tabla de programación dinámica
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (pesos[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - pesos[i - 1]] + beneficios[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Imprimir los objetos seleccionados
    int res = dp[n][W];
    cout << "Máximo beneficio: " << res << endl;

    cout << "Objetos seleccionados: ";
    int w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            cout << i << " ";
            res -= beneficios[i - 1];
            w -= pesos[i - 1];
        }
    }
    cout << endl;

    return dp[n][W];
}

int main() {
    int W = 15; // Capacidad de la mochila
    vector<int> pesos = {3, 7, 4, 2, 1, 6}; // Pesos de los objetos
    vector<int> beneficios = {12, 3, 7, 4, 3, 8}; // Beneficios de los objetos
    int n = pesos.size(); // Número de objetos

    knapsack(W, pesos, beneficios, n);

    return 0;
}

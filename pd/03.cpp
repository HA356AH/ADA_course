#include <iostream>
#include <vector>

using namespace std;

// Función para calcular la probabilidad de ganar el play-off
double calcularProbabilidadPlayoff(int n, double P) {
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));

    // Condición base: Si Informáticos CB ya ganó todos los partidos necesarios
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 1.0; // Probabilidad de ganar es 1 si no necesita más victorias
    }

    // Condición base: Si Basket Telecom ya ganó todos los partidos necesarios
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0.0; // Probabilidad de ganar es 0 si Basket Telecom no necesita más victorias
    }

    // Llenar la tabla dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = P * dp[i - 1][j] + (1 - P) * dp[i][j - 1];
        }
    }

    return dp[n][n]; // Probabilidad de ganar el play-off
}

int main() {
    int n = 4; // Número de partidos necesarios para ganar
    double P = 0.5; // Probabilidad de ganar un partido

    double probabilidad = calcularProbabilidadPlayoff(n, P);
    cout << "Probabilidad de que Informáticos CB gane el play-off: " << probabilidad << endl;

    return 0;
}

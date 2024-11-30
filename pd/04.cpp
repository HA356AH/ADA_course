#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Función para encontrar la subsecuencia creciente de máxima longitud
vector<int> longestIncreasingSubsequence(const vector<int>& V) {
    int n = V.size();
    vector<int> dp(n, 1); // dp[i] almacena la longitud de la LIS que termina en V[i]
    vector<int> prev(n, -1); // Para rastrear los índices de los elementos previos en la LIS

    int maxLength = 0, lastIndex = -1;

    // Llenar la tabla dp
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (V[j] < V[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        // Actualizar la longitud máxima y el índice final
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            lastIndex = i;
        }
    }

    // Reconstruir la subsecuencia
    vector<int> lis;
    for (int i = lastIndex; i != -1; i = prev[i]) {
        lis.push_back(V[i]);
    }
    reverse(lis.begin(), lis.end()); // La subsecuencia está en orden inverso

    return lis;
}

int main() {
    // Vector de entrada
    vector<int> V = {11, 17, 5, 8, 6, 4, 7, 12, 3};

    // Encontrar la subsecuencia creciente de máxima longitud
    vector<int> lis = longestIncreasingSubsequence(V);

    // Mostrar la subsecuencia
    cout << "Subsecuencia creciente de máxima longitud: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

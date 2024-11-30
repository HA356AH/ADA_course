#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Función para multiplicar símbolos según la tabla proporcionada
char multiplicacionSimbolos(const string &cadena, const unordered_map<char, unordered_map<char, char>> &tabla) {
    int n = cadena.size();
    vector<vector<char>> M(n, vector<char>(n));

    // Inicializar la diagonal de M
    for (int i = 0; i < n; ++i) {
        M[i][i] = cadena[i];
    }

    // Construir la matriz M
    for (int l = 2; l <= n; ++l) { // longitud de subsecuencia
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            M[i][j] = M[i][i]; // Inicializar con el primer símbolo
            for (int k = i; k < j; ++k) {
                // Multiplicar M[i][k] y M[k+1][j] usando la tabla
                M[i][j] = tabla.at(M[i][k]).at(M[k + 1][j]);
            }
        }
    }

    // El resultado final es M[0][n-1]
    return M[0][n - 1];
}

int main() {
    // Definir la tabla de multiplicación
    unordered_map<char, unordered_map<char, char>> tabla_multiplicacion = {
        {'a', {{'a', 'a'}, {'b', 'b'}, {'c', 'c'}}},
        {'b', {{'a', 'b'}, {'b', 'c'}, {'c', 'a'}}},
        {'c', {{'a', 'c'}, {'b', 'a'}, {'c', 'b'}}}
    };

    // Ejemplo de uso
    string cadena = "abc";
    char resultado = multiplicacionSimbolos(cadena, tabla_multiplicacion);
    cout << "El resultado de la multiplicación es: " << resultado << endl;

    return 0;
}
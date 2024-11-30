#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void construirABBOptimo(const vector<double>& p, const vector<double>& q, int n) {
    vector<vector<double>> cost(n + 1, vector<double>(n + 1, 0));
    vector<vector<int>> root(n + 1, vector<int>(n + 1, 0));

    // Inicializar costos para árboles de un solo nodo
    for (int i = 1; i <= n; i++) {
        cost[i][i] = p[i - 1] + q[i - 1] + q[i]; // Probabilidad de la clave + infructuosas
        root[i][i] = i; // La raíz es la clave misma
    }

    // Calcular costos para subárboles de longitud mayor
    for (int len = 2; len <= n; len++) { // longitud de subárbol
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1; // Determinar el rango
            cost[i][j] = numeric_limits<double>::infinity(); // Inicializar a infinito

            // Probar cada raíz posible
            for (int r = i; r <= j; r++) {
                // Costo de subárbol izquierdo y derecho
                double leftCost = (r > i) ? cost[i][r - 1] : 0;
                double rightCost = (r < j) ? cost[r + 1][j] : 0;

                // Total de costo
                double totalCost = leftCost + rightCost + p[r - 1] + q[r - 1] + q[r];

                // Actualizar el costo mínimo
                if (totalCost < cost[i][j]) {
                    cost[i][j] = totalCost;
                    root[i][j] = r; // Guardar la raíz
                }
            }
        }
    }

    // Imprimir costo mínimo
    cout << "Costo mínimo del árbol óptimo: " << cost[1][n] << endl;

    // Imprimir la raíz del árbol óptimo
    cout << "Raíz del árbol óptimo entre k1 y kn: " << root[1][n] << endl;
}

int main() {
    int n;
    cout << "Ingrese el número de claves: ";
    cin >> n;

    vector<double> p(n);
    vector<double> q(n + 1); // Hay n + 1 probabilidades de infructuosas

    cout << "Ingrese las probabilidades de acceso (p1, p2, ..., pn):\n";
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    cout << "Ingrese las probabilidades de búsqueda infructuosa (q0, q1, ..., qn):\n";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }

    construirABBOptimo(p, q, n);

    return 0;
}
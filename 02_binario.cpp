#include <iostream>
#include <vector>
using namespace std;

int M = 61; // Tamaño de la mochila
vector<int> W = {1, 11, 21, 23, 43}; // Vector de pesos
vector<int> B = {11, 21, 31, 33, 43}; // Vector de beneficios
int n = W.size(); // Número de objetos
int maxBenefit = 0; // Máximo beneficio encontrado

// Función de backtracking para resolver el problema
void knapsack(int index, int currentWeight, int currentBenefit) {
    // Caso base: si hemos considerado todos los objetos
    if (index == n) {
        if (currentWeight <= M) {
            maxBenefit = max(maxBenefit, currentBenefit);
        }
        return;
    }

    // Opción 1: No incluir el objeto actual
    knapsack(index + 1, currentWeight, currentBenefit);

    // Opción 2: Incluir el objeto actual si no excede la capacidad
    if (currentWeight + W[index] <= M) {
        knapsack(index + 1, currentWeight + W[index], currentBenefit + B[index]);
    }
}

int main() {
    knapsack(0, 0, 0); // Comenzar desde el primer objeto
    cout << "El máximo beneficio que se puede obtener es: " << maxBenefit << endl;
    return 0;
}
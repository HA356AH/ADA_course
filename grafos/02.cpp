#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

// Variables globales
int maxWeight = 61; // Tamaño de la mochila

vector<Item> items = {{1, 11}, {11, 21}, {21, 31}, {23, 33}, {33, 43}}; // {peso, valor}

int maxValue = 0; // Valor máximo encontrado
vector<Item> bestCombination; // Mejor combinación de elementos

// Función de backtracking
void knapsack(int index, int currentWeight, int currentValue, vector<Item>& currentCombination) {
    // Si el peso actual supera el límite, se poda la rama.
    if (currentWeight > maxWeight) 
    {
        return;
    }

    // Actualizar el valor máximo si se ha encontrado una mejor combinación
    if (currentValue > maxValue) 
    {
        maxValue = currentValue;
        bestCombination = currentCombination;
    }

    // Explorar las decisiones de incluir o no incluir el siguiente objeto
    for (int i = index; i < items.size(); ++i) 
    {
        // Incluir el objeto i
        currentCombination.push_back(items[i]);
        knapsack(i + 1, currentWeight + items[i].weight, currentValue + items[i].value, currentCombination);
        // No incluir el objeto i (backtrack)
        currentCombination.pop_back();
    }
}

int main() {
    vector<Item> currentCombination;
    
    // Llamar a la función de backtracking
    knapsack(0, 0, 0, currentCombination);
    
    // Mostrar el resultado
    cout << "Valor maximo: " << maxValue << endl;
    cout << "Mejor combinacion de objetos: " << endl;
    for (const auto& item : bestCombination) {
        cout << "Peso: " << item.weight << ", Valor: " << item.value << endl;
    }

    return 0;
}
/*

    Arbol combinatorio

    Un instructor de esquí dispone de n pares de esquís para sus n alumnos. 
    Obligatoriamente, cada alumno debe recibir un par de esquís, que han de 
    adecuarse lo máximo posible a su altura. El problema del instructor es asignar 
    los esquís a los alumnos de forma que se minimice la suma de los valores 
    absolutos de las diferencias entre las alturas de los alumnos y las longitudes de 
    los respectivos esquís asignados. Proponga un algoritmo que resuelva este 
    problema de forma óptima y aplíquelo sobre el siguiente ejemplo: 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int minDifference = numeric_limits<int>::max();
vector<pair<int, int>> bestPairs;

// Función para calcular la suma de diferencias
int calculateDifference(const vector<int>& heights, const vector<int>& lengths) {
    int totalDiff = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
        totalDiff += abs(heights[i] - lengths[i]);
    }
    return totalDiff;
}

// Función recursiva para asignar esquís usando backtracking
void assignSkis(vector<int>& heights, vector<int>& lengths, vector<bool>& used, int index, vector<int>& currentLengths) {
    // Si hemos asignado esquís a todos los alumnos
    if (index == heights.size()) {
        int currentDiff = calculateDifference(heights, currentLengths);
        // Actualizar la mejor solución
        if (currentDiff < minDifference) {
            minDifference = currentDiff;
            bestPairs.clear();
            for (size_t i = 0; i < currentLengths.size(); ++i) {
                bestPairs.push_back({heights[i], currentLengths[i]});
            }
        }
        return;
    }

    // Probar cada longitud de esquí
    for (int i = 0; i < lengths.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            currentLengths[index] = lengths[i]; // Asignar longitud de esquí
            assignSkis(heights, lengths, used, index + 1, currentLengths);
            used[i] = false; // Deshacer la asignación (backtrack)
        }
    }
}

int main() {
    vector<int> heights = {178, 168, 190, 170}; // Alturas de los alumnos
    vector<int> lengths = {183, 188, 168, 175}; // Longitudes de los esquís
    vector<bool> used(lengths.size(), false);
    vector<int> currentLengths(heights.size());

    assignSkis(heights, lengths, used, 0, currentLengths);

    cout << "Mejor asignación de esquís: " << endl;
    for (const auto& pair : bestPairs) {
        cout << "Altura: " << pair.first << ", Longitud: " << pair.second << endl;
    }

    cout << "Diferencia mínima: " << minDifference << endl;

    cout << "Diferencias de cada par asignado: " << endl;
    for (size_t i = 0; i < bestPairs.size(); ++i) {
        int height = bestPairs[i].first;
        int length = bestPairs[i].second;
        int difference = abs(height - length);
        cout << "Diferencia para Altura: " << height << ", Longitud: " << length << " = " << difference << endl;
    }

    return 0;
}
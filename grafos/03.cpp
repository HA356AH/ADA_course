/*
    Diseñe un algoritmo B&B para resolver el problema de la asignación con la 
siguiente matriz de costes: 
*/


#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int n = 4; // Número de trabajadores/tareas

// Matriz de costos
int cost[n][n] = {
    {94, 71, 54, 68},
    {72, 10, 10, 82},
    {62, 88, 8, 76},
    {11, 74, 81, 21}
};

int minCost = INF; // Costo mínimo encontrado
vector<int> bestAssignment(n, -1); // Mejor asignación (trabajador para cada tarea)

// Función para asignar tareas
void assignTasks(int worker, int currentCost, vector<bool>& assigned, vector<int>& currentAssignment) {
    // Si todos los trabajadores han sido asignados
    if (worker == n) {
        if (currentCost < minCost) {
            minCost = currentCost; // Actualizar el costo mínimo
            bestAssignment = currentAssignment; // Guardar la mejor asignación
        }
        return;
    }

    // Explorar las asignaciones posibles
    for (int task = 0; task < n; ++task) {
        if (!assigned[task]) { // Si la tarea no ha sido asignada
            assigned[task] = true; // Marcar tarea como asignada
            currentAssignment[worker] = task; // Registrar asignación actual
            assignTasks(worker + 1, currentCost + cost[worker][task], assigned, currentAssignment);
            assigned[task] = false; // Desmarcar para otras combinaciones
            currentAssignment[worker] = -1; // Deshacer la asignación actual
        }
    }
}

int main() {
    vector<bool> assigned(n, false); // Tareas asignadas inicialmente a falso
    vector<int> currentAssignment(n, -1); // Asignación actual
    assignTasks(0, 0, assigned, currentAssignment); // Comenzar la asignación

    // Mostrar el costo mínimo encontrado y la mejor asignación
    cout << "Costo mínimo de asignación: " << minCost << endl;
    cout << "Mejor asignación:" << endl;
    for (int worker = 0; worker < n; ++worker) {
        cout << "Trabajador " << worker + 1 << " realiza la tarea " << bestAssignment[worker] + 1 << endl;
    }

    return 0;
}
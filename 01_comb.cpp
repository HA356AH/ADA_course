#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

// Estructura para almacenar la información de los esquís y alumnos
struct Esqui {
    int altura;
    int longitud;
};

// Función para calcular la suma de las diferencias
int calcularDiferencias(const vector<Esqui>& alumnos, const vector<Esqui>& esquís, const vector<int>& asignaciones) {
    int suma = 0;
    for (size_t i = 0; i < alumnos.size(); i++) {
        suma += abs(alumnos[i].altura - esquís[asignaciones[i]].altura) +
                abs(alumnos[i].longitud - esquís[asignaciones[i]].longitud);
    }
    return suma;
}

// Función de backtracking
void backtrack(const vector<Esqui>& alumnos, const vector<Esqui>& esquís, 
               vector<int>& asignaciones, vector<bool>& usados, 
               int index, vector<int>& mejor_asignacion, int& mejor_suma) {
    if (index == alumnos.size()) {
        int suma_actual = calcularDiferencias(alumnos, esquís, asignaciones);
        if (suma_actual < mejor_suma) {
            mejor_suma = suma_actual;
            mejor_asignacion = asignaciones;
        }
        return;
    }

    for (int i = 0; i < esquís.size(); i++) {
        if (!usados[i]) {
            asignaciones[index] = i; // Asignar el esquí i al alumno
            usados[i] = true; // Marcar el esquí como usado
            backtrack(alumnos, esquís, asignaciones, usados, index + 1, mejor_asignacion, mejor_suma);
            usados[i] = false; // Deshacer la asignación
        }
    }
}

int main() {
    // Datos de entrada
    vector<Esqui> alumnos = {{178, 183}, {190, 188}, {176, 175}};
    vector<Esqui> esquís = {{178, 183}, {190, 188}, {176, 175}}; // Cambia según los esquís disponibles

    vector<int> asignaciones(alumnos.size(), -1);
    vector<bool> usados(esquís.size(), false);
    vector<int> mejor_asignacion(alumnos.size(), -1);
    int mejor_suma = numeric_limits<int>::max();

    // Llamada al backtracking
    backtrack(alumnos, esquís, asignaciones, usados, 0, mejor_asignacion, mejor_suma);

    // Resultados
    cout << "Mejor suma de diferencias: " << mejor_suma << endl;
    cout << "Asignaciones: " << endl;
    for (size_t i = 0; i < mejor_asignacion.size(); i++) {
        cout << "Alumno " << i + 1 << " -> Esquí " << mejor_asignacion[i] + 1 << endl;
    }

    return 0;
}
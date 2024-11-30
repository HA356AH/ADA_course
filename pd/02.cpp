#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Función para verificar si u precede a v en el orden total
bool precede(const string& u, const string& v, const unordered_map<string, vector<string>>& precedence) {
    // Verificamos si u está en la relación de precedencia
    if (precedence.find(u) != precedence.end()) {
        const vector<string>& precedesU = precedence.at(u);
        // Iteramos sobre los elementos que u precede
        for (const string& elem : precedesU) {
            // Si encontramos v, entonces u precede a v
            if (elem == v) {
                return true;
            }
            // Recursivamente verificamos los elementos que preceden a elem
            if (precede(elem, v, precedence)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Definir el alfabeto y la relación de precedencia
    unordered_map<string, vector<string>> precedence = {
        {"a", {"b", "c"}},
        {"b", {"d"}},
        {"c", {"d"}},
        // Agregar otras relaciones según sea necesario
    };

    string u, v;
    cout << "Ingrese el primer elemento (u): ";
    cin >> u;
    cout << "Ingrese el segundo elemento (v): ";
    cin >> v;

    // Verificar si u precede a v
    if (precede(u, v, precedence)) {
        cout << u << " precede a " << v << endl;
    } else {
        cout << u << " no precede a " << v << endl;
    }

    return 0;
}
#include <iostream>
#include <windows.h>
#include <vector>
using namespace std;


void func(vector<int>& a) {
    // Primer bucle: recorre todo el vector excepto el último elemento
    for (int i = 0; i < a.size() - 1; i++) {
        int vectMin = i; // Asumimos que el mínimo está en la posición actual (i)

        // Segundo bucle: busca el valor mínimo en el subvector desde i + 1 hasta el final
        for (int j = i + 1; j < a.size(); j++) {
            // Si encontramos un valor menor que el actual mínimo (a[vectMin])
            if (a[j] < a[vectMin]) {
                vectMin = j; // Actualizamos el índice del mínimo
            }
        }

        // Si vectMin ha cambiado, hacemos un intercambio para poner el mínimo en la posición i
        if (vectMin != i) {
            int temp = a[i];  // Guardamos el valor actual de a[i] en una variable temporal
            a[i] = a[vectMin]; // Colocamos el valor mínimo en la posición i
            a[vectMin] = temp; // Colocamos el valor original de a[i] en la posición vectMin
        }
    }
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector<int> a = {64, 25, 12, 22, 11}; // Un ejemplo de vector a ordenar
    func(a); // Llamamos a la función para ordenar el vector

    // Imprimir el vector ordenado
    cout << "Vector ordenado: ";
    for (int i = 0; i < a.size(); i++) {
       cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <string>
//Para poder usar acentos en la consola
#include <Windows.h>

//Written and Directed By Álvaro García Herrero

/*Recursividad Multiple => Cuando produce más de una llamada recursiva
hacia sí misma con diferentes parámetros.
*/

using namespace std;

long fibonacci(int num);

int main() {
    SetConsoleOutputCP(CP_UTF8); //Con esto permito acentos en la consola

    int n;
    
    cout << "Escribe un numero para calcular su  F(n) de Fibonacci" << endl;
    cin >> n;
    cout << "El f(n) de " << n << " es => " << fibonacci(n) << endl;
    
    return 0;
}

long fibonacci(int num) {
    // Condición base
    if (num == 0) return 0; //Si contamos con que el caso 0 es 0...
    if (num == 1 || num == 2) return 1; // F(1) y F(2) son 1

    return fibonacci(num - 2) + fibonacci(num - 1);
}

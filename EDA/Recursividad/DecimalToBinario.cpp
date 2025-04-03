#include <iostream>
#include <windows.h>

using namespace std;

int dec2bin(int num);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int num;
    cout << "Dime el número positivo entero que convertir en binario:" << endl;
    cin >> num;
    cout << "El número binario es: " << dec2bin(num) << endl; // Llamada a la función recursiva
    return 0;
}

//Crear funcion recursiva que convierta int en binario
int dec2bin(int num) {
    // Caso base: si el número es 0 o 1, simplemente devolver el mismo número
    if (num == 0) {
        return 0;
    }
    if (num == 1) {
        return 1;
    }
    int bit = num%2;
    // Recursión: calcular el valor binario para el número restante => num%2 devuelve el resto (0 o 1)
    return bit + 10 * dec2bin(num / 2); //Construye el bit de derecha a izq
}

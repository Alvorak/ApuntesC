#include <iostream>
#include <string>
//Para poder usar acentos en la consola
#include <Windows.h>

//Written and Directed By Álvaro García Herrero

/*Recursividad Lineal No Final => El resultado final de la función que llama se obtiene
evaluando una expresión que contiene una llamada
recursiva más simple.
*/

using namespace std;

long factorial(int num);

int main() {
    SetConsoleOutputCP(CP_UTF8); //Con esto permito acentos en la consola

    int n;
    
    cout << "Escribe un numero para calcular su factoria n!" << endl;
    cin >> n;
    cout << "El factorial de " << n << " es => " << factorial(n) << endl;
    
    return 0;
}

long factorial(int num){
  //Condicion Base
  if(num == 1){ //Si hemos llegado a que num es 1 devolvemos 1 como fin de la recursividad
    return 1;
  }else{
    return (numero * factorial(num - 1));  // Calculamos el producto del num y el num-1 hasta llegar a 1 (nuestra condición final)
  }
}

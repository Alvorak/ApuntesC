#include <iostream>
#include <string>
//Para poder usar acentos en la consola
#include <Windows.h>

//Written and Directed By Álvaro García Herrero

/*Recursividad Multiple: Implica que más de una función se
llaman mutuamente.
*/

using namespace std;

int par(int n);
int impar(int n);

int main() {
    SetConsoleOutputCP(CP_UTF8); //Con esto permito acentos en la consola

    int n;
    
    cout << "Escribe un numero" << endl;
    cin >> n;
    if(par(n) == 1){
        cout << "El numero " << n << " es par" << endl;
    }else{
        cout << "El numero " << n << " es impar" << endl;
    }
  
    return 0;
}

int par(int n){
  if(n==0){
    return 1; // Un número par devuelve 1
  }else{
    return impar(n-1);
  }
}

int impar(int n){
  if(n==0){
    return 0; // Un número impar devuelve 0
  }else{
    return par(n-1);
  }
}

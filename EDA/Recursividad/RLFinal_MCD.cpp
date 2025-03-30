#include <iostream>
#include <string>
//Para poder usar acentos en la consola
#include <Windows.h>

//Written and Directed By Álvaro García Herrero

/*Recursividad Lineal Final =>El resultado final de la función que llama se obtiene en
la ejecución de la última llamada recursiva.
*/

using namespace std;

int mcd(int a, int b);
int mcd2(int a, int b);

int main() {
    SetConsoleOutputCP(CP_UTF8); //Con esto permito acentos en la consola

    int n1,n2;
    
    cout << "Escribe el primer numero" << endl;
    cin << n1;

    cout << "Escribe el segundo numero" << endl;
    cin << n2;
    
    cout << "El mcd(" << n1 << "," << n2 << ") es => " << mcd(n1,n2) << endl;
    
    return 0;
}

int mcd(int a, int b){
  //Condicion Base
  if(a == b){ //Si a = b hemos llegado al fin del mcd 
    return a;
  }else if(a>b){
    return mcd(a-b,b);  
  }else{
    return mcd(a,b-a);
  }
}
//Opcion 2: mas optima
int mcd2(int a, int b) {
    if (b == 0) return a; //Si el resto es 0 devolvemos a => condicion base y final
    return mcd(b, a % b); //Calculamos el resto y si el resto es 0 se da la condicion final devolviendo el mcd
}

#include <iostream>
#include <string>
//Para poder usar acentos en la consola
#include <Windows.h>

//Written and Directed By Álvaro García Herrero
using namespace std;

class CalcularNumPositivo {
private:
    double numero;
    double resultado;

public:
    // Constructores
    CalcularNumPositivo() : numero(0), resultado(0) {}
    CalcularNumPositivo(double num) : numero(num), resultado(0) {}
    CalcularNumPositivo(const CalcularNumPositivo& otro) : numero(otro.numero), resultado(otro.resultado) {}

    //Set
    void setNumero(double num) { numero = num; }
    //Get
    double getNumero() const { return numero; }
    double getResultado() const { return resultado; } //Para devolver resultado

    //Funciones
    double sumaNum(double valor) {
        resultado = numero + valor; //Sumamos numero y se lo asignamos a resultado
        return resultado;
    }

    double restaNum(double valor) {
        resultado = numero - valor; //Restamos numero y se lo asignamos a resultado
        return resultado;
    }

    double multiplicaPor(double valor) {
        resultado = numero * valor; //Multiplicamos numero y se lo asignamos a resultado
        return resultado;
    }

    double dividePor(double divisor) {
        if (divisor == 0) {
            throw string("Error: división por cero."); //Primera excepcion
        } else if (divisor < 0) {
            throw string("Error: división por un número negativo.");// Segunda excepcion
        } else {
            resultado = numero / divisor; //Sin excepciones, dividimos y asignamos
            return resultado;
        }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8); //Con esto permito acentos en la consola
    CalcularNumPositivo calc(10);

    try {
        cout << "Suma: " << calc.sumaNum(5) << endl;
        cout << "Resta: " << calc.restaNum(3) << endl;
        cout << "Multiplicación: " << calc.multiplicaPor(2) << endl;
        cout << "División: " << calc.dividePor(2) << endl;
        // Intentando dividir por 0 (debe lanzar una excepción)
        cout << "Intento de división por 0: " << endl;
        cout << calc.dividePor(0) << endl;
       // cout << "Intento de división por negativo: " << endl;
       // cout << calc.dividePor(-2) << endl;
    } catch (const string& e) {
        cerr << "Error: " << e << endl;
    }

    return 0;
}

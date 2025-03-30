//Written and Directed By Alvorak
//Ejemplo COLA ESTATICA
#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Tamaño fijo de la cola

// Estructura para los datos de la cola
struct TipoDato {
    string elementoTipoString;
    int elementoTipoInt;
};

// Implementación de la Cola estática
class Cola {
private:
    TipoDato datos[MAX_SIZE]; // Arreglo para almacenar los elementos
    int front, end, count; // Índices de control y contador de elementos

public:
    Cola() : front(0), end(-1), count(0) {} //Constructor por defecto 
    bool empty() const { return count == 0; }
    bool full() const { return count == MAX_SIZE; }
    void push(const TipoDato &dato);
    void pop();
    const TipoDato &first() const;
};

void Cola::push(const TipoDato &dato) {
    if (!full()) {
        end = (end + 1) % MAX_SIZE; //calculamos la posición donde estamos insertando
        datos[end] = dato; //asignamos a esa posicion el dato
        count++; //Incrementamos el numero de elementos en la cola
    } else {
        throw string("La cola está llena");
    }
}

void Cola::pop() {
    if (!empty()) {
        front = (front + 1) % MAX_SIZE; //movemos front al siguiente elemeno, haciendo que el anterior front se vaya
        count--; //reducimos el numero de elementos en la cola
    } else {
        throw string("La cola está vacía");
    }
}

const TipoDato &Cola::first() const {
    if (!empty()) {
        return datos[front];
    }
    throw string("La cola está vacía");
}

//Funciones EXTERNAS extra de examenes

void insertarEnCola(Cola &c) { 
    string input;
    while (true) {
        cout << "Introduce una palabra o frase (escribe 'FIN' para terminar): ";
        getline(cin, input);
        if (input == "FIN") break;
        if (c.full()) {
            cout << "La cola está llena, no se pueden agregar más elementos." << endl;
            break;
        }
        c.push({input, 0});
    }
}


void mostrarCola(const Cola &c) {
    if (c.empty()) {
        cout << "La cola está vacía" << endl;
        return;
    }
    cout << "Elementos en la cola:" << endl;
    for (int i = 0, index = c.front; i < c.count; i++, index = (index + 1) % MAX_SIZE) {
        cout << c.datos[index].elementoTipoString << " - " << c.datos[index].elementoTipoInt << endl; //Aqui he metido int y string pero te quedas con el que estes usando...
    }
}

int vecesElementoCola(const Cola &c, const string &elemento) {
    int contador = 0;
    for (int i = 0, index = c.front; i < c.count; i++, index = (index + 1) % MAX_SIZE) {
        if (c.datos[index].elementoTipoString == elemento) { //Aqui solo estoy buscando string ya sabes
            contador++;
        }
    }
    return contador;
}

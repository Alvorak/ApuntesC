//Written and Directed By Alvorak
//Ejemplo PILA ESTATICA
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

//Apuntes: Hay que tener en cuenta que las funciones van en el cpp y las declaraciones en el header (o en el juzgado)

//Para las estructuras usamos TipoDato => aqui guardamos las opciones de datos que vamos a manejar
struct TipoDato{
    string elementoTipoString;
    int elementoTipoInt;
};

class Stack { //Llaman a PILA en clase STACK?
    public:
    Stack():front(-1){} //Constructor por defecto con la pila vacia

    bool empty() const; //para definir si la pila esta vacia 

    void push(const TipoDato &dato); //Añade un elemento a la pila, al final de la pila
    void pop(); //Elimina el ultimo elemento de la pila -.-
    TipoDato top() const; //Te devuelvo lo que esta al final de la pila. Por eso empieza por TipoDato.

    private:
        vector<TipoDato> datos; //Lista de datos de la pila
        int front; //front nos indica cual es el elemento final de la pila
};
//Funciones de la Pila

bool Stack::empty() const{ 
    return (front == -1); //Es como si preguntaramos si front (el ultimo elemento de la pila) es el -1 (el elemento de la lista vacia) para saber si esta la pila vacia
}

TipoDato Stack::top() const{ //NOTA IMPORTANTE => En el caso de no usar TIPODATO, usariamos int/string/lo que sea que guardemos dentro de la pila (por ejemplo drogas)
    if(front != -1){
        return(datos.at(front)); //Directamente devolvemos el elemento en el "frente" (jaja front es frente), pues no hay mucho mas. Front devuelve lo que esta arriba (España)
    }else {
        return TipoDato(); // Devuelve un TipoDato vacío
    }
}

void Stack::push(TipoDato dato){ //NOTA IMPORTANTE => En el caso de no usar TIPODATO, usariamos int/string/lo que sea que guardemos dentro de la pila (por ejemplo drogas)
        front++; //Indicamos que la pila CRECE 1 elemento (++ es +1)    
        datos.push_back(dato); //push_back => poner elemento al final de algo, en este caso, de nuestra pila
}

void Stack::pop() { //Como Hanna Montana
    if (!empty()) { // Solo eliminar si no está vacía
        front--; //Al igual que con ++, el "--" dice que -1. Si no lo entiendes... Vuelve a la ESO
        datos.pop_back(); //pop_back => quitar el ultimo elemento al final de algo, en este caso, de nuestra pila
    } else {
        cout << "La pila ya esta vacia." << endl;
    }
}

//Funciones que nos suelen pedir en examenes:

void llenarPila(Stack &pila) { //Pasamos la Pila
    string input; //El string/imput que queremos meter
    cout << "Escribe que quieres meter (escribe 'FIN' para terminar):" << endl;
    
    while (true) {
        getline(cin, input); //Asi cogemos frases/palabras
        if (input == "FIN") break; //Fin de la inserccion

        TipoDato dato; //Pues nuestro struc
        dato.elementoTipoString = input; //Input
        dato.elementoTipoInt = 0; // Valor por defecto (que asi no me da error)

        pila.push(dato);
    }
}

//Para mostrar palabras/frases en la pila
void mostrarPila(Stack &pila) {
    if (pila.empty()) {
        cout << "La pila está vacía." << endl;
        return;
    }

    Stack copia = pila; // Copia la pila para no modificar la original
    cout << "Contenido de la pila:" << endl;
    
    while (!copia.empty()) { //Recorremos copia
        cout << copia.top().elementoTipoString << endl; //Mostramos el ultimo elemento de la pila
        copia.pop();//Quitamos el ultimo elemento de la pila
    }
}

//Para contar las palabras/frases de la pila si son < 10 caracteres.
void contarMenosDe10(Stack &pila) {
    if (pila.empty()) {
        cout << "La pila está vacía." << endl;
        return;
    }

    Stack copia = pila; // Copia la pila para no modificar la original
    int contador = 0;

    while (!copia.empty()) {  //Recorremos copia
        if (copia.top().elementoTipoString.length() < 10) { //Comprobamos el ultimo elemento de la pila
            contador++; //Es menor de 10 caracteres
        }
        copia.pop(); //Quitamos el ultimo elemento de la pila
    }
    cout << "La cantidad de elementos con menos de 10 caracteres es: " << contador << endl;
}


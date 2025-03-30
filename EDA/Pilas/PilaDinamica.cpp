//Written and Directed By Alvorak
//Ejemplo PILA DINAMICA
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

class Nodo{ //Si ves un nodo => agarrate los machos que esto es dinamico
    private:
    TipoDato dato; //El contenido de la cola/pila/lo que estamos tratando
    shared_ptr<Nodo> next; //Es la referencia al SIGUIENTE elemento que tratamos en el nodo y si, es un puto puntero

    public:
    Nodo():next(nullptr){} //Constructor por defecto con el nodo vacio
    Nodo(TipoDato d, const shared_ptr<Nodo> &nextDato):dato(d),next(nextDato){}//Constructor PARAMETRICO 

    //Estructura clasica de getters y setters
    TipoDato getDato() const { return dato; }
    void setDato(TipoDato newDato){ dato = newDato; } 
    const shared_ptr<Nodo> &getNext() const{ return next;} //Pos como el getDato => Get SIGUIENTE dato
    void setNext(const shared_ptr<Nodo> &newNext){ next = newNext;} //Pos como el setDato => Set SIGUIENTE dato
};

class Stack { //Llaman a PILA en clase STACK?
    public:
    Stack():front(nullptr){} //Constructor por defecto con la pila vacia => al ser DINAMICO usamos nullptr

    int size() const; //Definimos un tamaño de la pila porque somos dinamicos, no barbaros
    bool empty() const; //para definir si la pila esta vacia 

    void push(const TipoDato dato); //Añade un elemento a la pila, al final de la pila => Fijate que ya no añadimos el "&" en el parametro de entrada
    void pop(); //Elimina el ultimo elemento de la pila -.-
    TipoDato top() const; //Te devuelvo lo que esta al final de la pila. Por eso empieza por TipoDato.

    private:
      shared_ptr<Nodo> front; //Aqui directamente puntero a front porque somos dinamicos, repito, no barbaros
};

//Funciones de la Pila

bool Stack::empty() const{ 
    return (front == nullptr); //Es como si preguntaramos si front (el ultimo elemento de la pila) es el null (el elemento de la lista vacia) para saber si esta la pila vacia
}

TipoDato Stack::top() const{ //NOTA IMPORTANTE => En el caso de no usar TIPODATO, usariamos int/string/lo que sea que guardemos dentro de la pila (por ejemplo drogas)
    if (front) {
        return(front->getDato()); //Directamente devolvemos el elemento en el "frente" (jaja front es frente), pues no hay mucho mas.  Front + getDato devuelve lo que esta(en front), que en este caso, arriba (España)
    } else {
        cout << "La pila está vacía." << endl;
        return TipoDato(); // Devolvemos un TipoDato vacío para evitar errores
    }
}

void Stack::push(TipoDato dato){ //NOTA IMPORTANTE => En el caso de no usar TIPODATO, usariamos int/string/lo que sea que guardemos dentro de la pila (por ejemplo drogas)
    shared_ptr<Nodo> elem;
    elem = make_shared<Nodo>(); //para gestionar la memoria del nodo
    *elem = Nodo(dato, nullptr); //le metemos a elem los datos de Nodo

    if(front != nullptr){ //Si la pila no está vacía, entonces elem debe apuntar al antiguo front, asegurando que la estructura en forma de pila se mantenga
        elem -> setNext(front);
    }
    //Actualizamos el frente de la Pila
    front = elem;
}

void Stack::pop() { //Como Hanna Montana
  if (front) {
    front = front->getNext();//Pues simple, quitamos el ultimo elemento de la pila
    } else {
        cout << "La pila ya está vacía." << endl;
    }
}


// Función para llenar la pila con datos ingresados por el usuario
void llenarPila(Stack &pila) {
    string input;
    cout << "Escribe qué quieres meter (escribe 'FIN' para terminar):" << endl;
    
    while (true) {
        getline(cin, input);
        if (input == "FIN") break;
        
        TipoDato dato;
        dato.elementoTipoString = input;
        dato.elementoTipoInt = 0; 
        
        pila.push(dato);
    }
}

// Función para mostrar los elementos de la pila
void mostrarPila(Stack &pila) {
    if (pila.empty()) {
        cout << "La pila está vacía." << endl;
        return;
    }

    Stack copia = pila;
    cout << "Contenido de la pila:" << endl;
    
    while (!copia.empty()) {
        cout << copia.top().elementoTipoString << endl;
        copia.pop();
    }
}

// Función para contar los elementos con menos de 10 caracteres
void contarMenosDe10(Stack &pila) {
    if (pila.empty()) {
        cout << "La pila está vacía." << endl;
        return;
    }

    Stack copia = pila;
    int contador = 0;
    
    while (!copia.empty()) {
        if (copia.top().elementoTipoString.length() < 10) {
            contador++;
        }
        copia.pop();
    }
    cout << "La cantidad de elementos con menos de 10 caracteres es: " << contador << endl;
}

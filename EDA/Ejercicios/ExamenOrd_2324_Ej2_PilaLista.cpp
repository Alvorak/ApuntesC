#include <iostream>
#include <memory>

using namespace std;
//Written And Directed By Alvorak
//Ejercicio 2 Examen Ordinaria 23-24


//Clase del Nodo
class Nodo{
private:
    int dato;
    shared_ptr<Nodo> next;
public:
    Nodo(int d): dato(d), next(nullptr){} //Parametrico
    ~Nodo(){}
    //Getter
    int getDato() const {
        return dato;
    }

    void setDato(int newDato){
        dato = newDato;
    }
    const shared_ptr<Nodo> &getNext() const {
        return next;
    }
    void setNext(const shared_ptr<Nodo> &newNext){
        next = newNext;
    }
};

class Pila{
private:
    shared_ptr<Nodo> cima;
public:
    Pila():cima(nullptr){}
    Pila(Pila const &P);
    ~Pila(){}

    bool empty() const{
        return cima == nullptr;
    }

    void push(int dato){//Insertamos en la pila
        // Creamos un nuevo nodo y lo inicializamos con el dato proporcionado
        shared_ptr<Nodo> newDato = make_shared<Nodo>(dato);
        // Verificamos si la pila no está vacía
        if (!empty()) {
            // Si no está vacía, establecemos el nuevo nodo como siguiente de la cima actual
            newDato->setNext(cima);
        }
        // Establecemos el nuevo nodo como la nueva cima de la pila
        cima = newDato;
    }

    void pop(){ //elimina lo que esta en la cima
        if(cima){ //Si no es null
            cima -> getNext(); //Sacamos la cima para pasar al siguiente
        }else{
            cout << "Pila vacía" << endl;
        }
    }

    int top() const{ //Devuelve la cima
        if(cima){
            return(cima ->getDato());
        }else{
            cout << "Pila vacía" << endl;
            return 0;
        }
    }
};

class Lista{
private:
    shared_ptr<Nodo> principio;
public:
    Lista():principio(nullptr){}
    ~Lista(){}

    bool empty() const{
        return principio == nullptr;
    }

    void push_principio(int dato){
        // Creamos un nuevo nodo y lo inicializamos con el dato proporcionado
        shared_ptr<Nodo> newDato = make_shared<Nodo>(dato);
        // Verificamos si la lista no está vacía
        if (!empty()) {
            // Si no está vacía, establecemos el nuevo nodo como siguiente de la cima actual
            newDato->setNext(principio);
        }
        // Establecemos el nuevo nodo como la nueva cima de la pila
        principio = newDato;
    }
    int primero(){
       return principio -> getDato();
    }
    const shared_ptr<Nodo> &getPrincipio() const{
        return principio;
    }
    void setPrincipio(shared_ptr<Nodo> const &newPrincipio){
        principio = newPrincipio;
    }

    void push_Final(int dato) {
        // Creamos un nuevo nodo con el dato
        shared_ptr<Nodo> nuevo = make_shared<Nodo>(dato);

        if (empty()) {
            // Si la lista está vacía, el nuevo nodo es el primero
            principio = nuevo;
        } else {
            // Recorremos la lista hasta el último nodo
            shared_ptr<Nodo> temporal = principio;
            while (temporal->getNext() != nullptr) {
                temporal = temporal->getNext(); // Avanzamos
            }
            // Enlazamos el nuevo nodo al final
            temporal->setNext(nuevo);
        }
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

void crearListaDesdePila(const Pila &P, Lista &L) {
    // Creamos una copia local de la pila para no modificar la original
    Pila copia = P;

    // Recorremos la copia de la pila y vamos insertando los datos al final de la lista
    while (!copia.empty()) {
        L.push_Final(copia.top());
        copia.pop();
    }
}


#include <iostream>
#include <memory>
#include <vector>
//Written and Directed By Alvorak
using namespace std;

//---------------Clase CDato
class CDato {
private:
    int n;
public:
    CDato() : n(0) {}
    CDato(int valor) : n(valor) {}

    int getN() const { return n; }
    void setN(int newN) { n = newN; }
};

//---------------Clase Nodo
class Nodo {
private:
    CDato dato;
    shared_ptr<Nodo> next = nullptr;
public:
    Nodo() = default;
    Nodo(const CDato& d, const shared_ptr<Nodo>& ptr) : dato(d), next(ptr) {}
    Nodo(const CDato& d) : dato(d) {}
    ~Nodo() = default;

    const CDato& getDato() const { return dato; }
    void setDato(const CDato& newDato) { dato = newDato; }
    const shared_ptr<Nodo>& getNext() const { return next; }
    void setNext(const shared_ptr<Nodo>& newNext) { next = newNext; }
};

//---------------Clase Lista
class Lista {
private:
    shared_ptr<Nodo> first;
public:
    Lista() : first(nullptr) {}

    // Constructor copia: clona los nodos de otra lista
    Lista(const Lista& L) {
        if (L.empty()) {
            first = nullptr;
        } else {
            first = make_shared<Nodo>(L.front(), nullptr);
            shared_ptr<Nodo> current = first;
            shared_ptr<Nodo> temp = L.first->getNext();
          
            while (temp) {
                current->setNext(make_shared<Nodo>(temp->getDato(), nullptr));
                current = current->getNext();
                temp = temp->getNext();
            }
        }
    }

    bool empty() const { return (first == nullptr); } //Si la lista esta vacia

    // Inserta un elemento al principio de la lista
    void push_front(const CDato& dato) {
        shared_ptr<Nodo> ptr = make_shared<Nodo>(dato, first);
        first = ptr;
    }

    // Devuelve el dato del primer dato de la lista
    const CDato& front() const { return first->getDato(); }

    // Devuelve el dato del último nodo de la lista
    const CDato& back() const {
        shared_ptr<Nodo> temp = first;
        while (temp->getNext()) {
            temp = temp->getNext();
        }
        return temp->getDato();
    }

    // Elimina el primer nodo de la lista
    void pop_front() { first = first->getNext(); }

    const shared_ptr<Nodo>& getFirst() const { return first; }//Coge el Nodo que corresponde al primer elemento
    void setFirst(const shared_ptr<Nodo>& newFirst) { first = newFirst; }

    // Muestra todos los elementos de la lista
    void mostrarLista() const {
        shared_ptr<Nodo> temp = first;
        while (temp) {
            cout << temp->getDato().getN() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    // Devuelve el valor mayor en la lista
    int mayorLista() const {
        if (empty()) return -1;
        int max = first->getDato().getN();
        shared_ptr<Nodo> temp = first->getNext();
        while (temp) {
            if (temp->getDato().getN() > max) {
                max = temp->getDato().getN();
            }
            temp = temp->getNext();
        }
        return max;
    }

    // Comprueba si un valor existe en la lista
    bool existeEnLista(int valor) const {
        shared_ptr<Nodo> temp = first;
        while (temp) {
            if (temp->getDato().getN() == valor) return true;
            temp = temp->getNext();
        }
        return false;
    }
    // Cuenta cuántas veces aparece un valor en la lista
    int vecesEnLista(int valor) const {
        int count = 0;
        shared_ptr<Nodo> temp = first;
        while (temp) {
            if (temp->getDato().getN() == valor) count++;
            temp = temp->getNext();
        }
        return count;
    }
};
// Funciones auxiliares externas integradas como métodos de clase:

// Mostrar la lista (alternativa externa ahora integrada)
    void mostrarLista(const Lista &L) {
    shared_ptr<Nodo> temp =L.getFirst();
    while (temp) {
        cout << temp->getDato().getN() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}
// Valor mayor en la lista (alternativa externa ahora integrada)
   int elementoMayorLista(const Lista &L) {
    if (L.empty()) return -1;
    int max = L.getFirst()->getDato().getN();
    shared_ptr<Nodo> temp = L.getFirst()->getNext();
    while (temp) {
        if (temp->getDato().getN() > max) {
            max = temp->getDato().getN();
        }
        temp = temp->getNext();
    }
    return max;
}

// Búsqueda de un valor en la lista (alternativa externa ahora integrada)
bool buscarElemLista(const Lista &L, int valor) {
    int count = 0;
    shared_ptr<Nodo> temp = L.getFirst();
    while (temp) {
        if (temp->getDato().getN() == valor) count++;
        temp = temp->getNext();
    }
    return count;
}

// Conteo de apariciones de un valor (alternativa externa ahora integrada)
int vecesElemLista(const Lista &L, int valor) {
    int count = 0;
    shared_ptr<Nodo> temp = L.getFirst();
    while (temp) {
        if (temp->getDato().getN() == valor) count++;
        temp = temp->getNext();
    }
    return count;
}

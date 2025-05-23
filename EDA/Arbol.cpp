#include <iostream>
#include <memory>
//Written and Edited by Álvaro García Herrero
using namespace std;
//Clase CDato
class CDato {
private:
    int n;
public:
    CDato(): n(0) {}
    CDato(int d): n(d) {}

    int getN() const { return n; }
    void setN(int newN) { n = newN; }
};


//Clase Nodo
class Nodo {
public:
    CDato dato;
    shared_ptr<Nodo> hizq;
    shared_ptr<Nodo> hdch;

    Nodo(): hizq(nullptr), hdch(nullptr) {}
    Nodo(const CDato& d): dato{d}, hizq(nullptr), hdch(nullptr) {}

    const CDato& getDato() const { return dato; }
    void setDato(const CDato& newDato) { dato = newDato; }

    const shared_ptr<Nodo>& getHizq() const { return hizq; }
    void setHizq(const shared_ptr<Nodo>& newHizq) { hizq = newHizq; }

    const shared_ptr<Nodo>& getHdch() const { return hdch; }
    void setHdch(const shared_ptr<Nodo>& newHdch) { hdch = newHdch; }

    void procesarNodo() const {
        cout << "%n%n%tNodo: " << getDato().getN();
    }
};


//Clase Arbol Binario de Busqueda (ABB)
class Arbol {
private:
    shared_ptr<Nodo> raiz;

public:
    Arbol(): raiz(nullptr) {}
    Arbol(const CDato& dato) { raiz = make_shared<Nodo>(Nodo{dato}); }

    bool empty() const { return (raiz == nullptr); }

    void addHizq(const Arbol &Ai){
        raiz -> setHizq(Ai.raiz);
    }
    void addHdch(const Arbol &Ad){
        raiz -> setHdch(Ad.raiz);
    }

    const CDato &getDatoNodo () const{
        return raiz->getDato();
    }
    const shared_ptr<Nodo> &getHiNodo() const{
        return raiz->getHizq();
    }
    const shared_ptr<Nodo> &getHdNodo() const{
        return raiz->getHdch();
    }

    void construirArbol (const Arbol &Ai, const Arbol &Ad, const CDato &dato){
        raiz = make_shared<Nodo>(Nodo{dato});
        raiz->setHizq(Ai.raiz);
        raiz->setHdch(Ad.raiz);
    }

    void InOrden(const shared_ptr<Nodo> &A) const {
        if (A != nullptr) {
            InOrden (A->getHizq());		// Izquierda
            A->procesarNodo();          // Raiz
            InOrden (A->getHdch());     // Derecha
        }
    }
    void recorrerInOrden() const {
        if (!empty()) {
            InOrden (raiz);
        }
    }

    void PreOrden(const shared_ptr<Nodo> &A) const {
        if (A != nullptr) {
            PreOrden (A->getHizq());      // Izquierda
            A->procesarNodo();            // Raiz
            PreOrden (A->getHdch());      // Derecha
        }
    }
    void recorrerPreOrden() const{
        if (!empty()) {
            PreOrden (raiz);
        }
    }

    void PostOrden(const shared_ptr<Nodo> &A) const {
        if (A != nullptr) {
            PostOrden (A->getHizq());	   // Izquierda
            A->procesarNodo();             // Raiz
            PostOrden (A->getHdch());      // Derecha
        }
    }
    void recorrerPostOrden() const {
        if (!empty()) {
            PostOrden (raiz);
        }
    }

    const shared_ptr<Nodo> &getRaiz() const{
        return raiz;
    }
    void setRaiz(const shared_ptr<Nodo> &newRaiz){
         raiz = newRaiz;
    }

    void recorrerAnchura () const; //Definimos fuera la funcion para poder usar cola

    //Funciones de ejercicios:
    int contarNodos() const; //EJ 1
    int sumarNodos() const; //EJ 2
    int contarNodosPares() const; //EJ 3
    int altura() const; //Ej 4
    int contarHojas() const; //EJ 5
};

//Funciones tipicas de ejercicio:

// Ejercicio 1: Contar el número total de nodos en el árbol
int contarNodosRec(const shared_ptr<Nodo>& nodo) {
    if (nodo == nullptr) return 0; // Caso base: nodo nulo no cuenta

    // Cuenta el nodo actual (1) + recursivamente cuenta los nodos del subárbol izquierdo y derecho
    return 1 + contarNodosRec(nodo->getHizq()) + contarNodosRec(nodo->getHdch());
}

int Arbol::contarNodos() const {
    return contarNodosRec(raiz); // Inicia desde la raíz
}

// Ejercicio 2: Calcular la suma de todos los valores almacenados en los nodos del árbol
int sumarNodosRec(const shared_ptr<Nodo>& nodo) {
    if (nodo == nullptr) return 0; // Caso base: nodo nulo no aporta suma

    // Suma el valor del nodo actual + suma recursiva de los valores de los subárboles izquierdo y derecho
    return nodo->getDato().getN() +
           sumarNodosRec(nodo->getHizq()) +
           sumarNodosRec(nodo->getHdch());
}

int Arbol::sumarNodos() const {
    return sumarNodosRec(raiz); // Inicia desde la raíz
}

// Ejercicio 3: Contar cuántos nodos almacenan un valor par
int contarNodosParesRec(const shared_ptr<Nodo>& nodo) {
    if (nodo == nullptr) return 0; // Caso base: nodo nulo no cuenta

    int valor = nodo->getDato().getN(); // Extrae el valor del nodo actual
    int cuenta = (valor % 2 == 0) ? 1 : 0; // Cuenta 1 si es par, 0 si no

    // Suma el resultado actual + cuenta recursiva de los subárboles
    return cuenta +
           contarNodosParesRec(nodo->getHizq()) +
           contarNodosParesRec(nodo->getHdch());
}

int Arbol::contarNodosPares() const {
    return contarNodosParesRec(raiz); // Inicia desde la raíz
}

// Ejercicio 4: Calcular la altura del árbol
int alturaRec(const shared_ptr<Nodo>& nodo) {
    if (nodo == nullptr) return 0; // Caso base: árbol vacío tiene altura 0

    // Calcula recursivamente la altura del subárbol izquierdo y derecho
    int altIzq = alturaRec(nodo->getHizq());
    int altDer = alturaRec(nodo->getHdch());

    // Altura del nodo actual es 1 + la mayor altura de sus dos hijos
    return 1 + max(altIzq, altDer);
}

int Arbol::altura() const {
    return alturaRec(raiz); // Inicia desde la raíz
}

// Ejercicio 5: Contar el número de nodos hoja (nodos sin hijos)
int contarHojasRec(const shared_ptr<Nodo>& nodo) {
    if (nodo == nullptr) return 0; // Caso base: nodo nulo no cuenta

    // Si no tiene hijos izquierdo ni derecho, es una hoja
    if (nodo->getHizq() == nullptr && nodo->getHdch() == nullptr) {
        return 1;
    }

    // Sigue buscando hojas en los subárboles izquierdo y derecho
    return contarHojasRec(nodo->getHizq()) + contarHojasRec(nodo->getHdch());
}

int Arbol::contarHojas() const {
    return contarHojasRec(raiz); // Inicia desde la raíz
}

//Para los niveles del arbol => Cola Dinámica
class NodoCola {
    private:
        Arbol elem;
        shared_ptr<NodoCola> sig;
    public:
        NodoCola():sig(nullptr) {};
        NodoCola(const Arbol &d, const shared_ptr<NodoCola> &ptr):elem(d),sig(ptr){}

        const Arbol &getElem() const;
        void setElem(const Arbol &newElem);

        const shared_ptr<NodoCola> &getSig() const;
        void setSig(const shared_ptr<NodoCola> &newSig);
};

class Cola {
    private:
        shared_ptr<NodoCola> ppio;
        shared_ptr<NodoCola> final;

    public:
        Cola():ppio(nullptr), final(nullptr){};

        bool empty() const;
        void push(const Arbol &dato);
        void pop();
        const Arbol &first() const;
};
const Arbol &NodoCola::getElem() const {
    return elem;
}
void NodoCola::setElem(const Arbol &newElem) {
    elem = newElem;
}

const shared_ptr<NodoCola> &NodoCola::getSig() const {
    return sig;
}
void NodoCola::setSig(const shared_ptr<NodoCola> &newSig) {
    sig = newSig;
}

// Inserta un elemento en la posición final de la cola
void Cola::push(const Arbol &dato) {
    shared_ptr<NodoCola> ptraux = make_shared<NodoCola>(NodoCola(dato, nullptr));

    if (this->empty()) {
        ppio = ptraux;
    }
    else  {
        final->setSig(ptraux);
    }
    final = ptraux;  // El puntero final de la cola debe seÃ±alar siempre al elemento incluido
}

// Elimina un elemento de la primera posiciÃ³n de la cola
void Cola::pop()  {
    ppio = ppio->getSig();
    if (ppio == nullptr) {
        final = nullptr;  // La cola queda vacÃ­a
    }
}

// Devuelve el elemento de la primera posiciÃ³n de la cola
const Arbol &Cola::first() const {
    return (ppio->getElem());
}

// Determina si la cola estÃ¡ vacÃ­a o no
bool Cola::empty() const  {
    return (ppio == nullptr && final == nullptr);
}
void Arbol::recorrerAnchura () const{
    Arbol Bi, Bd, B;
    Cola Niveles;
    CDato dato;

    if (!empty()) {
        Niveles.push(*this);    // Se añade el nodo raíz del Árbol, 1er. Nivel
    }
    while(!Niveles.empty()) {
        B = Niveles.first();  // Se extrae un elemento de la cola
        Niveles.pop();

        dato = B.getDatoNodo();
        Bi.setRaiz(B.getHiNodo());
        Bd.setRaiz(B.getHdNodo());
        cout << "%n%n%tNodo: " << dato.getN();

        //  Se añade al final de la cola el hi y hd, si es que existen.
        //  Siempre se procesan después de hacerlo los del nivel anterior.
        if (!Bi.empty()) {
            Niveles.push(Bi);
        }

        if (!Bd.empty()) {
            Niveles.push(Bd);
        }
    }
}
int main() {

    Arbol N0, Nizq, Ndch, N1, N2, N3;
    CDato dato(2);
    N1.construirArbol(Nizq, Ndch, dato);
    dato.setN(4);
    N2.construirArbol(N1, Ndch, dato);

    dato.setN(1);
    N1.construirArbol(Nizq, Ndch, dato);
    dato.setN(3);
    N3.construirArbol(Nizq, N1, dato);

    dato.setN(7);
    N1.construirArbol(N2, N3, dato);

    dato.setN(6);
    N2.construirArbol(Nizq, Ndch, dato);
    dato.setN(5);
    N0.construirArbol(Nizq, Ndch, dato);

    dato.setN(8);
    N3.construirArbol(N2, N0, dato);

    dato.setN(9);
    N0.construirArbol(N3, N1, dato);

    cout << "%n%n%n%tRecorrido InOrden";
    cout << "%n%t====================";
    N0.recorrerInOrden();


    cout << "%n%n%n%tRecorrido PreOrden";
    cout << "%n%t====================";
    N0.recorrerPreOrden();


    cout << "%n%n%n%tRecorrido PostOrden";
    cout << "%n%t====================";
    N0.recorrerPostOrden();

    cout << "%n%n%n%tRecorrido en ANCHURA";
    cout << "%n%t====================";
    N0.recorrerAnchura();

    cout << "%n%n%t";
    return 0;

}

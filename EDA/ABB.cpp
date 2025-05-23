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

    const shared_ptr<Nodo>& getRaiz() const { return raiz; }
    void setRaiz(const shared_ptr<Nodo>& newRaiz) { raiz = newRaiz; }

    void addHizq(const Arbol& Ai) { raiz->setHizq(Ai.raiz); }
    void addHdch(const Arbol& Ad) { raiz->setHdch(Ad.raiz); }

    void construirArbol(const Arbol& Ai, const Arbol& Ad, const CDato& dato) {
        raiz = make_shared<Nodo>(Nodo{dato});
        raiz->setHizq(Ai.raiz);
        raiz->setHdch(Ad.raiz);
    }

    // Inserta un nodo de forma recursiva
    void insertadoNodoABBRec(shared_ptr<Nodo>& A, const CDato& dato) {
        if (A == nullptr) {
            A = make_shared<Nodo>();
            *A = Nodo(dato);
        } else {
            if (A->getDato().getN() > dato.getN()) {
                insertadoNodoABBRec(A->hizq, dato);
            } else {
                insertadoNodoABBRec(A->hdch, dato);
            }
        }
    }

    void insertarNodoABBRec(const CDato& dato) {
        insertadoNodoABBRec(raiz, dato);
    }

    // Recorrido InOrden del arbol
    void InOrden(shared_ptr<Nodo> A) const {
        if (A != nullptr) {
            InOrden(A->getHizq());
            A->procesarNodo();
            InOrden(A->getHdch());
        }
    }

    void recorrerInOrden() const {
        if (!empty()) {
            InOrden(raiz);
        }
    }

    // Busqueda recursiva en ABB
    shared_ptr<Nodo> busquedaNodoABBRec(shared_ptr<Nodo> A, const CDato& dato) const {
        if (A != nullptr) {
            if (A->getDato().getN() > dato.getN()) {
                A = busquedaNodoABBRec(A->getHizq(), dato);
            } else if (A->getDato().getN() < dato.getN()) {
                A = busquedaNodoABBRec(A->getHdch(), dato);
            }
        }
        return A;
    }

    shared_ptr<Nodo> buscarNodoABBRec(const CDato& dato) const {
        if (!empty()) {
            return busquedaNodoABBRec(raiz, dato);
        } else {
            return nullptr;
        }
    }

    // Contar nodos recursivamente
    int calculaNodosRec(const shared_ptr<Nodo>& A) const {
        if (A == nullptr) {
            return 0;
        } else {
            return 1 + calculaNodosRec(A->getHizq()) + calculaNodosRec(A->getHdch());
        }
    }

    int calcularNodosArbolRec() const {
        return empty() ? 0 : calculaNodosRec(raiz);
    }

    // Calcular suma de los valores de nodos
    int calculaSumaNodosRec(const shared_ptr<Nodo>& A) const {
        if (A == nullptr) {
            return 0;
        } else {
            return A->getDato().getN() + calculaSumaNodosRec(A->getHizq()) + calculaSumaNodosRec(A->getHdch());
        }
    }

    int calcularSumaNodosArbolRec() const {
        return empty() ? 0 : calculaSumaNodosRec(raiz);
    }

    // Contar nodos pares
    int calculaNodosParesRec(const shared_ptr<Nodo>& A) const {
        if (A == nullptr) {
            return 0;
        } else if (A->getDato().getN() % 2 == 0) {
            return 1 + calculaNodosParesRec(A->getHizq()) + calculaNodosParesRec(A->getHdch());
        } else {
            return calculaNodosParesRec(A->getHizq()) + calculaNodosParesRec(A->getHdch());
        }
    }

    int calcularNodosParesArbolRec() const {
        return empty() ? 0 : calculaNodosParesRec(raiz);
    }

    // Buscar el mayor de los menores (rama izquierda, nodo más a la derecha)
    const CDato& elMAYORdeMENORES(const shared_ptr<Nodo>& A) {
        if (A->hdch != nullptr) {
            return elMAYORdeMENORES(A->hdch);
        } else {
            return A->dato;
        }
    }

    const CDato& elMAYORdeMENORESIter(shared_ptr<Nodo> A) {
        while (A->hdch != nullptr) {
            A = A->hdch;
        }
        return A->dato;
    }

    // Eliminacion de un nodo del ABB
    void eliminarNodoABB(const CDato& dato) {
        shared_ptr<Nodo> A{raiz};
        shared_ptr<Nodo> Apadre{nullptr};
        bool enc{false};

        while ((A != nullptr) && !enc) {
            if (A->dato.getN() == dato.getN()) {
                enc = true;
            } else {
                Apadre = A;
                if (dato.getN() < A->dato.getN()) {
                    A = A->hizq;
                } else {
                    A = A->hdch;
                }
            }
        }

        if (A != nullptr) {
            if (A->hizq != nullptr && A->hdch != nullptr) {
                A->dato = elMAYORdeMENORES(A->hizq);
                Apadre = A;
                A = A->hizq;
                while (A->hdch != nullptr) {
                    Apadre = A;
                    A = A->hdch;
                }
            }

            shared_ptr<Nodo> Anext;
            if (A->hizq != nullptr) {
                Anext = A->hizq;
            } else {
                Anext = A->hdch;
            }

            if (Apadre == nullptr) {
                raiz = Anext;
            } else {
                if (Apadre->hizq == A) {
                    Apadre->hizq = Anext;
                } else {
                    Apadre->hdch = Anext;
                }
            }
        }
    }
    // Busqueda iterativa en ABB ====================> EJERCICIO
    shared_ptr<Nodo> buscarNodoABBIter(const CDato& dato) const {
        shared_ptr<Nodo> actual = raiz;

        while (actual != nullptr) {
            if (dato.getN() == actual->dato.getN()) {
                return actual; // Encontrado
            } else if (dato.getN() < actual->dato.getN()) {
                actual = actual->hizq; // Ir a la izquierda
            } else {
                actual = actual->hdch; // Ir a la derecha
            }
        }

        return nullptr; // No encontrado
    }

};

int main() {
    CDato dato;
    int n;
    Arbol A;

    do {
        cout << "%n%tIntroduzca un numero (negativo para terminar): ";
        cin >> n;
        dato.setN(n);
        if (n > 0) {
            A.insertarNodoABBRec(dato);
        }
    } while (n > 0);

    cout << "%n%n%tRecorrido InOrden%n";
    A.recorrerInOrden();

    cout << "%n%tEl numero de nodos es " << A.calcularNodosArbolRec();
    cout << "%n%tLa suma de los nodos es " << A.calcularSumaNodosArbolRec();
    cout << "%n%tEl numero de nodos pares es " << A.calcularNodosParesArbolRec();

    cout << "%n%n%t";
    int valor = 20;
    auto resultado = A.buscarNodoABBIter(CDato(valor));
    if (resultado != nullptr) {
        cout << "%n%n%tEl nodo " << valor << " existe." << endl;
    } else {
        cout << "%n%n%tEl nodo " << valor << " no existe." << endl;
    }
    return 0;
}

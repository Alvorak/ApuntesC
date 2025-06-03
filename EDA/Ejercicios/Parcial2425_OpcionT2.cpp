#include <iostream>
#include <memory>
//Written And Directed By Alvorak

using namespace std;

struct TipoDato{
    int num;
};

class Nodo {
private:
    TipoDato dato;
    shared_ptr<Nodo> next;
public:
    Nodo():next(nullptr){}
    Nodo(TipoDato const &d, shared_ptr<Nodo> ptr): dato(d), next(ptr) {}

    const TipoDato &getDato() const{
        return dato;
    }
    const shared_ptr<Nodo> getNext() const{
        return next;
    }
    void setDato(const TipoDato &newDato){
        dato = newDato;
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
    Pila(const Pila &P); //Copia

    //Ejercicio
    Pila invertirPila(){
        Pila invertida;
        shared_ptr<Nodo> pilaAux(nullptr);
        shared_ptr<Nodo> pQ = cima; //asi no me cargo la original

        while (pQ != nullptr) { //Recorremos la copia
            // Creamos un nuevo nodo con el dato actual y lo conectamos al anterior
            pilaAux = make_shared<Nodo>(pQ->getDato(), pilaAux);
            pQ = pQ->getNext(); // Avanzamos al siguiente nodo
        }

        invertida.cima = pilaAux; // Asignamos la nueva cima invertida => ya que el ultimo elemento es este
        return invertida; // Devolvemos la pila invertida
    }
};
class Cola{
private:
    shared_ptr<Nodo> front,end; //front es el primero en salir y entrar recuerda es como ir al cine
public:
    Cola():front(nullptr), end(nullptr) {}
    Cola(const Cola &Q);

    bool empty() const;
    void push(const TipoDato &newDato){
       shared_ptr<Nodo> ptraux = make_shared<Nodo>(Nodo(newDato, nullptr));
       if (this->empty()) {
           front = ptraux; //SI esta vacia el primero es el primero en salir
       }
       else  {
           end->setNext(ptraux); //end es el final de la cola (primero en llegar)
       }
       // El puntero final de la cola debe SEÑALAR siempre al elemento incluido
       end = ptraux; //Para que end sea null y tengamos hueco para otro
      }
    void pop(){
        front = front->getNext();
        if (front == nullptr) {
            end = nullptr;  // La cola queda vacía
        }
    }
    const TipoDato &first() const { return (front -> getDato()); }
};
int contarDatoCola(const Cola&Q, const TipoDato &elementoBuscado){
    Cola copia(Q); //Creo una copia para no romper el original
    int contador{0};
    while(!copia.empty()){ //Mientras no este vacia
        if(copia.first().num == elementoBuscado.num){ //Comparamos el num
            contador ++; //Sumamos uno
        }
        copia.pop(); //Quitamos el elemento y pasamos al siguiente
    }
    return contador;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

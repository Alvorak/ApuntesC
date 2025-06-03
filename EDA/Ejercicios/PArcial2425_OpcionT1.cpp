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
    bool empty() const { return cima == nullptr; }
    const shared_ptr<Nodo> getCima() const {return cima;}
    const TipoDato &top() const{
        return cima ->getDato();
    }
    void pop(){
        if(!empty()){
            cima = cima -> getNext();
        }
    }
};
bool contarDatoPila(const Pila &p, const TipoDato &elem){
    Pila copia(p);
    if(!copia.empty()){
        if(copia.top().num == elem.num){
           return true;
        }
        copia.pop();
    }else{
        cout << "Pila vacía" << endl;
    }
    return false;
}
class Cola{
private:
    shared_ptr<Nodo> front,end; //end es el primero en salir y entrar recuerda es como ir al cine
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
           end->setNext(ptraux); //end es el principio de la cola (primero en llegar)
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
    const TipoDato &first() const { return front -> getDato(); }
    Cola invertirCola(){
        Cola invertida;
        if(!empty()){
            shared_ptr<Nodo> colaAux,colaNew; //Cola nueva y cola aux
            shared_ptr<Nodo> colaQ(front); //Copiamos la cola
            while(colaQ!=nullptr){ //Recorremos cola
             colaNew = make_shared<Nodo>(colaQ -> getDato(),colaAux); //El front es colaQ y el nullptr/aux es el end
             colaAux = colaNew; //pasamos los datos a aux
             if(colaQ==front){
                 invertida.end = colaAux; //Si es el primero acemos que el front sea el primer elemento
             }
             colaQ = colaQ->getNext(); //Pasamos al siguiente
            }
            invertida.front = colaAux; //Asignacion final de aux
        }
        return invertida;
    }
};
int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

//Written and Directed By Alvorak
//Ejemplo COLA DINAMICA
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
    Nodo() : next(nullptr){} //Constructor por defecto con el nodo vacio
    Nodo(TipoDato d, const shared_ptr<Nodo> &nextDato):dato(d),next(nextDato){}//Constructor PARAMETRICO 
    ~Nodo(){} //Destructor de mundos y suspensos

    //Estructura clasica de getters y setters
    TipoDato getDato() const { return dato; }
    void setDato(TipoDato newDato) { dato = newDato; }
    const shared_ptr<Nodo> &getNext() const { return next; } //Pos como el getDato => Get SIGUIENTE dato
    void setNext(const shared_ptr<Nodo> &newNext) { next = newNext; }//Pos como el setDato => Set SIGUIENTE dato
};


class Cola { //Una Joja Jola
    private:
    shared_ptr<Nodo> front, end; //Aqui directamente puntero a front y end porque somos dinamicos, repito, no barbaros

    public:
    Cola():front(nullptr), end(nullptr){} //Constructor por defecto con la cola vacia => al ser DINAMICO usamos nullptr => DECLARAMOS el inicio y fin de la cola
    Cola(const Cola &Q); //Constructor por copia => el control c + control v de toda la vida vaya
    ~Cola(); //Destructor de colas Aka Mario

    bool empty() const; //para definir si la cola esta vacia 

    void push(const TipoDato &dato); //Añade un elemento a la cola, al final de la cola => Fijate que ya AHORA si añadimos el "&" en el parametro de entrada
    void pop(); //Elimina el ultimo elemento de la cola -.-
    const TipoDato& Cola::first() const { return front->getDato(); }    //Te devuelvo lo que esta al principio de la cola. Por eso empieza por TipoDato y pone "first".

};

//Funciones de la Cola

bool Cola::empty() const{ 
    return (front == nullptr && end == nullptr); //Es como si preguntaramos si  y end es el null (el elemento de la lista vacia) para saber si esta la cola vacia
}

void Cola::push(TipoDato &dato){ //NOTA IMPORTANTE => En el caso de no usar TIPODATO, usariamos int/string/lo que sea que guardemos dentro de la cola (por ejemplo drogas)
    shared_ptr<Nodo> datoAux; //Lo que antes era elem ahora es datoAux
    datoAux = make_shared<Nodo>(); //para gestionar la memoria del nodo
    *datoAux = Nodo(dato, nullptr); //le metemos a datoAux los datos de Nodo

    if(front == nullptr && end == nullptr){ //Si la cola no está vacía, pos ale
        elem -> setNext(front);
    }
    //Actualizamos el final de la cola
    front = datoAux;
}

void Cola::pop() { //Como Hanna Montana
    front = front->getNext(); //Para eliminar el elemento al principio de la cola
    if(front == nullptr){ //Ostras hemos llegado al final
        end = nullptr; //Pos la cola queda vacia
    }
}

Cola::~Cola(){
    while(!(front == nullptr && end == nullptr)){ //Mientras no este la cola vacia seguimos => es igual que pop pero con un bulce (vaya como Hanna Montana)
        front ->getNext();
        if(front == nullptr){ //Ostras hemos llegado al final
            endl = nullptr; //Pos la cola queda vacia
        }
    }
}

Cola::Cola(const Cola &Q){
    if (Q.empty()) {
        front = nullptr;
        end = nullptr;
    }
    else {
        // Se declaran 2 punteros.
        // ptrNew sirve para crear los nodos de la Cola
        // qS sirve para recorrer los nodos de la Cola que se quiere copiar.
        // Se inicializa seÃ±alando al primer elemento de la Cola
        shared_ptr<Nodo> ptrNew, qS{Q.front};

        // Creamos el primer nodo y copiamos el valor del primer elemento de la cola que se quiere copiar
        ptrNew = make_shared<Nodo>();
        *ptrNew = Nodo(Q.front->getDato(), nullptr);

        //Señalamos el primer elemento creado a travÃ©s de pNew como el primer elemento y el Ãºltimo
        // de la cola copia
        end = ptrNew;
        front = ptrNew;

        // Se avanza en la cola que se quiere copiar
        qS=qS->getNext();

        // Bucle para procesar y copiar los diferente nodos de la cola que se quiere copiar
        while (qS!=nullptr){
            // 1.- Se crea un nuevo nodo
            ptrNew = make_shared<Nodo>();
            *ptrNew = Nodo(qS->getDato(), nullptr);

            // 2.- Se enlazan los dos nodos del final
            end->setNext(ptrNew);
            end=ptrNew;

            // 3.- Se avanza en la cola que se quiere copiar
            qS=qS->getNext();
        }
    }
}
// Funcion que incorpora datos en la cola
void introducirElemCola(Cola  &Q) {
    TipoDato dato;
    do {
        cout << "Introduzca un numero (para terminar teclee un FIN) " << endl;
        cin >> dato.num;
        if (dato.elementoTipoString != "FIN" && !Q.full()) {
            Q.push(dato);
        }
    } while (dato.num >= 0 && !Q.full());

    if(Q.full()){
        cout << "La cola se ha llenado." << endl;
    }
}

// Muestra los datos de la cola sin destruirla
void Cola::mostrarCola() const{
    shared_ptr<Nodo> qAux{front};

    while (qAux != nullptr) {
        cout << " " << qAux->getDato().elementoTipoString; //aqui ponemos lo que buscamos
        qAux = qAux->getNext();
    }
}

// Función que determina las veces que un determinado valor está en la cola
int vecesElementoCola (Cola const &Q, const TipoDato &elem) {
    if (Q.empty()) {
        cout << "La cola está vacía." << endl;
        return;
    }
    int veces{0};
    Cola paux(Q);

    while (!paux.empty())  {
        if (elem.num == paux.first().elementoTipoString) { //AQUI colocamos si el elemento es string/int/lo que necesitemos
            veces++;
        }
        paux.pop();
    }

    return veces;
}

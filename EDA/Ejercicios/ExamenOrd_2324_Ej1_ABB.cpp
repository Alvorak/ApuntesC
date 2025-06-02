#include <iostream>
#include <memory>
using namespace std;
//Written and Directed By Alvorak

/*
 * Nota importante: el ejercicio es muy lio...
 * El dato guarda un int y suma es el valor que corresponde a dato + suma hijos
 * Cuando nos piden suma total dice:
 * RAIZ = dato + suma de todos sus hijos
 * SUMA = dato + sus hijos (si no hay hijos es solo dato)
 */
class Nodo{
private:
    int dato;
    int suma;
    shared_ptr<Nodo> hizq = nullptr;
    shared_ptr<Nodo> hdcha = nullptr;
public:
    Nodo(int d): dato(d),suma(0){}

    //Getters
    int getDato() const { return dato; }
    int getSuma() const { return suma; }

    const shared_ptr<Nodo> &getIzq() const{
        return hizq;
    }
    const shared_ptr<Nodo> &getDcha() const{
        return hdcha;
    }
    //Setters
    void setDato(int newDato){ dato = newDato; }
    void setSuma(int newSuma){ suma = newSuma; }
    void setIzq(const shared_ptr<Nodo> &newIzq){
        hizq = newIzq;
    }
    void setDcha(const shared_ptr<Nodo> &newDcha){
        hdcha = newDcha;
    }

    //Extra
    void procesarNodo() const{
        cout << "La suma de nodos del Nodo: " << getDato();
        int suma{getSuma()};
        if(suma>0){
            cout << "es => " << getSuma() << endl;
        }
    }
    //Ejercicio
    void actualizarSuma(){
        int sumaTotal = dato; //Cogemos el dato

        if(hizq) sumaTotal += hizq -> getSuma(); //Si hay izq se lo sumo a la suma total del nodo
        if(hdcha) sumaTotal += hdcha-> getSuma(); //Si hay dcha se lo sumo a la suma total del nodo

        setSuma(sumaTotal); //Suma total añadida al nodo actual (hijos + dato ó dato)

    }
};
class Arbol{
private:
    shared_ptr<Nodo> raiz = nullptr;
public:
    Arbol():raiz(nullptr){}

    const shared_ptr<Nodo> &getRaiz() const{
        return raiz;
    }
    void setRaiz(const shared_ptr<Nodo> &newRaiz) {
        raiz = newRaiz;
    }
    bool empty() const { return raiz == nullptr; }
    //Ejercicio
    void calcularSumaNodoABBRec(){
        if(!empty()){ //Mientras el arbol no este vacio
            actuallizarSumaNodoAbbRec(raiz); //Llamamos a la funcion recursiva
        }
    }
    void actuallizarSumaNodoAbbRec(const shared_ptr<Nodo> &A){
        if(A){
           A -> actualizarSuma(); //Actualizamos del actual
           actuallizarSumaNodoAbbRec(A -> getIzq()); //Actualizamos del hijo IZQ
           actuallizarSumaNodoAbbRec(A -> getDcha());//Actualizamos del hijo DCHA
        }
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}

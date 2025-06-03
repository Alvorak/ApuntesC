#include <iostream>
#include <memory>
#include <windows.h>
using namespace std;
//Written and Directed By Alvorak

//Clase Nodo
class Nodo{
private:
    int dato;
    int suma; //esta dato empieza a 0
    shared_ptr<Nodo> hizq = nullptr;
    shared_ptr<Nodo> hdcha = nullptr;
public:
    //Constructores
    Nodo(int d): dato(d), suma(0) {}

    //Getters
    int getDato() const {
        return dato;
    }
    int getSuma() const {
        return suma;
    }
    shared_ptr<Nodo> getIzq() const {
        return hizq;
    }
    shared_ptr<Nodo> getDcha() const {
        return hdcha;
    }
    //Setters
    void setDato(int newDato) {
        dato = newDato;
    }
    void setSuma(int newSuma) {
        suma = newSuma;
    }
    void setIzq(const shared_ptr<Nodo> newIzq){
        hizq = newIzq;
    }
    void setDcha(const shared_ptr<Nodo> newDcha){
        hdcha = newDcha;
    }
    void actualizarSuma(){
        int totalSuma = dato; //Total de la suma
        if(hizq != nullptr){
            totalSuma += hizq->getSuma(); //Cogemos la suma del hijo
        }
        if(hdcha != nullptr){
            totalSuma += hdcha->getSuma(); //Cogemos la suma del hijo
        }
        setSuma(totalSuma); //Le sumamos el dato
    }
};
class Arbol{
private:
    shared_ptr<Nodo> raiz = nullptr;
public:
    Arbol():raiz(nullptr){}

    const shared_ptr<Nodo> &getRaiz(){return raiz;}
    void setRaiz(const shared_ptr<Nodo>  &newRaiz){ raiz = newRaiz; }

    bool empty() const { return raiz==nullptr; }

    void calcularSumaNodoABBRec() const{
        if(!empty()){
            actualizarSumaNodoABBRec(raiz);
        }
    }
    void actualizarSumaNodoABBRec(const shared_ptr<Nodo> &A) const{
        if(A){
            //Primero los hijos y luego el padre
            actualizarSumaNodoABBRec(A -> getIzq()); //Su hijo
            actualizarSumaNodoABBRec(A -> getDcha()); //Su hijo
            A -> actualizarSuma(); //Actualizar Suma actual
        }
    }
};

int main()
{
   SetConsoleOutputCP(CP_UTF8);
   cout << "Prueba de calcularSumaNodoABBRec()" << endl;

   // Crear nodos
   shared_ptr<Nodo> n1 = make_shared<Nodo>(10);
   shared_ptr<Nodo> n2 = make_shared<Nodo>(5);
   shared_ptr<Nodo> n3 = make_shared<Nodo>(15);
   shared_ptr<Nodo> n4 = make_shared<Nodo>(3);
   shared_ptr<Nodo> n5 = make_shared<Nodo>(7);

   // Montamos el árbol
   n2->setIzq(n4); // 5 -> 3
   n2->setDcha(n5); // 5 -> 7
   n1->setIzq(n2); // 10 -> 5
   n1->setDcha(n3); // 10 -> 15

   // Crear árbol y establecer raíz
   Arbol arbol;
   arbol.setRaiz(n1); //n1 ya posee todos los hijos rellenados

   // Calcular suma acumulada
   arbol.calcularSumaNodoABBRec();

   // Mostrar resultados
   cout << "Suma en nodo raíz (10): " << n1->getSuma() << endl; // Debe ser 10 + suma(5) + suma(15)
   cout << "Suma en nodo 5: " << n2->getSuma() << endl; // Debe ser 5 + suma(3) + suma(7)
   cout << "Suma en nodo 15: " << n3->getSuma() << endl; // Solo 15
   cout << "Suma en nodo 3: " << n4->getSuma() << endl; // Solo 3
   cout << "Suma en nodo 7: " << n5->getSuma() << endl; // Solo 7

   return 0;
}

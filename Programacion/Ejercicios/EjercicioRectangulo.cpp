#include <iostream>
#include <windows.h>//para acentos
//Written and Directed By Alvorak

using namespace std;

//Ejercicio1 => Clase Rectangulo
class Rectangulo{
    int ladox,ladoy;
public:
    Rectangulo():ladox(0),ladoy(0){} //Constructor base

    Rectangulo(int x, int y):ladox(x), ladoy(y){} //Como los setters no tienen validaciones mejor así

    //Getters
    int getLadoX(){return ladox;}
    int getLadoY(){return ladoy;}
    //Setters
    void setLadoX(int newladoX){
        ladox = newladoX;
    }
    void setLadoY(int newladoY){
        ladoy = newladoY;
    }
    //Funciones
    friend bool esIgual (const Rectangulo &r1, const Rectangulo &r2){
        return (r1.ladox == r2.ladox && r1.ladoy == r2.ladoy) ||
                  (r1.ladox == r2.ladoy && r1.ladoy == r2.ladox);
    }
    //Operators
    friend istream &operator>> (istream &is, Rectangulo &p){
        int X, Y;
           is >> X >> Y;
           p.setLadoX(X);
           p.setLadoY(Y);

           return is;
    }
    friend ostream &operator<< (ostream &os, const Rectangulo &p){
        os << "\n\t\tEl lado horizontal vale: " << p.ladox
             << "\n\t\tEl lado vertical vale: " << p.ladoy << endl;

        return os;
    }
    Rectangulo operator +(const Rectangulo &r) const{ //Operador + para restarle al rectangulo otro
        return Rectangulo(ladox+r.ladox,ladoy+r.ladoy);
    }

    Rectangulo operator -(const Rectangulo &r) const{ //Operador menos para restarle al rectangulo otro
        return Rectangulo(ladox-r.ladox,ladoy-r.ladoy);
    }
    /* POSTFIJO => implica que se debe devolver el valor original antes de la modificación
     * PREFIJA => modifica el objeto antes de devolverlo
     */
    Rectangulo &operator--(){//Prefijo
        --ladox;
        --ladoy;
        return *this;
    }

    Rectangulo operator--(int){
        Rectangulo temp = *this; //Cogemos una copia
        --(*this); //Editamos el original
        return temp; //Devolvemos la copia
    }

    Rectangulo &operator ++(){
        ++ladox;
        ++ladoy;
        return *this;
    }

    Rectangulo operator ++(int){
        Rectangulo temp = *this;
        ++(*this);
        return temp;
    }

    bool operator>(const Rectangulo &r) const { //COMPARADOR MAYOR QUE => Nos viene como referencia el rectangulo
         return (ladox * ladoy) > (r.ladox * r.ladoy); //Comparamos el rectangulo actual con el de referencia
    }

    bool operator<(const Rectangulo &r) const {//COMPARADOR MENOR QUE => Nos viene como referencia el rectangulo
         return (ladox * ladoy) < (r.ladox * r.ladoy); //Comparamos el rectangulo actual con el de referencia
    }

    bool operator==(const Rectangulo &r) const {//COMPARADOR IGUAL QUE => Nos viene como referencia el rectangulo
            return (ladox == r.ladox && ladoy == r.ladoy) ||
                    (ladox == r.ladoy && ladoy == r.ladox);//Comparamos el rectangulo actual con el de referencia
        }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    return 0;
}

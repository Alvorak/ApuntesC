#include <iostream>
#include <windows.h>
//Written and Directed By Alvorak
using namespace std;

class Reunion{
private:
    string texto;
    char categoria;
    int duracion;
public:
    Reunion() : texto(""),categoria('M'),duracion(1){}

    Reunion(string newTexto,char newCategoria, int newDuracion){
        setTexto(newTexto);
        setCategoria(newCategoria);
        setDuracion(newDuracion);
    };

    //Getters
    string getTexto(){return texto;}
    char getCategoria(){return categoria;}
    int getDuracion(){return duracion;}
    //Setters
    void setTexto(string newTexto){
        texto = newTexto;
    }

    void setCategoria(char newCategoria){
        if(newCategoria != 'H' && newCategoria != 'L' && newCategoria != 'M' ){
            throw string("La categoria no es correcta.");
        }else{
            categoria = newCategoria;
        }
    }

    void setDuracion(int newDuracion){
        if(newDuracion < 1 || newDuracion > 90){
            throw 1;
        }else{
            duracion = newDuracion;
        }
    }

    Reunion(const Reunion &reunionACopiar) : texto(reunionACopiar.texto), categoria(reunionACopiar.categoria), duracion(reunionACopiar.duracion){}
    Reunion& operator=(const Reunion &otra) {
        if (this != &otra) { // Evita autoasignación por si ya esta rellenada/es copia
            texto = otra.texto;
            categoria = otra.categoria;
            duracion = otra.duracion;
        }
        return *this;
    }
    //Operadores
    Reunion operator +(int minutos){
        int newDuracion = duracion + minutos;
        setDuracion(newDuracion);
        return Reunion(texto,categoria,newDuracion);
    }
    friend ostream& operator<<(ostream &os, const Reunion &r);
    friend istream& operator >>(istream &is, Reunion &r){
      string newTexto;
      char newCategoria;
      int newDuracion;
      cout << "Introduzca el texto de la reunión:" << endl;
      getline(is,newTexto);

      cout << "Introduzca el categoria de la reunión:" << endl;
      is >> newCategoria;

      cout << "Introduzca el duración de la reunión:" << endl;
      is >> newDuracion;

      r.setTexto(newTexto);
      r.setCategoria(newCategoria);
      r.setDuracion(newDuracion);

      return is;

    }
};
ostream &operator<<(ostream &os, const Reunion &r){
    os << "Reunión: " << r.texto << endl
       << "Categoria: " << r.categoria << endl
       << "Duracion: " << r.duracion << endl;
    return os;
}
int main()
{
    try{
    SetConsoleOutputCP(CP_UTF8);
    Reunion reunionBasica("Basica",'M',30), reunionCopia(reunionBasica), reunionSumar, reunionCin;

    cout << "Reunion Basica:" << endl << reunionBasica;
    cout << "----------------------------------------" << endl;
    cout << "Nueva reunión:" << endl;
    cin >> reunionCin;
    cout << endl << "Reunion Cin:" << reunionCin;
    cout << "----------------------------------------" << endl;
    cout << "Sumamos reuniones" << endl;
    cout << reunionCopia;
    reunionSumar = reunionCopia + 5;
    cout << reunionSumar;

    }catch (const string &errorString) {
    cout << errorString << endl;
    }catch(int){
        cout << "Error, duración no valida." << endl;
    }

    return 0;
}

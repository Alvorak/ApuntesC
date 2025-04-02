#include <iostream>
#include <windows.h>//Para los acentos
#include <vector>
//Written and Directed By Alvaro García Herrero
using namespace std;

class Libro{
private:
    string titulo;
    vector<string> autores;
    char recomendado;
    int paginas;
public:
    //Constructor por defecto
    Libro() : titulo(""),autores({""}), recomendado('-'), paginas(10) {} //Pongo 10 porque minimo ha de tener 10 paginas como validacion
    //Constructor paramétrico
    Libro(string newTitulo,vector<string> newAutores,char newRecomendado, int newPaginas){ //Como los setters ya tienen validaciones lo dejo asi
     setTitulo(newTitulo);
     setAutores(newAutores);
     setPaginas(newPaginas);
     setRecomendado(newRecomendado);
    }
    //Constructor copia
    Libro (const Libro &libroACopiar) : titulo(libroACopiar.titulo), autores(libroACopiar.autores), recomendado(libroACopiar.recomendado), paginas(libroACopiar.paginas) {}
    //Getters
    string getTitulo(){ return titulo; }
    vector<string> getAutores() { return autores; }
    char getRecomendado() { return recomendado; }
    int getPaginas() { return paginas; }
    //Setters
    void setTitulo(string newTitulo){
        titulo = newTitulo; //Sin validaciones
    }
    void setPaginas(int &newPaginas){
        if(newPaginas < 10 || newPaginas > 500){
           throw 1; //Páginas fuera del rango lanzamos error
        }else{
           paginas = newPaginas;
        }
    }
    void setRecomendado (char &newRecomendado){
        if(newRecomendado != '-' && newRecomendado != 'I' && newRecomendado != 'J' && newRecomendado != 'A' && newRecomendado != 'T'){
            throw string("Error, el código de recomendación no es correcto"); //Error de tipo string, valor fuera del rango
        }else{
            recomendado = newRecomendado;
        }
    }
    void setAutores(vector<string> &newAutores){
        for (string newAutor : newAutores) { //Por cada nuevo autor
            for (string autor : autores) {//Comprobamos que no esta ya dentro de los autores del libro
                if(newAutor == autor){
                    throw char('R'); //Error ese autor ya esta en el libro
                }
            }
           autores.push_back(newAutor); //No hemos tenido error de validación por lo que lo inserto
        }
    }
    //Operadores
    Libro operator --(){//Prefijo
        int nuevas_paginas =--paginas;
        setPaginas(nuevas_paginas);
        return *this;
    }
    Libro operator -(const string &autorParaBorrar){//Prefijo
        int contar = 0;
        for (string autor : autores) { //Para poder tener a todos los autores como un string que mostrar
            if(autorParaBorrar == autor){
                autores.at(contar).clear();
            }
            contar++;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &os, const Libro &libro){
        string autores;
         for (string autor : libro.autores) { //Para poder tener a todos los autores como un string que mostrar
           if(autor !=""){
             if(autores == ""){
                autores = autor;
             }else{
              autores += ", " + autor;
             }
            }
         }
        os <<"Información sobre el libro:" << endl
           << "Titulo: " << libro.titulo << endl
           << "Recomendado: " << libro.recomendado << endl
           << "Paginas: " << libro.paginas << endl
           << "Autores: " << autores << endl;
        return os;
    }
};

int main()
{
    try{
    SetConsoleOutputCP(CP_UTF8);//Así vemos los acentos
    Libro libro("El arte de programar en servilletas",{"Paco","Leon","Manolo","Antonio"},'T',30);

    cout << libro;

    cout << "-------------------------------------------------" << endl;
    cout << "Restamos con operador -- una página" << endl;
    --libro;

    cout << libro;

    cout << "-------------------------------------------------" << endl;
    cout << "Eliminamos de los autores a un autor elegido: " << endl;
    libro - "Leon";

    cout << libro;

    }catch(string error){
        cout << error << endl;
    }catch(char error){
        cout << "Error, hay un autor repetido en el libro." << endl;
    }catch(int error){
        if(error == 1){
            cout << "Error, numero de páginas fuera del rango. El libro ha de tener entre 10 y 500 páginas" << endl;
        }
    }

    return 0;
}

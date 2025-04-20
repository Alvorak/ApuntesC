#include <iostream>
#include <cmath>
#include <windows.h> // Para los acentos
// Written and Directed by Alvorak

using namespace std;

//Nuestra clase Base Abstracta
class FiguraGeometrica {
protected:
    int numLados; //Para el numero de lados de la figura
    double longLado; //La longitud de los lados de la figura geometrica
public:
    // Constructor por defecto
    FiguraGeometrica() : numLados(0), longLado(0.0) {}

    // Constructor paramétrico
    FiguraGeometrica(int lados, double longitud) {
        setNumLados(lados);
        setLongLado(longitud);
    }

    // Destructor
    virtual ~FiguraGeometrica() {}

    // Setters
    void setNumLados(int lados) {
        if (lados < 3 || lados > 10) throw string("Error: número de lados inválido.");
        numLados = lados;
    }

    void setLongLado(double longitud) {
        if (longitud <= 0) throw string("Error: longitud del lado debe ser positiva.");
        longLado = longitud;
    }

    // Getters
    int getNumLados() const { return numLados; }
    double getLongLado() const { return longLado; }

    // Métodos virtuales puros y duros
    virtual double calcularPerimetro() const {
       return numLados * longLado;
    }

    virtual double calcularArea() const = 0; //NOTA => Usamos overdrive luego para que cada metodo en cada clase cumpla con su formula de area
};

//Cuadrado => metodo Diagonal
class Cuadrado : public FiguraGeometrica {
public:
    Cuadrado(double lado) : FiguraGeometrica(4, lado) {}

    double calcularArea() const override {
        return longLado * longLado;
    }

    double calcularDiagonal() const {
        return longLado * sqrt(2);
    }
};

//Triángulo => Altura
class TrianguloEquilatero : public FiguraGeometrica {
public:
    TrianguloEquilatero(double lado) : FiguraGeometrica(3, lado) {}

    double calcularArea() const override {
        return (sqrt(3) / 4) * longLado * longLado;
    }

    double calcularAltura() const {
        return (sqrt(3) / 2) * longLado;
    }
};

//Pentágono => Apotema
class Pentagono : public FiguraGeometrica {
private:
    double apotema;

    // Método privado para calcular el apotema desde el lado
    double calcularApotema(double lado) const {
        return lado / (2 * tan(M_PI / 5)); // π radianes entre 5 lados => la formula del apotema
    }

public:
    Pentagono(double lado) : FiguraGeometrica(5, lado) {
        apotema = calcularApotema(lado);
    }

    double getApotema() const { return apotema; }

    double calcularArea() const override {
        return (calcularPerimetro() * apotema) / 2;
    }
};



int main() {
    SetConsoleOutputCP(CP_UTF8); // Para que salgan los acentos correctamente

    try {
        Cuadrado c(4.0);
        cout << "Cuadrado: " << c.getLongLado() << "x" << c.getNumLados() << endl;
        cout << "Área: " << c.calcularArea() << endl;
        cout << "Perímetro: " << c.calcularPerimetro() << endl;
        cout << "Diagonal: " << c.calcularDiagonal() << endl;
        cout << "------------------------" << endl;

        TrianguloEquilatero t(5.0);
        cout << "Triángulo equilátero: " << t.getLongLado() << "x" << t.getNumLados() << endl;
        cout << "Área: " << t.calcularArea() << endl;
        cout << "Perímetro: " << t.calcularPerimetro() << endl;
        cout << "Altura: " << t.calcularAltura() << endl;
        cout << "------------------------" << endl;

        Pentagono p(6.0);
        cout << "Pentágono regular: " << p.getLongLado() << "x" << p.getNumLados() << endl;
        cout << "Área: " << p.calcularArea() << endl;
        cout << "Perímetro: " << p.calcularPerimetro() << endl;
        cout << "Apotema: " << p.getApotema() << endl;
        cout << "------------------------" << endl;

    } catch (string error) {
        cout << "ERROR: " << error << endl;
    }

    return 0;
}

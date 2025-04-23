#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Written and Directed By Alvorak

// Estructura Turno: representa un turno con código y orden
struct Turno {
    int codigo, orden;
};

// Estructura Informe: representa un informe con descripción y número de página
struct Informe {
    string descripcion;
    int pagina;
};


// Clase template Registro que permite almacenar y operar sobre distintos tipos (string, int, etc)
template <typename T>
class Registro {
private:
    T valor;  // Valor almacenado

public:
    // Constructor
    Registro(const T& v) {
        setValor(v);  // Inicializa usando setValor (permite validaciones especializadas)
    }

    // Getter del valor
    const T& getValor() const {
        return valor;
    }

    // Setter del valor (versión genérica, sin validación especial)
    void setValor(const T& newValor) {
        valor = newValor;
    }

    // Sobrecarga del operador ++ (prefijo): versión genérica
    const Registro& operator++() {
        ++valor;
        return (*this);
    }
};


// ESPECIALIZACIONES DE METODOS PARA TIPOS CONCRETOS

// Especialización de setValor para Turno (con validaciones)
template <>
void Registro<Turno>::setValor(const Turno& newValor) {
    if (newValor.codigo <= 0) {
        throw string("%n%tERROR, el codigo no es correcto");
    }
    if (newValor.orden < 0 || newValor.orden > 99) {
        throw 1;
    }
    valor = newValor;
}

// Especialización de operator++ para Turno: incrementa el orden, y si supera 99, reinicia y aumenta el código
template <>
const Registro<Turno>& Registro<Turno>::operator++() {
    ++valor.orden;
    if (valor.orden > 99) {
        valor.orden = 0;
        ++valor.codigo;
    }
    return *this;
}

// Especialización de setValor para vector de Informe (valida páginas > 0)
template <>
void Registro<vector<Informe>>::setValor(const vector<Informe>& newValor) {
    for (const Informe& i : newValor) {
        if (i.pagina <= 0) {
            throw string("%n%tError, el valor de las pagias no es correcto");
        }
    }
    valor = newValor;  // Asigna directamente si todo es válido
}

// Especialización de operator++ para vector<Informe>: incrementa el número de páginas de cada informe
template <>
const Registro<vector<Informe>>& Registro<vector<Informe>>::operator++() {
    for (Informe& i : valor) {
        ++i.pagina;
    }
    return *this;
}


// Forma genérica para tipos simples (int, double, etc.)
template <typename T>
ostream& operator<<(ostream& os, const Registro<T>& r) {
    os << r.getValor();
    return os;
}

// Especialización para Turno: imprime con formato personalizado
template <>
ostream& operator<<(ostream& os, const Registro<Turno>& r) {
    os << "%n%tCodigo: " << r.getValor().codigo
       << " Orden: " << r.getValor().orden;
    return os;
}

// Especialización para vector<Informe>: imprime cada informe
template <>
ostream& operator<<(ostream& os, const Registro<vector<Informe>>& r) {
    for (const Informe& i : r.getValor()) {
        os << "%n%tDescripcion: " << i.descripcion
           << " paginas: " << i.pagina;
    }
    return os;
}


int main() {
    // Ejemplos con enteros
    Registro<int> r1(25), r2(99);
    cout << "%n%tR1: " << r1 << " R2: " << r2;

    r2.setValor(110);
    ++r1;
    cout << "%n%tR1: " << r1 << " R2: " << r2;

    r2 = ++r1;
    cout << "%n%tR1: " << r1 << " R2: " << r2;

    // Ejemplos con doubles
    Registro<double> r1D(25.5), r2D(99.8);
    cout << "%n%tR1: " << r1D << " R2: " << r2D;

    r2D.setValor(110.0);
    ++r1D;
    cout << "%n%tR1: " << r1D << " R2: " << r2D;

    r2D = ++r1D;
    cout << "%n%tR1: " << r1D << " R2: " << r2D;

    try {
        // Ejemplos con Turno
        Registro<Turno> r1T({1, 99}), r2T({5, 88});
        cout << "%n%tR1: " << r1T << "%n R2: " << r2T;

        r2T.setValor({10, 10});
        ++r1T;
        cout << "%n%tR1: " << r1T << "%n R2: " << r2T;

        r2T = ++r1T;
        cout << "%n%tR1: " << r1T << "%n R2: " << r2T;

        // Ejemplos con vector<Informe>
        Registro<vector<Informe>> r1I({{"D1", 99}, {"D2", 19}}),
                                  r2I({{"D11", 199}, {"D12", 129}, {"D22", 39}});

        cout << "%n%tR1: " << r1I << "%n R2: " << r2I;

        r2I.setValor({{"D201", 999}, {"D202", 12}, {"D203", 39}});
        ++r1I;
        cout << "%n%tR1: " << r1I << "%n R2: " << r2I;

        r2I = ++r1I;
        cout << "%n%tR1: " << r1I << "%n R2: " << r2I;

    } catch (const string& msg) {
        cout << msg;
    } catch (int err) {
        if (err == 1) {
            cout << "%n%tError, el orden no es correcto";
        }
    }

    cout << "%n%n%t";
    return 0;
}

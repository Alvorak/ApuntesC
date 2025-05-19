#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <windows.h>//Para los acentos

using namespace std;
//Written and Directed by Alvorak


class Transporte {
protected:
    string mercancia; 

public:
    //Constructor paramétrico
    Transporte(const string& mercancia) : mercancia(mercancia) {}

    //Getter
    string getMercancia() const {
        return mercancia;
    }

    //Setter
    void setMercancia(const string& nuevaMercancia) {
        mercancia = nuevaMercancia;
    }


    virtual string tipoMedio() const = 0; //Luego usamos override para cada tipo

    virtual void mostrarDatos() const = 0; //Luego usamos override para cada tipo

    virtual ~Transporte() {}
};

class Aereo : public Transporte {
private:
    string vuelo;

public:
    Aereo(const string& mercancia, const string& vuelo)
        : Transporte(mercancia), vuelo(vuelo) {}

    string getVuelo() const {
        return vuelo;
    }

    void setVuelo(const string& nuevoVuelo) {
        vuelo = nuevoVuelo;
    }

    string tipoMedio() const override {
        return "AEREO";
    }

    void mostrarDatos() const override {
        cout << "Mercancia: " << mercancia << endl
             << "Vuelo: " << vuelo << endl
             << "-----------------"<< endl;
    }
};

class Terrestre : public Transporte {
protected:
    double coste;

public:
    Terrestre(const string& mercancia, double coste)
        : Transporte(mercancia) {
        setCoste(coste);
    }

    double getCoste() const {
        return coste;
    }

    void setCoste(double nuevoCoste) {
        if (nuevoCoste <= 0) {
            throw string("Error, el coste no es correcto");
        }
        coste = nuevoCoste;
    }

    void mostrarDatos() const override {
        cout << "Mercancia: " << mercancia << endl
             << "Coste: " << coste << endl
             << "-----------------"<< endl;
    }
};

class Carretera : public Terrestre {
private:
    string formato;
    double MMA;

public:
    Carretera(const string& mercancia, double coste,
              const string& formato, double MMA)
        : Terrestre(mercancia, coste), formato(formato) {
        setMMA(MMA);
    }

    string getFormato() const {
        return formato;
    }

    void setFormato(const string& nuevoFormato) {
        formato = nuevoFormato;
    }

    double getMMA() const {
        return MMA;
    }

    void setMMA(double nuevoMMA) {
        if (nuevoMMA <= 0) {
            throw string("Error, el MMA no es correcto");
        }
        MMA = nuevoMMA;
    }

    string tipoMedio() const override {
        return "CARRETERA";
    }

    void mostrarDatos() const override {
        cout << "Mercancia: " << mercancia << endl
             << "Coste: " << coste << endl
             << "Formato: " << formato << endl
             << "MMA: " << MMA << endl
             << "-----------------"<< endl;
    }

    string tipoCategoria() const {
        if (MMA <= 3500) return "N1";
        if (MMA <= 12000) return "N2";
        return "N3";
    }
};

class Ferroviario : public Terrestre {
private:
    string empresa;

public:
    Ferroviario(const string& mercancia, double coste,
                const string& empresa)
        : Terrestre(mercancia, coste), empresa(empresa) {}

    string getEmpresa() const {
        return empresa;
    }

    void setEmpresa(const string& nuevaEmpresa) {
        empresa = nuevaEmpresa;
    }

    string tipoMedio() const override {
        return "FERROVIARIO";
    }

    void mostrarDatos() const override {
        cout << "Mercancia: " << mercancia << endl
             << "Coste: " << coste << endl
             << "Empresa: " << empresa << endl
             << "-----------------"<< endl;
    }
};

void listarTransportes(const vector<shared_ptr<Transporte>>& lista) {
    //Recorremos el vector
    for (const auto& t : lista) {
        cout << "Vehiculo:" << endl << "Tipo: " << t->tipoMedio() << endl;
        t->mostrarDatos(); //Mostramos los datos

        //Si es un objeto de tipo Carretera, mostramos su categoría
        Carretera* carreteraPtr = dynamic_cast<Carretera*>(t.get()); //Si el objeto se castea significa que estamos frente a una carretera
        if (carreteraPtr != nullptr) { //Si NO es null es una carretera por lo que mostramos su categoria con su metodo
            cout << "Categoria: " << carreteraPtr->tipoCategoria() << endl;
        }
    }
    cout << endl;
}


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    vector<shared_ptr<Transporte>> misTransportes;//para almacenar los transportes
    try {
       //2 objetos Aereo
       misTransportes.push_back(make_shared<Aereo>("Medicinas", "V123"));
       misTransportes.push_back(make_shared<Aereo>("Electrónica", "A456"));

       //2 objetos Carretera
       misTransportes.push_back(make_shared<Carretera>("Frutas", 150.0, "tráiler", 18000.0));
       misTransportes.push_back(make_shared<Carretera>("Muebles", 120.0, "rígido", 3200.0));

       //2 objetos Ferroviario
       misTransportes.push_back(make_shared<Ferroviario>("Vehículos", 800.0, "RENFE"));
       misTransportes.push_back(make_shared<Ferroviario>("Minerales", 900.0, "TransRail"));

       listarTransportes(misTransportes);

    }
    catch (const string& e) {
       cout << e;
    }

    return 0;

}

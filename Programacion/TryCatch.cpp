#include <iostream>
#include <string>
//Written and Directed By Alvorak
using namespace std;

int main() {
    try {
        //Lanzamos un thow => puede ser un numero un string lo que tu quieras porque se lo va a comer igual. Por lo general usamos int/string
        throw 1; 
    } catch (int e) {
        // Caso específico para errores tipo int
        if (e == 1) {
            cout << "Error tipo 1" << endl;
        } else if (e == 2) {
            cout << "Error tipo 2" << endl;
        }
 try {
    throw "Mensaje que quiera";
    } catch (string& error) {
        //Si es de tipo string le puedes hacer esto para que quede mas bonito => en error guardas el mensaje y listo.
        cout << "Error tipo string: " << error << endl;

    } catch (...) { //El catch generico para errores no controlados, no tiene mas
        cout << "Error desconocido" << endl;
    }

    return 0;
}

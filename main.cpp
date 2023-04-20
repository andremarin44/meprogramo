#include <iostream>
#include <fstream>

using namespace std;

void registrar_curso(ofstream& archivo) {
    int codigo, creditos, horas_clase, horas_trabajo;
    char nombre[50], horario[50], dias[10];

    cout << "Ingrese el codigo del curso: ";
    cin >> codigo;
    cout << "Ingrese el nombre del curso: ";
    cin >> nombre;
    cout << "Ingrese la cantidad de creditos del curso: ";
    cin >> creditos;
    cout << "Ingrese la cantidad de horas de clase con docente: ";
    cin >> horas_clase;
    cout << "Ingrese la cantidad de horas de trabajo independiente: ";
    cin >> horas_trabajo;
    cout << "Ingrese el horario del curso (dia/hora): ";
    cin >> dias >> horario;

    archivo << codigo << " " << nombre << " " << creditos << " " << horas_clase << " " << horas_trabajo << " " << dias << horario << endl;
    cout << "Registro exitoso!" << endl;
}

void mostrar_cursos(ifstream& archivo) {
    int codigo, creditos, horas_clase, horas_trabajo;
    char nombre[50], horario[50], dias[10];

    while (archivo >> codigo >> nombre >> creditos >> horas_clase >> horas_trabajo >> dias >> horario) {
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Creditos: " << creditos << endl;
        cout << "Horas de clase con docente: " << horas_clase << endl;
        cout << "Horas de trabajo independiente: " << horas_trabajo << endl;
        cout << "Horario: " << dias << horario << endl;
        cout << endl;
    }
}

int main() {
    ofstream archivo_escritura("cursos.txt", ios::app);
    ifstream archivo_lectura("cursos.txt");

    int opcion;

    while (true) {
        cout << "1. Registrar un curso" << endl;
        cout << "2. Mostrar cursos registrados" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrar_curso(archivo_escritura);
                break;
            case 2:
                mostrar_cursos(archivo_lectura);
                break;
            case 3:
                archivo_escritura.close();
                archivo_lectura.close();
                return 0;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }

    return 0;
}

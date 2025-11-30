// hola aqui trabajaremos
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

string archivo = "Gastos.txt";

struct Gasto {
    float monto;
    string categoria;
    string fecha;
    string descripcion;
};

vector<Gasto> cargarGastos() {
    vector<Gasto> listaGastos;
    ifstream f(archivo);
    
    if (!f) {
        return listaGastos;
    }
    
    Gasto gastoTemporal;
    string montoStr;
    
    while (getline(f, montoStr)) {
        getline(f, gastoTemporal.categoria);
        getline(f, gastoTemporal.fecha);
        getline(f, gastoTemporal.descripcion);
        
        gastoTemporal.monto = stof(montoStr);
        listaGastos.push_back(gastoTemporal);
    }
    
    f.close();
    return listaGastos;
}

void guardarGastos(const vector<Gasto>& gastos) {
    ofstream f(archivo);
    
    for (const auto& g : gastos) {
        f << g.monto << endl;
        f << g.categoria << endl;
        f << g.fecha << endl;
        f << g.descripcion << endl;
    }
    
    f.close();
}

void agregarGasto() {
    vector<Gasto> gastos = cargarGastos();
    Gasto nuevoGasto;
    
    cout << "\n--- AGREGAR NUEVO GASTO ---\n";
    
    cout << "Monto: $";
    cin >> nuevoGasto.monto;
    cin.ignore();
    
    cout << "Categoria: ";
    getline(cin, nuevoGasto.categoria);
    
    cout << "Fecha: ";
    getline(cin, nuevoGasto.fecha);
    
    cout << "Descripcion: ";
    getline(cin, nuevoGasto.descripcion);
    
    gastos.push_back(nuevoGasto);
    guardarGastos(gastos);
    cout << "Gasto agregado correctamente!\n";
}

void mostrarGastos() {
    vector<Gasto> gastos = cargarGastos();
    
    if (gastos.empty()) {
        cout << "No hay gastos registrados.\n";
        return;
    }
    
    cout << "\n=== MIS GASTOS ===\n";
    for (int i = 0; i < gastos.size(); i++) {
        cout << "Gasto #" << (i + 1) << ":\n";
        cout << "Monto: $" << gastos[i].monto << endl;
        cout << "Categoria: " << gastos[i].categoria << endl;
        cout << "Fecha: " << gastos[i].fecha << endl;
        cout << "Descripcion: " << gastos[i].descripcion << endl;
        cout << endl;
    }
}

void pausa() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
    cin.get();
}

int main() {
    int opcion;
    
    do {
        system("cls");
        cout << "=== CONTROL DE GASTOS ===\n";
        cout << "1. Agregar gasto\n";
        cout << "2. Ver gastos\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion) {
            case 1:
                agregarGasto();
                break;
            case 2:
                mostrarGastos();
                break;
            case 3:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida!\n";
        }
        
        if (opcion != 3) {
            pausa();
        }
        
    } while(opcion != 3);
    
    return 0;
}
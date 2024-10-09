#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Tarea {
    string descripcion;
    bool completada;
};

void mostrarTareas(vector<Tarea> listaTareas) {
    if (listaTareas.empty()) {
        cout << "La Lista no contiene tareas\n";
        return;
    } else {
        cout << "Tareas pendientes: \n";
    }

    for (int i = 0; i < listaTareas.size(); i++) {
        cout << i + 1 << ". " << listaTareas[i].descripcion
             << " [ " << (listaTareas[i].completada ? "Completada" : "Pendiente") << " ]" << endl;
    }
}





void mostrarMenu() {
    cout << "\n=== Menu opciones ===\n";
    cout << "1. Agregar tarea\n";
    cout << "2. Marcar como completada\n";
    cout << "3. Mostrar todas las tareas\n";
    cout << "4. Salir\n";
    cout << "=====================\n";
    cout << "Elija una opción: ";
}

void agregarTarea(vector<Tarea>& listaTareas) {
    string descripcion;
  ;
    cout << "Ingrese la descripcion de la tarea:\n";
    
    cin.ignore();
    getline(cin, descripcion);
    
    Tarea nuevaTarea = {descripcion, false};
    listaTareas.push_back(nuevaTarea);
    cout << "Tarea agregada\n";
}

void completarTarea(vector<Tarea>& listaTareas){
    if(listaTareas.empty()){
        cout << "La lista no contiene tareas\n";
        return;
    }

  int indice;
cout << "Ingrese el número de la tarea a completar: ";
cin >> indice;

if(indice > 0 && indice <= listaTareas.size()) {
    listaTareas[indice - 1].completada = true;
    cout << "Tarea completa\n";
} else {
    cout << "Número inválido";
}
}

int main () {


vector<Tarea> listaTareas;

int opcion;
do {
   mostrarMenu();
    cin >> opcion;
    switch (opcion) {
        case 1:
            agregarTarea(listaTareas);
            break;
        case 2:
            completarTarea(listaTareas);
            break;
        case 3:
            mostrarTareas(listaTareas);
            break;
        case 4:
            return 0;
        default:
            cout << "Opción inválida\n";
            break;
    }
} while (opcion != 4);  

    return 0;
}


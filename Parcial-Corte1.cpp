#include <iostream>
#include <cmath>

// Definir la estructura de una nota (grade)
struct Grade{
    int studentId; float grade;
};

// Función para leer las notas de varios estudiantes
void leerNotas(Grade notas[], int n){
    char respuesta;
    std::cout << "¿Desea ingresar las notas manualmente? (s/n): ";
    std::cin >> respuesta;
    if (respuesta == 's' || respuesta == 'S'){
        for (int i = 0; i < n; i++){
            std::cout << "Ingrese el id del estudiante " << i + 1 << ": ";
            std::cin >> notas[i].studentId;
            std::cout << "Ingrese la nota del estudiante " << i + 1 << ": ";
            std::cin >> notas[i].grade;
            // Validación de rango de la nota
            while (notas[i].grade < 0.0 || notas[i].grade > 5.0){
                std::cout << "Nota inválida. Ingrese una nota entre 0.0 y 5.0: ";
                std::cin >> notas[i].grade;
            }
        }
    }
    else{
        // Usar valores predeterminados
        std::cout << "Usando valores predeterminados...\n";
        if (n >= 4){
            notas[0] = {1010, 3.5};
            notas[1] = {1020, 4.0};
            notas[2] = {1030, 2.8};
            notas[3] = {2056, 5.0};
        }
        for (int i = 4; i < n; i++){
            notas[i] = {3000 + i, 3.0}; // valores extra si el usuario pidió más de 4
        }
    }
}

// Función para calcular el promedio y encontrar la mejor nota
double calcularPromedio(Grade notas[], int n, int &indiceNotaMasAlta){
    double suma = 0.0;
    indiceNotaMasAlta = 0;
    for (int i = 0; i < n; i++){
        suma += notas[i].grade;
        if (notas[i].grade > notas[indiceNotaMasAlta].grade){
            indiceNotaMasAlta = i;
        }
    }
    return suma/n;
}

// Función para mostrar el promedio y estudiante con mayor nota
void mostrarResultado(Grade notas[], int indiceNotaMasAlta, double promedio){
    std::cout << "\nEl id del estudiante con mejor calificación es: "
              << notas[indiceNotaMasAlta].studentId
              << ", con una nota de " << notas[indiceNotaMasAlta].grade << "\n";
    std::cout << "La calificación promedio del arreglo es: "
              << promedio << std::endl;
}

int main(){
    int n;
    std::cout << "Ingrese el número de estudiantes (mínimo 2): ";
    std::cin >> n;
    if (n < 2){
        std::cout << "Se necesitan al menos 2 estudiantes para determinar el promedio.\n";
        return 1;
    }
    Grade *notas = new Grade[n]; // arreglo dinámico

    // Leer las notas (manual o predeterminado)
    leerNotas(notas, n);

    // Calcular promedio y encontrar índice de la mejor nota
    int indiceNotaMasAlta;
    double promedio = calcularPromedio(notas, n, indiceNotaMasAlta);

    // Mostrar el resultado
    mostrarResultado(notas, indiceNotaMasAlta, promedio);

    delete[] notas;
    return 0;
}
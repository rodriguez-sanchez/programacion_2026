/**
 * @file estudiante.cpp
 * @author Gerardo Israel Rodríguez
 * @brief Implementación de la clase Estudiante.
 * @date 2026-01-29
 * 
 * Contiene la lógica interna de los métodos definidos
 * en estudiante.hpp.
 */

#include <iostream>
#include <libestudiante/estudiante.hpp>

using std::cout;
using std::cerr;
using std::endl;

Estudiante::Estudiante()
    : nombre(""), codigo(""), edad(0), promedio(0.0f), activo(false) {}

Estudiante::Estudiante(string nombre, string codigo, int edad, float promedio, bool activo) {
    this->nombre = nombre;
    this->codigo = codigo;
    this->edad = edad;
    this->promedio = promedio;
    this->activo = activo;
}

void Estudiante::actualizarNombre(string nuevoNombre) {
    nombre = nuevoNombre;
}

void Estudiante::actualizarCodigo(string nuevoCodigo) {
    codigo = nuevoCodigo;
}

void Estudiante::actualizarEdad(int nuevaEdad) {
    edad = nuevaEdad;
}

/**
 * @details
 * Se valida que el promedio esté en el rango permitido.
 * En caso contrario, se muestra un mensaje de error
 * y no se modifica el valor almacenado.
 */
void Estudiante::actualizarPromedio(float nuevoPromedio) {
    if (nuevoPromedio < 0.0f || nuevoPromedio > 10.0f) {
        cerr << "Error: El promedio debe estar entre 0.0 y 10.0" << endl;
        return;
    }
    promedio = nuevoPromedio;
}

void Estudiante::actualizarActivo(bool nuevoEstado) {
    activo = nuevoEstado;
}

string Estudiante::obtenerNombre() const { return nombre; }
string Estudiante::obtenerCodigo() const { return codigo; }
int Estudiante::obtenerEdad() const { return edad; }
float Estudiante::obtenerPromedio() const { return promedio; }
bool Estudiante::obtenerActivo() const { return activo; }

void Estudiante::mostrarNombre() const {
    cout << "Nombre: " << nombre << endl;
}

void Estudiante::mostrarCodigo() const {
    cout << "Código: " << codigo << endl;
}

void Estudiante::mostrarEdad() const {
    cout << "Edad: " << edad << " años" << endl;
}

void Estudiante::mostrarPromedio() const {
    cout << "Promedio: " << promedio << endl;
}

void Estudiante::mostrarActivo() const {
    cout << "Estado: " << (activo ? "Activo" : "Inactivo") << endl;
}

void Estudiante::mostrarInformacionCompleta() const {
    mostrarNombre();
    mostrarCodigo();
    mostrarEdad();
    mostrarPromedio();
    mostrarActivo();
}

void Estudiante::incrementarEdad() {
    edad++;
}

void Estudiante::calcularEstadoAcademico() const {
    cout << "Estado académico: ";

    if (promedio >= 9.0f)
        cout << "Excelente";
    else if (promedio >= 8.0f)
        cout << "Muy Bueno";
    else if (promedio >= 7.0f)
        cout << "Bueno";
    else if (promedio >= 6.0f)
        cout << "Regular";
    else
        cout << "Necesita Mejorar";

    cout << endl;
}

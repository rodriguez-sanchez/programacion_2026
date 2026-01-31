/**
 * @file estudiante.test.cpp
 * @author Gerardo Israel Rodríguez
 * @brief Pruebas unitarias para la clase Estudiante.
 * @date 2026-01-30
 *
 * @details
 * Este archivo contiene pruebas unitarias para verificar el correcto
 * funcionamiento de la clase Estudiante, incluyendo constructores,
 * setters, getters y validaciones.
 */

#include <cassert>
#include <libestudiante/estudiante.hpp>

int main() {

    // Prueba 1: Constructor por defecto
    Estudiante estudiante1;
    assert(estudiante1.obtenerEdad() == 0);
    assert(estudiante1.obtenerPromedio() == 0.0f);
    assert(estudiante1.obtenerActivo() == false);

    // Prueba 2: Constructor con parámetros válidos
    Estudiante estudiante2("Juan Pérez", "EST-001", 20, 8.5f, true);

    assert(estudiante2.obtenerEdad() == 20);
    assert(estudiante2.obtenerPromedio() == 8.5f);
    assert(estudiante2.obtenerActivo() == true);

    // Prueba 3: Validación de promedio inválido
    estudiante2.actualizarPromedio(15.0f); // debería rechazarse
    assert(estudiante2.obtenerPromedio() == 8.5f); // no cambió

    // Prueba 4: Incremento de edad
    estudiante2.incrementarEdad();
    assert(estudiante2.obtenerEdad() == 21);

    return 0; // Éxito
}
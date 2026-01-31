/**  
 * @file main.cpp
 * @author Gerardo Israel Rodríguez
 * @brief Programa principal del Sistema de Gestión de Estudiantes.
 * @date 2026-01-29
 *
 * @details
 * Este programa demuestra el uso de la clase Estudiante:
 * - Creación de objetos mediante constructores
 * - Actualización de atributos
 * - Validación de datos
 * - Cálculo del estado académico
 *
 * En sistemas Windows, se habilita automáticamente la salida UTF-8
 * para permitir la correcta impresión de caracteres acentuados.
 */

#include <iostream>
#include <libestudiante/estudiante.hpp>

#ifdef _WIN32
    #include <libestudiante/console_utf8.hpp>
#endif

using std::cout;
using std::endl;

/**
 * @brief Función principal del programa.
 *
 * @return int Código de salida del programa.
 */
int main() {

#ifdef _WIN32
    /**
     * @brief Objeto RAII que habilita UTF-8 en la consola de Windows.
     *
     * Al crearse, cambia el codepage a UTF-8.
     * Al destruirse, restaura el codepage original.
     */
    ConsoleUTF8 utf8;
#endif

    cout << "=== Sistema de Gestión de Estudiante ===" << endl << endl;

    /**
     * @section estudiante1 Sección Estudiante 1
     * @brief Uso del constructor por defecto y setters.
     */

    // 1. Constructor por defecto
    Estudiante estudiante1;
    cout << "Estudiante 1 (constructor por defecto):" << endl;
    estudiante1.mostrarInformacionCompleta();
    cout << endl;

    // 2. Actualización de atributos
    estudiante1.actualizarNombre("María García López");
    estudiante1.actualizarCodigo("EST-2024-001");
    estudiante1.actualizarEdad(20);
    estudiante1.actualizarPromedio(9.2f);
    estudiante1.actualizarActivo(true);

    cout << "Estudiante 1 después de actualizar:" << endl;
    estudiante1.mostrarInformacionCompleta();
    estudiante1.calcularEstadoAcademico();
    cout << endl;

    /**
     * @section estudiante2 Sección Estudiante 2
     * @brief Uso del constructor con parámetros y validaciones.
     */

    // 3. Constructor con parámetros
    Estudiante estudiante2("Juan Pérez Martínez", "EST-2024-002", 22, 7.5f, true);

    cout << "Estudiante 2 (constructor con parámetros):" << endl;
    estudiante2.mostrarInformacionCompleta();
    estudiante2.calcularEstadoAcademico();
    cout << endl;

    // 4. Incrementar edad
    cout << "Incrementando edad del estudiante 2:" << endl;
    estudiante2.incrementarEdad();
    estudiante2.mostrarEdad();
    cout << endl;

    // 5. Validación de promedio
    cout << "Intentando actualizar promedio con valor inválido:" << endl;
    estudiante2.actualizarPromedio(15.0f);
    estudiante2.mostrarPromedio();
    cout << endl;

    return 0;
}

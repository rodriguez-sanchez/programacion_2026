/**
 * @file estudiante.hpp
 * @author Gerardo Israel Rodríguez
 * @brief Definición de la clase Estudiante.
 * @date 2026-01-29
 *
 * @details
 * Esta clase modela a un estudiante con información básica como
 * nombre, código, edad, promedio y estado de actividad.
 * Proporciona métodos para actualizar, consultar y mostrar
 * dicha información, así como calcular su estado académico.
 */

#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

using std::string;

/**
 * @brief Clase que representa a un estudiante.
 */
class Estudiante {
private:
    string nombre;   ///< Nombre completo del estudiante
    string codigo;   ///< Código identificador del estudiante
    int edad;        ///< Edad del estudiante
    float promedio;  ///< Promedio académico (0.0 - 10.0)
    bool activo;     ///< Estado del estudiante (activo/inactivo)

public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa todos los atributos con valores neutros.
     */
    Estudiante();

    /**
     * @brief Constructor con parámetros.
     *
     * @param nombre Nombre del estudiante.
     * @param codigo Código identificador.
     * @param edad Edad del estudiante.
     * @param promedio Promedio académico.
     * @param activo Estado del estudiante.
     */
    Estudiante(string nombre, string codigo, int edad, float promedio, bool activo);

    /**
     * @name Setters
     * @{
     */

    /**
     * @brief Actualiza el nombre del estudiante.
     * @param nuevoNombre Nuevo nombre.
     */
    void actualizarNombre(string nuevoNombre);

    /**
     * @brief Actualiza el código del estudiante.
     * @param nuevoCodigo Nuevo código.
     */
    void actualizarCodigo(string nuevoCodigo);

    /**
     * @brief Actualiza la edad del estudiante.
     * @param nuevaEdad Nueva edad.
     */
    void actualizarEdad(int nuevaEdad);

    /**
     * @brief Actualiza el promedio del estudiante.
     *
     * El promedio debe estar en el rango [0.0, 10.0].
     *
     * @param nuevoPromedio Nuevo promedio.
     */
    void actualizarPromedio(float nuevoPromedio);

    /**
     * @brief Actualiza el estado de actividad del estudiante.
     * @param nuevoEstado Estado activo/inactivo.
     */
    void actualizarActivo(bool nuevoEstado);

    /** @} */

    /**
     * @name Getters
     * @{
     */

    /**
     * @brief Obtiene el nombre del estudiante.
     * @return Nombre del estudiante.
     */
    string obtenerNombre() const;

    /**
     * @brief Obtiene el código del estudiante.
     * @return Código del estudiante.
     */
    string obtenerCodigo() const;

    /**
     * @brief Obtiene la edad del estudiante.
     * @return Edad del estudiante.
     */
    int obtenerEdad() const;

    /**
     * @brief Obtiene el promedio del estudiante.
     * @return Promedio académico.
     */
    float obtenerPromedio() const;

    /**
     * @brief Obtiene el estado del estudiante.
     * @return true si está activo, false en caso contrario.
     */
    bool obtenerActivo() const;

    /** @} */

    /**
     * @name Métodos de visualización
     * @{
     */

    /**
     * @brief Muestra el nombre del estudiante.
     */
    void mostrarNombre() const;

    /**
     * @brief Muestra el código del estudiante.
     */
    void mostrarCodigo() const;

    /**
     * @brief Muestra la edad del estudiante.
     */
    void mostrarEdad() const;

    /**
     * @brief Muestra el promedio del estudiante.
     */
    void mostrarPromedio() const;

    /**
     * @brief Muestra el estado del estudiante.
     */
    void mostrarActivo() const;

    /**
     * @brief Muestra toda la información del estudiante.
     */
    void mostrarInformacionCompleta() const;

    /** @} */

    /**
     * @name Métodos de utilidad
     * @{
     */

    /**
     * @brief Incrementa la edad del estudiante en una unidad.
     */
    void incrementarEdad();

    /**
     * @brief Calcula y muestra el estado académico del estudiante.
     */
    void calcularEstadoAcademico() const;

    /** @} */
};

#endif // ESTUDIANTE_H

## Problema: Sistema de Gestión de Estudiantes

Deberás diseñar e implementar un programa en lenguaje C que permita gestionar información básica de estudiantes universitarios. Este programa será utilizado por un sistema de gestión académica.

---


### Menú del programa

1) Agregar estudiante
2) Mostrar un estudiante en específico
3) Mostrar todos los estudiantes
4) Salir


### Variables por estudiante

- `nombre` (string): Nombre completo del estudiante
- `codigo` (string): Código de identificación único del estudiante
- `edad` (int): Edad del estudiante
- `promedio` (float): Promedio de calificaciones (rango 0.0 a 10.0)
- `activo` (bool): Indica si el estudiante está activo en el sistema


### Funciones

#### Métodos para actualizar
- `void actualizarNombre(string nuevoNombre)`: Actualiza el nombre del estudiante
- `void actualizarCodigo(string nuevoCodigo)`: Actualiza el código del estudiante
- `void actualizarEdad(int nuevaEdad)`: Actualiza la edad del estudiante
- `void actualizarPromedio(float nuevoPromedio)`: Actualiza el promedio (debe validar que esté entre 0.0 y 10.0)
- `void actualizarActivo(bool nuevoEstado)`: Actualiza el estado activo del estudiante

#### Métodos de Visualización
- `void mostrarNombre()`: Muestra en consola: "Nombre: [nombre]"
- `void mostrarCodigo()`: Muestra en consola: "Código: [codigo]"
- `void mostrarEdad()`: Muestra en consola: "Edad: [edad] años"
- `void mostrarPromedio()`: Muestra en consola: "Promedio: [promedio]"
- `void mostrarActivo()`: Muestra en consola: "Estado: Activo" o "Estado: Inactivo"
- `void mostrarInformacionCompleta()`: Muestra toda la información del estudiante de forma organizada
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// ============================================
// CONSTANTES Y CONFIGURACIÓN
// ============================================
#define MAX_ESTUDIANTES 50
#define MAX_NOMBRE 30
#define MAX_CODIGO 15

// ============================================
// ESTRUCTURA DEL ESTUDIANTE
// ============================================
typedef struct Estudiante {
    char nombre[MAX_NOMBRE + 1];
    char codigo[MAX_CODIGO + 1];
    int edad;
    float promedio;
    bool activo;
} Estudiante;

// ============================================
// VARIABLES GLOBALES
// ============================================
Estudiante estudiantes[50];
int totalEstudiantes = 0;

// ============================================
// UTILIDADES DE ENTRADA
// ============================================
static void descartar_hasta_fin_linea(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

static void leer_linea(char *buf, size_t size) {
    if (fgets(buf, (int)size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    } else {
        descartar_hasta_fin_linea();
    }
}

static int leer_int(const char *mensaje, int *out_valor) {
    char linea[128];

    if (mensaje != NULL) {
        printf("%s", mensaje);
    }

    leer_linea(linea, sizeof(linea));

    char *endptr = NULL;
    long v = strtol(linea, &endptr, 10);
    if (endptr == linea) return 0;

    while (*endptr == ' ' || *endptr == '\t') endptr++;
    if (*endptr != '\0') return 0;

    *out_valor = (int)v;
    return 1;
}

static int leer_float(const char *mensaje, float *out_valor) {
    char linea[128];

    if (mensaje != NULL) {
        printf("%s", mensaje);
    }

    leer_linea(linea, sizeof(linea));

    char *endptr = NULL;
    float v = strtof(linea, &endptr);
    if (endptr == linea) return 0;

    while (*endptr == ' ' || *endptr == '\t') endptr++;
    if (*endptr != '\0') return 0;

    *out_valor = v;
    return 1;
}

// ============================================
// FUNCIONES DE VALIDACIÓN
// ============================================
bool validarPromedio(float promedio) {
    return (promedio >= 0.0f && promedio <= 10.0f);
}

int buscarEstudiantePorCodigo(const char* codigo) {
    for (int i = 0; i < totalEstudiantes; i++) {
        if (strcmp(estudiantes[i].codigo, codigo) == 0) {
            return i;
        }
    }
    return -1;
}

// ============================================
// FUNCIONES DE ENTRADA CON LÍMITES
// ============================================
void leerCadenaConLimite(char* destino, int maxLongitud, const char* mensaje) {
    printf("%s", mensaje);

    char temp[2048];
    leer_linea(temp, sizeof(temp));

    if ((int)strlen(temp) > maxLongitud) {
        temp[maxLongitud] = '\0';
        printf("Nota: Texto truncado a %d caracteres.\n", maxLongitud);
    }

    strncpy(destino, temp, (size_t)maxLongitud);
    destino[maxLongitud] = '\0';
}

// ============================================
// FUNCIONES DE ACTUALIZACIÓN
// ============================================
void actualizarNombre(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        leerCadenaConLimite(estudiantes[indice].nombre, MAX_NOMBRE, "Nuevo nombre: ");
        printf("Nombre actualizado.\n");
    }
}

void actualizarCodigo(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        char nuevoCodigo[MAX_CODIGO + 1];
        leerCadenaConLimite(nuevoCodigo, MAX_CODIGO, "Nuevo codigo: ");

        for (int i = 0; i < totalEstudiantes; i++) {
            if (i != indice && strcmp(estudiantes[i].codigo, nuevoCodigo) == 0) {
                printf("Error: Codigo ya existe.\n");
                return;
            }
        }

        strcpy(estudiantes[indice].codigo, nuevoCodigo);
        printf("Codigo actualizado.\n");
    }
}

void actualizarEdad(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        int nuevaEdad;
        if (!leer_int("Nueva edad: ", &nuevaEdad)) {
            printf("Error: Edad no valida.\n");
            return;
        }

        if (nuevaEdad > 0 && nuevaEdad < 120) {
            estudiantes[indice].edad = nuevaEdad;
            printf("Edad actualizada.\n");
        } else {
            printf("Error: Edad no valida.\n");
        }
    }
}

void actualizarPromedio(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        float nuevoPromedio;
        if (!leer_float("Nuevo promedio: ", &nuevoPromedio)) {
            printf("Error: Promedio no valido.\n");
            return;
        }

        if (validarPromedio(nuevoPromedio)) {
            estudiantes[indice].promedio = nuevoPromedio;
            printf("Promedio actualizado.\n");
        } else {
            printf("Error: Promedio no valido.\n");
        }
    }
}

void actualizarActivo(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        char linea[32];
        printf("Activo? (s/n): ");
        leer_linea(linea, sizeof(linea));
        char opcion = linea[0];
        estudiantes[indice].activo = (opcion == 's' || opcion == 'S');
        printf("Estado actualizado.\n");
    }
}

// ============================================
// FUNCIONES DE VISUALIZACIÓN EN TABLA
// ============================================
void mostrarCabeceraTabla() {
    printf("\n+------------------------------+---------------+-------+----------+------------+\n");
    printf("| %-28s | %-13s | %-5s | %-8s | %-10s |\n",
           "NOMBRE", "CODIGO", "EDAD", "PROMEDIO", "ESTADO");
    printf("+------------------------------+---------------+-------+----------+------------+\n");
}

void mostrarFilaEstudiante(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        printf("| %-28s | %-13s | %-5d | %-8.2f | %-10s |\n",
               estudiantes[indice].nombre,
               estudiantes[indice].codigo,
               estudiantes[indice].edad,
               estudiantes[indice].promedio,
               (estudiantes[indice].activo ? "ACTIVO" : "INACTIVO"));
    }
}

void mostrarPieTabla() {
    printf("+------------------------------+---------------+-------+----------+------------+\n");
}

void mostrarEstudianteEspecifico(int indice) {
    if (indice >= 0 && indice < totalEstudiantes) {
        mostrarCabeceraTabla();
        mostrarFilaEstudiante(indice);
        mostrarPieTabla();
    }
}

void mostrarTodosEstudiantes() {
    if (totalEstudiantes == 0) {
        printf("\nNo hay estudiantes registrados.\n");
        return;
    }

    printf("\nLISTADO DE ESTUDIANTES (%d)\n", totalEstudiantes);
    mostrarCabeceraTabla();

    for (int i = 0; i < totalEstudiantes; i++) {
        mostrarFilaEstudiante(i);
    }

    mostrarPieTabla();
}

// ============================================
// FUNCIONES PRINCIPALES DEL SISTEMA
// ============================================
void agregarEstudiante() {
    if (totalEstudiantes >= MAX_ESTUDIANTES) {
        printf("\nError: Limite de estudiantes alcanzado.\n");
        return;
    }

    Estudiante nuevo;

    printf("\n--- AGREGAR ESTUDIANTE ---\n");

    leerCadenaConLimite(nuevo.nombre, MAX_NOMBRE, "Nombre: ");

    bool codigoValido = false;
    while (!codigoValido) {
        leerCadenaConLimite(nuevo.codigo, MAX_CODIGO, "Codigo: ");

        if (buscarEstudiantePorCodigo(nuevo.codigo) != -1) {
            printf("Error: Codigo ya existe.\n");
        } else {
            codigoValido = true;
        }
    }

    while (!leer_int("Edad: ", &nuevo.edad) || nuevo.edad <= 0 || nuevo.edad >= 120) {
        printf("Error. Ingrese edad entre 1 y 120: ");
        char linea[128];
        leer_linea(linea, sizeof(linea));
        char *endptr = NULL;
        long v = strtol(linea, &endptr, 10);
        if (endptr != linea) nuevo.edad = (int)v;
    }

    while (!leer_float("Promedio (0.0-10.0): ", &nuevo.promedio) || !validarPromedio(nuevo.promedio)) {
        printf("Error. Ingrese promedio entre 0.0 y 10.0: ");
        char linea[128];
        leer_linea(linea, sizeof(linea));
        char *endptr = NULL;
        float v = strtof(linea, &endptr);
        if (endptr != linea) nuevo.promedio = v;
    }

    char linea_estado[32];
    printf("Activo? (s/n): ");
    leer_linea(linea_estado, sizeof(linea_estado));
    char estado = linea_estado[0];
    nuevo.activo = (estado == 's' || estado == 'S');

    estudiantes[totalEstudiantes] = nuevo;
    totalEstudiantes++;

    printf("\nEstudiante agregado.\n");
}

void buscarYMostrarEstudiante() {
    if (totalEstudiantes == 0) {
        printf("\nNo hay estudiantes registrados.\n");
        return;
    }

    char codigoBusqueda[MAX_CODIGO + 1];
    printf("\nCodigo del estudiante: ");
    if (scanf("%15s", codigoBusqueda) != 1) {
        descartar_hasta_fin_linea();
        return;
    }
    descartar_hasta_fin_linea();

    int indice = buscarEstudiantePorCodigo(codigoBusqueda);

    if (indice != -1) {
        mostrarEstudianteEspecifico(indice);

        char linea_op[32];
        printf("\nActualizar datos? (s/n): ");
        leer_linea(linea_op, sizeof(linea_op));
        char opcion = linea_op[0];

        if (opcion == 's' || opcion == 'S') {
            int opcionActualizar;
            do {
                printf("\n1. Actualizar nombre\n");
                printf("2. Actualizar codigo\n");
                printf("3. Actualizar edad\n");
                printf("4. Actualizar promedio\n");
                printf("5. Actualizar estado\n");
                printf("6. Volver\n");

                if (!leer_int("Opcion: ", &opcionActualizar)) {
                    printf("Opcion no valida.\n");
                    opcionActualizar = 0;
                }

                switch (opcionActualizar) {
                    case 1: actualizarNombre(indice); break;
                    case 2: actualizarCodigo(indice); break;
                    case 3: actualizarEdad(indice); break;
                    case 4: actualizarPromedio(indice); break;
                    case 5: actualizarActivo(indice); break;
                    case 6: printf("Volviendo...\n"); break;
                    default: printf("Opcion no valida.\n");
                }

                if (opcionActualizar >= 1 && opcionActualizar <= 5) {
                    printf("\nDatos actualizados:\n");
                    mostrarEstudianteEspecifico(indice);
                }

            } while (opcionActualizar != 6);
        }
    } else {
        printf("\nError: Estudiante no encontrado.\n");
    }
}

// ============================================
// MENÚ PRINCIPAL
// ============================================
void mostrarMenu() {
    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1. Agregar estudiante\n");
    printf("2. Buscar estudiante\n");
    printf("3. Mostrar todos\n");
    printf("4. Salir\n");
    printf("Estudiantes: %d/%d\n", totalEstudiantes, MAX_ESTUDIANTES);
    printf("Opcion: ");
}

// ============================================
// FUNCIÓN PRINCIPAL
// ============================================
int main(void) {
    int opcion;

    do {
        mostrarMenu();

        if (scanf("%d", &opcion) != 1) {
            printf("\nOpcion no valida.\n");
            descartar_hasta_fin_linea();
            continue;
        }
        descartar_hasta_fin_linea();

        switch (opcion) {
            case 1:
                agregarEstudiante();
                break;
            case 2:
                buscarYMostrarEstudiante();
                break;
            case 3:
                mostrarTodosEstudiantes();
                break;
            case 4:
                printf("\nSaliendo...\n");
                break;
            default:
                printf("\nOpcion no valida.\n");
                descartar_hasta_fin_linea();
        }

    } while (opcion != 4);

    return 0;
}

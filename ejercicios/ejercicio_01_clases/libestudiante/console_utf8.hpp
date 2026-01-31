/**
 * @file console_utf8.hpp
 * @author Gerardo Israel Rodríguez
 * @brief Gestión automática de UTF-8 en la consola de Windows.
 * @date 2026-01-30
 */

#ifndef CONSOLE_UTF8_HPP
#define CONSOLE_UTF8_HPP

#ifdef _WIN32
    #include <windows.h>
#endif

/**
 * @brief Clase que gestiona automáticamente la codificación UTF-8
 *        de la consola usando RAII.
 *
 * Al crear un objeto, se activa UTF-8 en la consola.
 * Al destruirlo, se restaura el codepage original.
 *
 * En sistemas no Windows, la clase no realiza ninguna acción.
 */
class ConsoleUTF8 {
    #ifdef _WIN32
        unsigned int oldcp;
    #endif

public:
    /**
     * @brief Constructor: activa UTF-8.
     */
    ConsoleUTF8() {
        #ifdef _WIN32
            oldcp = GetConsoleOutputCP();
            SetConsoleOutputCP(CP_UTF8);
        #endif
    }

    /**
     * @brief Destructor: restaura el codepage original.
     */
    ~ConsoleUTF8() {
        #ifdef _WIN32
            SetConsoleOutputCP(oldcp);
        #endif
    }
};

#endif // CONSOLE_UTF8_HPP

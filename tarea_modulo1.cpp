// Axel Dardon - Programacion 1
// Actividad del Modulo 1
// esto cubre los temas que vimos en clase, trate de hacerlo lo mas ordenado posible

#include <iostream>
#include <iomanip>   // esta es para el setw y setprecision
#include <fstream>   // la necesito para lo de los archivos
#include <vector>    // para usar vectores
#include <string>
using namespace std;

// ------------------------------------------------------------
// funcion de bienvenida, solo imprime un saludo al inicio
// ------------------------------------------------------------
void saludar_usuario() {
    string nombreUsuario = "Axel";
    cout << "\n==============================" << endl;
    cout << "  Hola " << nombreUsuario << "! Bienvenido :)" << endl;
    cout << "  Modulo 1 - Fundamentos C++" << endl;
    cout << "==============================" << endl;
}

// ------------------------------------------------------------
// 1) tipos de datos primitivos
// aqui muestro los tipos basicos que aprendimos: int, float, char, bool
// uso setw para que se vea alineado en consola
// ------------------------------------------------------------
void mostrar_tipos_datos() {
    cout << "\n--- Tipos de Datos ---\n";

    int edadAxel = 19;
    float notaFinal = 88.5f;
    char inicial = 'A';
    bool aprobo = true;
    double saldo = 250.75;

    cout << fixed << setprecision(2);
    cout << setw(18) << left << "Edad:"    << edadAxel  << endl;
    cout << setw(18) << left << "Nota:"    << notaFinal << endl;
    cout << setw(18) << left << "Inicial:" << inicial   << endl;
    cout << setw(18) << left << "Aprobo:"  << boolalpha << aprobo << endl;
    cout << setw(18) << left << "Saldo:"   << saldo     << endl;
}

// ------------------------------------------------------------
// 2) palabras reservadas
// son palabras que ya usa C++ y no podemos usar como nombres
// por ejemplo no puedo poner "int int = 5" porque int ya es reservada
// ------------------------------------------------------------
void explicar_palabras_reservadas() {
    cout << "\n--- Palabras Reservadas ---\n";

    int numeroValido = 42;  // esto si esta bien
    // int int = 42;        // esto daria error, int es reservada

    cout << "Las palabras reservadas son las que C++ ya usa.\n";
    cout << "Ejemplos: int, float, if, else, while, for, return...\n\n";
    cout << "mi variable 'numeroValido' = " << numeroValido << " (esa si es valida)\n";

    cout << "\nConvencion que usamos:\n";
    cout << "  variables  -> camelCase  ejemplo: edadAxel, notaFinal\n";
    cout << "  funciones  -> snake_case ejemplo: mostrar_datos, leer_archivo\n";
}

// ------------------------------------------------------------
// 3) bibliotecas
// usamos las de C++ como iostream, iomanip
// y aqui tambien hice una funcion propia que seria como mi "libreria"
// ------------------------------------------------------------

// esta funcion la hice yo, calcula el area de un rectangulo
double calcular_area_rectangulo(double base, double altura) {
    return base * altura;
}

void ejemplo_uso_bibliotecas() {
    cout << "\n--- Bibliotecas ---\n";
    cout << "Estoy usando: iostream, iomanip, fstream, vector\n\n";

    double base = 4.0;
    double altura = 6.5;
    double areaResultado = calcular_area_rectangulo(base, altura);

    cout << fixed << setprecision(2);
    cout << "Base: " << base << "  Altura: " << altura << endl;
    cout << "Area del rectangulo: " << areaResultado << endl;
    cout << "\n(calcular_area_rectangulo() es mi funcion propia)\n";
}

// ------------------------------------------------------------
// 4) entrada y salida
// cin para recibir datos, cout para mostrarlos
// setw sirve para darle formato a la salida, se ve mas prolijo
// ------------------------------------------------------------
void manejo_entrada_salida() {
    cout << "\n--- Entrada y Salida ---\n";

    string miNombre;
    int miEdad;

    cout << "Escribe tu nombre: ";
    cin >> miNombre;
    cout << "Escribe tu edad: ";
    cin >> miEdad;

    cout << "\n";
    cout << setw(12) << left << "Nombre:" << miNombre << endl;
    cout << setw(12) << left << "Edad:"   << miEdad << " anios" << endl;
}

// ------------------------------------------------------------
// 5) estructura del programa
// un programa en C++ siempre sigue un orden logico
// primero los includes, luego las funciones, luego el main
// ------------------------------------------------------------
void estructurar_programa() {
    cout << "\n--- Estructura de un Programa C++ ---\n";
    cout << "El orden basico es:\n\n";
    cout << "  1. #include (las bibliotecas)\n";
    cout << "  2. using namespace std\n";
    cout << "  3. declaracion de funciones\n";
    cout << "  4. int main() <- aqui empieza todo\n";
    cout << "  5. las funciones que declaramos arriba\n\n";
    cout << "Si dividimos el codigo en funciones es mas facil\n";
    cout << "de leer y de encontrar errores. eso es modularidad.\n";
}

// ------------------------------------------------------------
// 6) funciones basicas con parametros y retorno
// tambien meti la recursiva aqui que es el bonus
// ------------------------------------------------------------

// suma dos numeros y regresa el resultado
int sumar(int x, int y) {
    return x + y;
}

// funcion recursiva - se llama a si misma hasta llegar a 1
// si n es 0 o 1 regresa 1, si no multiplica n por factorial(n-1)
int calculate_factorial(int n) {
    if (n <= 1)
        return 1;
    return n * calculate_factorial(n - 1);
}

void ejemplo_funciones_basicas() {
    cout << "\n--- Funciones Basicas ---\n";

    int resultadoSuma = sumar(15, 7);
    cout << "sumar(15, 7) = " << resultadoSuma << endl;

    int numFact;
    cout << "\nIngresa un numero para el factorial: ";
    cin >> numFact;

    if (numFact < 0) {
        cout << "no existe factorial de negativos\n";
    } else {
        cout << "factorial de " << numFact << " = " << calculate_factorial(numFact) << endl;
    }
}

// ------------------------------------------------------------
// 7) archivos - escribir y leer con fstream
// ofstream para escribir, ifstream para leer
// ------------------------------------------------------------
void leer_escribir_archivo() {
    cout << "\n--- Archivos ---\n";

    string archivoNombre = "datos_axel.txt";

    // escribo el archivo
    ofstream escribir(archivoNombre);
    if (escribir.is_open()) {
        escribir << "Nombre: Axel Dardon\n";
        escribir << "Curso: Programacion 1\n";
        escribir << "Modulo: 1\n";
        escribir.close();
        cout << "archivo creado: " << archivoNombre << "\n\n";
    }

    // ahora lo leo
    ifstream leer(archivoNombre);
    string linea;
    cout << "contenido del archivo:\n";
    while (getline(leer, linea)) {
        cout << "  " << linea << endl;
    }
    leer.close();
}

// ------------------------------------------------------------
// 8) vectores y matrices
// vector es como un arreglo pero mas flexible
// la matriz es un arreglo de dos dimensiones
// ------------------------------------------------------------
void recorrer_vectores_matrices() {
    cout << "\n--- Vectores y Matrices ---\n";

    // vector con mis notas
    vector<int> misNotas = {70, 85, 90, 60, 95};
    int suma = 0;

    cout << "mis notas:\n";
    for (int i = 0; i < misNotas.size(); i++) {
        cout << "  nota " << i + 1 << ": " << misNotas[i] << endl;
        suma += misNotas[i];
    }
    cout << "  promedio: " << fixed << setprecision(1)
         << (double)suma / misNotas.size() << endl;

    // matriz 2x3
    cout << "\nmatriz 2x3:\n";
    int matriz[2][3] = { {1, 2, 3}, {4, 5, 6} };

    for (int f = 0; f < 2; f++) {
        cout << "  ";
        for (int c = 0; c < 3; c++) {
            cout << setw(4) << matriz[f][c];
        }
        cout << endl;
    }
}

// ------------------------------------------------------------
// main - aqui empieza el programa, tiene el menu con switch
// ------------------------------------------------------------
int main() {

    saludar_usuario();

    int opcion;

    do {
        cout << "\n========= MENU =========\n";
        cout << " 1. Tipos de datos\n";
        cout << " 2. Palabras reservadas\n";
        cout << " 3. Bibliotecas\n";
        cout << " 4. Entrada y salida\n";
        cout << " 5. Estructura del programa\n";
        cout << " 6. Funciones y factorial\n";
        cout << " 7. Archivos\n";
        cout << " 8. Vectores y matrices\n";
        cout << " 0. Salir\n";
        cout << "========================\n";
        cout << "opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: mostrar_tipos_datos();          break;
            case 2: explicar_palabras_reservadas(); break;
            case 3: ejemplo_uso_bibliotecas();      break;
            case 4: manejo_entrada_salida();        break;
            case 5: estructurar_programa();         break;
            case 6: ejemplo_funciones_basicas();    break;
            case 7: leer_escribir_archivo();        break;
            case 8: recorrer_vectores_matrices();   break;
            case 0: cout << "\nchao! :)\n";         break;
            default: cout << "\nesa opcion no existe, intenta de nuevo\n";
        }

    } while (opcion != 0);

    return 0;
}
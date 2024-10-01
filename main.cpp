#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void PreprocesarArchivo(string file) {
    ifstream inputFile(file); //Abre el archivo en modo lectura
    ofstream outputFile("output.txt"); // Crea un archivo

    if (!inputFile.is_open()) { //Si el archivo no existe
        cout << "Archivo no existe" << endl;
        return;
    }

    string content; // Variable para guardar el contenido de cada linea

    while(getline(inputFile, content)) { // Mientras haya lineas en el archivo
        content.erase(remove(content.begin(), content.end(), '\t'), content.end()); // Elimina los tabs
        content.erase(content.begin(), find_if(content.begin(), content.end(), [](unsigned char ch) {
            return !isspace(ch);
        })); // Elimina los espacios al inicio de la linea

        content.erase(remove_if(content.begin(), content.end(), ::isspace), content.end());
        // Elimina los espacios en blanco


        if (!(content.empty() || (content[0] == '#' || content[0] == '/'))) {
            outputFile << content << endl;
        }

    }
    // Cierra el archivo
    inputFile.close();
}

void RecorrerArchivo(string file) {
    ifstream inputFile(file);

    if (!inputFile.is_open()) { //Si el archivo no existe
        cout << "Archivo no existe" << endl;
        return;
    }

    char caracter; // Variable para almacenar cada carácter leído

    while (inputFile.get(caracter)) {  // Leer carácter por carácter
        if (caracter != '\n') {
            cout << caracter << endl;  // Imprimir el carácter en la consola
        }
    }

    inputFile.close();
}

bool VerificarDigito(const string& input) {
    int estado = 0;  // Iniciamos en el estado Q0

    // Recorrer cada carácter de la cadena de entrada
    for (char c : input) {
        switch (estado) {
            case 0:
                if (c >= '0' && c <= '9') {
                    estado = 1;  // Transición a Q1 si es un dígito
                } else {
                    return false;  // Si no es un dígito, falla
                }
            break;
            case 1:
                // Una vez en Q1, cualquier carácter no es válido
                    return false;
        }
    }

    // El autómata acepta si estamos en el estado Q1 al final de la entrada
    return estado == 1;
}


int main() {
    // Llama a la funcion PreprocesarArchivo
   // PreprocesarArchivo("ola.txt");
    //RecorrerArchivo("output.txt");
    string entrada = "1";
    bool resultado = VerificarDigito(entrada);

    cout << entrada << endl;
    if (resultado) {
        cout << "La entrada es una cadena de digitos valida." << endl;
    } else {
        cout << "La entrada NO es una cadena de digitos valida." << endl;
    }

    string name = "Montalvo";
    int sizeofpatron = 10;
    printf("%zu\n", sizeof(name));
    return 0;
}

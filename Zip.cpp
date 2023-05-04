#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    // Lettura del nome del file da zippare dal file esterno
    string filename;
    ifstream infile("filelist.txt");
    if (!infile) {
        cout << "Errore nella lettura del file esterno" << endl;
        return 1;
    }
    getline(infile, filename);
    infile.close();

    // Comando di WinRAR per creare un file ZIP
    string command = "winrar a -afzip archive.zip " + filename;

    // Esecuzione del comando tramite il sistema
    int result = system(command.c_str());
    if (result != 0) {
        cout << "Errore durante la creazione del file ZIP" << endl;
        return 1;
    }

    cout << "File ZIP creato con successo" << endl;
    return 0;
}

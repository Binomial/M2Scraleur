#include "../include/File.h"

using namespace std;

void File::readFile(string path) {
    ifstream fichier(path.c_str(), ios::in); // on ouvre le fichier en lecture

    if (fichier) {
        string ligne;
        while (getline(fichier, ligne)) // tant que l'on peut mettre la ligne dans "contenu"
        {
            cout << ligne << endl; // on l'affiche
        }
    }
}

void File::writeFile(string path, string text) {
    ofstream fichier(path.c_str(), ios::out | ios::trunc); // ouverture en écriture avec effacement du fichier ouvert

    if (fichier) {
        fichier << text;
        cout << "fichier sauvegarde" << endl;
        fichier.close();
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

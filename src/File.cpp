#include "../include/File.h"
#include "../include/Anagram.h"
using namespace std;


void File::readFile(string path) {
    ifstream fichier(path.c_str(), ios::in); // on ouvre le fichier en lecture

    if (fichier) { // si l'ouverture a réussi
        string contenu; // déclaration d'une chaîne qui contiendra la ligne lue
        getline(fichier, contenu); // on met dans "contenu" la ligne
        cout << contenu; // on affiche la ligne
        fichier.close(); // on ferme le fichier
    } else { // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;
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

void File::readFileAna(string path) {
    ifstream fichier(path.c_str(), ios::in); // on ouvre le fichier en lecture
    ofstream badFile("./Dico/badFile.tmp", ios::out|ios::trunc);
    
    Anagram an("./Dico/diciAnagrams.txt");

    if (fichier) { // si l'ouverture a réussi
        string contenu; // déclaration d'une chaîne qui contiendra la ligne lue
        while (getline(fichier, contenu)) {
            if (contenu.length() < 8) {
                an.anagram(contenu, 0, contenu.length());
            }else{
                badFile << contenu << endl;
            }
            
        }
        //cout << contenu << endl;
        fichier.close(); // on ferme le fichier
    } else { // sinon
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}
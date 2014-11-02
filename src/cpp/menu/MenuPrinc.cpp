
#include "../../include/menu/MenuPrinc.h"

using namespace std;

void MenuPrinc::menu() {
    string letters;

    Anagram an;
    an.fileToMap("dico/map/dictFr.dc");

    FindWord f(an.getMap());

    cout << "Bienvenue sur le Scraleur" << endl << endl;


    do {
        cout << "Saissez vos lettres, ou 0 pour quitter : ";
        cin >> letters;
        cout << endl << endl;
        
        f.findPotentialWord(letters);
    } while (letters.compare("0") != 0);

}
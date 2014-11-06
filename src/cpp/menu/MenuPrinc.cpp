
#include "../../include/menu/MenuPrinc.h"

using namespace std;

void MenuPrinc::menu() {
    string letters;
    int white = 0; // White letter
    
    Anagram an;
    an.fileToMap("dico/map/dictFr.dc");

    FindWord f(an.getMap());

    cout << "Bienvenue sur le Scraleur" << endl << endl;


    do {
        cout << "Saissez vos lettres, ou 0 pour quitter : ";
        cin >> letters;
        cout << endl << endl;
        
        for(int i = 0; i<letters.length(); i++) {
            if(letters[i]== '8') {
                white++;
                string alpha = "abcdefghijklmnopqrstuvwxz";
                for(int j=0; j < 26; j++) {
                    letters[i] = alpha[j];
                    cout << "joker vaut " << alpha[j] << endl;
                    f.findPotentialWord(letters);
                }
            }
        }
        
        
        if(white == 0) {
            f.findPotentialWord(letters);
        } else {
            cout << "vous avez eut " << white << " lettre blanche" <<endl;
        }
    } while (letters.compare("0") != 0);

}
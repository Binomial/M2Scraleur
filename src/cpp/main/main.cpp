/* 
 * File:   main.cpp
 * Author: jeremy
 *
 * Created on 30 octobre 2014, 21:24
 */

#include "../../include/Dictionnary.h"
#include "../../include/FindWord.h"
using namespace std;

int main() {
    
    Dictionnary dict;
    dict.importDictionnary();
    
    FindWord fw(dict.getMap());
    string letters;
    
    cout << "Saisir lettres : ";
    cin >> letters;
    
    fw.permut(letters);
    fw.displaySolution();
    
    return 0;
}
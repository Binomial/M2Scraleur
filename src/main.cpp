/* 
 * File:   main.cpp
 * Author: jschnei2
 *
 * Created on 23 octobre 2014, 18:33
 */

#include "../include/Anagram.h"
#include "../include/File.h"

using namespace std;

/*
 * 
 */
int main() {    
    string word;
    /*
    cout << "Veuillez saisir le mot : "<< endl;
    cin >> word;
    
    Anagram an;
    an.anagram(word, 0, word.length());
     * */
    
    File file;
    //file.writeFile("Dico/DicoFr.dc", "coucou");
    file.readFileAna("./Dico/DicoFr.dc");
            
    return 0;
}


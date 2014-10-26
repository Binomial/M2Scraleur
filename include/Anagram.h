/* 
 * File:   Anagramme.h
 * Author: jschnei2
 *
 * Created on 23 octobre 2014, 18:34
 */

#ifndef ANAGRAMME_H
#define	ANAGRAMME_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class Anagram {
public:
    Anagram(string path) : file(path.c_str()) { cout << "Début de la cinstruction" << endl;}
    // Permut 2 letters
    string letters_permutation(string word, int position1, int position2);
    // Construct all anagrams of word, recursively
    void anagram(string word, int position, int size);
    
    ofstream file;
};

#endif	/* ANAGRAMME_H */


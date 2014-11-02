/* 
 * File:   SortDict.cpp
 * Author: jeremy
 *
 * Created on 30 octobre 2014, 21:37
 */

#include "../../include/sort/SortDict.h"

using namespace std;

/*
 * Create a file with all words that contains  exactly "wordSize" number of  caracters
 * Write in "dico/bad/bad.dc" the word that contains more than MAX_LENGHT caracters
 */
void SortDict::sortFile(int wordSize, int MAX_LENGTH, string path, string pathSave) {
    ifstream dict(path.c_str(), ios::in);
    ofstream newDict(pathSave, ios::out | ios::trunc);
    ofstream badWord("dico/bad/bad.dc", ios::out | ios::trunc);

    string word;
    if (dict) {


        while (getline(dict, word)) {
            if (word.length() == wordSize) {
                newDict << word << endl;
            }
            if (word.length() > MAX_LENGTH) {
                badWord << word << endl;
            }            
        }
        cout << "The file was created " << endl;
    } else {
        cout << "Can't open the file in " << path << endl;
    }
}

/*
 * Generate all the file for an input
 */
void SortDict::splitDictionnary() {
    for(int i =1; i < 26; i++) {
        string path = "dico/generate/dicoFr" + std::to_string(i) + ".dc";
        sortFile(i,26,"dico/dicoFr.dc", path);
    }
}
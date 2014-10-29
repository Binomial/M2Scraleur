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
#include <map>
#include <set>

using namespace std;

namespace anagram {

    class Anagram {
    public:

        // map (int, set(string))

        //Constructor, open an ouput file

        Anagram(string path, string path2) : path(path), file(path2, ios::out | ios::trunc), fileTest(path) {
            map<int, set < string>> mapWord;
        }


        void mapToFile();

        int testWord(string word);

        // Permut 2 letters
        string letters_permutation(string word, int position1, int position2);

        // Construct all anagrams of word, recursively
        void anagram(int id, string word, int position, int size);

    private:
        map<int, set<string>> mapWord;
        string path;
        ofstream file;
        ifstream fileTest;
    };

}
#endif	/* ANAGRAMME_H */


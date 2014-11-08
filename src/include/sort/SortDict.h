/* 
 * File:   SortDict.h
 * Author: jeremy
 *
 * Created on 30 octobre 2014, 21:32
 */

#ifndef SORTDICT_H
#define	SORTDICT_H

#include <string>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

/*
 * trie le dictionnaire par taille de mot
 * puis créer un fichier par taille de mot
 */
class SortDict {
public:
    void sortFile(const unsigned int wordSize, const unsigned int MAX_LENGTH, string path, string pathSave);
    void splitDictionnary();
};

#endif	/* SORTDICT_H */


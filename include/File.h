/* 
 * File:   Anagramme.h
 * Author: jschnei2
 *
 * Created on 23 octobre 2014, 18:34
 */

#ifndef FILE_H
#define	FILE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class File {
public:
    ofstream openFileWr(string path);
    // Read file at path
    void readFile(string path);
    // write in path
    void writeFile(string path, string text);
    void readFileAna(string path);
};

#endif	/* FILE_H */


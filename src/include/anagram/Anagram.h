/* 
 * File:   Anagram.h
 * Author: jeremy
 *
 * Created on 31 octobre 2014, 12:23
 */

#ifndef ANAGRAM_H
#define	ANAGRAM_H
#include <string>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class Anagram {
public:
    
    bool compareTo(string word, string wordToCompare);
    bool mapContain(string word);
    
    map<int, set<string>> getMap();
    
    string deleteCarFromString(string str, char car);
    
    void makeAnagramsDictionary();
    void anagramOfWord(int num, string word, string path);
    void anagramOfFile(string path);
    void fileToMap(string path);
    void mapToFile();
    void mapToString();
    void lineToMap(string line);
    
private:
    int num;
    map<int,set<string>> mapAnagrams;
};


#endif	/* ANAGRAM_H */


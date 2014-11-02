/* 
 * File:   findword.h
 * Author: jeremy
 *
 * Created on 1 novembre 2014, 19:05
 */

#ifndef FINDWORD_H
#define	FINDWORD_H

#include <string>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
using namespace std;

class FindWord {
public:
    FindWord(map<int, set<string>> mapAnagrams) : mapAnagrams(mapAnagrams) {}
    
    bool compareTo(string word, string wordToCompare);
    int commonLetters(string word, string wordToCompare);
    int nbPoints(string word);
    string deleteCarFromString(string str, char car);
    void findPotentialWord(string word);
    
    
private:
    map<int, set<string>> mapAnagrams;
    int bestPoint;
    string bestWord;
};
#endif	/* FINDWORD_H */
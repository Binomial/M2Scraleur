/* 
 * File:   Anagram.cpp
 * Author: jeremy
 *
 * Created on 31 octobre 2014, 12:26
 */

#include "../../include/anagram/Anagram.h"

using namespace std;


/*
 * Return mapAnagram (contain all anagrams in format (1 as sa / 2 ah ha...)
 */
map<int,set<string>> Anagram::getMap() {
    return mapAnagrams;
}


/*
 * Write mapAnagram on the console
 */
void Anagram::mapToString() {
    ofstream file("dico/map/dictFr.dc", ios::out | ios::trunc);
    for (const auto& anagram : mapAnagrams) {
        cout << anagram.first;
        for (const auto& set : mapAnagrams[anagram.first]) {
            cout << " " << set;
        }
        cout << endl;
    }
}

/*
 * Save the map into file
 */
void Anagram::mapToFile() {
    ofstream file("dico/map/dictFr.dc", ios::out | ios::trunc);
    for (const auto& anagram : mapAnagrams) {
        file << anagram.first;
        for (const auto& set : mapAnagrams[anagram.first]) {
            file << " " << set;
        }
        file << endl;
    }
    cout << "The map is save" << endl;
}

/*
 * Parse a line like 1 ab ba to add it on the map
 */
void Anagram::lineToMap(string line) {
    int num; 
    int position = 0;
    unsigned int t = 0;
    string tmp;
    while (t <= line.length()) {
        if (line[t] == ' ' || t == line.length()) {
            position++;
            if (position == 1) {
                istringstream(tmp) >> num;
            } else {
                mapAnagrams[num].insert(tmp);
            }
            tmp = "";
        } else {
            tmp += line[t];
        }
        t++;
    }
}


/*
 * Put a file in mapAnagrams
 */
void Anagram::fileToMap(string path) {
    ifstream file(path.c_str(), ios::in);
    if(file) {
        string line;
        while(getline(file, line)) {
            lineToMap(line);
        }
        cout << "the map was loaded" << endl;
    } else {
        cerr << "Can't read file in " << path << endl;
    }
}


/*
 * Test the existence of "word" in mapAnagrams
 */
bool Anagram::mapContain(string word) {
    for (const auto& s : mapAnagrams) {
        if (s.second.find(word) != s.second.end()) {
            return true;
        }
    }

    return false;
}


/*
 * Delete car in str
 */
string Anagram::deleteCarFromString(string str, char car) {
    unsigned int i = 0;
    while (i <= str.length()) {
        if (str[i] == car) {
            for (unsigned int j = i; j <= str.length(); j++) {
                str[j] = str[j + 1];
            }

            break;
        }
        i++;
    }
    return str;
}


/*
 * compare if wordToCompare contains all caraters of word
 */
bool Anagram::compareTo(string word, string wordToCompare) {

    unsigned int i = 0;
    unsigned int j;
    bool letterOk = true;

    while (i < word.length()) {
        letterOk = false;
        j = 0;
        while (j < wordToCompare.length() && !letterOk) {
            if (word[i] == wordToCompare[j]) {
                letterOk = true;
                wordToCompare = deleteCarFromString(wordToCompare, wordToCompare[j]);
            }
            j++;
        }

        if (!letterOk)
            return false;
        i++;
    }

    return true;
}


/*
 * Find all angrams of "word" and put it on mapAnagrams 
*/
void Anagram::anagramOfWord(int num, string word, string path) {
    ifstream inputFile(path.c_str(), ios::in);
    if (inputFile) {
        string line;

        while (getline(inputFile, line)) {
            if (compareTo(word, line) && !mapContain(line)) {
                mapAnagrams[num].insert(line);
            }
            //}
        }
        inputFile.close();
    } else {
        cerr << "Can't open file from " << path << endl;
    }
}


/*
 * Browse a file to find all anagrams of each line, an put it on mapAnagrams
 */
void Anagram::anagramOfFile(string path) {
    ifstream inputFile(path.c_str(), ios::in);
    if (inputFile) {
        string line;
        while (getline(inputFile, line)) {
            num++;
            anagramOfWord(num, line, path);
        }
    } else {
        cerr << "Cant open file form " << path << endl;
    }
}


/*
 * Browse all file in "dico/generate/" to find all anagrams of each line, an put it on mapAnagrams
 */
void Anagram::makeAnagramsDictionary() {
    num = 0;
    for (int i = 1; i < 26; i++) {
        cout << i << endl;
        string path = "dico/generate/dicoFr" + std::to_string(i) + ".dc";
        ifstream fileToRead(path, ios::in);
        // Si le fichier existe
        if (fileToRead) {
            anagramOfFile(path);
        }

    }
}


#include "../../include/findword/FindWord.h"
using namespace std;

/*
 * Return the number of point for word
 */
int FindWord::nbPoints(string word) {
    int nbPoints = 0;
    for (int i = 0; i < word.length(); i++) {
        switch (word[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'l':
            case 'n':
            case 'o':
            case 'r':
            case 's':
            case 't':
            case 'u':
                nbPoints += 1;
                break;

            case 'd':
            case 'g':
            case 'm':
                nbPoints += 2;
                break;

            case 'b':
            case 'c':
            case 'p':
                nbPoints += 3;
                break;

            case 'f':
            case 'h':
            case 'v':
                nbPoints += 4;
                break;

            case 'j':
            case 'q':
                nbPoints += 8;
                break;

            case 'k':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                nbPoints += 10;
                break;
        }
    }

    return nbPoints;
}

/*
 * Delete the caracter car in str
 */
string FindWord::deleteCarFromString(string str, char car) {
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
 * Return the number of common letters between word and wordToCompare
 */
int FindWord::commonLetters(string word, string wordToCompare) {
    int commonLetters = 0;

    unsigned int i = 0;
    unsigned int j;
    bool letterOk = true;

    while (i < word.length()) {
        letterOk = false;
        j = 0;
        while (j < wordToCompare.length() && !letterOk) {
            if (word[i] == wordToCompare[j]) {
                letterOk = true;
                commonLetters++;
                wordToCompare = deleteCarFromString(wordToCompare, wordToCompare[j]);
            }
            j++;
        }
        i++;
    }
    return commonLetters;
}

void FindWord::findPotentialWord(string letters) {
    bestPoint = 0;
    for (const auto& anagram : mapAnagrams) {
        for (const auto& set : mapAnagrams[anagram.first]) {
            if (compareTo(letters, set)) {
                int nbPoint = nbPoints(set);
                if(bestPoint < nbPoint) {
                    bestPoint = nbPoint;
                    bestWord = set;
                }
                cout << " avec " << letters << " on peut faire " << set << " pour " << nbPoint << endl;
            }
        }
    }
    
    cout << endl << endl << "Un meilleur mot est " << bestWord << " pour " << bestPoint << " points" << endl << endl;
}

bool FindWord::compareTo(string wordToCompare, string word) {

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
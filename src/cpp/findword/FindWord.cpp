

#include "../../include/findword/FindWord.h"
using namespace std;
/*
 * Clear the map of solution
 */
void FindWord::mapClear() {
    mapSolution.clear();
    bestPoint = 0;
    bestWord = "";
}

/*
 * Test the existence of "word" in mapAnagrams
 */
bool FindWord::mapContain(string word) {
    for (const auto& s : mapSolution) {
        if (s.second.find(word) != s.second.end()) {
            return true;
        }
    }

    return false;
}

void FindWord::start(string letters) {
    int nbWhiteLetters = nbWHite(letters);
    int indFirstWhite, indSecondeWhite;
    string alpha;
    
    if (nbWhiteLetters > 2) {
        cerr << "You can't have more than 2 white letter" << endl;
    }
    switch (nbWhiteLetters) {
        case 0:
            findPotentialWord(letters);
            break;
        case 1:
            indFirstWhite = indWhiteLetter(letters, 0);
            alpha = "abcdefghijklmnopqrstuvwxyz";
            for (int j = 0; j < 26; j++) {
                letters[indFirstWhite] = alpha[j];
                findPotentialWord(letters);
            }
            break;
        case 2:
            indFirstWhite = indWhiteLetter(letters, 0);
            indSecondeWhite = indWhiteLetter(letters, 1); 
            alpha = "abcdefghijklmnopqrstuvwxyz";
            for (int i = 0; i < 26; i++) {
                letters[indFirstWhite] = alpha[i];
                for(int j=0; j <26; j++) {
                   letters[indSecondeWhite] = alpha[j]; 
                   //cout << "Jok 1 : " << letters[indFirstWhite] << "Jok 2 : " << letters[indSecondeWhite] << endl; 
                   findPotentialWord(letters);
                }
                
            }
            cout << indFirstWhite << " " << indSecondeWhite << endl;
            break;


    }
}

/*
 * Nomber of white letter 
 */
int FindWord::nbWHite(string letters) {
    int nbWhiteLetters = 0;
    for (unsigned int i = 0; i < letters.length(); i++) {
        if (letters[i] == '8') {
            nbWhiteLetters++;
        }
    }
    return nbWhiteLetters;
}

int FindWord::indWhiteLetter(string letters, int position) {
    int pos = 0;
    for (unsigned int i = 0; i < letters.length(); i++) {
        if (letters[i] == '8' && pos == position) {
            return i;
        }
        pos++;
    }
    
    return 888;
}

/*
 * Return the number of point for word
 */
int FindWord::nbPoints(string word) {
    int nbPoints = 0;
    for (unsigned int i = 0; i < word.length(); i++) {
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
    bestWord = "";

    for (const auto& anagram : mapAnagrams) {
        for (const auto& set : anagram.second) {
            if (compareTo(letters, set)) {
                int nbPoint = nbPoints(set);
                if (bestPoint < nbPoint) {
                    bestPoint = nbPoint;
                    bestWord = set;
                }
                if (nbPoint > 0 && ! mapContain(set)) {
                    mapSolution[nbPoint].insert(set);
                    cout << " avec " << letters << " on peut faire " << set << " pour " << nbPoint << endl;
                }

            }
        }
    }
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
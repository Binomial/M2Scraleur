#include "../../include/anagram/Anagram.h"

using namespace std;

namespace anagram {

    string Anagram::letters_permutation(string word, int position1, int position2) {
        char tempLetter;
        tempLetter = word[position1];
        word[position1] = word[position2];
        word[position2] = tempLetter;
        return word;
    }

    int Anagram::testWord(string word) {
        string line;
        // En théorie on se place au début du fichier fileTest
        // on parcours ce fichier tant qu'on trouve pas un mot = word ou fin fichier



        if (fileTest) {
            fileTest.seekg(0, ios::beg);
            do {
                getline(fileTest, line);
                if (line.compare(word) == 0) {
                    return 0;
                }
            } while (line.compare("OLLA") != 0);
            return -1;
        } else {
            cerr << "Could not open fileTest ! line " << line << " word " << word << endl;
            exit(0);
        }
        return -1;
    }

    void Anagram::mapToFile() {
        for (const auto& s : mapWord) {
            file << s.first << " ";
            for (const auto& ss : mapWord[s.first]) {
                file << ss << " ";
            }
            file << endl;
        }
    }

    void Anagram::anagram(int id, string word, int position, int size) {
        int j;
        int i;
       
        // Tester si word est dans un set
        for(const auto& s : mapWord) {
            if(s.second.find(word) != s.second.end()) {
                return;
            }           
        }
        
        if (position == size - 1) { // Stop condition
            i = testWord(word);
            if (i == 0) {
                mapWord[id].insert(word);
            }
        } else {
            for (j = position; j < size; j++) {
                word = letters_permutation(word, position, j);
                anagram(id, word, position + 1, size);
                word = letters_permutation(word, position, j);
            }
        }
    }
}
#include "../include/Anagram.h"
using namespace std;

string Anagram::letters_permutation(string word, int position1, int position2) {
    char tempLetter;
    tempLetter = word[position1];
    word[position1] = word[position2];
    word[position2] = tempLetter;
    return word;
}

void Anagram::anagram(string word, int position, int size) {
    int j;

    if (position == size - 1) //Si position (pos) est égal à DimMot (nombre de lettres ds le mot) -1 (posit° de la dernière lettre), alors :
    {
        cout << "  Mot: " << word << endl;
    } else {
        for (j = position; j < size; j++) {
            word = letters_permutation(word, position, j);
            anagram(word, position + 1, size);
            word = letters_permutation(word, position, j);
        }
    }
}

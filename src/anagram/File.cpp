#include "../../include/File.h"
#include "../../include/anagram/Anagram.h"

using namespace std;

void File::readFileAna(string path) {
    // opens the dictionnary in read mode to constructs anagrams
    ifstream file(path.c_str(), ios::in);
    // opens a file to write the largest than 8 caracters word
    ofstream badFile("./Dico/badFile.tmp", ios::out | ios::trunc);

    anagram::Anagram an(path, "./Dico/dictAnagrams.txt");
    int numLine = 0;
    
    if (file) {
        if (badFile) {
            string line;
            while (getline(file, line)) {
                if (line.length() < 8) {
                    numLine++;
                    an.anagram(numLine, line, 0, line.length());
                } else {
                    badFile << line << endl;
                }
            }
            an.mapToFile();
            badFile.close();
        }else{
            cerr << "Error by opening the badFile";
        }
        file.close();
    } else {
       cerr << "Error by opening the dictionnary file";
    }
}
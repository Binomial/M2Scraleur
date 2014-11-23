#include "../include/Permut.h"

bool Permut::next(int n, int k, int* i) {
    return next_rec(n, k, i, k - 1);
}

bool Permut::next_rec(int n, int k, int* i, int j) {
    i[j]++;

    if (i[j] == n - (k - j) + 1) {


        if (j == 0) {

            return false;
        }


        if (!next_rec(n, k, i, j - 1)) {

            return false;
        }


        i[j] = i[j - 1] + 1;
    }

    return true;
}

void Permut::start(string letters) {
    setCombinaison.clear();
    const int n = letters.length();
    string tmp;

    sort(letters.begin(), letters.end());

    for (unsigned int k = 2; k <= letters.length(); k++) {
        int *i = new int[k];
        for (unsigned int j = 0; j < k; ++j) {

            i[j] = j;
        }

        do {
            tmp = "";
            for (unsigned int j = 0; j < k; ++j) {
                tmp += letters[i[j]];
                
            }
            findAnagrams(tmp);
        } while (next(n, k, i));
    }
}

void Permut::printSolution() {
    cout << setSolution.size() << " solutions trouvees" << endl << endl;
    for (const auto& an : setSolution) {
        cout << an << endl;
    }
}

void Permut::findAnagrams(string key) {
    if (mapDict.count(key) > 0) {
        //La clé existe, on affiche les solutions
        for (const auto& word : mapDict[key]) {
            setSolution.insert(word);
        }
    }
}



void Permut::lineToMap(string line) {
    string cle;
    int position = 0;
    unsigned int t = 0;
    string tmp;
    while (t <= line.length()) {
        if (line[t] == ' ' || t == line.length()) {
            position++;
            if (position == 1) {
                istringstream(tmp) >> cle;
            } else {
                mapDict[cle].insert(tmp);
            }
            tmp = "";
        } else {
            tmp += line[t];
        }
        t++;
    }
}

void Permut::importDictionnary() {
    ifstream file("dico/dictFr2.dc", ios::in);

    if (file) {
        string line;
        while (getline(file, line)) {
            lineToMap(line);
        }
        cout << "the map was loaded" << endl;
    } else {
        cerr << "Can't open the dictionnary" << endl;
    }
}
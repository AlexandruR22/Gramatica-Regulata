#include <iostream>
#include <map>
#include <string.h>
#include <fstream>


using namespace std;

int main() {
    multimap<char, pair<char, char>> Gramatica;
    multimap < char, pair < char, char >> ::iterator
            it;

    ifstream f("Gramatica.txt");

    int n, i, ok;
    char c1, c2, c3, Cuvant[50], StareCurenta, StareFinala;

    f >> n;
    for (i = 0; i < n; i++) {
        f >> c1 >> c2 >> c3;
        Gramatica.insert(make_pair(c1, make_pair(c2, c3)));
    }

    f >> Cuvant;

    f >> StareCurenta;

    f >> StareFinala;

    for (i = 0; i < strlen(Cuvant); i++) {
        ok = 0;
        for (it = Gramatica.begin(); it != Gramatica.end(); it++)
            if (StareCurenta == (*it).first && Cuvant[i] == (*it).second.first) {
                StareCurenta = (*it).second.second;
                ok = 1;
            }

        if (ok == 0) {
            cout << endl << "Cuvantul '" << Cuvant << "' nu apartine gramaticii regulate." << endl;
            return 0;
        }

    }

    if (StareCurenta != StareFinala) {
        cout << endl << "Cuvantul '" << Cuvant << "' nu apartine gramaticii regulate." << endl;
        return 0;
    }

    cout << endl << "Cuvantul '" << Cuvant << "' apartine gramaticii regulate." << endl;

    return 0;
}

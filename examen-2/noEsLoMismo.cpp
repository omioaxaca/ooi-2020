#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main () {
    vector<string> valores;
    string s;
    while (cin >> s) {
        valores.push_back(s);
    }
    int idx_separacion = 0;
    for (int i = 0; i < valores.size() - 1; i++) {
        if (valores[i] == "lo" && valores[i + 1] == "que") {
            idx_separacion = i;
        }
    }
    for (int i = idx_separacion + 2; i < valores.size(); i++) {
        cout << valores[i] << " ";
    }
    cout << "lo que ";
    for (int i = 0; i < idx_separacion; i++) {
        cout << valores[i] << " ";
    }
    


    return 0;
}

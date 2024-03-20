//NOMBRE y APELLIDOS
//Pablo Gamo González
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> heidi(const vector<int>& vec, int l, int& cont, int& r) {
    cont = 0; r = 0;
    int i = vec.size()-1;
    int s = 1;
    int maxi = 0;
    vector<int> resVec;

    while (i > 0) {
        maxi = max(maxi, vec[i]);
        if (vec[i] == vec[i - 1] && vec[i] >= maxi) {
            s++;
            if (s == l) {
                resVec.push_back(i+s-2);
                cont++;
                r = max(r, s);
            }else if (s > l) {
                r = max(r, s);
            }
        }else {
            s = 1;
        }
        i--;
    }
    
    return resVec;
}

bool resuelveCaso() {
    int n, l;
    //Lee los datos
    cin >> n >> l;
    if (!cin) return false;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    //Calcula el resultado
    int cont, r;
    vector <int> resVec = heidi(vec, l, cont, r);
    //Escribe el resultado
    cout << r << " " << cont << " ";
    for (int i = 0; i < (int) resVec.size(); i++) {
        cout << resVec[i] << " ";
    }
    cout << "\n";

    return true;
}

int main() {

    // ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // restablecimiento de cin
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("pause");
#endif
    return 0;
}
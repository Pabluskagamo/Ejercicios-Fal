//NOMBRE y APELLIDOS
//Pablo Gamo González
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//Q {0 <= vec.size() <= 1000 && forall i: 0 <= i <= vec.size() : vec[i] < 4000}
//R {max p, q: 0 <= p <= q <= vec.size() && A(p,q): q-p}
//A(p,q) = (forall i: p <= i < q-1 : v[i] > v[i+1]) 
//I{max p, q: 0 <= p <= q <= vec.size() && A(p,q): q-p && s = (min p: 0 < p <= vec.size() && A(p,n): p)} //Revisar Invariante
//C = vec.size() - i
//Coste: O(n) donde n = vec.size().
int tramaMasLarga(const vector<int>& vec) {
    int i = 1; int r = 0; int s = 0;

    if (vec.size()!= 0) {
        r = 1;
        while (i < vec.size()) {
            if (vec[i] > vec[i - 1]) {
                s = i;
            }
            r = max(r, (i + 1 - s));
            i++;
        }
    }
    
    return r;
}

void resuelveCaso() {
 //resuelve aqui tu caso
    int n;
    //Lee los datos
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    //Calcula el resultado
    int res = tramaMasLarga(vec);
    //Escribe el resultado
    cout << res << "\n";
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    
    unsigned int numCasos;
    std::cin >> numCasos;
    // Resolvemos
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
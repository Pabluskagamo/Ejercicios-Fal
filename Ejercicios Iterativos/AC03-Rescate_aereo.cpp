//NOMBRE y APELLIDOS
//Pablo Gamo Gonzalez

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//Muchas dudas Invariante.

//Q{True}
//fun esPastoso(vector<int>vec, int f , out int ini, out int fin) dev<bool>
//R{max i, f : forall j: 0 <= i < j <= f < vec.size() && v[j] > f}
//I{0 <= i < vec.size() && s = (s+1 : vec[i] > f  || 0 } //Invariante está mal
//C = vec.size() - i
//Coste: O(n) donde n = vec.size()
void secMasLargaAltura(const vector<int>& vec, int f, int& ini, int& fin) {
    int i = 0; int r = 0; int s = 0;
    ini = 0;

    while (i != vec.size()) {
        if (vec[i] > f) {
            s++;
            if (s > r) {
                r = s;
                fin = i;
            }
        }else {
            s = 0;
        }
        i++;
    }

    ini = fin - r + 1;
}

void resuelveCaso() {
 //resuelve aqui tu caso
    int n, t;
    //Lee los datos
    cin >> n;
    cin >> t;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    //Calcula el resultado
    int ini, fin = 0;
    secMasLargaAltura(vec, t, ini, fin);
    //Escribe el resultado
    cout << ini << " " << fin << "\n";

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
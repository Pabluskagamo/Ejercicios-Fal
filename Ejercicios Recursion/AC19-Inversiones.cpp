//NOMBRE y APELLIDOS
//Pablo Gamo Gonzalez
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


long long int inversiones(const vector<int>& vec, int i, int f, int max) { //incompleto

    if (i + 2 == f) {
        if (vec[i] > vec[i + 1]) {
            return 1;
        }
    }
    else {
        int m = (i + f) / 2;
        int izq, der;

        izq = inversiones(vec, i, m, max);
        der = inversiones(vec, m, f, max);
        
        
        return total * inversiones(vec, i, m, total);


    }

}

long long int inversiones(const vector<int>& vec) {
    return inversiones(vec,0, vec.size(), 0);
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
    long long int res = inversiones(vec);
    //Escribe el resultado
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
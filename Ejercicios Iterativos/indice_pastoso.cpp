//NOMBRE y APELLIDOS
//Pablo Gamo Gonzalez

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Revisar especificacion.
//Q{ 0 <= vec.size() <= 10^5 }
//fun esPastoso(vector<int>v) dev<bool>
//R{ x = E z: 0 <= z < vec.size : esPastoso(v,z) && x ==> p = max l: 0 <= l < vec.size() && esPastoso(v,l) : l)
//esPastoso(v,k) = v[K] = sum j : k+1 < j < v.size(): v[j]
//Coste: O(n) donde n = vec.size()
//C = i+1
//I {-1 <= i < vec.size && sum = sum j: i < j < v.size() : v[j] 
    //&& ok = E j: i < j < v.size() : esPastoso(v,j) && ok ==> p = max j: 0 <= j < vec.size() && esPastoso(v,j) : j} 
bool esPastoso(const vector<int>& vec, int &pos) {
    bool ok = false;

    int i = (int) vec.size() - 1;
    int sum = 0;

    while (!ok && i >= 0) {
        if (vec[i] == sum) {
            ok = true;
            pos = i;
        }
        sum += vec[i];
        i--;
    }

    return ok;
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
    int pos;
    bool res = esPastoso(vec, pos);
    //Escribe el resultado
    if (res) {
        cout << "Si " << pos << "\n";
    }
    else {
        cout << "No\n";
    }
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
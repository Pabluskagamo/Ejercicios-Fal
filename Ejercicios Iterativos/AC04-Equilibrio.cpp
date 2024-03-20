//NOMBRE y APELLIDOS
//Pablo Gamo González

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void tieneCeroUno(int pos,int& ceros, int& unos) {
    if (pos == 1) {
        unos++;
    }else if (pos == 0) {
        ceros++;
    }
}

//Q {true}
//R { -1 <= p < vec.size() and numUnos(vec, p+1) = numCeros(vec, p+1) 
// and forall k : p < k < vec.size() : numUnos(vec, k+1) != numCeros(vec, k+1)}
// I {-1 <= p < vec.size() and numUnos(vec, p+1) = numCeros(vec, p+1) 
// and forall i : p < i < vec.size() : numUnos(vec, i) != numCeros(vec, i)}.
//C = vec.size() - i
//Coste: O(n) donde n = vec.size();
int equilibrio(const vector<int>& vec) {
    int i = 0;
    int unos = 0;
    int ceros = 0;
    int p = -1;

    while (i < vec.size()){
        tieneCeroUno(vec[i], ceros, unos);
        if (ceros == unos) {
            p = i;
        }
        i++;
    }

    return p;
}

void resuelveCaso() {
 //resuelve aqui tu caso
    int n;
    //Lee los datos
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    //Calcula el resultado
    int res = equilibrio(vec);
    //Escribe el resultado
    cout << res <<"\n";
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
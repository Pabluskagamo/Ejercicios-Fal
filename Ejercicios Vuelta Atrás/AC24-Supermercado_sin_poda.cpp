//NOMBRE y APELLIDOS
//Pablo Gamo González

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


bool esValida(vector<int>& marcaSup, int i) {
    return marcaSup[i] < 3;
}


void minValor(const vector<vector<int>>& prods, int n, int m, int k, vector<int>& solucion, vector<int>& solucionMejor, vector<int>& marcaSup, int coste, int& valorMejor) {

    for (int i = 0; i < m; i++) {
        solucion[k] = i;
        if (esValida(marcaSup, i)) {
            marcaSup[i]++;
            coste += prods[i][k];
            if (k == n - 1) {
                if (coste < valorMejor) {
                    valorMejor = coste;
                    solucionMejor = solucion;
                }
            }
            else {
                minValor(prods, n, m, k + 1, solucion, solucionMejor, marcaSup, coste, valorMejor);
            }
            marcaSup[i]--;
            coste -= prods[i][k];
        }

    }

}


int minValor(const vector<vector<int>>& prods, int n, int m, int sumMax) {

    vector<int> solucion(n);
    vector<int> solucionMejor(n);
    vector<int> marcaSup(m);
    int coste = 0;
    int valorMejor = sumMax;

    for (int i = 0; i < n; i++) {
        solucion[i] = 0;
        solucionMejor[i] = 0;
        if (i < m) {
            marcaSup[i] = 0;
        }
    }

    minValor(prods, n, m, 0, solucion, solucionMejor, marcaSup, coste, valorMejor);

    return valorMejor;
}

void resuelveCaso() {
 //resuelve aqui tu caso
    int n, m;

    cin >> m >> n;
    vector<vector<int>> prods(m, vector<int>(n));
    int sumaProds = 0;

    //Lee los datos
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            cin >> prods[i][j];
            sumaProds += prods[i][j];
        }
    }
    //Calcula el resultado
    int res = minValor(prods, n, m, sumaProds);
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
//NOMBRE y APELLIDOS
//Pablo Gamo González

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
ESPACIO DE SOLUCIONES: Vector de n posiciones donde n es el numero de productos a comprar en el que cada
componente solucion[i] pertenece a [0...m-1] donde m es el supermercado donde compra el producto.

RESTRICCIONES EXPLICITAS: cada componente de la solucion pertenece a [0 ,..., m-1] donde m es el supermercado.
RESTRICCIONES IMPLICITAS: cada m solo puede aparecer como mucho 3 veces en la solucion, es decir solo de pueden
comprar 3 productos en cada supermercado.


TAMAÑO DEL ARBOL DE EXPLORACION: Es un arbol de profundidad n y ramificacion m donde n es el numero de productos y m
el numero de supermercados, luego es de tamaño m^n.
*/



void preCalculo(const vector<vector<int>>& prods, vector<int>& sumMinProds, int m, int n) {
    vector<int> minimos(prods[0].size());

    for (int i = 0; i < n; i++) {
        int min = prods[0][i];
        for (int j = 0; j < m; j++) {
            if (prods[j][i] < min) {
                min = prods[j][i];
            }
        }
        minimos[i] = min;
    }

    sumMinProds[n-1] = 0;
    for (int i = n - 2; i > -1; i--) {
        sumMinProds[i] = sumMinProds[i + 1] + minimos[i+1];
    }

}


bool esValida(vector<int>& marcaSup, int i) {
    return marcaSup[i] < 3;
}


void minValor(const vector<vector<int>>& prods, int n, int m, int k, vector<int>& solucion, vector<int>& solucionMejor, vector<int>& marcaSup, int coste, int& valorMejor, int min, vector<int>& sumMinProds) {

    for (int i = 0; i < m; i++) {
        solucion[k] = i;
        if (esValida(marcaSup, i)) {
            marcaSup[i]++;
            coste += prods[i][k];
            int estimacion = coste + sumMinProds[k];
            if (estimacion < valorMejor) {
                if (k == n - 1) {
                    if (coste < valorMejor) {
                        valorMejor = coste;
                        solucionMejor = solucion;
                    }
                }
                else {
                    int optimista = coste + (min * (n - (k + 1)));
                    if (valorMejor > optimista) {
                        minValor(prods, n, m, k + 1, solucion, solucionMejor, marcaSup, coste, valorMejor, min, sumMinProds);
                    }
                }
            }
            marcaSup[i]--;
            coste -= prods[i][k];
        }

    }

}


int minValor(const vector<vector<int>>& prods, int n, int m, int sumMax, int min) {

    vector<int> solucion(n);
    vector<int> solucionMejor(n);
    vector<int> marcaSup(m);
    int coste = 0;
    int valorMejor = sumMax;

    vector<int> sumaMinProds(n);

    preCalculo(prods, sumaMinProds,m,n);
    minValor(prods, n, m, 0, solucion, solucionMejor, marcaSup, coste, valorMejor , min, sumaMinProds);

    return valorMejor;
}

void resuelveCaso() {
 //resuelve aqui tu caso
    int n, m;

    cin >> m >> n;
    vector<vector<int>> prods(m, vector<int>(n));
    int sumaProds = 0;
    int min = 1 <<30;

    //Lee los datos
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            cin >> prods[i][j];
            sumaProds += prods[i][j];
            if (prods[i][j] < min) {
                min = prods[i][j];
            }
        }
    }
    //Calcula el resultado
    int res = minValor(prods, n, m, sumaProds, min);
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
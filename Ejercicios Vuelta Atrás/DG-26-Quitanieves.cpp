//NOMBRE y APELLIDOS
//Pablo Gamo González.

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void preCalculo(const vector<vector<int>>& calidades, vector<int>& faltantes, int n, int m) {
    vector<int> rapidos(n);

    for (int i = 0; i < m; i++) {
        int max = calidades[i][0];
        for (int j = 0; j < n; j++) {
            if (calidades[i][j] > max) {
                max = calidades[i][j];
            }
        }
        rapidos[i] = max;
    }

    faltantes[n - 1] = 0; //Está mal, revisar.
    for (int i = n - 2; i > -1; i--) {
        faltantes[i] = faltantes[i + 1] + rapidos[i + 1];
    }


}

bool esValida(vector<bool>& marcas, vector<int>& maquinas, vector<int>& carreteras, int i, int k) {
    return !marcas[i] && maquinas[k] <= carreteras[i];
}

//Mal hecho.
void maxCalidad(vector<vector<int>>& calidades, int m, int n, int k, int coste, int& valorMejor, vector<int>& solucion, vector<int>& solucionMejor, vector<bool>&marcas, vector<int>& maquinas, vector<int>& carreteras, int max, vector<int>& faltantes) {

    for (int i = 0; i < n; i++) {
        solucion[k] = i;
        if (esValida(marcas, maquinas, carreteras,i,k)) {
            marcas[i] = true;
            coste += calidades[k][i];
            if (k == m - 1) {
                if (coste > valorMejor) {
                    solucionMejor = solucion;
                    valorMejor = coste;
                }
            }
            else {
                int optimista = coste + max * (m - (k + 1));
                if (optimista > valorMejor) {
                    maxCalidad(calidades, m, n, k + 1, coste, valorMejor, solucion, solucionMejor, marcas, maquinas, carreteras, max, faltantes);
                }
            }
            marcas[i] = false;
            coste -= calidades[k][i];
        }

    }


}

int maxCalidad(vector<vector<int>>& calidades,int m , int n, vector<int>& maquinas, vector<int>& carreteras, int max) {
    int mejorValor = 0;

    vector<int> solucion(n);
    vector<int> solucionMejor(n);
    vector<bool> marcas(n, false);
    vector<int> faltantes(n);

    //preCalculo(calidades, faltantes, n, m);
    maxCalidad(calidades, m, n, 0, 0, mejorValor, solucion, solucionMejor, marcas, maquinas, carreteras, max, faltantes);


    return mejorValor;
}


void resuelveCaso() {
    int m, n;
 //resuelve aqui tu caso
    //Lee los datos
    cin >> m >> n;
    
    vector<int> maquinas(m);
    vector<int> carreteras(n);
    vector<vector<int>> calidades(m, vector<int>(n));
    //Calcula el resultado
    for (int i = 0; i < m; i++) {
        cin >> maquinas[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> carreteras[i];
    }

    int max = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> calidades[i][j];
            if (calidades[i][j] > max) {
                max = calidades[i][j];
            }
        }
    }
    
    int res = maxCalidad(calidades, m, n, maquinas, carreteras,max);
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
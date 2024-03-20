// NOMBRE Y APELLIDOS
//Pablo Gamo González

#include <iostream>
#include<vector>
#include <fstream>
using namespace std;

/*
ESPACIO DE SOLUCIONES: Es un vector de n elementos donde n es el numero de trabajos y en cada posicion i está el trabajador que lo realiza

RESTRICCIONES EXPLICITAS: Todos los componentes del vector solucion tienen que pertenecer a [0,...,n] donde n es el numero de trabajadores.

RESTRICCIONES IMPLICITAS: Un trabajador solo puede realizar un trabajo y un trabajo solo puede ser realizado por un trabajador.

ARBOL DE EXPLORACION: El arbol de exploracion es de ramificacion n y de profundidad n donde n es a su vez el numero de trabajadores y de trabajos
luego el tamaño entonces es de n^n


*/

void preCalculo(const vector<vector<int>>& funcs, int n, vector<int>& minimosFaltantes){
    vector<int> minimosCol(n);
    int min;
    for (int i = 0; i < n; i++) {
        min = funcs[i][0];
        for (int j = 1; j < n; j++) {
            if (funcs[i][j] < min) {
                min = funcs[i][j];
            }
        }
        minimosCol[i] = min;
    }

    minimosFaltantes[n - 1] = 0;

    for (int i = n - 2; i > -1; i--) {
        minimosFaltantes[i] = minimosFaltantes[i + 1] + minimosCol[i + 1];
    }
    
}
bool esValida(const vector<bool>& marcas, vector<bool>& marcasTr, int i, int k) {
    return !marcas[k] && !marcasTr[i];
}

void minCoste(const vector<vector<int>>& funcs,int n, int k,vector<bool>& marcas, vector<bool>& marcasTr,int& mejorValor, int coste, vector<int>& solucion, vector<int>& solucionMejor, int min, vector<int>& minimosFaltantes) {

    for (int i = 0; i < n; i++) {
        solucion[k] = i;
        if (esValida(marcas,marcasTr,i,k)) {
            marcas[k] = true;
            marcasTr[i] = true;
            coste += funcs[k][i];
            int estimacion = coste + minimosFaltantes[k];
            if (estimacion < mejorValor) {
                if (k == n - 1) {
                    if (coste < mejorValor) {
                        mejorValor = coste;
                        solucionMejor = solucion;
                    }
                }
                else {
                    int optimista = coste + (min * (n - (k + 1)));
                    if (optimista < mejorValor) {
                        minCoste(funcs, n, k + 1, marcas, marcasTr, mejorValor, coste, solucion, solucionMejor, min, minimosFaltantes);
                    }
                }
            }
            marcas[k] = false;
            marcasTr[i] = false;
            coste -= funcs[k][i];
        }

    }

}


int minCoste(const vector<vector<int>>& funcs, int n, int sumaFuncs, int min) {
    int mejorValor = sumaFuncs;
    vector<int> solucion(n);
    vector<int> solucionMejor(n);
    vector<bool> marcas(n,false);
    vector<bool> marcasTr(n,false);
    int coste = 0;
    
    vector<int> minimosFaltantes(n);


    preCalculo(funcs, n, minimosFaltantes);
    minCoste(funcs, n, 0, marcas, marcasTr, mejorValor, coste, solucion, solucionMejor, min, minimosFaltantes);

    return mejorValor;
}

bool resuelveCaso() {
    int n;
    //Leer caso de prueba: cin>>...
    cin >> n; 
    if (n == 0)
        return false;
 
    vector<vector<int>> funcs(n, vector<int>(n));

    int suma = 0;
    int min = 1 <<30;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> funcs[i][j];
            suma += funcs[i][j];
            if (funcs[i][j] < min) {
                min = funcs[i][j];
            }
        }
    }
    //Resolver problema
    int res = minCoste(funcs, n, suma, min);
    //Escribir resultado
    cout << res << "\n";
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
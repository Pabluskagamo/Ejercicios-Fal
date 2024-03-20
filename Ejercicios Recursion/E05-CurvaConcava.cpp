// NOMBRE Y APELLIDOS
//Pablo Gamo González   

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*Analisis del coste:
    T(n){
        T(n) = c0 si n = 0
        T(n) = T(n/2) + c1 si n >=1
    }

    T(n) es del orden de O(log(n)) por el teorema de la division
*/

int minCurva(const vector<int>& vec, int i, int f) {
    if (i + 1 == f) { //vector unitario
        return vec[i];
    }
    else {

        int m = (i + f) / 2;

        if (vec[m] > vec[m-1]) { //está decreciendo.
            return minCurva(vec, i, m);
        }
        else{ //está creciendo.
            return minCurva(vec, m, f);
        }
    }
}

int minCurva(const vector<int>& vec) {
    return minCurva(vec, 0, vec.size());
}

bool resuelveCaso() {
    int n;
    //Leer caso de prueba: cin>>...
    cin >> n;
    if (!std::cin)
        return false;
 
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    //Resolver problema
    int res = minCurva(vec);
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
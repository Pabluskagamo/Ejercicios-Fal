// NOMBRE Y APELLIDOS
//Pablo Gamo Gozalez

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void mezcla(vector <int >& v, int a, int m, int b) {
    int* u = new int[b - a + 1];
    int i, j, k;
    // Copia en el vector auxiliar
    for (k = a; k <= b; k++) u[k - a] = v[k];
    // Bucle principal de la mezcla
    i = 0; j = m - a + 1; k = a;
    while ((i <= m - a) && (j <= b - a)) {
        if (u[i] <= u[j]) {
            v[k] = u[i];
            i = i + 1;
        }
        else {
            v[k] = u[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i <= m - a) {
        v[k] = u[i];
        i = i + 1;
        k = k + 1;
    }
    while (j <= b - a) {
        v[k] = u[j];
        j = j + 1;
        k = k + 1;
    }
    delete[] u;
}



int reestructurarFlota(vector<int>& vec, int i, int f) { //Terminar, probablemente esté todo mal.

    if (i + 2 == f) { //Vector de long 2.
        int aux;

        if (vec[i] > vec[i + 1]) {
            aux = vec[i];
            vec[i] = vec[i + 1];
            vec[i+1] = aux;
        }
    }
    else {
        int m = (i + f) / 2;

        if (vec[m] < m) {
            return reestructurarFlota(vec, i, m);
            mezcla(vec, i, m, 0);
        }
        else if (vec[m] > m) {
            return reestructurarFlota(vec, m, f);
            mezcla(vec, m, f, 0);
        }
        else {

        }
    }

}


int reestructurarFlota(vector<int>& vec) {



    return reestructurarFlota(vec, 0 ,vec.size());
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
    int res = reestructurarFlota(vec);
    //Escribir resultado
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
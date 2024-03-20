//NOMBRE y APELLIDOS
//Pablo Gamo Gonzalez  
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


void calculaPicosValles(const vector<int>& vector, int& p, int& v, int n) {


    for (int i = 1; i < n - 1; i++) {
        if (vector[i] > vector[i - 1] && vector[i] > vector[i + 1]) {
            p++;
        }
        if (vector[i] < vector[i - 1] && vector[i] < vector[i + 1]) {
            v++;
        }

    }
}


void resuelveCaso() {
    //resuelve aqui tu caso
    int n;
    cin >> n;
    vector<int> vector(n);

    //Lee los datos
    for (int i = 0; i < n; i++) {
        cin >> vector[i];
    }
    //Calcula el resultado
    int p = 0;
    int v = 0;

    calculaPicosValles(vector, p, v, n);

    //Escribe el resultado
    cout << p << " " << v << endl;
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
// NOMBRE Y APELLIDOS
//Pablo Gamo Gonzalez

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*Analisis del coste:

    T(n){
        T(n) = c0 si n <= 2
        T(n) = 2T(n/2) + c1 si n > 2
    }
    El coste es del orden de O(n) donde n es el numero de elementos del vector, por el teorema de la division.
*/

//Precondicion: (forall k: 0 <= k < vec.size() && vec[k] = 2^x)
//Postcondicion:
bool esDegradado(const vector<int>& vec, int i, int f, int& total) {

    if (i + 1 == f) { //Vector unitario
        return true;
    }
    else if (i + 2 == f) { //Vector de 2 elementos.
        total = vec[i] + vec[f - 1];
        return vec[i] < vec[f-1];
    }
    else {
        int m = (i + f) / 2;

        int suma1, suma2 = 0;
        bool der = true, izq = true;

        der = esDegradado(vec, i, m, suma1);
        izq = esDegradado(vec, m, f, suma2);

        total = suma1 + suma2;
        
        return der && izq && (suma1 < suma2);
    }
}


bool esDegradado(const vector<vector<int>>& vec) {
    bool ok = true;
    int suma = 0;
    int i = 0;
    while (i < vec.size() && ok) {
        ok = esDegradado(vec[i], 0, vec[i].size(),suma);
        i++;
    }
    return ok;
}

bool resuelveCaso() {
    int n, m;
    //Leer caso de prueba: cin>>...
    cin >> n >> m;
    
    if (!std::cin)
        return false;
    
    vector<vector<int>>vec(n);
    for (int i = 0; i < n; i++) {
        int num;
        for (int j = 0; j < m; j++) {
            cin >> num;
            vec[i].push_back(num);
        }
    }
    
    //Resolver problema
    bool res = esDegradado(vec);
    //Escribir resultado
    if (res) {
        cout << "SI\n";
    }
    else {
        cout << "NO\n";
    }
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
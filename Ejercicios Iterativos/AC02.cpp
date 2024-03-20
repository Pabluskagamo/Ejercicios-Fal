//NOMBRE y APELLIDOS
//Pablo Gamo González
#include <iostream>
#include <fstream>
#include <vector> 
using namespace std;

//Dudas invariante y función de cota.
//Q{ 0 < n < longitud(vec) && 0 <= p < n }
//R{ x = (forall i,j : 0 <= i <= p < j < n : vec[i] < vec[j]) }
//I{ i <= pos < n }
//C = pos - i;
//Coste O(n) donde n = vector.size()
bool vectorBienDiv(const vector<int>& vec, int n, int pos) {
    bool ok;
    int max = vec[0];
   
    for (int i = 0; i <= pos; i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }
    int min = (pos + 1 < n) ? (vec[pos + 1]) : (max + 1);

    for (int i = pos + 1; i < n; i++) {
        if (vec[i] < min) {
            min = vec[i];
        }
    }

    return ok = (max < min);
}

/*bool vectorBienDiv(const vector<int>& vec, int n, int pos) {
    int i = 0;
    int j;
    bool ok = true;

    while (i < pos + 1 && ok) {
        j = pos + 1;
        while (j < n) {
            if (vec[i] < vec[j]) {
                j++;
            }
        }
        ok = (i == j);
    }

    return ok;
}*/

void resuelveCaso() {
    int n, pos;
 //resuelve aqui tu caso
    //Lee los datos
    cin >> n;
    cin >> pos;

    vector<int> vector(n);
    for (int i = 0; i < n; i++) {
        cin >> vector[i];
    }
    //Calcula el resultado
    bool res = vectorBienDiv(vector, n , pos);
    //Escribe el resultado
    if (res) {
        cout << "SI\n";
    }else {
        cout << "NO\n";
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
//NOMBRE y APELLIDOS
//Pablo Gamo Gonzalez  

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//Creciente(vec) = {forall i: 0 <= i < vec.size()-1 : vec[i] < vec[i+1]}
//noConsecutivo(vec) = {forall i: 0 <= i < vec.size()-1 : vec[i] != vec[i+1] + 1}
//Precondicion: {forall k: 0 < k < vec.size() && creciente(vec) && noConsecutivo(vec)}
//func bongo(vector<int> vec, int i, int f, int x) dev int
//Postcondicion:{n = E k: ( 0 <= k < vec.size() : vec[i] == x+i)

/*Analisis del coste:
    T(n){
        T(n) = c0 si n = 0
        T(n) = T(n/2) + c1 si n >= 1
    }

    T(n) es del orden de O(log(n)) por el teorema de la division
*/
int bongo(const vector<int>& vec, int i, int f, int x) {

    if (i + 1 == f) { //vector unitario.
        if (vec[i] == (x+i)) {
            return vec[i];
        }
        else {
            return -1;
        }
    }
    else {
        int m = (i + f) / 2;

        if (vec[m] == (x + m)) { //el numero es justo el del medio.
            return vec[m];
        }else if (vec[m] < (x + m)) {
            return bongo(vec, m, f, x);
        }else if (vec[m] > (x + m)) {
            return bongo(vec, i, m, x);
        }
    }
}

int bongo(const vector<int>& vec, int x) {
    return bongo(vec, 0, vec.size(), x);
}

void resuelveCaso() {
    int n, x;
 //resuelve aqui tu caso
    //Lee los datos
    cin >> n >> x;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    //Calcula el resultado
    int num = bongo(vec, x);
    //Escribe el resultado
    if (num != -1) {
        cout << num << "\n";
    }
    else {
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
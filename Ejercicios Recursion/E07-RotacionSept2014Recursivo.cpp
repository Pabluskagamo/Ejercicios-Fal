// NOMBRE Y APELLIDOS
//Pablo Gamo Gonzalez

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//decrecienteConRotacion(vec) = (forall i,j: 0 <= i < j <= vec.size() : decreciente(0,j) && decreciente(j,vec.size()))
//Precondicion: { forall n: 0 < n <= vec.size() && decrecienteConRotacion(vec)} //Dudas precondicion. Sobre todo con el decreciente con rotacion.
//fun buscaMinVec(vector<int> vec, int i, int f) dev int 
//PostCondicion: min = {min i: 0 <= i < vec.size(): vec[i]}

/*Analisis del coste
    T(n){
        T(n) = c0 si n = 0
        T(n) = c1 si n = 1
        T(n) = T(n/2) + c2 si n >= 2
    }
    T(n) es del orden de O(log(n)) por el teorema de la division
*/


int buscaMinVec(const vector<int>& vec, int i, int f) {

    if (i + 2 == f) { //Vector de 2 elementos
        if (vec[i] < vec[i + 1]) {
            return vec[i];
        }
        else {
            return vec[i+1];
        }
    }
    else if (i + 1 == f){//Vector de unitario
        return vec[i];
    }
    else {
        
        if (vec[i] > vec[f-1]) {
            return vec[f-1];
        }

        int m = (i + f) / 2;

        if (vec[m] < vec[f - 1]) {
            return buscaMinVec(vec, m, f);
        }
        else if (vec[i] < vec[m]) {
            return buscaMinVec(vec, i, m);
        }

    }

    
}

int buscaMinVec(const vector<int>& vec) {
    return buscaMinVec(vec, 0, vec.size());
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
    int min = buscaMinVec(vec);
    //Escribir resultado
    cout << min << "\n";
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
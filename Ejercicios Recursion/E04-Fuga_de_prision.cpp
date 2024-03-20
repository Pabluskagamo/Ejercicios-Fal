//NOMBRE y APELLIDOS
//Pablo Gamo Gonzalez

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;




//Precondicion: {E c : forall i: ini <= c <= fin: vec[i] != c && ordenado(vec)}
//func encuentraPrisionero(vector<char> vec, i, f, ini, fin) dev char c
//Postcondicion: {c = x, !E z : forall i: ini <= c <= fin: vec[i])} //Seguramente está sintacticamente mal 

/*Analisis del Coste
    T(n){
        T(n) = c0 si n = 0
        T(n) = T(n/2) + c1
    }
    T(n) es del orden de O(log(n)) por el teorema de la division

*/


char encuentraPrisionero(const vector<char>& vec, int i, int f, char ini, char fin) { 
    char c;

    if (i + 1 == f) { //Vector Unitario
        if (vec[i] == ini) {
            c = vec[i] + 1;
        }
        else {
            c = vec[i] - 1;
        }   
    }
    else {

        if (ini != vec[i]) { //Si el prisionero era el primero
            return ini;
        }
        else if (fin != vec[f - 1]) { //Si el prisionero era el ultimo.
            return fin;
        }

        int m = (i + f) / 2;

        if (vec[m] - vec[i] == m - i) {
            return encuentraPrisionero(vec, m, f, vec[m], fin);
        }
        else {
            return encuentraPrisionero(vec, i, m, ini, vec[m - 1]);
        }
    }
    
    return c;
}

char encuentraPrisionero(const vector<char>& vec, char ini, char fin) {
    return encuentraPrisionero(vec,0, vec.size(), ini, fin);
}


void resuelveCaso() {
 //resuelve aqui tu caso
    char ini, fin;
    //Lee los datos
    cin >> ini >> fin;
    int n = fin - ini;
    vector<char> vec(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    //Calcula el resultado
    char c = encuentraPrisionero(vec, ini, fin);
    //Escribe el resultado
    cout << c << "\n";
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
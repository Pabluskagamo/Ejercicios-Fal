//NOMBRE y APELLIDOS
//Pablo Gamo Gonzalez

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Especificacion compleja, hay que hacer algo parecido al multiset pero debe mantener la secuencia.
//multSetPares(v): conjunto de pares del vector
//Q{ 0 <= vec.size() < logitud(vec) && ord(v, 0, vec.size()) && v = V}
//R{ord(V, 0, vec.size()) && multSetPares(v) = multSetPares(V)}
//I{forall j: 0 <= i < vec.size() : vec[i] % 2 == 0 && p = min j: 0 <= j <= i < vec.size(): vec[j] !=E multSetPares(v)}
//C = vec.size()-i;
//Coste: O(n) donde n = vec.size()
void eliminaPares(vector<int>& vec) {
    int i = 0; int p = 0;

    while (i < vec.size()) {
        if (vec[i] % 2 == 0) {
            vec[p] = vec[i];
            p++;
        }
        i++;
    }
    vec.resize(p);
}



void resuelveCaso() {
 //resuelve aqui tu caso
    long long int n;
    //Lee los datos
    cin >> n;
    vector<int> vec(n);

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    //Calcula el resultado
    eliminaPares(vec);

    //Escribe el resultado
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";

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
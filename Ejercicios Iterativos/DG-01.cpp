// NOMBRE Y APELLIDOS
// Pablo Gamo Gonzalez

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


//Q{ 2 <= n <= 10^6 : 1 <= vec[i] <= 10^6}
//R{ x = (i: 1 <= i <= vec.size() : vec[i-1] < vec[i] < vec[i+1] || vec[i+1] < vec[i] < vec[i-1])}
//Coste: O(n) donde n = vector.size()
bool isDalton(const vector<int>& vector) {
    bool ok = true;
    int i = 1;
    
    while (i < vector.size()-1 && ok) {
        if (vector[i] < vector[i - 1] && vector[i] > vector[i + 1]) {
            ok = true;
        }
        else if (vector[i] > vector[i - 1] && vector[i] < vector[i + 1]) {
            ok = true;
        }else{
            ok = false;
        }
        i++;
    }

    return ok;
}


bool resuelveCaso() {
    int n;
    //Leer caso de prueba: cin>>...
    std::cin >> n;

    if (n <= 0)
        return false;

    vector<int> vec(n);
 
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i];
    }

    //Resolver problema
    bool res = isDalton(vec);
    //Escribir resultado
    if (res) {
        std::cout << "DALTON\n";
    }else {
        std::cout << "DESCONOCIDOS\n";
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
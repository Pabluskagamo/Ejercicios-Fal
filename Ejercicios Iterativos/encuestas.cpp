//NOMBRE y APELLIDOS
//Pablo Gamo Gonzalez

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Revisar especificacion.
//Q {0 < vec.size() < 1000 && forall i :vec[i] <= size(int)}
//R {sum: 0 < i < vec.size : vec[i] > min(vec)}
//C = vec.size -i
//I { 0 < i < vec.size() && sum: 0 < i < vec.size : vec[i] > min(vec) }
//Coste: O(n) donde n = vec.size()

long long int sumaValorAtipico(const vector<int>& vec, int &cont) {
    cont = 0;
    int min = vec[0];
    long long int sum = 0;
    int equalsMin = 1;

    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] < min) {
            sum += (equalsMin*min);
            cont += equalsMin;
            min = vec[i];
            equalsMin = 1;
        }else if (vec[i] == min) {
            equalsMin++;
        }else {
            sum += vec[i];
            cont++;
        }
    }

    return sum;
}

void resuelveCaso() {
 //resuelve aqui tu caso
    int n;
    //Lee los datos
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    //Calcula el resultado
    int cont;
    long long int res = sumaValorAtipico(vec, cont);
    //Escribe el resultado
    cout << res << " " << cont << "\n";
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
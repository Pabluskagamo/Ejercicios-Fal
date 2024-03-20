//NOMBRE y APELLIDOS
//Pablo Gamo González
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


//Q{ 0 < vec.size() <= 1000 && d > 0}
//R{ ok = forall i: 0 <= i < vec.size()-1 : porPelos(vec, i) && Diver(vec, i)}
//porPelos(vec, i) = vec[i] < vec[i+1] && vec[i+1] - vec[i] <= 1
//Diver(vec, i) = #vec[i] <= d //Revisar.
//I{  0 <= i < vec.size()-1 && dif = vec[i+1] - vec[i] && ok = porPelos(vec, i-1) && Diver(vec, i-1)}
//C = vec.size() - 1 - i;
//Coste: O(n) donde n = vec.size()-1

bool porlosPelosyDivertido(const vector<int>& vec, int d) {
    int i = 0;
    int dif = 0;
    int cont = 0;
    bool ok = true;

    while(i < vec.size()-1 && ok) {
        dif = vec[i + 1] - vec[i];
        cont = (dif == 0) ? (cont + 1) : (0);

        if (vec[i] > vec[i + 1] || dif > 1 || cont >= d) {
            ok = false;
        }
        i++;
    }

    return ok;
}

void resuelveCaso() {
 //resuelve aqui tu caso
    int n;
    int d;
    //Lee los datos
    cin >> d;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    //Calcula el resultado
    bool res = porlosPelosyDivertido(vec, d);
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
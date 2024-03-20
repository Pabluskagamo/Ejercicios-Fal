// NOMBRE Y APELLIDOS
//Pablo Gamo Gonzalez
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//Duda con la postcondicion y el invariante.
//Q{0 <= D < = 10^6 && 1 <= vec.size() <= 2*10^5 && forall i: 0 <= i < vec.size(): 0 < vec[i] < 10^6}
//R{ok = forall i: 0 <= i < vec.size() && vec[i] < vec[i+1]: vec[i+1]- min() //duda con el min}
//I{ok = forall j: 0 <= p < j < vec.size()-1 && vec[j] < vec[j+1]: vec[j+1] - vec[p] > D //duda con el min
//s = min i: 0 <= j < i && vec[i] < vec[i + 1]} //Revisar
//C = vec.size - i + 1
//Coste: O(n) donde n = vec.size();
bool excursionApta(const vector<int>& vec, int d){
    bool ok = true;
    int i = 0;
    int s = 0;

    while (i < vec.size()-1 && ok) {
        if (vec[i] < vec[i + 1]){
            if(vec[i + 1] - vec[s] > d){
                ok = false;
            }
        }else{
            s = i;
        }
        i++;
    }

    return ok;
}


bool resuelveCaso() {
    int n;
    int d;

    //Leer caso de prueba: cin>>...
    cin >> d >> n;
    if (!std::cin)
        return false;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    //Resolver problema
    bool res;
    res = excursionApta(vec, d);
    //Escribir resultado
    if (res) {
        cout << "APTA\n";
    }else {
        cout << "NO APTA\n";
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
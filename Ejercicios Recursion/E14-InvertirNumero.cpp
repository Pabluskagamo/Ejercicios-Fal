//NOMBRE Y APELLIDOS
//Pablo Gamo Gozález
#include <iostream>
#include <fstream>
using namespace std;


//Q{n: 0 < n <= sizeof(int) && ...} No puede empezar por 0 
//R{} Duda invariante.
//Coste: T(n): {k1 si n < 10, T(n/10) + k2 si n >= 10} coste O(log n) donde n es el número de dígitos de una cifra. Por el teorema de la division.
int invertirNum(int num, int& i) {
    int newNum = 0;

    if (num < 10) {
        i = i * 10;
        return num;
    }else {
        newNum = invertirNum(num / 10, i) + i * (num % 10);
        i = i * 10;
    }

    return newNum;
}

int invertirNum(int num) {
    int i = 1;
    return invertirNum(num,i);
}

bool resuelveCaso() {
    int num;
    //Leer caso de prueba: cin>>...
    cin >> num;
    
    if (num == 0)   
        return false;
    //Resolver problema
    int res = invertirNum(num);
    //Escribir resultado
    cout << res <<"\n";

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
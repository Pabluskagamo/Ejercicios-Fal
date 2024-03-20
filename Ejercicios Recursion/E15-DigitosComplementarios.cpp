//NOMBRE y APELLIDOS
//Pablo Gamo González
#include <iostream>
#include <fstream>
using namespace std;

//Q{forall n: 0 < n <= sizeof(int)}
//R{res } Duda poscondicion.
/*Analisis del coste:
    T(n){
        T(n) = c0 si n < 10
        T(n) = T(n/10) + c1 si n >= 10
    }
    El coste es del orden de O(log(n)) donde n es el numero de digitos por el teorema de la division.
*/
long long int invertirNum(long long int num, int pot) {
    long long int newNum = 0;

    if (num < 10 && pot ==1) {
        return num;
    }
    else if(num >= 10){
        newNum = pot * (num % 10) + invertirNum(num / 10, pot/10);
    }
    else {
        newNum = num * pot + invertirNum(num/10, pot / 10);
    }

    return newNum;
}

//Q{forall n: 0 <= n <= 1^9}
//compl(n) = {} duda sobre como represento las cifras
//R{r = compl(n)}.
/*Analisis del coste:
    T(n){
        T(n) = c0 si n < 10
        T(n) = T(n/10) + c1 si n >= 10
    }
    El coste es del orden de O(log(n)) donde n es el numero de digitos por el teorema de la division.
*/
long long int complementario(long long int num, int pot, int& cont) {
    long long int newNum = 0;

    if (num < 10) {
        cont = pot;
        return (9-num) * pot;
    }else {
        newNum =  complementario(num / 10, pot*10, cont) + pot * (9 - (num % 10));
    }

    return newNum;
}

long long int complementarioEInvertido(long long int num, long long int &inv) {
    int pot = 0;
    long long int res = complementario(num, 1, pot);
    inv = invertirNum(res, pot);
    return res;
}


void resuelveCaso() {
 //resuelve aqui tu caso
    long long int num;
    //Lee los datos
    cin >> num;
    //Calcula el resultado
    long long int inv;
    long long int res = complementarioEInvertido(num, inv);
    //Escribe el resultado
    cout << res << " " << inv << "\n";
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
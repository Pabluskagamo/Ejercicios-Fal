// NOMBRE Y APELLIDOS
//Pablo Gamo Gonzalez

#include <iostream>
#include <fstream>
using namespace std;

int numeroSinUnos(int n, int pot, int r, bool uno) {

    if (n < 10) { //Solo si es caso base
        if (n > 1) {
            int res = ((n - 1) * pot) + r;
            if (!uno && pot > 1) res++;
            return res;
        }
        else if(n == 1){
            return pot * 1;
        }
        else {
            return r+1;
        }
    }
    else {
        bool aux = uno;
        int resto = n % 10;
        int acum;
        if (resto > 1) {
            acum = ((resto - 1) * pot)+ r;
        }
        else if (resto == 0){
            acum = (1 * pot) + r;
        }
        else {
            acum = pot*1;
            aux = true;
        }
        
        return  numeroSinUnos(n / 10, pot * 9, acum, aux);
    }

}


int numerosSinUnos(int n) {
    return numeroSinUnos(n, 1, 0, false);
}

bool resuelveCaso() {
    int n;
    //Leer caso de prueba: cin>>...
    cin >> n;

    if (!std::cin)
        return false;
 
    
    //Resolver problema
    int res = numerosSinUnos(n);
    //Escribir resultado
    cout << res << "\n";

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
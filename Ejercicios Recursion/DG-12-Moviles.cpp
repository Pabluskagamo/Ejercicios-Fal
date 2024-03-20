//NOMBRE y APELLIDOS
//Pablo Gamo Gonzalez

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef struct {
    int pi,di, pd, dd;
}tMovil;

/*Analisis del coste:
    T(n){
        T(n) = c0 si n != 0
        T(n) = 2T(n-1) + c1 si n = 0
    }
    El coste es del orden de O(n) donde n es el número de móviles:
    Despliegue de recurrencias:

    1:T(n-1) + c1
    2:T(n-2) + c1 + c1
    3:T(n-3) + 2c1 + c1
    ..................
    n:T(0) + n*c1 = n * c1 + c0 luego el coste es del orden de O(n)  
*/

//Precondicion: (true)
//func bienMovil(tMovil, int peso) dev bool
//equilibrio(movil) = ((movil.pi * movil.di) = (movil.pd * movil.dd))
//Postcondicon: res = (equilibrio(movil) && ) 
bool bienMovil(tMovil movil, int& peso) {
    bool okIzq = true, okDer = true;

    if (movil.pi == 0) {
        tMovil aux;
        cin >> aux.pi >> aux.di >> aux.pd >> aux.dd;
        okIzq = bienMovil(aux, movil.pi);
    }
    if (movil.pd == 0) {
        tMovil aux;
        cin >> aux.pi >> aux.di >> aux.pd >> aux.dd;
        okDer = bienMovil(aux, movil.pd);
    }
    peso += (movil.pi + movil.pd);

    return okIzq && okDer && ((movil.pi * movil.di) == (movil.pd * movil.dd));
}


bool bienMovil(tMovil movil) {

    int peso = 0;
    return bienMovil(movil, peso);
}

void resuelveCaso() {

 //resuelve aqui tu caso
    //Lee los datos
    tMovil primerMov;
    cin >> primerMov.pi >> primerMov.di >> primerMov.pd >> primerMov.dd;
    //Calcula el resultado
    int res = bienMovil(primerMov);
    //Escribe el resultado
    if (res) {
        cout << "SI\n";
    }
    else {
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
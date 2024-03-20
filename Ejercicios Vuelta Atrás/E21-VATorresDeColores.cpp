// NOMBRE Y APELLIDOS
// Pablo Gamo González.

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void tratarSolucion(const vector<int>& sol) {
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i] == 1) {
            cout << "rojo ";
        }
        else if (sol[i] == 2) {
            cout << "azul ";
        }
        else if (sol[i] == 0) {
            cout << "verde ";
        }
    }
    cout << "\n";
}


bool esSolucion(int n, int k) {
    return k == n-1;
}

//1 -> azul, 0 -> roja, 2-> verde
bool esValida(int n, const vector<int>& vec, const vector<int>& sol, int k) {
    int i = 0;
    int r = 0; int a = 0; int v = 0;
    bool ok = false;
    
    if (sol[i] == 1) {
        ok = true;
        r++; i++;
        while (i < k+1 && ok) {
            if (sol[i] == 1) {
                r++;
            }
            else if (sol[i] == 2) {
                a++;
            }
            else if (sol[i] == 0) {
                v++;
                if (sol[i - 1] == 0) {
                    v++;
                    ok = false;
                }
            }
            if (vec[0] < a || vec[1] < r || vec[2] < v) {
                ok = false;
            }
            i++;
        }
    }

    return ok && (a >= v) && ((a + v) < (r + (n-(k+1))));
}

//Arbol de exploración: arbol de longitud 3^n

void construirTorre(int n, const vector<int>& vec, int k, vector<int>& sol, bool& ok) {

    for (int pieza = 2; pieza > -1; pieza--) {
        sol[k] = pieza;
        if (esValida(n, vec, sol, k)) {
            if (esSolucion(n, k)) {
                tratarSolucion(sol);
                ok = true;
            }
            else {
                construirTorre(n, vec, k + 1, sol, ok);
            }
        }
    }
}


void construirTorre(int n, const vector<int>& vec) {
    bool ok = false;
    vector<int> sol(n);
    construirTorre(n, vec, 0, sol, ok);
    if (!ok) {
        cout << "SIN SOLUCION\n";
    }
    cout << "\n";
}


bool resuelveCaso() {
    
    //Leer caso de prueba: cin>>...
    int n;
    vector<int> vec(3);

    cin >> n;
    for (int i = 0; i < vec.size(); i++) {
        cin >> vec[i];
    }

    if (n == 0) 
        return false;
 
    
    //Resolver problema
    construirTorre(n, vec);
 
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
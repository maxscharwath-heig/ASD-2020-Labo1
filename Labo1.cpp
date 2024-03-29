//
//  Labo1.cpp
//
//	Bard, Ganguillet, Scharwath
//

#include <cstdlib>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std::chrono;

using namespace std;

/**
 * 1. Recherche la position d'une valeur dans un vector.
 *
 * Pour la complexité, on considère le nombre d'itérations.
 * Tester pour diverses valeurs de val, présentes ou non dans le vector.
 *
 * @param v vector dans lequel on cherche
 * @param val valeur à chercher
 * @return la position de la valeur dans le vector si trouvé, -1 sinon
 */
size_t chercherPosition(const vector<int> &v, int val) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v.at(i) == val) {
            cout << i + 1;
            return i;
        }
    }
    cout << v.size();
    return -1;
}

/**
 * 2. Trie un vector.
 *
 * Pour la complexité, on considère le nombre de comparaisons (>)
 *
 * @param v vector à trier
 */

void trier(vector<int> &v) {
    unsigned long long compte = 0;

    if (v.empty()) {
        cout << compte;
        return;
    }

    for (int a : v) {
        auto j = v.begin();
        auto k = j++;
        for (; j != v.end(); k = j++) {
            ++compte;
            if (*k > *j)
                swap(*k, *j);
        }
    }

    cout << compte;
}

/**
 * 3. Retourne true si la valeur est contenue dans le vector.
 *
 * Pour la complexité, on considère le nombre d'itérations.
 * v doit être trié en entrée !
 * Tester pour diverses valeurs de val, présentes ou non dans le vecteur.
 *
 * @param v vector trié dans lequel on cherche
 * @param val valeur à chercher
 * Retourne true si la valeur est contenue dans le vector, false sinon.
 */
bool chercherSiContient(const vector<int> &v, int val) { //
    unsigned long long compte = 0;
    auto first = v.begin();
    auto last = v.end();

    while (first != last) {
        ++compte;
        auto mid = first + (last - first) / 2;
        if (*mid == val) {
            cout << compte;
            return true;
        } else if (*mid < val) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }

    cout << compte;
    return false;
}

/**
 * 4. Pour la complexité, on considère le nombre d'additions
 *
 * @param n
 * @return
 */
unsigned long long f(unsigned n) { 

    if (n == 0) return 1;

    return f(n - 1) + f(n - 1) + f(n - 1);
}

/**
 * 5. Pour la complexité, on considère le nombre d'additions (+=)
 *
 * @param v
 */
void g(vector<int> &v) { 
    int nb_addition = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = v.size() - 1; j > 0; j /= 2) {
            v.at(i) += v.at(j);
            ++nb_addition;
        }
    }
    cout << nb_addition << endl;
}

/**
 * 6. Pour la complexité, on considère les opérations push_back()
 *
 * Evaluer le temps d'exécution
 *
 * @param N nombre de données à générer
 * @param maxVal valeur maximale des données
 * @return vector rempli de N valeurs aléatoires.
 */
vector<int> random(size_t N, int maxVal) { 

    vector<int> v;
    for (size_t i = 0; i < N; ++i) {
        v.push_back(1 + rand() % maxVal);
    }

    return v;
}

/**
 * 7. Pour la complexité, on considère les opérations insert()
 *
 * Evaluer le temps d'exécution
 *
 * @param N nombre de données à générer
 * @param maxVal valeur maximale des données
 * @return vector rempli de N valeurs aléatoires.
 */
vector<int> random2(size_t N, int maxVal) { 

    vector<int> v;
    for (size_t i = 0; i < N; ++i) {
        v.insert(v.begin(), 1 + rand() % maxVal);
    }

    return v;
}

int main() {
    //initialisation du générateur aléatoire
    srand(time(NULL));
    high_resolution_clock::time_point t1, t2;

    //========= FONCTION chercherPosition() =========

    cout << "Fonction chercherPosition() :" << endl;
    for (int i = 4; i < 10; ++i) {
        int taille = round(pow(3,i));
        vector<int> v = random(taille, taille);
        cout << "vecteur taille " << taille << " : ";
        for(int j = 0; j < 18; ++j) {
            int valeurAChercher = (rand() % taille);
            chercherPosition(v, valeurAChercher);
            cout << "  ";
        }
        cout << endl;
    }

    //========= FONCTION TRIER() =========
    cout << "Fonction trier() :" << endl;
    for (int i = 6; i < 12; ++i) {
        int taille = round(pow(2, i));
        vector<int> v(taille);
        generate(v.begin(), v.end(), rand);
        cout << "trier(" << taille << ") ";
        trier(v);
        cout << endl;
    }

    //========= FONCTION chercherSiContient() =========
    cout << "Fonction chercherSiContient() :" << endl;
    for (int i = 6; i < 12; ++i) {
        int val = rand();
        int taille = round(pow(2, i));
        vector<int> v(taille);
        generate(v.begin(), v.end(), rand);
        sort(v.begin(),v.end());
        cout << "chercherSiContient(" << taille << ") : ";
        chercherSiContient(v,val);
        cout << endl;
    }


    //========= FONCTION f() =========

    cout << "Fonction f() :" << endl;
    for (int i = 11; i < 19; ++i) {
        cout << "f(" << i << ") = ";
        cout << f(i) << endl;
    }

    //========= FONCTION g() =========

    cout << "Fonction g() :" << endl;

    for (int i = 8; i < 14; ++i) {
        int taille = round(pow(3,i));
        vector<int> v(taille);
        cout << "g(v), vecteur de taille " << taille << " : ";
        g(v);
    }

    //========= FONCTION random() =========

    cout << "Fonction random() :" << endl;
    for (int i = 10; i < 17; ++i) {

        int n = round(pow(3,i));
        int v_max = rand();
        cout << "random(" << n << ") : ";
        for(int j = 0; j<5;++j) {
            t1 = high_resolution_clock::now();
            random(n, v_max);
            t2 = high_resolution_clock::now();
            cout << duration_cast<nanoseconds>(t2 - t1).count() << " ns" << "   ";
        }
        cout << endl;
    }

    //========= FONCTION random2() =========

    int n = 0;

    cout << "Fonction random2() :" << endl;
    for (int i = 1; i < 7; ++i) {

        n += 5000*i;
        int v_max = rand();
        cout << "random2(" << n << ") : ";
        for(int j = 0; j<5;++j){
            t1 = high_resolution_clock::now();
            random2(n, v_max);
            t2 = high_resolution_clock::now();
            cout << duration_cast<nanoseconds>(t2 - t1).count() << " ns" << "  ";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

//
//  Labo1.cpp
//
//	/* NOMS DES ETUDIANTS ICI */
//

#include <cstdlib>
#include <vector>
#include <random>
#include <ctime>
#include <chrono>
#include <iostream>
#include <algorithm>

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
        if (v.at(i) == val)
            return i;
    }
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
    if (v.empty()) return;

    for (int a : v) {
        auto j = v.begin();
        auto k = j++;
        for (; j != v.end(); k = j++)
            if (*k > *j)
                swap(*k, *j);
    }
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
    auto first = v.begin();
    auto last = v.end();

    while (first != last) {
        auto mid = first + (last - first) / 2;
        if (*mid == val) {
            return true;
        } else if (*mid < val) {
            first = mid + 1;
        } else {
            last = mid;
        }
    }
    return false;
}

/**
 * 4. Pour la complexité, on considère le nombre d'additions
 *
 * @param n
 * @return
 */
unsigned long long f(unsigned n) { //n+1 => t*3

    if (n == 0) return 1;

    return f(n - 1) + f(n - 1) + f(n - 1);
}

/**
 * 5. Pour la complexité, on considère le nombre d'additions (+=)
 *
 * @param v
 */
void g(vector<int> &v) { //~n
    for (size_t i = 0; i < v.size(); ++i) {//n
        for (size_t j = v.size() - 1; j > 0; j /= 2) {//logn
            v.at(i) += v.at(j);
        }
    }
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
vector<int> random(size_t N, int maxVal) { //n

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
vector<int> random2(size_t N, int maxVal) { //n²

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



    //========= FONCTION TRIER() =========
    cout << "Fonction trier() :" << endl;
    for (int i = 0; i < 5; ++i) {
        int j = round(pow(10, i));
        vector<int> v(j);
        generate(v.begin(), v.end(), rand);
        t1 = high_resolution_clock::now();
        trier(v);
        t2 = high_resolution_clock::now();
        //calcul du temps, ici en nanosecondes
        cout << j << ": " << duration_cast<nanoseconds>(t2 - t1).count() << " ns" <<
             endl;
    }

    //========= FONCTION F() =========

    cout << "Fonction f() :" << endl;
    for (int i = 11; i < 20; ++i) {
        cout << "f(" << i << ") : ";
        t1 = high_resolution_clock::now();
        f(i);
        t2 = high_resolution_clock::now();
        //calcul du temps, ici en nanosecondes
        cout << duration_cast<nanoseconds>(t2 - t1).count() << " ns" << endl;
    }

    return EXIT_SUCCESS;
}

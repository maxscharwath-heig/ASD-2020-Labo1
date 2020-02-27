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
void trier(vector<int> &v) { //n^2
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

    //========= FONCTION chercherPosition() =========

    cout << "Fonction chercherPosition() :" << endl;

    vector<size_t> tailles {10, 100, 1000, 10000};

    size_t tailleMax = *max_element(tailles.begin(), tailles.end());
    vector<int> v(tailleMax);
    auto begin = v.begin();
    generate(begin, v.end(), rand);

    vector<vector<int>> valeurs(tailles.size());
    for (size_t i = 0; i < tailles.size(); ++i) {
        valeurs[i] = vector(begin, begin + tailles[i]);
    }

    int valeurAChercher;
    if (rand() % 2) {
        auto begin = tailles.begin();
        auto taille_min = min_element(begin, tailles.end());
        auto valeursMin = valeurs.begin() + (taille_min - begin);
        valeurAChercher = (*valeursMin)[valeurAChercher];
    } else {
        valeurAChercher = rand();
    }

    for (int i = 0; i < tailles.size(); ++i) {
        cout << "chercherPosition(" << tailles[i] << ") : " << chercherPosition(valeurs[i], valeurAChercher) << endl;
    }

    //========= FONCTION TRIER() =========
    cout << "Fonction trier() :" << endl;
    for (int i = 7; i < 12; ++i) {
        int j = round(pow(2, i));
        vector<int> v(j);
        generate(v.begin(), v.end(), rand);
        t1 = high_resolution_clock::now();
        trier(v);
        t2 = high_resolution_clock::now();
        //calcul du temps, ici en nanosecondes
        cout << j << ": " << duration_cast<nanoseconds>(t2 - t1).count() << " ns" << endl;
    }

    //========= FONCTION chercherSiContient() =========
    cout << "Fonction chercherSiContient() :" << endl;
    for (int i = 7; i < 12; ++i) {
        int val = rand();
        int j = round(pow(2, i));
        vector<int> v(j);
        generate(v.begin(), v.end(), rand);
        sort(v.begin(),v.end());
        t1 = high_resolution_clock::now();
        chercherSiContient(v,val);
        t2 = high_resolution_clock::now();
        //calcul du temps, ici en nanosecondes
        cout << j << ": " << duration_cast<nanoseconds>(t2 - t1).count() << " ns" << endl;
    }


    //========= FONCTION f() =========

    cout << "Fonction f() :" << endl;
    for (int i = 11; i < 19; ++i) {
        cout << "f(" << i << ") : ";
        t1 = high_resolution_clock::now();
        f(i);
        t2 = high_resolution_clock::now();
        //calcul du temps, ici en nanosecondes
        cout << duration_cast<nanoseconds>(t2 - t1).count() << " ns" << endl;
    }

    //========= FONCTION g() =========

    cout << "Fonction g() :" << endl;
    for (int i = 4; i < 8; ++i) {
        int taille = round(pow(10,i));
        vector<int> v(taille);
        cout << "g(v), vecteur de taille " << taille << " : ";
        t1 = high_resolution_clock::now();
        g(v);
        t2 = high_resolution_clock::now();
        //calcul du temps, ici en nanosecondes
        cout << duration_cast<nanoseconds>(t2 - t1).count() << " ns" << endl;
    }

    //========= FONCTION random() =========

    cout << "Fonction random() :" << endl;
    for (int i = 4; i < 8; ++i) {

        int n = round(pow(10,i));
        int v_max = rand();
        cout << "random(" << n << ") : ";
        t1 = high_resolution_clock::now();
        random(n, v_max);
        t2 = high_resolution_clock::now();
        //calcul du temps, ici en nanosecondes
        cout << duration_cast<nanoseconds>(t2 - t1).count() << " ns" << endl;
    }

    //========= FONCTION random2() =========

    cout << "Fonction random2() :" << endl;
    for (int i = 6; i < 11; ++i) {

        int n = round(pow(3,i));
        int v_max = rand();
        cout << "random2(" << n << ") : ";
        t1 = high_resolution_clock::now();
        random2(n, v_max);
        t2 = high_resolution_clock::now();
        //calcul du temps, ici en nanosecondes
        cout << duration_cast<nanoseconds>(t2 - t1).count() << " ns" << endl;
    }


    return EXIT_SUCCESS;
}

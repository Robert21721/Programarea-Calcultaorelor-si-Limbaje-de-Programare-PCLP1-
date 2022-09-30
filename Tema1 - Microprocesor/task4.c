#include<stdio.h>

int grupuri_dim_biti(unsigned short nr, unsigned int Dim, int k) {
    return (nr >> (16 - Dim * k));
    /*
    functia imi returneaza (la primul apel pt k=1) primii Dim biti din numar.
     Dupa prima utilizare a functiei se sterg primii Dim biti (in main) 
     iar k creste cu o unitate permitand astfel afisarea urmatorilor Dim biti
    */
}

int main() {
    unsigned int x, N, mask, simbol, Dim;
    int operatori[8] = {0}, k = 0;

    scanf("%u", &x);

    // Retin in N numarul format cu primii 3 biti si adun 1
    N = (x >> 29) + 1;

    for (int i = 1; i <= N; i++) {
    /*
    Folosesc o masca si operatia de siftare pentru a 
    determina valoarea urmatorilor biti in perechi de cate 2 
    dupa care folosesc un switch pentru a inlocui valorile
    grupelor de 2 biti cu simbolul corespunzator
    */

        mask = 3 << (29 - 2 * i);   // 29=31-3+1
        simbol = (mask & x) >> (29 - 2 * i);

        switch (simbol) {
            case 0:
                operatori[k] = 0;
                break;

            case 1:
                operatori[k] = 1;
                break;

            case 2:
                operatori[k] = 2;
                break;

            case 3:
                operatori[k] = 3;
                break;
            }

        k++;
    }

    /*
    25 = 31 - 3 - 3 
    (primul 3 de la nr de biti ai lui N 
    si al doilea de la 15 = 1111 in baza 2 care trebuie 
    siftat de 4-1 ori mai putin pentru copie ajunge sub bitii
    lui Dim si pentru copie putea face operatia &)
    */
    // 2*N este numarul de biti corespunzator operatorilor + - * /
    mask = 15 << (25-2*N);
    Dim = ((x&mask) >> (25-2*N)) + 1;
    /*
    aici incepe task2

    !!!! 
    A se observa ca am retinut numerele corespunzatoare
    caracterelor + - * / intr-un vector numit operatori
    !!!!
    */

    int n;
    int nr_operanti = k;
    unsigned short nr;
    unsigned short numere[16];
    int j = 0;

    if (((N + 1) * Dim) % 16 == 0) {
        n = ((N + 1) * Dim) / 16;
    } else {
        n = ((N + 1) * Dim) / 16 + 1;   // retin in n cate numere voi introduce
    }

    unsigned short copie;
            // citesc cele n numere, le inpart in grupuri de cate Dim biti
            // si retin valorile in vectorul numere
    for (int i = 1; i <= n; i++) {
            scanf("%hu", &nr);
            k = 1;

            int nr_executii = 16;

            while (nr_executii) {
                numere[j] = grupuri_dim_biti(nr, Dim, k);
                nr = nr << Dim*k;
                nr = nr >> Dim*k;
                j++;
                k++;

                nr_executii = nr_executii - Dim;
            }
        }

//!!! aici incepe task 4 !!!

    int calcul[20], i;
    calcul[0] = numere[0];

    // retin in vectorul calcul numerele si operatorii
    for (i = 1 ; i <= 2 * nr_operanti; i += 2) {
        calcul[i] = operatori[i / 2];
        calcul[i + 1] = numere[i / 2 + 1];
    }

    i = 0;
    int ok = 0;  // daca ok = 0 fac operatiile de * si /
                 // daca ok = 1 fac + si -

    while (i <= 2 * nr_operanti) {
        if ((ok == 0) && (i % 2 == 1)) {    // daca i este operator principal
            if (calcul[i] == 2) {   // daca este *
            // fac inmultirea si retin rezultatul pe pozitia i-1
                calcul[i - 1] = calcul[i - 1] * calcul[i + 1];

            // sterg urmatoarele 2 elemente din vector
                for (int j = i; j < 2 * (nr_operanti - 1); j += 2) {
                    calcul[j] = calcul[j+2];
                    calcul[j+1]= calcul[j+3];
                }
    // scad numarul de elemente cu 2 (nr de elemente initial e 2 * nr_operanti + 1)
                nr_operanti--;
                i = 0;    // reiau algoritmul


            } else if (calcul[i] == 3) {  // daca este / repet algoritmul
                calcul[i - 1] = calcul[i - 1] / calcul[i + 1];

                for (int j = i; j <= 2 * (nr_operanti - 1); j += 2) {
                    calcul[j] = calcul[j + 2];
                    calcul[j + 1] = calcul[j + 3];
                }

                nr_operanti--;
                i = 0;

            } else {  // daca nu este nici * nici / incrementez
                i++;
            }
        }
                // daca in vectorul calcul nu mai sunt * sau /
            if (i == 2 * nr_operanti) {
                ok = 1;  // incep sa rezolv operatiile de + si -
                i = 0;  // resetez i la 0
        }

            if (ok &&  (i % 2 == 1)) {  // daca am terminat * si /

                if (calcul[i] == 0) {  // calculez adunarea
                    calcul[i - 1] = calcul[i - 1] + calcul[i + 1];

                    for (int j = i; j < 2 * nr_operanti; j += 2) {
                        calcul[j] = calcul[j + 2];
                        calcul[j + 1]= calcul[j + 3];
                    }

                    nr_operanti--;
                    i = 0;
                }

                if (calcul[i] == 1) {  // calculez scaderea
                    calcul[i - 1] = calcul[i - 1] - calcul[i + 1];

                    for (int j = i; j < 2 * nr_operanti; j += 2) {
                        calcul[j] = calcul[j+2];
                        calcul[j+1]= calcul[j+3];
                    }

                    nr_operanti--;
                    i = 0;
                }

        } else {  // daca nu este + sau - (adica e un operant) incrementez i
            i++;
            }
    }

    // la final rezultatul va fi pe pozitia 0 in vectorul calcul
    printf("%d\n", calcul[0]);
    return 0;
}

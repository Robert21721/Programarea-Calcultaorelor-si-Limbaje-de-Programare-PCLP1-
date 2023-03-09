#include <stdio.h>

unsigned int create_mask(int Dim) {
    unsigned int nr = 0;

    for (int i = 0; i < Dim; i++) {
        nr = nr << 1;
        nr++;
    }

    return nr;
}


int main() {
    unsigned int x, N, mask, simbol, Dim;
    int operatori[8] = {0}, k = 0;

    scanf("%u", &x);

    // Retin in N numarul format cu primii 3 biti si adun 1
    N = (x>>29) + 1;

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
    siftat de 4-1 ori mai putin pentru a ajunge sub bitii
    lui Dim si pentru copie putea face operatia &)
*/

    // 2 * N este numarul de biti corespunzator operatorilor + - * /
    mask = 15 << (25 - 2 * N);
    Dim = ((x & mask) >> (25 - 2 * N)) + 1;

/*
    aici incepe task2

    !!!! 
    A se observa ca am retinut numerele corespunzatoare
    caracterelor + - * / intr-un vector numit operatori
    !!!!
*/

    int n;
    int nr_operatori = k;
    unsigned short nr;
    unsigned short numere[16];
    int j = 0;

    // int a = create_mask(Dim);

    if (((N + 1) * Dim) % 16 == 0) {
        n = ((N + 1) * Dim) / 16;

    } else {
        n = ((N + 1) * Dim) / 16 + 1;   // retin in n cate numere voi introduce
    }

    unsigned short copie;

        // citesc cele n numere, le inpart in grupuri de cate 4 biti
        // si retin valorile in vectorul numere
    unsigned int nr_mare = 0;
    int nr_executii = 0;

    for (int i = 0; i < n; i++) {
        scanf("%hu", &nr);

        nr_mare = nr_mare << 16;
        nr_mare = nr_mare + nr;
        nr_executii += 16;

        while (nr_executii >= Dim) {
            unsigned int mask = create_mask(Dim);
            mask = mask << nr_executii - Dim;
            mask = mask & nr_mare;
            mask = mask >> (nr_executii - Dim);

            numere[j++] = mask;

            nr_executii = nr_executii - Dim;
        }
  }

    // calculez rezultatul final
    int rezultat = numere[0];

    for (int i = 0; i < nr_operatori; i++) {
        switch (operatori[i]) {
            case 0:
                rezultat = rezultat + numere[i + 1];
                break;

            case 1:
                rezultat = rezultat - numere[i + 1];
                break;

            case 2:
                rezultat = rezultat * numere[i + 1];
                break;

            case 3:
                rezultat = rezultat / numere[i + 1];
                break;
       }
    }

    printf("%d\n", rezultat);
    return 0;
}

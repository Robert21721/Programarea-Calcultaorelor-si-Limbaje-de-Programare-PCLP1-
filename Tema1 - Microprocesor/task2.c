#include <stdio.h>

int grupuri_dim_biti(unsigned short nr, unsigned int Dim, int k) {
    return (nr >> (16 - Dim*k));
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
            k++;
            break;

        case 1:
            operatori[k] = 1;
            k++;
            break;

        case 2:
            operatori[k] = 2;
            k++;
            break;

        case 3:
            operatori[k] = 3;
            k++;
            break;
        }
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
    int nr_operanti = k - 1;
    unsigned short nr;
    unsigned short numere[16];
    int j = 0;

    if (((N + 1) * Dim) % 16 == 0) {
        n = ((N + 1) * Dim) / 16;

    } else {
        n = ((N + 1) * Dim) / 16 + 1;   // retin in n cate numere voi introduce
    }

    unsigned short copie;

        // citesc cele n numere, le inpart in grupuri de cate 4 biti
        // si retin valorile in vectorul numere
    for (int i = 1; i <= n; i++) {
        scanf("%hu", &nr);
        k = 1;

        int nr_executii = 16;

        while (nr_executii) {
            numere[j] = grupuri_dim_biti(nr, Dim, k);
        // sterg bitii mai semnificativi
            nr = nr << Dim * k;
            nr = nr >> Dim * k;
            j++;
            k++;

            nr_executii = nr_executii - Dim;
        }
  }

    // calculez rezultatul final
    int rezultat = numere[0];

    for (int i = 0; i <= nr_operanti; i++) {
        switch (operatori[i]) {
            case 0:
                rezultat = rezultat + numere[i+1];
                break;

            case 1:
                rezultat = rezultat - numere[i+1];
                break;

            case 2:
                rezultat = rezultat * numere[i+1];
                break;

            case 3:
                rezultat = rezultat / numere[i+1];
                break;
       }
    }

    printf("%d\n", rezultat);
    return 0;
}

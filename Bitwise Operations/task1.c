#include<stdio.h>

int main() {
    unsigned int x, N, mask, simbol, Dim;

    scanf("%u", &x);

    // Retin in N numarul format cu primii 3 biti si adun 1
    N = (x>>29) + 1;
    printf("%u ", N);

    for (int i = 1; i <= N; i++) {
/*
Folosesc o masca si operatia de siftare pentru a
determina valoarea urmatorilor biti in perechi de cate 2
dupa care folosesc un switch pentru a inlocui valorile
grupelor de 2 biti cu simbolul corespunzator
*/

    mask = 3 << (29 - 2 * i);
    simbol = (mask & x) >> (29 - 2 * i);

    switch (simbol) {
        case 0:
            printf("+ ");
            break;
        case 1:
            printf("- ");
            break;
        case 2:
            printf("* ");
            break;
        case 3:
            printf("/ ");
            break;
        default:
            break;
    }
}

/*
25=31-3-3 
(primul 3 de la nr de biti ai lui N 
si al doilea de la 15 = 1111 in baza 2 care trebuie 
siftat de 4-1 ori mai putin pentru a ajunge sub bitii
 lui Dim si pentru a putea face operatia &)
*/

    // 2 * N este numarul de biti corespunzator operatorilor + - * /
    mask = 15 << (25 - 2 * N);
    Dim = ((x & mask) >> (25 - 2 * N)) + 1;
    printf("%u\n", Dim);

    return 0;
}

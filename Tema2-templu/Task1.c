#include "utils.h"
# define X 100
# define Y 10

char *a(char instructiune[]) {
     // compar codurile ascii ale caracterelor numerice si retin indicele maxim
    int mx = 0, indice = 0;

    for (int i = 1; i <= 4; i++) {
        if (instructiune[i] > mx) {
            mx = instructiune[i];
            indice = i;
        }
    }

    if (indice == 1)
    // in functie de indicele gasit returnez directia de deplasare
        return "dreapta";

    if (indice == 2)
        return "sus";

    if (indice == 3)
        return "stanga";

    if (indice == 4)
        return "jos";
}



int palindrom(int k) {
    // verific daca numarul este palindrom
    int copie = k, invers = 0;

    while (copie) {
        invers = invers * Y + copie % Y;     // Y == 10
        copie = copie / Y;
    }

    if (k == invers)
    return 1;
    return 0;
}


int prim(int x) {
    // verific daca numarul este prim
    if (x % 2 == 0)
    return 0;

    for (int i = 3; i <= (int) sqrt(x); i += 2) {
        if (x % i == 0)
        return 0;
    }

    return 1;
}


char *b(char instructiune[]) {
    strcpy(instructiune, instructiune + 1);
    // sterg prima litera din cuvant (b)
    int k = atoi(instructiune);
    // retin in k valoarea numarica a sirului de cifre ramas
    int x = k % X;
    // retin in k numarul format cu ultimele 2 cifre
    // X==100

    // dupa caz, returnez directia de deplasare
    if (palindrom(k) == 1 && prim(x) == 1)
    return "stanga";

    if (palindrom(k) ==1  && prim(x) == 0)
    return "dreapta";

    if (palindrom(k) == 0 && prim(x) == 1)
    return "sus";

    if (palindrom(k) == 0 && prim(x) == 0)
    return "jos";
}


char *c(char instructiune[]) {
    int s = 0, j = 0, nr = 0;

    strcpy(instructiune, instructiune + 1);
    // sterg prima litera din cuvant (c)
    // retin in n valoarea numerica a caracterului de pe prima pozitie
    // acelasi lucru fac si cu k
    int k = instructiune[1] - '0';
    int n = instructiune[0] - '0';

    strcpy(instructiune, instructiune + 2);
    // sterg n si k din cuvant

    nr = k;
    while (nr) {
        // calculez suma din k in k elemente
        s = s + instructiune[k * j % n] - '0';
        nr--;
        j++;
    }

    if (s % 4 == 0)      // returnez directia dupa caz
        return "stanga";

    if (s % 4 == 1)
        return "sus";

    if (s % 4 == 2)
        return "dreapta";

    if (s % 4 == 3)
        return "jos";
}


void SolveTask1() {
    int m = 0, n = 0, harta[X][X] = {1}, nr = 0 , current_i = 0, current_j = 0;

    char *p = NULL, comenzi_citite[2 * X];
    char vector_comenzi[X][X], separatori[] = " ";
    char comanda[X];

    scanf("%d%d\n", &n, &m);
    // citesc n si m (si \n pentru a permite citirea mai departe cu fgets)


    fgets(comenzi_citite, sizeof(comenzi_citite), stdin);
    // citesc comenzile

    // impart comenzile si le retin intr-un vector
        p = strtok(comenzi_citite, separatori);

        while (p != NULL) {
            strcpy(vector_comenzi[nr++], p);
            p = strtok(NULL, separatori);
        }

    for (int i = 0; i < nr; i++) {
        switch (vector_comenzi[i][0]) {
    // parcurg vectorul de comenzi si in functie de prima litera
    // apelez functia corespunzatoare
            case 'a':
                strcpy(comanda, a(vector_comenzi[i]));
                break;

            case 'b':
                strcpy(comanda, b(vector_comenzi[i]));
                break;

            case 'c':
                strcpy(comanda, c(vector_comenzi[i]));
                break;
        // retin comanda returnata in variabila comanda
        }


    // in functie de comanda primita fac deplasarea pe harta
            if (strcmp(comanda, "sus") == 0) {
                current_i--;
                harta[current_i][current_j] = i+2;
            }

            if (strcmp(comanda, "jos") == 0) {
                current_i++;
                harta[current_i][current_j] = i+2;
            }

            if (strcmp(comanda, "stanga") == 0) {
                current_j--;
                harta[current_i][current_j] = i+2;
            }

            if (strcmp(comanda, "dreapta") == 0) {
                current_j++;
                harta[current_i][current_j] = i+2;
            }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        printf("%d ", harta[i][j]);

        printf("\n");
    }
}

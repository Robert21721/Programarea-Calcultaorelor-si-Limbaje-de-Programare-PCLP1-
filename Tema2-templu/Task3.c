#include "utils.h"

#define Y 10000
#define X 1000
#define Z 100
#define T 10

// functia primeste un int si un char si
// converteste numarul intreg in sir de caractere

char* int_to_string(int nr, char cuvant[]) {
    int copie = nr, k = 0;

    while (copie) {
        k++;
        // numar cate cifre are numarul
        copie = copie/T;
    }

    for (int i = k - 1; i >= 0; i--) {
    // construiesc sirul caracter cu caracter facand cast
        cuvant[i] = (char)(nr % T + '0');     // T==10
        nr = nr / T;
    }

    return cuvant;
}


void SolveTask3() {
    char paragraf[X], propozitie[Y] = "", *p = NULL, separatori[] = " ,.!;\n";
    char cuvinte[X][Z], grupuri_cuvinte[X][Z];
    int n = 0;

    scanf("\n");

    while (fgets(paragraf, sizeof(propozitie), stdin)) {
        strcat(propozitie, paragraf);
// citesc textul paragraf cu paragraf si il concatenez in propozitie
    }


    p = strtok(propozitie, separatori);

    while (p != NULL) {
        // impart textul intr-un vector de cuvinte
        strcpy(cuvinte[n++], p);
        p = strtok(NULL, separatori);
    }


     for (int i = 0; i < n-1; i++) {
        strcpy(grupuri_cuvinte[i], cuvinte[i]);
        strncat(grupuri_cuvinte[i], " ", 1);
        strcat(grupuri_cuvinte[i], cuvinte[i+1]);
        // grupez cuvintele cate 2 cu spatiu intre ele
     }


    for (int i = 0; i < n-1; i++) {
        int nr_aparitii = 1;

        for (int j = i+1; j < n-1;  j++) {
            if (strcmp(grupuri_cuvinte[i], grupuri_cuvinte[j]) == 0) {
                nr_aparitii++;
    // daca gasesc 2 grupuri de cuvinte la fel cresc nr de aparitii

                for (int k = j; k < n-2; k++) {
                    strcpy(grupuri_cuvinte[k], grupuri_cuvinte[k+1]);
                    // sterg grupul de cuvinte din vector
                    }

                n--;
                // decrementez numarul de grupuri de cuvinte
                }
            }

        char ch_nr_aparitii[T] = "";
        strcat(grupuri_cuvinte[i], " ");
        strcat(grupuri_cuvinte[i], int_to_string(nr_aparitii, ch_nr_aparitii));
    // adaug la finalul grupurilor de cuvinte numarul de apapritii
    }

    printf("%d\n", n-1);

    for (int i = 0; i < n - 1; i++) {
        printf("%s\n", grupuri_cuvinte[i]);
    }
}

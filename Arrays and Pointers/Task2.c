#include "utils.h"
#define X 1001
#define Y 10

char letter(int k, char cod[], int j) {
// aceasta functie primeste o litera dintr-un cuvant si o roteste de k ori
for (int i = 0; i < k; i++) {
     if (cod[j] != 'a' && cod[j] != 'A' && cod[j] != '0') {
            cod[j] = (char) (cod[j] - 1);

            } else if (cod[j] == 'a') {
                        cod[j] = 'z';
            } else if (cod[j] == 'A') {
                        cod[j] = 'Z';
            } else if (cod[j] == '0') {
                        cod[j] = '9';
            }
        }

    return cod[j];
}


char* caesar(int k, char cod[]) {
// parcurge pe rand fiecare litera din cuvant si o roteste
// de k ori cu ajutorul functiei letter
    int lungime_cod = (int)strlen(cod);

            for (int i = 0; i < lungime_cod; i++)
                cod[i] = letter(k, cod, i);

    return cod;
}


char* vigenere(char k[], char cod[]) {
    int lungime_cheie = (int) strlen(k);
    int lungime_cod = (int) strlen(cod);

    for (int i = 0; i < lungime_cod; i++) {
        int rotiri = k[i % lungime_cheie] - 'A';
        // retin numarul de rotiri in variabila rotiri
        // i%lungime_cheie asigura ciclicitatea cheii

        cod[i] = letter(rotiri, cod, i);
        // folosesc functia letter pentru a roti fiecare litera de "rotiri" ori
        }

    return cod;
}


char* addition(char nr1[], char nr2[]) {
    int l1 = 0, l2 = 0;
    int cifra1 = 0, cifra2 = 0;
    int ok = 0;


    if (strlen(nr1) < strlen(nr2)) {
        // ma asigur ca sirul mai lung de caractere
        // este in nr1 pentru simplificare

        char aux[X];

        strcpy(aux, nr1);
        strcpy(nr1, nr2);
        strcpy(nr2, aux);
    }

    l1 = (int)strlen(nr1);
    l2 = (int)strlen(nr2);

    for (int i = 0 ; i < l1 - l2; i++) {
    // completez numarul mai scurt cu zerouri in fata (daca exista)

        char zero[X] = "0";

        strcat(zero, nr2);
        strcpy(nr2, zero);
    }


    for (int i = l1 - 1; i >= 0 ; i--) {
    // fac adunarea caracter cu caracter si retin restul
    // (care poate fi 1 sau 0) in ok
        cifra1 = nr1[i] - '0';
        cifra2 = nr2[i] - '0';

        int s = cifra1 + cifra2 + ok;

        // Y ==10
        if (s >= Y) {
            nr1[i] = (char)( s % Y + '0');
            ok = 1;
            } else {
                nr1[i] = (char)(s + '0');
                ok = 0;
                }
    }

    if (ok == 1) {
        // daca la finalul parcurgerii ok ==1 atunci
        // adaug 1 in fata rezultatului prin concatenare
        char rezultat[X] = "1";
        strcat(rezultat, nr1);
        strcpy(nr1, rezultat);
        }

    return nr1;
}


void SolveTask2() {
    char mod_criptare[Y], cod[X];
    char nr1[X], nr2[X];

    scanf("%s", mod_criptare);
    // citesc modul de criptare

    if (strcmp(mod_criptare, "caesar") == 0) {
    // daca modul de criptare este caesar atunci
    // citesc cheia si codul si apelez functia
        int k = 0;

            scanf("%d", &k);
            scanf("%s", cod);
            printf("%s\n", caesar(k, cod));
    }

    if (strcmp(mod_criptare, "vigenere") == 0) {
    // la fel si pentru vigenere (doar ca aici si cheia este de tip char)
        char k[Y];

            scanf("%s", k);
            scanf("%s", cod);
            printf("%s\n", vigenere(k, cod));
    }


    if (strcmp(mod_criptare, "addition") == 0) {
    // daca modul de criptare este addition atunci citesc cheia si cele 2 numere
        int k = 0;

        scanf("%d", &k);
        scanf("%s", nr1);
        scanf("%s", nr2);

        // aplic caesar numerelor pentru a le decodifica
        strcpy(nr1, caesar(k, nr1));
        strcpy(nr2, caesar(k, nr2));

        // sterg zerourile din fata numerelor (daca exista)
        while (nr1[0] == '0') {
            strcpy(nr1, nr1 + 1);
        }

        while (nr2[0] == '0') {
            strcpy(nr2, nr2 + 1);
        }

        // apelez functia addition si afisez rezultatul
        printf("%s\n", addition(nr1, nr2));
    }
}

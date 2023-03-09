#include"function_headers.h"
#define THREE 3
#define FOUR 4

bmp_bitmap **matrix(FILE* f_in, bmp_infoheader *ih) {
    // aloc memorie pentru matrica de biti
    bmp_bitmap **matrix = (bmp_bitmap**)calloc(ih->height, sizeof(bmp_bitmap*));
    if (matrix == NULL) {
        printf("Nu a putut fi alocata memoria\n");
        exit(-1);
    }
    // aloc memorie pentru liniile matricei de biti
    for (int i = 0; i < ih->height; i++) {
        matrix[i] = (bmp_bitmap*)calloc(ih->width, sizeof(bmp_bitmap));
        if (matrix[i] == NULL) {
            printf("Nu a putut fi alocata memoria\n");
            exit(-1);
        }
    }
    // completez matricea de biti
    for (int i = 0; i < ih->height; i++) {
        fread(matrix[i], sizeof(bmp_bitmap), ih->width, f_in);
            // pentru padding
        if (ih->width % FOUR != 0) {
            fseek(f_in, FOUR - ((ih->width * THREE) % FOUR), SEEK_CUR);
        }
    }

    fclose(f_in);   // inchid fisierul

    return matrix;
}

void edit(FILE *f_in, char path[], bmp_fileheader *fh, bmp_infoheader *ih) {
    // verific daca fisierul a fost deschis cu succes
    if (f_in == NULL) {
        printf("Nu s-a putut deschide fisierul\n");
        exit(-1);
    }

    // citesc fileheader ul si infoheaderul dupa care pozitionez
    // adresa de citirea cu fseek
    fread(fh, sizeof(bmp_fileheader), 1, f_in);
    fread(ih, sizeof(bmp_infoheader), 1, f_in);
    fseek(f_in, fh->imageDataOffset, SEEK_SET);
}

void save(FILE *f_out, char path[], bmp_fileheader *fh, bmp_infoheader *ih, bmp_bitmap **matrix) {
    // verific daca fisierul a fost deschis cu succes
    if (f_out == NULL) {
        printf("Nu s-a putut deschide fisierul\n");
        exit(-1);
    }

    char padding = 0;

    // scriu informatiile in noua imagine
    fwrite(fh, sizeof(bmp_fileheader), 1, f_out);
    fwrite(ih, sizeof(bmp_infoheader), 1, f_out);
    // pun valoarea 0 pe bitii de padding
     for ( long pad = ftell(f_out) ; pad < fh->imageDataOffset ; pad++)
        fwrite(&padding, sizeof(char), 1, f_out);
    // pozitionez locul de citire a matricei de biti
    fseek(f_out, fh->imageDataOffset, SEEK_SET);

    // citesc matricea de biti
    for (int i = 0; i < ih->height; i++) {
        fwrite(matrix[i], sizeof(bmp_bitmap), ih->width, f_out);
    // in cazul in care apare paddingul, in setez pe 0
        if (ih->width % FOUR != 0) {
            for (int pad = 0; pad < FOUR - ((ih->width * THREE) % FOUR); pad++)
                fwrite(&padding, sizeof(char), 1, f_out);
        }
    }

    fclose(f_out);  // inchide fisierul
}

void quit(bmp_fileheader *fh, bmp_infoheader *ih, bmp_bitmap **mat) {
    // eliberez memoria
    for (int i = 0; i < ih->height; i++) {
        free(mat[i]);
    }
    free(mat);

    free(fh);
    free(ih);
}

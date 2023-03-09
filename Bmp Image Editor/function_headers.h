#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bmp_header.h"

// functia din fisierul task0_parser.c
void parser();

// functiile din fisierul task1_functions.c
bmp_bitmap **matrix(FILE* f_in, bmp_infoheader *ih);
void edit(FILE *f_in, char path[], bmp_fileheader *fh, bmp_infoheader *ih);
void save(
    FILE *f_out, char path[], bmp_fileheader *fh,
    bmp_infoheader *ih, bmp_bitmap **matrix);
void quit(bmp_fileheader *fh, bmp_infoheader *ih, bmp_bitmap **mat);

// functia din fisierul task2_functions.c
void insert(
    bmp_infoheader *ih2, bmp_fileheader *fh2, bmp_infoheader *ih,
    bmp_bitmap **mat, bmp_bitmap **mat2, unsigned int y, unsigned int x);

// functiile din fisierul task3_functions.c
void line_fill(
    int y1, int x1, int y2, int x2, bmp_bitmap **mat,
    bmp_bitmap color, int line_width, char xy, bmp_infoheader *ih);
void draw_line(int y1, int x1, int y2, int x2, bmp_bitmap **mat,
    bmp_bitmap color, int line_width, bmp_infoheader *ih);
void draw_rectangle(int y1, int x1, int width, int height, bmp_bitmap **mat,
    bmp_bitmap color, int line_width, bmp_infoheader *ih);
void draw_triangle(int y1, int x1, int y2, int x2, int y3, int x3, bmp_bitmap **mat,
    bmp_bitmap color, int line_width, bmp_infoheader *ih);

// functiile din fisierul task4_functions.c
int compare(bmp_bitmap matrix_color, bmp_bitmap initial_color);
void complete(
    int y, int x, bmp_bitmap **mat, bmp_bitmap new_color,
    bmp_bitmap initial_color, bmp_infoheader *ih);
void fill(int y, int x, bmp_bitmap **map, bmp_bitmap color, bmp_infoheader *ih);

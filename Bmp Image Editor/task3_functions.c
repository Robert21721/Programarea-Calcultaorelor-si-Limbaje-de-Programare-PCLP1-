#include"function_headers.h"
#define TWO 2

void line_fill(
    int y1, int x1, int y2, int x2, bmp_bitmap **mat,
    bmp_bitmap color, int line_width, char xy, bmp_infoheader *ih
    ) {
    // in functie de intervalul mai mare, desenez linia dupa variabila
    // x sau dupa variabila y
    if (xy == 'y') {
    for (int y = y1; y <= y2; y++) {
    // aplic formula din enunt
        int x = (int)(((x2 - x1)*(y - y1) + x1*(y2 - y1))/(y2 - y1));

    // pentru fiecare bit de pe linia principala colorez un patrat
    // in jurul lui de dimensiune line_width
        for (int i = x - line_width/TWO; i <= x + line_width/TWO; i++)
            for (int j = y - line_width/TWO; j <= y + line_width/TWO; j++)
                if (i >= 0 && j >= 0 && i < ih->height && j < ih->width)
                    mat[i][j] = color;
        }
    }

    if (xy == 'x') {
    // functioneaza in mod similar
        for (int x = x1; x <= x2; x++) {
            int y = (int)(((y2 - y1)*(x - x1) + y1*(x2 - x1))/(x2 - x1));

            for (int i = x - line_width/TWO; i <= x + line_width/TWO; i++)
                for (int j = y - line_width/TWO; j <= y + line_width/TWO; j++)
                    if (i >= 0 && j >= 0 && i < ih->height && j < ih->width)
                        mat[i][j] = color;
        }
    }
}

void draw_line(
    int y1, int x1, int y2, int x2, bmp_bitmap **mat,
    bmp_bitmap color, int line_width, bmp_infoheader *ih
    ) {
    int intervalX = abs(x2 - x1);
    int intervalY = abs(y2 - y1);

    // in functie de intervalul mai mare decid modul in care sa fie desenata linia
    if (intervalY >= intervalX) {
        if (y1 < y2) {
            line_fill(y1, x1, y2, x2, mat, color, line_width, 'y', ih);
        } else if (y1 > y2) {
            line_fill(y2, x2, y1, x1, mat, color, line_width, 'y', ih);
        }
    } else if (intervalY < intervalX) {
        if (x1 < x2) {
            line_fill(y1, x1, y2, x2, mat, color, line_width, 'x', ih);
        } else if (x1 > x2) {
            line_fill(y2, x2, y1, x1, mat, color, line_width, 'x', ih);
        }
    }
}

void draw_rectangle(
    int y1, int x1, int width, int height, bmp_bitmap **mat,
    bmp_bitmap color, int line_width, bmp_infoheader *ih
    ) {
    int y2 = y1 + width;
    int x2 = x1 + height;
    // desenez dreptunghiul facand apel la functia draw_line
    draw_line(y1, x1, y1, x2, mat, color, line_width, ih);
    draw_line(y1, x1, y2, x1, mat, color, line_width, ih);
    draw_line(y2, x1, y2, x2, mat, color, line_width, ih);
    draw_line(y2, x2, y1, x2, mat, color, line_width, ih);
}

void draw_triangle(
    int y1, int x1, int y2, int x2, int y3, int x3, bmp_bitmap **mat,
     bmp_bitmap color, int line_width, bmp_infoheader *ih
     ) {
    // desenez triunghiul facand apel la functia draw_line
    draw_line(y1, x1, y2, x2, mat, color, line_width, ih);
    draw_line(y1, x1, y3, x3, mat, color, line_width, ih);
    draw_line(y2, x2, y3, x3, mat, color, line_width, ih);
}

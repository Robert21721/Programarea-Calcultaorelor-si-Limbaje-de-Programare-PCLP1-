#include"function_headers.h"

int compare(bmp_bitmap matrix_color, bmp_bitmap initial_color) {
    // compar culoarea unui pixel din matrice cu culoarea care
    // trebuie inlocuita si in caz afirmativ intorc 1
    if (
        matrix_color.Blue == initial_color.Blue &&
        matrix_color.Green == initial_color.Green &&
         matrix_color.Red == initial_color.Red
        )
        return 1;
    return 0;
}

void complete(
    int y, int x, bmp_bitmap **mat, bmp_bitmap new_color,
    bmp_bitmap initial_color, bmp_infoheader *ih
    ) {
    // fac fill apeland functia in mod recursiv
    // avand grija sa nu depasesc dimensiunile imaginii
    if ((x + 1 >= 0) && (x + 1 < ih->height) && (y >= 0) && (y < ih->width)) {
        if (compare(mat[x + 1][y], initial_color)) {
            mat[x + 1][y] = new_color;
            complete(y, x + 1, mat, new_color, initial_color, ih);
        }
    }

    if ((x - 1 >= 0) && (x - 1 < ih->height) && (y >= 0) && (y < ih->width)) {
        if (compare(mat[x - 1][y], initial_color)) {
            mat[x - 1][y] = new_color;
            complete(y, x - 1, mat, new_color, initial_color, ih);
        }
    }

    if ((x >= 0) && (x < ih->height) && (y + 1 >= 0) && (y + 1 < ih->width)) {
        if (compare(mat[x][y + 1], initial_color)) {
            mat[x][y + 1] = new_color;
            complete(y + 1, x, mat, new_color, initial_color, ih);
        }
    }

    if ((x >= 0) && (x < ih->height) && (y - 1 >= 0) && (y - 1 < ih->width)) {
        if (compare(mat[x][y - 1], initial_color)) {
            mat[x][y - 1] = new_color;
            complete(y - 1, x, mat, new_color, initial_color, ih);
        }
    }
}

void fill(int y, int x, bmp_bitmap **map, bmp_bitmap color, bmp_infoheader *ih) {
    // retin culoarea initiala si colorez punctul de inceput cu noua culoare
    bmp_bitmap initial_color = map[x][y];
    map[x][y] = color;
    // colorez intreaga forma apeland founctia complete
    complete(y, x, map, color, initial_color, ih);
}

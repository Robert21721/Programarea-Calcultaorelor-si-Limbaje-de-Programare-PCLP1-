#include"function_headers.h"

void insert(
        bmp_infoheader *ih2, bmp_fileheader *fh2, bmp_infoheader *ih,
        bmp_bitmap **mat, bmp_bitmap **mat2, unsigned int y, unsigned int x
         ) {
    // retin in variabilele height si width noua dimensiune a imaginii 2
    unsigned int height = ih2->height, width = ih2->width;

    if (y + ih2->width > ih->width) {
        width = ih->width - y;
        }

    if (x + ih2->height > ih->height) {
        height = ih->height - x;
    }

    // inlocuiesc bitii din imaginea initiala cu bitii din noua imagine
    for (int i = (int)x; i < (int)(x + height); i++) {
        for (int j = (int)(y + width - 1); j >=(int)y; j--) {
            mat[i][j] = mat2[i-x][j-y];
        }
    }

    // eliberez memoria ocupata de a 2a imagine
    for (int i = 0; i < ih2->height; i++) {
            free(mat2[i]);
        }
    free(mat2);

    free(fh2);
    free(ih2);
    }

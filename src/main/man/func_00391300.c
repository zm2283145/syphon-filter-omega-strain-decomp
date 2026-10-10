#include "types.h"
extern int D_004933D0[5];
extern char D_004BC3F0[];
extern char D_004BC400[];
extern unsigned char D_0053B340;
extern unsigned char D_0053B341;
extern unsigned char D_0053B348;
extern unsigned char D_0053B349;
extern int Morph_FindShapeIndex(char* name, int which);
void Expression_Init(void)
{
    int i;
    if (D_004933D0[0] == -1) {
        D_004933D0[0] = 0;
    }
    for (i = 1; i < 5; i++) {
        if (D_004933D0[i] == -1) {
            D_004933D0[i] = D_004933D0[0];
        }
    }
    D_0053B340 = Morph_FindShapeIndex(D_004BC3F0, 0);
    D_0053B341 = Morph_FindShapeIndex(D_004BC3F0, 1);
    D_0053B348 = Morph_FindShapeIndex(D_004BC400, 0);
    D_0053B349 = Morph_FindShapeIndex(D_004BC400, 1);
}
#include "types.h"
typedef struct { float v; float pad[3]; } B5fEnt;
extern B5fEnt D_004F80F0[];
extern B5fEnt D_004F80F4[];
extern B5fEnt D_004F80F8[];
extern B5fEnt D_004F80FC[];
#define B5F_ARG(var, i) (*(int*)&(var) = args[i])
int Script_SetLockColor(int* args) {
    int b;
    int g;
    int r;
    float a;
    int idx;
    int bb, gg, rr, ii;
    float aa;
    B5F_ARG(b, 4);
    bb = b;
    B5F_ARG(g, 3);
    gg = g;
    B5F_ARG(r, 2);
    rr = r;
    B5F_ARG(a, 1);
    aa = a;
    B5F_ARG(idx, 0);
    ii = idx;
    if (ii < 10) {
        if (!(aa <= 0.0f)) {
            D_004F80F0[ii].v = aa;
        }
        D_004F80F4[ii].v = rr;
        D_004F80F8[ii].v = gg;
        D_004F80FC[ii].v = bb;
    }
    return 0;
}
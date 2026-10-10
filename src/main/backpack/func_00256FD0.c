#include "types.h"
typedef struct { int id; int a[4]; int b[4]; int pad; } G3En_00256FD0;
typedef struct { G3En_00256FD0 e[5]; int pad2; int cc; unsigned char d0; } G3El_00256FD0;
typedef struct { int pad; G3El_00256FD0 el[3]; int x280[4]; } G3S_00256FD0;
void func_00256FD0(G3S_00256FD0* s) {
    int j, i, k;
    for (i = 0; i < 4; i++) s->x280[i] = 0;
    for (j = 0; j < 3; j++) {
        s->el[j].cc = 0;
        s->el[j].d0 = 0;
        for (i = 0; i < 5; i++) {
            for (k = 0; k < 4; k++) {
                s->el[j].e[i].a[k] = 0;
                s->el[j].e[i].b[k] = 0;
            }
        }
    }
}
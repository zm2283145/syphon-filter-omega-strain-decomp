#include "types.h"
typedef struct { char c[21]; } S21;
typedef struct { char c[32]; } S32;
typedef struct { char c[256]; } S256;
int func_004505C0();
int func_00451B00(char *, int, char *, int);
extern char D_004C0D10;
extern char *D_00585E60;
typedef struct { S21 name; int a; int b; S32 c; int d; S32 e; S256 f; int g; } R48A;
void func_00448050(int d0, int d1, int d2, R48A *src) {
    if (func_004505C0() == 0) {
        R48A *d;
        *(int *)(D_00585E60 + 0x1EC) = 1;
        switch (src->a) {
        case 0:
            break;
        case -971:
            src->d = -1;
            break;
        case -991:
        case -989:
        case -988:
        default:
            func_00451B00(D_00585E60, 1, &D_004C0D10, 0x970);
            break;
        }
        d = (R48A *)(D_00585E60 + 0x122C);
        d->name = src->name;
        d->a = src->a;
        d->b = src->b;
        d->c = src->c;
        d->d = src->d;
        d->e = src->e;
        d->f = src->f;
        d->g = src->g;
    }
}

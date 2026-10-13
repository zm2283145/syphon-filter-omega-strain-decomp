#include "types.h"
typedef struct { char c[21]; } S21;
typedef struct { char c[32]; } S32;
typedef struct { char c[256]; } S256;
int SFOLobby_NoInstance();
extern char *D_00585E60;
typedef struct { S21 name; int a; int b; int c; S32 d; int e; S32 f; S256 g; int h; signed char flag; } R4B;
void func_00448B70(int d0, int d1, int d2, R4B *src) {
    if (SFOLobby_NoInstance() == 0) {
        switch (src->a) {
        case 0:
            break;
        case 1:
            *(int *)(D_00585E60 + 0x1E0) = 1;
            return;
        case -989:
        case -991:
        case -988:
            break;
        }
        if (src->e >= 0) {
            R4B *d = (R4B *)(D_00585E60 + 0xCF8);
            d->name = src->name;
            d->a = src->a;
            d->b = src->b;
            d->c = src->c;
            d->d = src->d;
            d->e = src->e;
            d->f = src->f;
            d->g = src->g;
            d->h = src->h;
            d->flag = src->flag;
            *(int *)(D_00585E60 + 0x1E0) = 1;
        } else if (src->flag == 1) {
            *(int *)(D_00585E60 + 0x1E0) = 1;
        }
    }
}

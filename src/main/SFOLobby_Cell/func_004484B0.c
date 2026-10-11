#include "types.h"
typedef struct { char c[21]; } S21;
typedef struct { char c[200]; } S200;
typedef struct { S21 name; int a; int b; S200 data; int e8; char ec; } R48;
int func_00128C68();
int func_0044F470();
int func_004505C0();
extern char D_004C0D28;
extern char *D_00585E60;
void func_004484B0(int d0, int d1, int d2, R48 *src) {
    if (func_004505C0() == 0) {
        R48 *d;
        switch (src->a) {
        case 0: {
            int h[1];
            h[0] = 0;
            func_00128C68(src, &D_004C0D28, h);
            func_0044F470(h[0], src);
            break;
        }
        case 1:
        case -991:
        case -989:
        case -988:
            break;
        }
        d = (R48 *)(D_00585E60 + 0x16DC);
        d->name = src->name;
        d->a = src->a;
        d->b = src->b;
        d->data = src->data;
        d->e8 = src->e8;
        d->ec = src->ec;
    }
}

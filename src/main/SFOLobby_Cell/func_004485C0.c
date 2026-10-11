#include "types.h"
typedef struct { char c[21]; } S21;
typedef struct { char c[200]; } S200;
typedef struct { S21 name; int a; int b; S200 data; char e8; } R45;
int String_Copy();
int func_004505C0();
int func_00451B00();
int strncpy();
extern char D_004C0D10;
extern char D_004C0D30;
extern char *D_00585E60;
void func_004485C0(int d0, int d1, int d2, R45 *src) {
    if (func_004505C0() == 0) {
        R45 *d;
        switch (src->a) {
        case 0:
            break;
        case 1:
            String_Copy(&src->data, &D_004C0D30);
            break;
        case -991:
        case -989:
        default:
            func_00451B00(D_00585E60, 1, &D_004C0D10, 0x854);
            String_Copy(&src->data, &D_004C0D30);
            break;
        }
        strncpy(D_00585E60 + 0x2594, &src->data, 0xC8);
        d = (R45 *)(D_00585E60 + 0x15F0);
        d->name = src->name;
        d->a = src->a;
        d->b = src->b;
        d->data = src->data;
        d->e8 = src->e8;
    }
}

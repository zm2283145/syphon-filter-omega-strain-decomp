#include "types.h"
int func_004505C0();
int func_00451B00(char *, int, char *, int);
int memcpy();
extern char D_004C0CB0;
extern char *D_00585E60;
typedef struct { char p[0x18]; int a; int b; } R475;
void func_004475E0(int d0, int d1, int d2, R475 *src) {
    if (func_004505C0() == 0) {
        *(int *)(D_00585E60 + 0x18C) = 1;
        switch (src->a) {
        case 0:
            break;
        case -978:
            func_00451B00(D_00585E60, 0x3A, &D_004C0CB0, 0x2D0);
            break;
        case -998:
            func_00451B00(D_00585E60, 0x3B, &D_004C0CB0, 0x2E0);
            break;
        case -989:
            func_00451B00(D_00585E60, 1, &D_004C0CB0, 0x2EB);
            break;
        case -997:
            func_00451B00(D_00585E60, 0x3C, &D_004C0CB0, 0x2F6);
            break;
        case -987:
            func_00451B00(D_00585E60, 1, &D_004C0CB0, 0x301);
            break;
        case -988:
            func_00451B00(D_00585E60, 1, &D_004C0CB0, 0x30C);
            break;
        case -991:
            func_00451B00(D_00585E60, 1, &D_004C0CB0, 0x317);
            break;
        }
        *(int *)(D_00585E60 + 0x2480) = src->b;
        memcpy(D_00585E60 + 0x250, src, 0xC4);
    }
}

#include "types.h"
int func_004505C0();
int func_00451B00(char *, int, char *, int);
extern char D_004C0CB0;
extern char *D_00585E60;
typedef struct { char p[0x18]; int a; } R44C;
void func_004474C0(int d0, int d1, int d2, R44C *src) {
    if (func_004505C0() == 0) {
        int e;
        *(int *)(D_00585E60 + 0x190) = 1;
        e = src->a;
        switch (e) {
        case 0:
            break;
        case -989:
            func_00451B00(D_00585E60, 1, &D_004C0CB0, 0x351);
            break;
        case -987:
            func_00451B00(D_00585E60, 1, &D_004C0CB0, 0x35C);
            break;
        case -988:
            func_00451B00(D_00585E60, 1, &D_004C0CB0, 0x367);
            break;
        case -991:
            func_00451B00(D_00585E60, 1, &D_004C0CB0, 0x372);
            break;
        default:
            if (e < 0) func_00451B00(D_00585E60, 1, &D_004C0CB0, 0x379);
            break;
        }
    }
}

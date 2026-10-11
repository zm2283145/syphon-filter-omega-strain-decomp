#include "types.h"
int func_00128C68();
char *strchr();
extern char D_004C02A0;
extern char D_004C02D8;

typedef struct { int count; unsigned short v[1]; } T43F;
int func_0043FE20(T43F *out, char *s) {
    int ver;
    int n;
    int i;
    char *p;
    int val;

    out->count = 0;
    if (func_00128C68(s, &D_004C02A0, &ver, &n) != 2) {
        return 0;
    }
    if (ver != 1 || n >= 0xDF || n == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        s = strchr(s + 1, 0xA);
        if (s == 0) {
            return 0;
        }
        if (func_00128C68(s + 1, &D_004C02D8, &val) != 1) {
            return 0;
        }
        if (val & 0xFFFF0000) {
            return 0;
        }
        out->v[i] = val;
        out->count++;
    }
    return out->v[0] == 0x20;
}
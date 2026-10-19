#include "types.h"
typedef struct { int n; unsigned short v[1]; } S43F;
extern char D_004C02A0[];
extern int Libc_Sscanf(char*, char*, ...);
extern char* strchr(const char*, int);
int CharMap_Parse(S43F* s, char* text) {
    int ver[1];
    int n[1];
    int v[1];
    int i;
    s->n = 0;
    if (Libc_Sscanf(text, D_004C02A0, ver, n) != 2) return 0;
    if (ver[0] != 1 || n[0] >= 0xDF || n[0] == 0) return 0;
    for (i = 0; i < n[0]; i++) {
        text = strchr(text + 1, '\n');
        if (!text) return 0;
        if (Libc_Sscanf(text + 1, "%x", v) != 1) return 0;
        if (v[0] & 0xFFFF0000) return 0;
        s->v[i] = v[0];
        s->n++;
    }
    return s->v[0] == 0x20;
}

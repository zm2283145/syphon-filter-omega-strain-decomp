#include "types.h"
typedef struct {
    char p0[0x40];
    float f40;
    char p44[0x320C - 0x44];
    int state;
    char p3210[0x33A5 - 0x3210];
    unsigned char b33A5;
} S_1872F0;
int func_001872F0(S_1872F0* p) {
    if (p->b33A5 || p->state == 0x1F)
        return 3;
    if (p->state == 0x1B)
        return 2;
    return (int)p->f40 ? 0 : 3;
}
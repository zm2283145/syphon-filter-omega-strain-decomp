#include "types.h"
typedef struct { char d[0x18]; } g2E180;
typedef struct { int pad0; int size; g2E180* data; } g2Vec180;
extern void func_004172E0(g2E180* e, int flag);
void func_004183A0(g2Vec180* v) {
    g2E180* b = v->data;
    g2E180* e = b + v->size;
    while (b < e) {
        --e;
        func_004172E0(e, -1);
    }
    v->size = 0;
}
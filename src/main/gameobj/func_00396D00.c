#include "types.h"
typedef struct { char d[0x180]; } g2E180;
typedef struct { int pad0; int size; g2E180* data; } g2Vec180;
extern void func_00396D80(g2E180* e, int flag);
void func_00396D00(g2Vec180* v) {
    g2E180* b = v->data;
    g2E180* e = b + v->size;
    while (b < e) {
        --e;
        func_00396D80(e, -1);
    }
    v->size = 0;
}
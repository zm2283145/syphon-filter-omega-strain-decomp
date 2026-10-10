#include "types.h"
typedef struct { char d[0x3C]; } g2E3C;
typedef struct { int pad0; int size; g2E3C* data; } g2Vec3C;
extern void func_001AEF70(g2E3C* e, int flag);
void func_002A6F40(g2Vec3C* v) {
    g2E3C* b = v->data;
    g2E3C* e = b + v->size;
    while (b < e) {
        --e;
        func_001AEF70(e, -1);
    }
    v->size = 0;
}
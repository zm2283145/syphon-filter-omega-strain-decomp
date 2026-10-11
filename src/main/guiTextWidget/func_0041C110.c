#include "types.h"
typedef struct { char pad[0x11]; unsigned char b11; unsigned char b12; } PC110;
typedef struct { char pad[0x74]; unsigned char mode; char pad2[3]; PC110* p; } TC110;
void func_0041C110(TC110* t, unsigned char mode) {
    t->mode = mode;
    if (t->p) {
        t->p->b12 = t->mode == 0;
        t->p->b11 = t->mode == 2;
    }
}

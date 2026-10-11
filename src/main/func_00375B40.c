#include "types.h"
typedef struct { char p0[8]; unsigned int end; char pC[4]; unsigned int cur; int f14; int f18; char f1C; } B375;
typedef struct { char p0[0xC]; int base; } C375;
typedef struct { B375 *buf[0x33]; C375 *cfg[3]; int cursel; } A375;
int func_00375B40(A375 *self, unsigned char i, int n) {
    B375 *b = self->buf[i];
    if (b->cur + n * 0x10 >= b->end) {
        self->cursel = i;
        b->cur = self->cfg[i]->base;
    }
    b->f14 = b->cur;
    b->f18 = 0;
    b->f1C = 0;
    return b->cur;
}

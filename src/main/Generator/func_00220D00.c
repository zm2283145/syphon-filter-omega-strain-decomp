#include "types.h"
typedef struct cGen00220D00 {
    char pad0[0xC];
    char f0C[0x20];
    char b2C;
    char pad2D[0xCC - 0x2D];
    unsigned int mask;
} cGen00220D00;
extern void func_0043B190(void* msg);
extern void func_0043A030(void* msg, void* target);
void cGenerator_v09(cGen00220D00* self, int bit)
{
    if (bit >= 0)
        self->mask &= ~(1 << bit);
    else
        self->mask = 0;
    if (self->mask == 0) {
        int msg[1];
        self->b2C = 0;
        func_0043B190(msg);
        func_0043A030(msg, self->f0C);
    }
}
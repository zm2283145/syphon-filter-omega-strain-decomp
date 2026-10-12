#pragma cplusplus on
#include "types.h"

typedef enum { MODE_OFF, MODE_ON } Mode3700;

typedef struct {
    int id;
    int f4;
    bool flag;
    unsigned char pad[11];
} E3700;

typedef struct {
    unsigned char pad0[0x48];
    void* tbl;
    unsigned char pad4C[0x70 - 0x4C];
    int count;
    E3700* items;
} O3700;

extern "C" void func_00421290(void* t, int id, int i, Mode3700 m);

/* MW folds `c ? 0 : 1` on ints into sltiu; enum constants keep the movz select. */
extern "C" void func_00353700(O3700* self)
{
    int i;
    for (i = 0; i < self->count; i++) {
        E3700* e = &self->items[(unsigned int)i];
        func_00421290(self->tbl, e->id, i, e->flag ? MODE_OFF : MODE_ON);
    }
}

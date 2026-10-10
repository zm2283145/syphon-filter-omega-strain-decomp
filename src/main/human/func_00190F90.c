#include "types.h"

typedef struct Rec14 {
    char b[0x14];
} Rec14;

typedef struct Tmp20 {
    char b[0x14];
} Tmp20;

typedef struct Holder {
    char pad[0x3C];
    char vec[4];
    int count;
    Rec14* data;
} Holder;

extern void func_00191040(Tmp20*, int, int*);
extern void func_001BDA10(void*, Rec14*, int, Tmp20*);

/* Builds a record from (a1, {a2, a3}) and appends it to the vector at +0x3C. */
Holder* func_00190F90(Holder* self, int a1, int a2, int a3) {
    Tmp20 rec;
    int pair[2];
    pair[0] = a2;
    pair[1] = a3;
    func_00191040(&rec, a1, pair);
    func_001BDA10(self->vec, self->data + self->count, 1, &rec);
    return self;
}

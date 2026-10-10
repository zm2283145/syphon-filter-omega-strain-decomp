#include "types.h"

typedef struct { float a; float b; } FPair;
typedef struct { FPair items[2]; float scale; } FPairTable;

/* Sets entry idx to (*a, *b * scale). */
void func_00364FB0(FPairTable* self, int idx, float* a, float* b)
{
    float scaled = *b * self->scale;
    self->items[idx].a = *a;
    self->items[idx].b = scaled;
}

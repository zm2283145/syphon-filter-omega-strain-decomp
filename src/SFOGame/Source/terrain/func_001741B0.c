#pragma opt_strength_reduction off
#include "types.h"
typedef struct { int pad; int size; int* data; } Vec_741B0;
typedef struct { char pad[0xC]; char* cur; } Strm_741B0;
typedef struct { char pad[0x204]; Vec_741B0 keys; char pad210[0x20]; float a[3]; char pad23C[4]; float b[3]; } Ter_741B0;
extern void std_vector_imp_cObjectId_reserve(Vec_741B0* v, int n);
extern void std_vector_imp_cObjectId_insert(Vec_741B0* v, int* pos, int n, int* key);
void cTerrain_InitializeActivation_cPopulationR_cArrayP(Ter_741B0* self, Strm_741B0* s, Vec_741B0* src)
{
    int n;
    int i;
    self->a[0] = *(float*)s->cur; s->cur += 4;
    self->a[1] = *(float*)s->cur; s->cur += 4;
    self->a[2] = *(float*)s->cur; s->cur += 4;
    self->b[0] = *(float*)s->cur; s->cur += 4;
    self->b[1] = *(float*)s->cur; s->cur += 4;
    self->b[2] = *(float*)s->cur; s->cur += 4;
    n = src->size;
    if (n > 0) {
        std_vector_imp_cObjectId_reserve(&self->keys, self->keys.size + n);
        for (i = 0; i < n; i++) {
            unsigned int v = src->data[i];
            int hi = (v & 0xFF0000) >> 16; int k = (v & 0xFFFF) | (hi << 16);
            std_vector_imp_cObjectId_insert(&self->keys, self->keys.data + self->keys.size, 1, &k);
        }
    }
}


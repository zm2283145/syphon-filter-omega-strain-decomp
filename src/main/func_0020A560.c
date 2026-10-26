#include "types.h"
#pragma optimization_level 1

typedef struct { int unk0; int unk4; int unk8; } Triple;
extern void Metrowerks_swap_compressedpairR_compressedpairR(Triple* dst, Triple* src);
extern void std_swap_cSkaBlendSequenceItemPR_cSkaBlendSequenceItemPR(int* dst, int* src);
extern void std_swap_uintR_uintR(int* dst, int* src);

/* Assigns src to dst member by member (no-op on self-assignment). */
void std_swap_vectordeleterR_vectordeleterR_14(Triple* dst, Triple* src)
{
    if (dst != src) {
        Metrowerks_swap_compressedpairR_compressedpairR(dst, src);
        std_swap_cSkaBlendSequenceItemPR_cSkaBlendSequenceItemPR(&dst->unk8, &src->unk8);
        std_swap_uintR_uintR(&dst->unk4, &src->unk4);
    }
}

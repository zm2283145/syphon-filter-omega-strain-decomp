#include "types.h"

/* Built at a lower optimization level (unscheduled call sequence). */
#pragma optimization_level 1

typedef struct { int head; int mid; int tail; } Triple;
extern void Metrowerks_swap_compressedpairR_compressedpairR_3(Triple* dst, Triple* src);
extern void std_swap_cSkaSwitchItemPR_cSkaSwitchItemPR(int* dst, int* src);
extern void std_swap_uintR_uintR(int* dst, int* src);

/* Assignment: copies the three parts unless dst == src. */
void std_swap_vectordeleterR_vectordeleterR_16(Triple* dst, Triple* src)
{
    if (dst != src) {
        Metrowerks_swap_compressedpairR_compressedpairR_3(dst, src);
        std_swap_cSkaSwitchItemPR_cSkaSwitchItemPR(&dst->tail, &src->tail);
        std_swap_uintR_uintR(&dst->mid, &src->mid);
    }
}

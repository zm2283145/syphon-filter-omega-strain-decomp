#include "types.h"

extern void Metrowerks_swap_compressedpairR_compressedpairR_2(void* dst, void* src);
extern void std_swap_cSkaTransBLENDPR_cSkaTransBLENDPR(void* dst, void* src);
extern void std_swap_uintR_uintR(void* dst, void* src);

/* Copy-assigns three members (+0, +8, +4) unless self-assignment. */
#pragma optimization_level 1
void std_swap_vectordeleterR_vectordeleterR_15(char* self, char* other)
{
    if (self != other) {
        Metrowerks_swap_compressedpairR_compressedpairR_2(self, other);
        std_swap_cSkaTransBLENDPR_cSkaTransBLENDPR(self + 8, other + 8);
        std_swap_uintR_uintR(self + 4, other + 4);
    }
}
#pragma optimization_level reset

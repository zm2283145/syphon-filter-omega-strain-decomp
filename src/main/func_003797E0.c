#include "types.h"

/* Unpacked fields of a 64-bit hardware register (stored one per word). */
typedef struct RegFields {
    char pad[0xD8];
    unsigned int f0;  /* bit 0 */
    unsigned int f1;  /* bits 1.. */
    unsigned int f4;  /* bits 4.. */
    unsigned int f12; /* bits 12.. */
    unsigned int f14; /* bit 14 */
    unsigned int f15; /* bit 15 */
    unsigned int f16; /* bit 16 */
    unsigned int f17; /* bits 17.. */
} RegFields;

/* Packs the unpacked register fields into a 64-bit register value. */
unsigned long func_003797E0(RegFields* s) {
    return (unsigned long)s->f0
         | ((unsigned long)s->f1 << 1)
         | ((unsigned long)s->f4 << 4)
         | ((unsigned long)s->f12 << 12)
         | ((unsigned long)s->f14 << 14)
         | ((unsigned long)s->f15 << 15)
         | ((unsigned long)s->f16 << 16)
         | ((unsigned long)s->f17 << 17);
}

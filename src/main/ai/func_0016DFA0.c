/*
 * Matched functions (byte-identical with the retail executable).
 * Initializes a few fields of an AI state record.
 */

#include "types.h"

extern char D_0053834C[]; /* float */
extern char D_005383C8[]; /* pointer */

typedef struct AIStateInit {
    char pad00[0x10];
    float unk10;  /* 0x10 */
    int unk14;    /* 0x14: written as the bit pattern of pi/4 */
    char pad18[0x38];
    int unk50;    /* 0x50 */
} AIStateInit;

void func_0016DFA0(AIStateInit* self) {
    self->unk14 = 0x3F490FDB; /* 0.7853982f */
    self->unk10 = *(float*)D_0053834C;
    self->unk50 = *(int*)D_005383C8 + 20;
}

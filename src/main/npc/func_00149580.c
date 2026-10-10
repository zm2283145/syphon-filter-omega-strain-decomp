#include "types.h"

typedef struct cNPC_5C {
    char pad000[0x141];
    unsigned char flag0 : 1; /* 0x141 */
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char flag3 : 1;
    unsigned char flag4 : 4;
    char pad142[0x72];
    int unk1B4;              /* 0x1B4 */
} cNPC_5C;

/* cNPC virtual slot 0x5C: stores the value at +0x1B4 and clears flag bit 3. */
void cNPC_v5C(cNPC_5C* self, int value) {
    self->unk1B4 = value;
    self->flag3 = 0;
}

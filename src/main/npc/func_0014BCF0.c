#include "types.h"

typedef struct Target78 {
    char pad00[0x78];
    int id; /* 0x78 */
} Target78;

typedef struct cNPC_35 {
    char pad000[0x44];
    char state44[0xFB];      /* 0x044 */
    unsigned char kind;      /* 0x13F */
    char pad140[0x70];
    void* brain;             /* 0x1B0 */
} cNPC_35;

extern void func_0016E170(void* state, int kind, int value);
extern void func_0015FB20(void* brain, int id);

/* cNPC virtual 0x35: records an event kind (< 7) and forwards the target. */
void cNPC_v35(cNPC_35* self, int kind, Target78* target) {
    if ((unsigned char)kind < 7) {
        func_0016E170(self->state44, (unsigned char)kind, 100);
        if (target) {
            self->kind = kind;
            func_0015FB20(self->brain, target->id);
        }
    }
}

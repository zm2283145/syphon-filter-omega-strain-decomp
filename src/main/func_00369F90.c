#include "types.h"
typedef struct {
    char pad0[0x40];
    char state[0x14C - 0x40];
    int busy;
    char pad150[0x16C - 0x150];
    char stickL[8];
    char stickR[8];
    char pad17C[0x1C0 - 0x17C];
} PadEntry;
typedef struct { int a0; int count; } PadSet;
extern void Pad_GetStickDeadzone(float* out, void* state, void* stick, int flag);

int func_00369F90(PadSet* self) {
    unsigned char active = 0;
    int i;
    for (i = 0; i < self->count; i++) {
        PadEntry* p = (PadEntry*)self + i;
        active = (active | p->busy) != 0;
        if (!active) {
            float l[2];
            float r[2];
            float lx, ly, rx, ry;
            Pad_GetStickDeadzone(l, p->state, p->stickL, 0);
            lx = l[0]; ly = l[1];
            Pad_GetStickDeadzone(r, p->state, p->stickR, 0);
            rx = r[0]; ry = r[1];
            { float z = 0.0f; active = lx != z || ly != z || rx != z || ry != z; }
        }
    }
    return !active;
}

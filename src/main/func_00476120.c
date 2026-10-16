#include "types.h"
typedef struct H1Actor6120 {
    char pad0000[0x3248];
    int flags;               /* 0x3248 */
    char pad324C[0x3310 - 0x324C];
    void* phys;              /* 0x3310 */
} H1Actor6120;
extern float func_00476230(H1Actor6120* self, int unused);
extern float Math_Floorf(float x);
extern float Math_FMod(float x, float y);
extern float D_004A0418;
static inline float h1_fabs(float x) { asm { abs.s x, x } return x; }

static inline unsigned char h1_aligning(H1Actor6120* s) { unsigned char r = 1; if (!((s->flags >> 25) & 1) && !((s->flags >> 26) & 1)) r = 0; return r; }
/* Hand parity on the ladder (left hand when true), optionally inverted while aligning. */
int Ladder_HandParity(H1Actor6120* self, int invert) {
    if (self->phys != 0) {
        int r = (unsigned char)(Math_FMod(Math_Floorf(0.5f + h1_fabs(func_00476230(self, 0)) / (2.0f * D_004A0418)), 2.0f) < 0.999f);
        unsigned char flip = 0;
        if (invert) {
            if (h1_aligning(self)) flip = 1;
        }
        if (flip) r = !r;
        return r;
    }
    return 1;
}
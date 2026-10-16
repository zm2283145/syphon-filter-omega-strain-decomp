#include "types.h"
typedef struct {
    int target; int current; char pad08[0x28];
    unsigned char b30; unsigned char b31; char pad32[2];
    int f34; float v38; float v3C; float v40; float v44;
} Track2609;
void VisionMgr_SetPendingMode(Track2609* s, int id, int force) {
    if (s->target != id) {
        s->current = id;
        if (force) s->target = id;
    }
    if (s->current == -1 && id != 0) {
        s->current = id;
        s->f34 = 0;
        s->v44 = 0; s->v40 = 0; s->v3C = 0; s->v38 = 0;
        s->b30 = 0;
        s->b31 = 0;
        s->v38 = 0.0f; s->v3C = 1.0f; s->v40 = 0.0f; s->v44 = 0.0f;
    }
}
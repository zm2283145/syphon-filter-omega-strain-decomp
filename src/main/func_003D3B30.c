#include "types.h"
typedef struct { char pad[0x64]; int count; } E2Target;
typedef struct { char pad[0x1176C]; E2Target* target; int pos; int step; } E2Anim;
void Shadow_NextReceiverBatch(E2Anim* s) {
    if (s->target) {
        s->pos += s->step;
        if (s->pos == s->target->count) {
            s->target = 0;
            s->pos = 0;
            s->step = 0;
        }
    }
}
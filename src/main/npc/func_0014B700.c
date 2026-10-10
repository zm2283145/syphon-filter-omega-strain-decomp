#include "types.h"

typedef struct cNPC {
    char pad[0x70];
    float rangeMin;
    float rangeMax;
    char pad2[0xAC - 0x78];
    int rangePriority;
} cNPC;

/* vtable slot: sets a range center +- half width when priority >= current. */
void cNPC_v55(cNPC* self, int priority, float center, float width) {
    if (priority >= self->rangePriority) {
        float half = 0.5f * width;
        self->rangeMin = center - half;
        self->rangeMax = center + half;
        self->rangePriority = priority;
    }
}

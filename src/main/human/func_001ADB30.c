#include "types.h"
typedef struct { unsigned char latched; unsigned char value; } LatchEdge;
void Physical_LatchEdgeRequest(LatchEdge* e, int v) {
    if (e->latched) {
        e->value = e->value && v;
    } else {
        e->value = v;
    }
    e->latched = 1;
}
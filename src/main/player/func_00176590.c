#include "types.h"
typedef struct { char pad[0x1AC]; float f1AC; } A2P176;
void cPlayer_v1E(A2P176* p, float x) {
    if (!(x <= p->f1AC)) p->f1AC = x;
}
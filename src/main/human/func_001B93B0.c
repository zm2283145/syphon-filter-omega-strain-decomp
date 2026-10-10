#include "types.h"
typedef struct { int a[4]; float f10; } Seg1B9;
typedef struct { int a[10]; float f28; int b; Seg1B9* seg; float f34; } Ch1B9;
int AnimChannel_IsFreshSegment(Ch1B9* c) {
    int r = c->f34 == c->seg->f10;
    if (r) r = c->f28 > 0.0f;
    return r;
}
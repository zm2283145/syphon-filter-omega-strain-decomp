#include "types.h"
typedef struct { char pad[0x62]; unsigned char useLos; } Col_3BCDD0;
extern int Los_TraceWithWater(Col_3BCDD0* c, void* ray, int mode, void* out);
extern int func_003C3880(Col_3BCDD0* c, void* ray, int mode, void* out);
extern int Los_TraceTriangles(Col_3BCDD0* c, void* ray, int mode, void* out);
extern int Col_TraceFloorTriangles(Col_3BCDD0* c, void* ray, int mode, void* out);
unsigned char Col_TraceFloorRay(Col_3BCDD0* c, void* ray, int mode, void* out) {
    unsigned char r;
    if (c->useLos) {
        if (mode) r = Los_TraceWithWater(c, ray, mode, out);
        else r = func_003C3880(c, ray, mode, out);
    } else if (mode) r = Los_TraceTriangles(c, ray, mode, out);
    else r = Col_TraceFloorTriangles(c, ray, mode, out);
    return r;
}
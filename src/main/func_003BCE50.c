#include "types.h"
typedef struct { char p00[0x62]; unsigned char mask; } ColA_3BCE50;
typedef struct { char p00[0x40]; unsigned char mask; } ColB_3BCE50;
extern int func_003C4A80(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
extern int Los_IntersectRecord(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
extern int func_003C4120(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
extern int Col_SegmentVsTriangle(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
unsigned char Col_TestSegmentTriangles(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d) {
    unsigned char r;
    int hit = (unsigned char)(b->mask & a->mask) != 0;
    if (mode) {
        if (hit)
            r = func_003C4A80(a, b, mode, d);
        else
            r = Los_IntersectRecord(a, b, mode, d);
    } else {
        if (hit)
            r = func_003C4120(a, b, mode, d);
        else
            r = Col_SegmentVsTriangle(a, b, mode, d);
    }
    return r;
}
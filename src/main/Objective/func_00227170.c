#pragma cplusplus on
#include "types.h"
typedef struct {
    char pad0[0x24];
    signed char state;
    unsigned char flag25;
    signed char kind;
} Obj_227170;
typedef struct {
    char p0[0xA4];
    int cur;
    char pA8[0xB0 - 0xA8];
    Obj_227170* lists[32][32];
    Obj_227170* extra[32];
    int counts[32];
    int total;
} Man_227170;

static inline bool IsActive_227170(Obj_227170* o) { return o->state == 1 || o->state == 2; }
extern "C" int ObjMan_GatherObjectives(Man_227170* m, Obj_227170** out, int max, int f25, int fActive, int fKind5, int fState1, int fState2)
{
    int n;
    int pass;
    if (!out) return 0;
    n = 0;
    for (pass = 0; pass < 2; pass++) {
        int count;
        int i;
        Obj_227170** list;
        if (pass == 0) list = m->extra;
        else list = m->lists[m->cur];
        if (pass == 0) count = m->total;
        else count = m->counts[m->cur];
        for (i = 0; i < count && n < max; list++, i++) {
            if (f25 != -1 && (f25 == 1) != (*list)->flag25) continue;
            if (fActive != -1 && (fActive == 1) != IsActive_227170(*list)) continue;
            if (fKind5 != -1 && (fKind5 == 1) != ((*list)->kind == 5)) continue;
            if (fState1 != -1 && (fState1 == 1) != ((*list)->state == 1)) continue;
            if (fState2 != -1 && (fState2 == 1) != ((*list)->state == 2)) continue;
            n++;
            *out++ = *list;
        }
    }
    return n;
}







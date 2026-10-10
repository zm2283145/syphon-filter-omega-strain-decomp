#include "types.h"

extern void ObjMan_GatherObjectives(void* a, void* b, void* c, int d, int e, int f, int g, int h);

/* Wrapper: gathers objectives with a negated team mask and fixed defaults. */
void func_002270C0(void* a, void* b, void* c, unsigned char flag) {
    ObjMan_GatherObjectives(a, b, c, 1, -1, -flag, 1, -1);
}

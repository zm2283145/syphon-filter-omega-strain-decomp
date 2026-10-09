/*
 * Matched functions from gameobj.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int ChannelVector_Resize(void* v, int a1, int a2);
extern int func_001BE020(void* v, int a1, int a2);

int func_00393B80(void* v, int a1, int a2) {
    return func_001BE020(v, a1, a2);
}

int func_00393B90(char* self) {
    return *(int*)(self + 0x58);
}

/* Clears a two-word pair. */
int* func_00393BA0(int* p) {
    p[0] = 0;
    p[1] = 0;
    return p;
}

int func_00393BB0(void* v, int a1, int a2) {
    return ChannelVector_Resize(v, a1, a2);
}

int func_00393BC0(char* self) {
    return *(int*)(self + 0x54);
}

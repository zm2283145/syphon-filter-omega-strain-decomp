/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "game_types.h"

extern int func_00129A70(char* dst, const char* src, int n); /* bounded string copy */

int func_0012F5B0(NameSlotTable* t, int i) {
    return t->values[i];
}

void func_0012F5C0(NameSlotTable* t, int i, int value) {
    t->values[i] = value;
}

char* func_0012F5D0(NameSlotTable* t, int i) {
    return t->names[i];
}

/* Copies up to 15 characters of name into slot i and terminates it. */
int NameSlot_SetName(NameSlotTable* t, int i, const char* name) {
    int ret;

    ret = func_00129A70(t->names[i], name, 15);
    t->names[i][15] = 0;
    return ret;
}

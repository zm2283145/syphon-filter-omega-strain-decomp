/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

extern int Script_ObjectToId(int obj);
extern int func_003D9CC0(void* self, int* id);

/* Converts obj to its script id and passes it by address to func_003D9CC0. */
void func_003D9C80(void* self, int obj) {
    int loc[1];

    loc[0] = Script_ObjectToId(obj);
    func_003D9CC0(self, loc);
}

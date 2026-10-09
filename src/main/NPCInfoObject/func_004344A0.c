/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */

#include "npc_types.h"

extern void func_00434600(void* self, int* key);

/* Calls func_00434600 with the key passed by address. */
void func_004344A0(void* self, int key) {
    int k[1];

    *(int*)(char*)k = key;
    func_00434600(self, k);
}

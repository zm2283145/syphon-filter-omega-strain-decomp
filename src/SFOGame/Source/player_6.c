/*
 * SFOGame/Source/player: 1 file, 00175830
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00175830 */
#pragma push /* merge_units */
#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

typedef struct Actor {
    char pad[0x4C];
    int type;
    char pad2[0x3528 - 0x50];
    void* items;
} Actor;

extern int g_HumanActorClassKey;
extern Actor* cGOBJ_SOBJ_convert(void*);
extern int cInventory_GetCount_charP(void*, int);

/* Script: PlayerGetItemCount(actor, item) -> count, 0 for non-players. */
int Script_PlayerGetItemCount(ScriptArg* args) {
    volatile int result;
    int item[1];
    int itemValue;
    Actor* actor;
    int count;
    item[0] = args[1].i;
    itemValue = *(int*)item;
    actor = cGOBJ_SOBJ_convert(args[0].p);
    if (actor->type == g_HumanActorClassKey) {
        count = cInventory_GetCount_charP(actor->items, itemValue);
    } else {
        count = 0;
    }
    result = count;
    return result;
}
static inline void merge_flush_func_00175830(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00175830 */

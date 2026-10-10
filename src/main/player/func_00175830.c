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

extern int D_0049D010;
extern Actor* GObj_IdentityB(void*);
extern int Global_PlayerGetItemCount(void*, int);

/* Script: PlayerGetItemCount(actor, item) -> count, 0 for non-players. */
int Script_PlayerGetItemCount(ScriptArg* args) {
    volatile int result;
    int item[1];
    int itemValue;
    Actor* actor;
    int count;
    item[0] = args[1].i;
    itemValue = *(int*)item;
    actor = GObj_IdentityB(args[0].p);
    if (actor->type == D_0049D010) {
        count = Global_PlayerGetItemCount(actor->items, itemValue);
    } else {
        count = 0;
    }
    result = count;
    return result;
}

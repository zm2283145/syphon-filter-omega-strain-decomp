/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

/* Virtual-call view of Item: only the slots used here are named (vtable offset in comments). */
struct Item {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int flag); /* +0x5C */
    virtual void Method60(int flag); /* +0x60 */
};

typedef struct cPlayer {
    char pad[0x50];
    int sub50; /* +0x50 */
    char pad54[0x1A0 - 0x54];
    Item* held; /* +0x1A0 */
} cPlayer;

extern "C" void func_002504C0(int* sub, Item* item);

/* Replaces the held item: releases the old one (virtual +0x60), attaches and activates the new one (virtual +0x5C). */
extern "C" void func_00176F30(cPlayer* self, Item* item)
{
    if (self->held)
        self->held->Method60(1);
    self->held = item;
    if (item) {
        func_002504C0(&self->sub50, item);
        item->Method5C(1);
    }
}

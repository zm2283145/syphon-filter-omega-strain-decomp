/*
 * main/gobj: range (2 files, 003CE980-003CE9D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "gobj_types.h"

/* merge_units: begin func_003CE980 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Component {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F();
    virtual void Activate(); /* +0x48 */
};

typedef struct Owner {
    char pad[0x2C];
    unsigned char enabled;  /* +0x2C */
    unsigned char active;   /* +0x2D */
    char pad2E[0x58 - 0x2E];
    Component* component; /* +0x58 */
} Owner;

/* Marks the object active (+0x2D) and, if enabled (+0x2C), activates its component (+0x58, virtual +0x48). */
extern "C" void Object_Activate(Owner* self)
{
    Component* component;
    self->active = 1;
    component = self->component;
    if (component && self->enabled)
    component->Activate();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE980(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE980 */

/* merge_units: begin func_003CE9D0 */
#pragma push /* merge_units */
/*
 * Matched functions from gobj.cc (byte-identical with the retail executable).
 */


void cNode_v14(void) {
}

void func_003CE9E0(void) {
}

void func_003CE9F0(void) {
}

void cNode_v0D(void) {
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE9D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE9D0 */

/*
 * main/gobj: range (2 files, 003CE790-003CE7D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003CE790 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

/* Virtual-call view of Attachment: only the slots used here are named (vtable offset in comments). */
struct Attachment {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10();
    virtual void Method4C(); /* +0x4C */
};

typedef struct Owner {
    char pad[0x2D];
    unsigned char active;   /* +0x2D */
    char pad2E[0x58 - 0x2E];
    Attachment* attachment; /* +0x58 */
} Owner;

/* Clears the active flag and calls the attachment's virtual +0x4C, if any. */
extern "C" void Object_Deactivate(Owner* self)
{
    self->active = 0;
    if (self->attachment)
        self->attachment->Method4C();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE790 */

/* merge_units: begin func_003CE7D0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on


/* Clears the active flag and calls its virtual at vtable+0x4C, if any. */
extern "C" void func_003CE7D0(Owner* self)
{
    self->active = 0;
    if (self->attachment)
        self->attachment->Method4C();
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003CE7D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003CE7D0 */

/*
 * SFOGame/Source/GameGOBJ: 2 files, 00213A60-00213AC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00213A60 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable_base_dtor.h"

DEFINE_VTABLE_BASE_DTOR(cElevatorNotice_dtor, D_004DAED0, cMessage_dtor)
static inline void merge_flush_func_00213A60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00213A60 */

/* merge_units: begin func_00213AC0 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

typedef struct Link { int head; } Link;

/* Virtual-call view of Target: only the slots used here are named (vtable offset in comments). */
struct Target {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v1A(); virtual void v1B(); virtual void v1C(); virtual void v1D();
    virtual void v1E(); virtual void v1F();
    virtual int Method88(); /* +0x88 */
    char pad04[0x68 - 4];
    Link* link; /* +0x68 */
    bool HasItems() { return link->head != 0; }
};

typedef struct Holder {
    char pad[0x60];
    unsigned char enabled; /* +0x60 */
    char pad61[3];
    Target* target; /* +0x64 */
} Holder;

static inline bool IsReady(Holder* self)
{
    return self->enabled && self->target->HasItems();
}

/* Returns the target's virtual +0x88 result when enabled and its link is non-empty, else 0. */
#pragma optimization_level 3
extern "C" int cGameGOBJ_GetBBox(Holder* self)
{
    if (!IsReady(self))
        return 0;
    return self->target->Method88();
}
#pragma optimization_level reset
static inline void merge_flush_func_00213AC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00213AC0 */
